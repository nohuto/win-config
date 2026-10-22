
/* THIS FILE IS AUTO-GENERATED!  DO NOT EDIT!
**
** To modify this file, regenerate after editing
** any RKY file
*/

#if !defined (_G_D3DOGLREG_H_)
#define _G_D3DOGLREG_H_

#if !defined KERNEL_NOTIFICATION_ID_FLAG 
#define KERNEL_NOTIFICATION_ID_FLAG                                    0x01000000
#define NEEDS_KERNEL_NOTIFICATION(id)                                  (id & KERNEL_NOTIFICATION_ID_FLAG)
#endif // KERNEL_NOTIFICATION_ID_FLAG 

#define AAMODE_STRING                                                  "70835937"
#define AAMODE_ID                                                      0x100b8ede
#define AAMODE_OVERINSTALL                                             0 // OVERRIDE
#define AAMODE_NONE                                                    0x0
#define AAMODE_SUPERSAMPLE_2X_H                                        0x1
#define AAMODE_SUPERSAMPLE_2X_V                                        0x2
#define AAMODE_SUPERSAMPLE_1_5X1_5                                     0x2
#define AAMODE_FREE_0x03                                               0x3
#define AAMODE_FREE_0x04                                               0x4
#define AAMODE_SUPERSAMPLE_4X                                          0x5
#define AAMODE_SUPERSAMPLE_4X_BIAS                                     0x6
#define AAMODE_SUPERSAMPLE_4X_GAUSSIAN                                 0x7
#define AAMODE_FREE_0x08                                               0x8
#define AAMODE_FREE_0x09                                               0x9
#define AAMODE_SUPERSAMPLE_9X                                          0xA
#define AAMODE_SUPERSAMPLE_9X_BIAS                                     0xB
#define AAMODE_SUPERSAMPLE_16X                                         0xC
#define AAMODE_SUPERSAMPLE_16X_BIAS                                    0xD
#define AAMODE_MULTISAMPLE_2X_DIAGONAL                                 0xE
#define AAMODE_MULTISAMPLE_2X_QUINCUNX                                 0xF
#define AAMODE_MULTISAMPLE_4X                                          0x10
#define AAMODE_FREE_0x11                                               0x11
#define AAMODE_MULTISAMPLE_4X_GAUSSIAN                                 0x12
#define AAMODE_MIXEDSAMPLE_4X_SKEWED_4TAP                              0x13
#define AAMODE_FREE_0x14                                               0x14
#define AAMODE_FREE_0x15                                               0x15
#define AAMODE_MIXEDSAMPLE_6X                                          0x16
#define AAMODE_MIXEDSAMPLE_6X_SKEWED_6TAP                              0x17
#define AAMODE_MIXEDSAMPLE_8X                                          0x18
#define AAMODE_MIXEDSAMPLE_8X_SKEWED_8TAP                              0x19
#define AAMODE_MIXEDSAMPLE_16X                                         0x1a
#define AAMODE_MULTISAMPLE_4X_GAMMA                                    0x1b
#define AAMODE_MULTISAMPLE_16X                                         0x1c
#define AAMODE_VCAA_32X_8v24                                           0x1d
#define AAMODE_CORRUPTION_CHECK                                        0x1e
#define AAMODE_6X_CT                                                   0x1f
#define AAMODE_MULTISAMPLE_2X_DIAGONAL_GAMMA                           0x20
#define AAMODE_SUPERSAMPLE_4X_GAMMA                                    0x21
#define AAMODE_MULTISAMPLE_4X_FOSGAMMA                                 0x22
#define AAMODE_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA                        0x23
#define AAMODE_SUPERSAMPLE_4X_FOSGAMMA                                 0x24
#define AAMODE_MULTISAMPLE_8X                                          0x25
#define AAMODE_VCAA_8X_4v4                                             0x26
#define AAMODE_VCAA_16X_4v12                                           0x27
#define AAMODE_VCAA_16X_8v8                                            0x28
#define AAMODE_MIXEDSAMPLE_32X                                         0x29
#define AAMODE_SUPERVCAA_64X_4v12                                      0x2a
#define AAMODE_SUPERVCAA_64X_8v8                                       0x2b
#define AAMODE_MIXEDSAMPLE_64X                                         0x2c
#define AAMODE_MIXEDSAMPLE_128X                                        0x2d
#define AAMODE_COUNT                                                   0x2e
#define AAMODE_METHOD_MASK                                             0x0000ffff
#define AAMODE_METHOD_MAX                                              0xf1c57815
#define AAMODE_SELECTOR_MASK                                           0x30000000
#define AAMODE_SELECTOR_APP_CONTROL                                    0x00000000
#define AAMODE_SELECTOR_OVERRIDE                                       0x10000000
#define AAMODE_SELECTOR_ENHANCE                                        0x20000000
#define AAMODE_SELECTOR_SLIAA_MASK                                     0x40000000
#define AAMODE_SELECTOR_MAX                                            0x20000000
#define AAMODE_REPLAY_SAMPLES_MASK                                     0x07000000
#define AAMODE_REPLAY_SAMPLES_ONE                                      0x00000000
#define AAMODE_REPLAY_SAMPLES_TWO                                      0x01000000
#define AAMODE_REPLAY_SAMPLES_FOUR                                     0x02000000
#define AAMODE_REPLAY_SAMPLES_EIGHT                                    0x03000000
#define AAMODE_REPLAY_SAMPLES_MAX                                      0x03000000
#define AAMODE_REPLAY_MODE_MASK                                        0x00f00000
#define AAMODE_REPLAY_MODE_OFF                                         0x00000000
#define AAMODE_REPLAY_MODE_ALPHA_TEST                                  0x00100000
#define AAMODE_REPLAY_MODE_PIXEL_KILL                                  0x00200000
#define AAMODE_REPLAY_MODE_DYN_BRANCH                                  0x00400000
#define AAMODE_REPLAY_MODE_OPTIMAL                                     0x00400000
#define AAMODE_REPLAY_MODE_ALL                                         0x00800000
#define AAMODE_REPLAY_MODE_MAX                                         0x00f00000
#define AAMODE_REPLAY_TRANSPARENCY                                     0x02300000
#define AAMODE_REPLAY_TRANSPARENCY_DEFAULT                             0x00000000
#define AAMODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA                       0x00000000
#define AAMODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI                       0x00000000
#define AAMODE_FORCE_FOS_MASK                                          0x00080000
#define AAMODE_FORCE_FOS_DISABLED                                      0x00080000
#define AAMODE_FORCE_FOS_PASSIVE                                       0x00000000
#define AAMODE_IGNORE_FOS_MEM_LIMITS_MASK                              0x08000000
#define AAMODE_IGNORE_FOS_MEM_LIMITS_ENABLE                            0x08000000
#define AAMODE_IGNORE_FOS_MEM_LIMITS_PASSIVE                           0x00000000
#define AAMODE_ALPHATOCOVERAGE_MODE_MASK                               0x00040000
#define AAMODE_ALPHATOCOVERAGE_MODE_OFF                                0x00000000
#define AAMODE_ALPHATOCOVERAGE_MODE_ON                                 0x00040000
#define AAMODE_ALPHATOCOVERAGE_MODE_MAX                                0x00040000
#define AAMODE_GAMMACORRECTION_MASK                                    0x00030000
#define AAMODE_GAMMACORRECTION_OFF                                     0x00000000
#define AAMODE_GAMMACORRECTION_ON_IF_FOS                               0x00010000
#define AAMODE_GAMMACORRECTION_ON_ALWAYS                               0x00020000
#define AAMODE_GAMMACORRECTION_MAX                                     0x00020000
#define AAMODE_GAMMACORRECTION_DEFAULT                                 0x00000000
#define AAMODE_GAMMACORRECTION_DEFAULT_TESLA                           0x00020000
#define AAMODE_GAMMACORRECTION_DEFAULT_FERMI                           0x00020000
#define AAMODE_DEFAULT                                                 0x00000000
#define AAMODE_DEFAULT_FERMI                                           0x00020000
#define AAMODE_DEFAULT_TESLA                                           0x00020000


#define AA_BEHAVIOR_FLAGS_STRING                                       "05143845"
#define AA_BEHAVIOR_FLAGS_ID                                           0x10ecdb82
#define AA_BEHAVIOR_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define AA_BEHAVIOR_FLAGS_NONE                                         0x00000000
#define AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_APP_CONTROLLED             0x00000001
#define AA_BEHAVIOR_FLAGS_TREAT_OVERRIDE_AS_ENHANCE                    0x00000002
#define AA_BEHAVIOR_FLAGS_DISABLE_OVERRIDE                             0x00000003
#define AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_APP_CONTROLLED              0x00000004
#define AA_BEHAVIOR_FLAGS_TREAT_ENHANCE_AS_OVERRIDE                    0x00000008
#define AA_BEHAVIOR_FLAGS_DISABLE_ENHANCE                              0x0000000c
#define AA_BEHAVIOR_FLAGS_MAP_VCAA_TO_MULTISAMPLING                    0x00010000
#define AA_BEHAVIOR_FLAGS_SLI_DISABLE_TRANSPARENCY_SUPERSAMPLING       0x00020000
#define AA_BEHAVIOR_FLAGS_DISABLE_CPLAA                                0x00040000
#define AA_BEHAVIOR_FLAGS_SKIP_RT_DIM_CHECK_FOR_ENHANCE                0x00080000
#define AA_BEHAVIOR_FLAGS_DISABLE_SLIAA                                0x00100000
#define AA_BEHAVIOR_FLAGS_DEFAULT                                      0x00000000
#define AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4                              0xf0000000
#define AA_BEHAVIOR_FLAGS_AA_RT_BPP_DIV_4_SHIFT                        28
#define AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4                          0x0f000000
#define AA_BEHAVIOR_FLAGS_NON_AA_RT_BPP_DIV_4_SHIFT                    24
#define AA_BEHAVIOR_FLAGS_MASK                                         0xff1f000f


#define AA_MODE_ALPHATOCOVERAGE_STRING                                 "70835937D"
#define AA_MODE_ALPHATOCOVERAGE_ID                                     0x10fc2d9c
#define AA_MODE_ALPHATOCOVERAGE_OVERINSTALL                            0 // OVERRIDE
#define AA_MODE_ALPHATOCOVERAGE_MODE_MASK                              0x00000004
#define AA_MODE_ALPHATOCOVERAGE_MODE_OFF                               0x00000000
#define AA_MODE_ALPHATOCOVERAGE_MODE_ON                                0x00000004
#define AA_MODE_ALPHATOCOVERAGE_MODE_MAX                               0x00000004
#define AA_MODE_ALPHATOCOVERAGE_DEFAULT                                0x00000000
#define AA_MODE_ALPHATOCOVERAGE_DEFAULT_FERMI                          0x00000000
#define AA_MODE_ALPHATOCOVERAGE_DEFAULT_TESLA                          0x00000000


#define AA_MODE_FOS_STRING                                             "70835937C"
#define AA_MODE_FOS_ID                                                 0x10e8bf72
#define AA_MODE_FOS_OVERINSTALL                                        0 // OVERRIDE
#define AA_MODE_FOS_FORCE_FOS_MASK                                     0x00000008
#define AA_MODE_FOS_FORCE_FOS_DISABLED                                 0x00000008
#define AA_MODE_FOS_FORCE_FOS_PASSIVE                                  0x00000000
#define AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_MASK                         0x00000080
#define AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_ENABLE                       0x00000080
#define AA_MODE_FOS_IGNORE_FOS_MEM_LIMITS_PASSIVE                      0x00000000
#define AA_MODE_FOS_DEFAULT                                            0x00000000
#define AA_MODE_FOS_DEFAULT_FERMI                                      0x00000000
#define AA_MODE_FOS_DEFAULT_TESLA                                      0x00000000


#define AA_MODE_GAMMACORRECTION_STRING                                 "70835937E"
#define AA_MODE_GAMMACORRECTION_ID                                     0x107d639d
#define AA_MODE_GAMMACORRECTION_OVERINSTALL                            1 // MERGE
#define AA_MODE_GAMMACORRECTION_MASK                                   0x00000003
#define AA_MODE_GAMMACORRECTION_OFF                                    0x00000000
#define AA_MODE_GAMMACORRECTION_ON_IF_FOS                              0x00000001
#define AA_MODE_GAMMACORRECTION_ON_ALWAYS                              0x00000002
#define AA_MODE_GAMMACORRECTION_MAX                                    0x00000002
#define AA_MODE_GAMMACORRECTION_DEFAULT                                0x00000000
#define AA_MODE_GAMMACORRECTION_DEFAULT_TESLA                          0x00000002
#define AA_MODE_GAMMACORRECTION_DEFAULT_FERMI                          0x00000002
#define AA_MODE_GAMMACORRECTION_DEFAULT                                0x00000000
#define AA_MODE_GAMMACORRECTION_DEFAULT_FERMI                          0x00000002
#define AA_MODE_GAMMACORRECTION_DEFAULT_TESLA                          0x00000002


#define AA_MODE_METHOD_STRING                                          "70835937F"
#define AA_MODE_METHOD_ID                                              0x10d773d2
#define AA_MODE_METHOD_OVERINSTALL                                     1 // MERGE
#define AA_MODE_METHOD_NONE                                            0x0
#define AA_MODE_METHOD_SUPERSAMPLE_2X_H                                0x1
#define AA_MODE_METHOD_SUPERSAMPLE_2X_V                                0x2
#define AA_MODE_METHOD_SUPERSAMPLE_1_5X1_5                             0x2
#define AA_MODE_METHOD_FREE_0x03                                       0x3
#define AA_MODE_METHOD_FREE_0x04                                       0x4
#define AA_MODE_METHOD_SUPERSAMPLE_4X                                  0x5
#define AA_MODE_METHOD_SUPERSAMPLE_4X_BIAS                             0x6
#define AA_MODE_METHOD_SUPERSAMPLE_4X_GAUSSIAN                         0x7
#define AA_MODE_METHOD_FREE_0x08                                       0x8
#define AA_MODE_METHOD_FREE_0x09                                       0x9
#define AA_MODE_METHOD_SUPERSAMPLE_9X                                  0xA
#define AA_MODE_METHOD_SUPERSAMPLE_9X_BIAS                             0xB
#define AA_MODE_METHOD_SUPERSAMPLE_16X                                 0xC
#define AA_MODE_METHOD_SUPERSAMPLE_16X_BIAS                            0xD
#define AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL                         0xE
#define AA_MODE_METHOD_MULTISAMPLE_2X_QUINCUNX                         0xF
#define AA_MODE_METHOD_MULTISAMPLE_4X                                  0x10
#define AA_MODE_METHOD_FREE_0x11                                       0x11
#define AA_MODE_METHOD_MULTISAMPLE_4X_GAUSSIAN                         0x12
#define AA_MODE_METHOD_MIXEDSAMPLE_4X_SKEWED_4TAP                      0x13
#define AA_MODE_METHOD_FREE_0x14                                       0x14
#define AA_MODE_METHOD_FREE_0x15                                       0x15
#define AA_MODE_METHOD_MIXEDSAMPLE_6X                                  0x16
#define AA_MODE_METHOD_MIXEDSAMPLE_6X_SKEWED_6TAP                      0x17
#define AA_MODE_METHOD_MIXEDSAMPLE_8X                                  0x18
#define AA_MODE_METHOD_MIXEDSAMPLE_8X_SKEWED_8TAP                      0x19
#define AA_MODE_METHOD_MIXEDSAMPLE_16X                                 0x1a
#define AA_MODE_METHOD_MULTISAMPLE_4X_GAMMA                            0x1b
#define AA_MODE_METHOD_MULTISAMPLE_16X                                 0x1c
#define AA_MODE_METHOD_VCAA_32X_8v24                                   0x1d
#define AA_MODE_METHOD_CORRUPTION_CHECK                                0x1e
#define AA_MODE_METHOD_6X_CT                                           0x1f
#define AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_GAMMA                   0x20
#define AA_MODE_METHOD_SUPERSAMPLE_4X_GAMMA                            0x21
#define AA_MODE_METHOD_MULTISAMPLE_4X_FOSGAMMA                         0x22
#define AA_MODE_METHOD_MULTISAMPLE_2X_DIAGONAL_FOSGAMMA                0x23
#define AA_MODE_METHOD_SUPERSAMPLE_4X_FOSGAMMA                         0x24
#define AA_MODE_METHOD_MULTISAMPLE_8X                                  0x25
#define AA_MODE_METHOD_VCAA_8X_4v4                                     0x26
#define AA_MODE_METHOD_VCAA_16X_4v12                                   0x27
#define AA_MODE_METHOD_VCAA_16X_8v8                                    0x28
#define AA_MODE_METHOD_MIXEDSAMPLE_32X                                 0x29
#define AA_MODE_METHOD_SUPERVCAA_64X_4v12                              0x2a
#define AA_MODE_METHOD_SUPERVCAA_64X_8v8                               0x2b
#define AA_MODE_METHOD_MIXEDSAMPLE_64X                                 0x2c
#define AA_MODE_METHOD_MIXEDSAMPLE_128X                                0x2d
#define AA_MODE_METHOD_COUNT                                           0x2e
#define AA_MODE_METHOD_METHOD_MASK                                     0x0000ffff
#define AA_MODE_METHOD_METHOD_MAX                                      0xf1c57815
#define AA_MODE_METHOD_DEFAULT                                         AA_MODE_METHOD_NONE
#define AA_MODE_METHOD_DEFAULT_FERMI                                   AA_MODE_METHOD_NONE
#define AA_MODE_METHOD_DEFAULT_TESLA                                   AA_MODE_METHOD_NONE


#define AA_MODE_REPLAY_STRING                                          "70835937B"
#define AA_MODE_REPLAY_ID                                              0x10d48a85
#define AA_MODE_REPLAY_OVERINSTALL                                     1 // MERGE
#define AA_MODE_REPLAY_SAMPLES_MASK                                    0x00000070
#define AA_MODE_REPLAY_SAMPLES_ONE                                     0x00000000
#define AA_MODE_REPLAY_SAMPLES_TWO                                     0x00000010
#define AA_MODE_REPLAY_SAMPLES_FOUR                                    0x00000020
#define AA_MODE_REPLAY_SAMPLES_EIGHT                                   0x00000030
#define AA_MODE_REPLAY_SAMPLES_MAX                                     0x00000030
#define AA_MODE_REPLAY_MODE_MASK                                       0x0000000f
#define AA_MODE_REPLAY_MODE_OFF                                        0x00000000
#define AA_MODE_REPLAY_MODE_ALPHA_TEST                                 0x00000001
#define AA_MODE_REPLAY_MODE_PIXEL_KILL                                 0x00000002
#define AA_MODE_REPLAY_MODE_DYN_BRANCH                                 0x00000004
#define AA_MODE_REPLAY_MODE_OPTIMAL                                    0x00000004
#define AA_MODE_REPLAY_MODE_ALL                                        0x00000008
#define AA_MODE_REPLAY_MODE_MAX                                        0x0000000f
#define AA_MODE_REPLAY_TRANSPARENCY                                    0x00000023
#define AA_MODE_REPLAY_DISALLOW_TRAA                                   0x00000100
#define AA_MODE_REPLAY_TRANSPARENCY_DEFAULT                            0x00000000
#define AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_TESLA                      0x00000000
#define AA_MODE_REPLAY_TRANSPARENCY_DEFAULT_FERMI                      0x00000000
#define AA_MODE_REPLAY_MASK                                            0x0000017f
#define AA_MODE_REPLAY_DEFAULT                                         0x00000000
#define AA_MODE_REPLAY_DEFAULT_FERMI                                   0x00000000
#define AA_MODE_REPLAY_DEFAULT_TESLA                                   0x00000000


#define AA_MODE_SELECTOR_STRING                                        "70835937A"
#define AA_MODE_SELECTOR_ID                                            0x107efc5b
#define AA_MODE_SELECTOR_OVERINSTALL                                   1 // MERGE
#define AA_MODE_SELECTOR_MASK                                          0x00000003
#define AA_MODE_SELECTOR_APP_CONTROL                                   0x00000000
#define AA_MODE_SELECTOR_OVERRIDE                                      0x00000001
#define AA_MODE_SELECTOR_ENHANCE                                       0x00000002
#define AA_MODE_SELECTOR_MAX                                           0x00000002
#define AA_MODE_SELECTOR_DEFAULT                                       AA_MODE_SELECTOR_APP_CONTROL
#define AA_MODE_SELECTOR_DEFAULT_FERMI                                 AA_MODE_SELECTOR_APP_CONTROL
#define AA_MODE_SELECTOR_DEFAULT_TESLA                                 AA_MODE_SELECTOR_APP_CONTROL


#define AA_MODE_SELECTOR_SLIAA_STRING                                  "70835937SA"
#define AA_MODE_SELECTOR_SLIAA_ID                                      0x107afc5b
#define AA_MODE_SELECTOR_SLIAA_OVERINSTALL                             1 // MERGE
#define AA_MODE_SELECTOR_SLIAA_DISABLED                                0
#define AA_MODE_SELECTOR_SLIAA_OFF                                     0
#define AA_MODE_SELECTOR_SLIAA_ENABLED                                 1
#define AA_MODE_SELECTOR_SLIAA_ON                                      1
#define AA_MODE_SELECTOR_SLIAA_DEFAULT                                 AA_MODE_SELECTOR_SLIAA_DISABLED


#define AFRSLIAA_STRING                                                "12677979"
#define AFRSLIAA_ID                                                    0x10f115bc
#define AFRSLIAA_OVERINSTALL                                           0 // OVERRIDE
#define AFRSLIAA_OFF                                                   0x51621661
#define AFRSLIAA_DISABLED                                              0x51621661
#define AFRSLIAA_ON                                                    0x29060798
#define AFRSLIAA_ENABLED                                               0x29060798
#define AFRSLIAA_DEFAULT                                               AFRSLIAA_OFF


#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_STRING                       "0xd6c4e8"
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ID                           0x10d6c4e8
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_OVERINSTALL                  0 // OVERRIDE
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_OFF                          0x00000000
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_DISABLED                     0x00000000
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ON                           0x00000001
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ENABLED                      0x00000001
#define ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_DEFAULT                      ALLOW_TC_PS_BARRIER_BEFORE_EARLYZ_ON


#define ANISOMODE_STRING                                               "74095213"
#define ANISOMODE_ID                                                   0x10f74257
#define ANISOMODE_OVERINSTALL                                          0 // OVERRIDE
#define ANISOMODE_SELECTOR_MASK                                        0xf0000000
#define ANISOMODE_SELECTOR_APP                                         0x00000000
#define ANISOMODE_SELECTOR_USER                                        0x10000000
#define ANISOMODE_SELECTOR_COND                                        0x20000000
#define ANISOMODE_SELECTOR_MAX                                         0x20000000
#define ANISOMODE_LEVEL_MASK                                           0x0000ffff
#define ANISOMODE_LEVEL_NONE_POINT                                     0x00000000
#define ANISOMODE_LEVEL_NONE_LINEAR                                    0x00000001
#define ANISOMODE_LEVEL_MAX                                            0x00000010
#define ANISOMODE_DEFAULT                                              0x00000001


#define ANISO_MODE_LEVEL_STRING                                        "74095213B"
#define ANISO_MODE_LEVEL_ID                                            0x101e61a9
#define ANISO_MODE_LEVEL_OVERINSTALL                                   1 // MERGE
#define ANISO_MODE_LEVEL_MASK                                          0x0000ffff
#define ANISO_MODE_LEVEL_NONE_POINT                                    0x00000000
#define ANISO_MODE_LEVEL_NONE_LINEAR                                   0x00000001
#define ANISO_MODE_LEVEL_MAX                                           0x00000010
#define ANISO_MODE_LEVEL_DEFAULT                                       0x00000001


#define ANISO_MODE_SELECTOR_STRING                                     "74095213A"
#define ANISO_MODE_SELECTOR_ID                                         0x10d2bb16
#define ANISO_MODE_SELECTOR_OVERINSTALL                                1 // MERGE
#define ANISO_MODE_SELECTOR_MASK                                       0x0000000f
#define ANISO_MODE_SELECTOR_APP                                        0x00000000
#define ANISO_MODE_SELECTOR_USER                                       0x00000001
#define ANISO_MODE_SELECTOR_COND                                       0x00000002
#define ANISO_MODE_SELECTOR_MAX                                        0x00000002
#define ANISO_MODE_SELECTOR_DEFAULT                                    0x00000000


#define ANSEL_ALLOW_STRING                                             "10682898"
#define ANSEL_ALLOW_ID                                                 0x1035db89
#define ANSEL_ALLOW_OVERINSTALL                                        0 // OVERRIDE
#define ANSEL_ALLOW_DISALLOWED                                         0
#define ANSEL_ALLOW_OFF                                                0
#define ANSEL_ALLOW_DISABLED                                           0
#define ANSEL_ALLOW_ALLOWED                                            1
#define ANSEL_ALLOW_ON                                                 1
#define ANSEL_ALLOW_ENABLED                                            1
#define ANSEL_ALLOW_DEFAULT                                            ANSEL_ALLOW_ALLOWED


#define ANSEL_ALLOWLISTED_STRING                                       "14792591"
#define ANSEL_ALLOWLISTED_ID                                           0x1085da8a
#define ANSEL_ALLOWLISTED_OVERINSTALL                                  0 // OVERRIDE
#define ANSEL_ALLOWLISTED_DISALLOWED                                   0
#define ANSEL_ALLOWLISTED_OFF                                          0
#define ANSEL_ALLOWLISTED_DISABLED                                     0
#define ANSEL_ALLOWLISTED_ALLOWED                                      1
#define ANSEL_ALLOWLISTED_ON                                           1
#define ANSEL_ALLOWLISTED_ENABLED                                      1
#define ANSEL_ALLOWLISTED_DEFAULT                                      ANSEL_ALLOWLISTED_DISALLOWED


#define ANSEL_ALLOW_FREESTYLE_MODE_STRING                              "33999624"
#define ANSEL_ALLOW_FREESTYLE_MODE_ID                                  0x101baaaf
#define ANSEL_ALLOW_FREESTYLE_MODE_OVERINSTALL                         0 // OVERRIDE
#define ANSEL_ALLOW_FREESTYLE_MODE_DISABLED                            0x0000
#define ANSEL_ALLOW_FREESTYLE_MODE_ENABLED                             0x0001
#define ANSEL_ALLOW_FREESTYLE_MODE_DEFAULT                             ANSEL_ALLOW_FREESTYLE_MODE_DISABLED


#define ANSEL_ALLOW_OFFLINE_STRING                                     "93980749"
#define ANSEL_ALLOW_OFFLINE_ID                                         0x10d5c2db
#define ANSEL_ALLOW_OFFLINE_OVERINSTALL                                0 // OVERRIDE
#define ANSEL_ALLOW_OFFLINE_DISALLOWED                                 0
#define ANSEL_ALLOW_OFFLINE_OFF                                        0
#define ANSEL_ALLOW_OFFLINE_DISABLED                                   0
#define ANSEL_ALLOW_OFFLINE_ALLOWED                                    1
#define ANSEL_ALLOW_OFFLINE_ON                                         1
#define ANSEL_ALLOW_OFFLINE_ENABLED                                    1
#define ANSEL_ALLOW_OFFLINE_DEFAULT                                    ANSEL_ALLOW_OFFLINE_DISALLOWED


#define ANSEL_BUFFERS_DEPTH_SETTINGS_STRING                            "16068746"
#define ANSEL_BUFFERS_DEPTH_SETTINGS_ID                                0x101314ce
#define ANSEL_BUFFERS_DEPTH_SETTINGS_OVERINSTALL                       0 // OVERRIDE
#define ANSEL_BUFFERS_DEPTH_SETTINGS_NONE                              0x00000000
#define ANSEL_BUFFERS_DEPTH_SETTINGS_USE_STATS                         0x00000001
#define ANSEL_BUFFERS_DEPTH_SETTINGS_USE_VIEWPORT                      0x00000002
#define ANSEL_BUFFERS_DEPTH_SETTINGS_VIEWPORT_SCALING                  0x00000004
#define ANSEL_BUFFERS_DEPTH_SETTINGS_OVERRIDE_EN                       0x00000008
#define ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Y                          0x00000010
#define ANSEL_BUFFERS_DEPTH_SETTINGS_INVERT_Z                          0x00000020
#define ANSEL_BUFFERS_DEPTH_SETTINGS_ALL                               0xFFFFFFFF
#define ANSEL_BUFFERS_DEPTH_SETTINGS_DEFAULT                           ANSEL_BUFFERS_DEPTH_SETTINGS_NONE


#define ANSEL_BUFFERS_DEPTH_WEIGHTS_STRING                             "16068747"
#define ANSEL_BUFFERS_DEPTH_WEIGHTS_ID                                 0x10079dbc
#define ANSEL_BUFFERS_DEPTH_WEIGHTS_OVERINSTALL                        0 // OVERRIDE
#define ANSEL_BUFFERS_DEPTH_WEIGHTS_DEFAULT                            L""


#define ANSEL_BUFFERS_DISABLED_STRING                                  "16068745"
#define ANSEL_BUFFERS_DISABLED_ID                                      0x10e74421
#define ANSEL_BUFFERS_DISABLED_OVERINSTALL                             0 // OVERRIDE
#define ANSEL_BUFFERS_DISABLED_NONE                                    0x00000000
#define ANSEL_BUFFERS_DISABLED_DEPTH                                   0x00000001
#define ANSEL_BUFFERS_DISABLED_HDR                                     0x00000002
#define ANSEL_BUFFERS_DISABLED_HUDLESS                                 0x00000004
#define ANSEL_BUFFERS_DISABLED_FINAL_COLOR                             0x00000008
#define ANSEL_BUFFERS_DISABLED_ALL                                     0xFFFFFFFF
#define ANSEL_BUFFERS_DISABLED_DEFAULT                                 ANSEL_BUFFERS_DISABLED_NONE


#define ANSEL_BUFFERS_HUDLESS_DRAWCALL_STRING                          "16068750"
#define ANSEL_BUFFERS_HUDLESS_DRAWCALL_ID                              0x101fd0c1
#define ANSEL_BUFFERS_HUDLESS_DRAWCALL_OVERINSTALL                     0 // OVERRIDE
#define ANSEL_BUFFERS_HUDLESS_DRAWCALL_DEFAULT                         2


#define ANSEL_BUFFERS_HUDLESS_SETTINGS_STRING                          "16068748"
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_ID                              0x10ad7f3b
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_OVERINSTALL                     0 // OVERRIDE
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_NONE                            0x00000000
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_USE_STATS                       0x00000001
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_ONLY_SINGLE_RTV_BINDS           0x00000002
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_RESTRICT_FORMATS                0x00000004
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_ALL                             0xFFFFFFFF
#define ANSEL_BUFFERS_HUDLESS_SETTINGS_DEFAULT                         ANSEL_BUFFERS_HUDLESS_SETTINGS_NONE


#define ANSEL_BUFFERS_HUDLESS_WEIGHTS_STRING                           "16068749"
#define ANSEL_BUFFERS_HUDLESS_WEIGHTS_ID                               0x10c41bb5
#define ANSEL_BUFFERS_HUDLESS_WEIGHTS_OVERINSTALL                      0 // OVERRIDE
#define ANSEL_BUFFERS_HUDLESS_WEIGHTS_DEFAULT                          L""


#define ANSEL_DENYLIST_ALL_PROFILED_STRING                             "43102335"
#define ANSEL_DENYLIST_ALL_PROFILED_ID                                 0x10f272b9
#define ANSEL_DENYLIST_ALL_PROFILED_OVERINSTALL                        0 // OVERRIDE
#define ANSEL_DENYLIST_ALL_PROFILED_DEFAULT                            L""


#define ANSEL_DENYLIST_PER_GAME_STRING                                 "23776708"
#define ANSEL_DENYLIST_PER_GAME_ID                                     0x100d51f7
#define ANSEL_DENYLIST_PER_GAME_OVERINSTALL                            0 // OVERRIDE
#define ANSEL_DENYLIST_PER_GAME_DEFAULT                                L""


#define ANSEL_ENABLE_STRING                                            "97373802"
#define ANSEL_ENABLE_ID                                                0x1075d972
#define ANSEL_ENABLE_OVERINSTALL                                       1 // MERGE
#define ANSEL_ENABLE_OFF                                               0
#define ANSEL_ENABLE_DISABLED                                          0
#define ANSEL_ENABLE_ON                                                1
#define ANSEL_ENABLE_ENABLED                                           1
#define ANSEL_ENABLE_DEFAULT                                           ANSEL_ENABLE_ON


#define ANSEL_ENABLE_OPTIMUS_STRING                                    "97373801"
#define ANSEL_ENABLE_OPTIMUS_ID                                        0x1075d973
#define ANSEL_ENABLE_OPTIMUS_OVERINSTALL                               1 // MERGE
#define ANSEL_ENABLE_OPTIMUS_OFF                                       0
#define ANSEL_ENABLE_OPTIMUS_DISABLED                                  0
#define ANSEL_ENABLE_OPTIMUS_ON                                        1
#define ANSEL_ENABLE_OPTIMUS_ENABLED                                   1
#define ANSEL_ENABLE_OPTIMUS_DEFAULT                                   ANSEL_ENABLE_OPTIMUS_OFF


#define ANSEL_FREESTYLE_MODE_STRING                                    "27152819"
#define ANSEL_FREESTYLE_MODE_ID                                        0x105e2a1d
#define ANSEL_FREESTYLE_MODE_OVERINSTALL                               0 // OVERRIDE
#define ANSEL_FREESTYLE_MODE_DISABLED                                  0x0000
#define ANSEL_FREESTYLE_MODE_ENABLED                                   0x0001
#define ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLED                      0x0002
#define ANSEL_FREESTYLE_MODE_APPROVED_ONLY                             0x0004
#define ANSEL_FREESTYLE_MODE_MULTIPLAYER_APPROVED_ONLY                 0x0008
#define ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_EXTRA_BUFFERS         0x0010
#define ANSEL_FREESTYLE_MODE_MULTIPLAYER_DISABLE_DEPTH                 0x0020
#define ANSEL_FREESTYLE_MODE_DEFAULT                                   ANSEL_FREESTYLE_MODE_DISABLED


#define APIINDICATOR_STRING                                            "111baea9"
#define APIINDICATOR_ID                                                0x107b1e3d
#define APIINDICATOR_OVERINSTALL                                       0 // OVERRIDE
#define APIINDICATOR_OFF                                               0x0
#define APIINDICATOR_DISABLED                                          0x0
#define APIINDICATOR_ON                                                0x1
#define APIINDICATOR_ENABLED                                           0x1
#define APIINDICATOR_DEFAULT                                           APIINDICATOR_OFF


#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_STRING                "4554b6"
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ID                    0x104554b6
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_OVERINSTALL           1 // MERGE
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED              0
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_OFF                   0
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ZERO                  0
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_NINE_SECONDS          9
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_FIFTEEN_SECONDS       15
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_THIRTY_SECONDS        30
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_ONE_MINUTE            60
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_TWO_MINUTES           120
#define APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DEFAULT               APPLICATION_PROFILE_NOTIFICATION_TIMEOUT_DISABLED


#define APPLICATION_STEAM_ID_STRING                                    "7cddbc"
#define APPLICATION_STEAM_ID_ID                                        0x107cddbc
#define APPLICATION_STEAM_ID_OVERINSTALL                               0 // OVERRIDE
#define APPLICATION_STEAM_ID_DEFAULT                                   0


#define AUTOFL_STRING                                                  "C0009600"
#define AUTOFL_ID                                                      0x10834ffe
#define AUTOFL_OVERINSTALL                                             1 // MERGE
#define AUTOFL_OFF                                                     0
#define AUTOFL_DISABLED                                                0
#define AUTOFL_ON                                                      1
#define AUTOFL_ENABLED                                                 1
#define AUTOFL_DEFAULT                                                 AUTOFL_ON


#define BATTERY_BOOST_STRING                                           "f1846870"
#define BATTERY_BOOST_ID                                               0x10115c89
#define BATTERY_BOOST_OVERINSTALL                                      0 // OVERRIDE
#define BATTERY_BOOST_MIN                                              0x00000001
#define BATTERY_BOOST_MAX                                              0x000003ff
#define BATTERY_BOOST_ENABLED                                          0x10000000
#define BATTERY_BOOST_DISABLED                                         0x00000000
#define BATTERY_BOOST_XQM                                              0x1000001e
#define BATTERY_BOOST_DEFAULT                                          BATTERY_BOOST_DISABLED


#define BATTERY_BOOST_APP_FPS_STRING                                   "f1846873"
#define BATTERY_BOOST_APP_FPS_ID                                       0x10115c8c
#define BATTERY_BOOST_APP_FPS_OVERINSTALL                              0 // OVERRIDE
#define BATTERY_BOOST_APP_FPS_MIN                                      0x00000001
#define BATTERY_BOOST_APP_FPS_MAX                                      0x000003ff
#define BATTERY_BOOST_APP_FPS_NO_OVERRIDE                              0x00000000
#define BATTERY_BOOST_APP_FPS_DEFAULT                                  BATTERY_BOOST_APP_FPS_NO_OVERRIDE


#define BG_FRL_FPS_STRING                                              "00008608"
#define BG_FRL_FPS_ID                                                  0x10835005
#define BG_FRL_FPS_OVERINSTALL                                         1 // MERGE
#define BG_FRL_FPS_DISABLED                                            0x00000000
#define BG_FRL_FPS_MIN                                                 0x00000000
#define BG_FRL_FPS_MAX                                                 0x000003ff
#define BG_FRL_FPS_DEFAULT                                             BG_FRL_FPS_DISABLED


#define BG_FRL_FPS_NVCPL_STRING                                        "00008609"
#define BG_FRL_FPS_NVCPL_ID                                            0x10835006
#define BG_FRL_FPS_NVCPL_OVERINSTALL                                   1 // MERGE
#define BG_FRL_FPS_NVCPL_DISABLED                                      0x00000000
#define BG_FRL_FPS_NVCPL_MIN                                           0x00000000
#define BG_FRL_FPS_NVCPL_MAX                                           0x000003ff
#define BG_FRL_FPS_NVCPL_DEFAULT                                       BG_FRL_FPS_NVCPL_DISABLED


#define CBF_THRESHOLD_STRING                                           "48576894"
#define CBF_THRESHOLD_ID                                               0x10291d8e
#define CBF_THRESHOLD_OVERINSTALL                                      0 // OVERRIDE
#define CBF_THRESHOLD_MIN                                              0x00000000
#define CBF_THRESHOLD_MAX                                              0xffffffff
#define CBF_THRESHOLD_DEFAULT                                          12


#define CB_ALPHA_CACHELINES_PER_SM_STRING                              "FF54EC98"
#define CB_ALPHA_CACHELINES_PER_SM_ID                                  0x1080b678
#define CB_ALPHA_CACHELINES_PER_SM_OVERINSTALL                         0 // OVERRIDE
#define CB_ALPHA_CACHELINES_PER_SM_MIN                                 0x00000000
#define CB_ALPHA_CACHELINES_PER_SM_AUTOMATIC                           0x00000000
#define CB_ALPHA_CACHELINES_PER_SM_FERMI_MAX                           0x000003ff
#define CB_ALPHA_CACHELINES_PER_SM_MAXWELL_MAX                         0x000003fff
#define CB_ALPHA_CACHELINES_PER_SM_PASCAL_MAX                          0x000003fffff
#define CB_ALPHA_CACHELINES_PER_SM_MAX                                 0x000003fffff
#define CB_ALPHA_CACHELINES_PER_SM_DEFAULT                             0


#define CB_CACHELINES_PER_SM_STRING                                    "FF54EC97"
#define CB_CACHELINES_PER_SM_ID                                        0x1080b677
#define CB_CACHELINES_PER_SM_OVERINSTALL                               0 // OVERRIDE
#define CB_CACHELINES_PER_SM_MIN                                       0x00000000
#define CB_CACHELINES_PER_SM_AUTOMATIC                                 0x00000000
#define CB_CACHELINES_PER_SM_FERMI_MAX                                 0x000003ff
#define CB_CACHELINES_PER_SM_MAXWELL_MAX                               0x000003fff
#define CB_CACHELINES_PER_SM_PASCAL_MAX                                0x000003fffff
#define CB_CACHELINES_PER_SM_MAX                                       0x000003fffff
#define CB_CACHELINES_PER_SM_DEFAULT                                   0


#define COLLECTGFEINFO_STRING                                          "50273967"
#define COLLECTGFEINFO_ID                                              0x1088513a
#define COLLECTGFEINFO_OVERINSTALL                                     0 // OVERRIDE
#define COLLECTGFEINFO_DISABLE                                         0x00000000
#define COLLECTGFEINFO_GFE_MS_PER_FRAME_HIST                           0x00000001
#define COLLECTGFEINFO_GFE_MS_PER_FRAME_DERIV_HIST                     0x00000002
#define COLLECTGFEINFO_GFE_PSTATE_HIST                                 0x00000004
#define COLLECTGFEINFO_GFE_PCT_BATTERY                                 0x00000008
#define COLLECTGFEINFO_GFE_STEREO_INFO                                 0x00000010
#define COLLECTGFEINFO_DEFAULT                                         COLLECTGFEINFO_DISABLE


#define COMPILER_KNOBS_STRING                                          "0xe6a55a"
#define COMPILER_KNOBS_ID                                              0x10e6855a
#define COMPILER_KNOBS_OVERINSTALL                                     0 // OVERRIDE
#define COMPILER_KNOBS_DEFAULT                                         ""


#define COMPILER_STATS_FILE_STRING                                     "0xe0389b"
#define COMPILER_STATS_FILE_ID                                         0x10e0089b
#define COMPILER_STATS_FILE_OVERINSTALL                                0 // OVERRIDE
#define COMPILER_STATS_FILE_DEFAULT                                    ""


#define COMPILER_STATS_LEVEL_STRING                                    "0xe0388b"
#define COMPILER_STATS_LEVEL_ID                                        0x10e0088b
#define COMPILER_STATS_LEVEL_OVERINSTALL                               0 // OVERRIDE
#define COMPILER_STATS_LEVEL_LEVEL0                                    0x0
#define COMPILER_STATS_LEVEL_DISABLED                                  0x0
#define COMPILER_STATS_LEVEL_LEVEL1                                    0x1
#define COMPILER_STATS_LEVEL_LEVEL2                                    0X2
#define COMPILER_STATS_LEVEL_LEVEL3                                    0X3
#define COMPILER_STATS_LEVEL_LEVEL4                                    0X4
#define COMPILER_STATS_LEVEL_DEFAULT                                   COMPILER_STATS_LEVEL_LEVEL0


#define CONSTANT_COLOR_RENDERING_ENABLE_STRING                         "c0457a47"
#define CONSTANT_COLOR_RENDERING_ENABLE_ID                             0x10f20b10
#define CONSTANT_COLOR_RENDERING_ENABLE_OVERINSTALL                    0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_ENABLE_ON                             0x00000001
#define CONSTANT_COLOR_RENDERING_ENABLE_ENABLED                        0x00000001
#define CONSTANT_COLOR_RENDERING_ENABLE_OFF                            0x00000000
#define CONSTANT_COLOR_RENDERING_ENABLE_DISABLED                       0x00000000
#define CONSTANT_COLOR_RENDERING_ENABLE_DEFAULT                        CONSTANT_COLOR_RENDERING_ENABLE_ON


#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA_STRING           "c0457a9c"
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA_ID               0x10937ecb
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA_OVERINSTALL      0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ALPHA_DEFAULT          1.0f


#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE_STRING            "c0457a8b"
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE_ID                0x1019a5fe
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE_OVERINSTALL       0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_BLUE_DEFAULT           1.0f


#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_STRING          "c0457a58"
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_ID              0x10c04a01
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_OVERINSTALL     0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_ON              0x00000001
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_ENABLED         0x00000001
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_OFF             0x00000000
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_DISABLED        0x00000000
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_DEFAULT         CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_ENABLE_OFF


#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN_STRING           "c0457a7a"
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN_ID               0x10d825e1
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN_OVERINSTALL      0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_GREEN_DEFAULT          0.0f


#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED_STRING             "c0457a69"
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED_ID                 0x1012afd6
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED_OVERINSTALL        0 // OVERRIDE
#define CONSTANT_COLOR_RENDERING_OVERRIDE_COLOR_RED_DEFAULT            1.0f


#define CONSUMER_STEREO_ENABLE_STRING                                  "EnableConsumerStereoSupport"
#define CONSUMER_STEREO_ENABLE_ID                                      0x10c8e380
#define CONSUMER_STEREO_ENABLE_OVERINSTALL                             0 // OVERRIDE
#define CONSUMER_STEREO_ENABLE_OFF                                     0
#define CONSUMER_STEREO_ENABLE_DISABLED                                0
#define CONSUMER_STEREO_ENABLE_ON                                      1
#define CONSUMER_STEREO_ENABLE_ENABLED                                 1
#define CONSUMER_STEREO_ENABLE_DEFAULT                                 CONSUMER_STEREO_ENABLE_OFF


#define CONTROLFLOWGUARD_ENABLE_STRING                                 "73163701"
#define CONTROLFLOWGUARD_ENABLE_ID                                     0x1053e972
#define CONTROLFLOWGUARD_ENABLE_OVERINSTALL                            1 // MERGE
#define CONTROLFLOWGUARD_ENABLE_OFF                                    0
#define CONTROLFLOWGUARD_ENABLE_DISABLED                               0
#define CONTROLFLOWGUARD_ENABLE_ON                                     1
#define CONTROLFLOWGUARD_ENABLE_ENABLED                                1
#define CONTROLFLOWGUARD_ENABLE_DEFAULT                                CONTROLFLOWGUARD_ENABLE_ON


#define COPROC_STAGING_BUFFER_PLACEMENT_STRING                         "30008600"
#define COPROC_STAGING_BUFFER_PLACEMENT_ID                             0x10038600
#define COPROC_STAGING_BUFFER_PLACEMENT_OVERINSTALL                    0 // OVERRIDE
#define COPROC_STAGING_BUFFER_PLACEMENT_DEFAULT_WITH_FALLBACK          0x00000000
#define COPROC_STAGING_BUFFER_PLACEMENT_APERTURE_ONLY                  0x00000001
#define COPROC_STAGING_BUFFER_PLACEMENT_SYSMEM_ONLY                    0x00000002
#define COPROC_STAGING_BUFFER_PLACEMENT_HALLOC_ONLY                    0x00000003
#define COPROC_STAGING_BUFFER_PLACEMENT_CPUCOPY_ONLY                   0x00000004
#define COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2COPY_ONLY               0x00000005
#define COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD1_ONLY            0x00000006
#define COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD2_ONLY            0x00000007
#define COPROC_STAGING_BUFFER_PLACEMENT_CPUSSE2THREAD4_ONLY            0x00000008


#define COPROC_WINSAT_SPLIT_STRING                                     "20008600"
#define COPROC_WINSAT_SPLIT_ID                                         0x10028600
#define COPROC_WINSAT_SPLIT_OVERINSTALL                                0 // OVERRIDE
#define COPROC_WINSAT_SPLIT_DISABLE                                    0x00000000
#define COPROC_WINSAT_SPLIT_ENABLE                                     0x00000001
#define COPROC_WINSAT_SPLIT_IGPU_ONLY                                  0x00000002
#define COPROC_WINSAT_SPLIT_DGPU_ONLY                                  0x00000003
#define COPROC_WINSAT_SPLIT_DEFAULT                                    COPROC_WINSAT_SPLIT_ENABLE


#define CPL_HIDDEN_PROFILE_STRING                                      "6d5cff"
#define CPL_HIDDEN_PROFILE_ID                                          0x106d5cff
#define CPL_HIDDEN_PROFILE_OVERINSTALL                                 0 // OVERRIDE
#define CPL_HIDDEN_PROFILE_DISABLED                                    0
#define CPL_HIDDEN_PROFILE_OFF                                         0
#define CPL_HIDDEN_PROFILE_ENABLED                                     1
#define CPL_HIDDEN_PROFILE_ON                                          1
#define CPL_HIDDEN_PROFILE_DEFAULT                                     CPL_HIDDEN_PROFILE_DISABLED


#define CROP_L2_CACHE_CONTROL_STRING                                   "0x1fd4"
#define CROP_L2_CACHE_CONTROL_ID                                       0x10001fd4
#define CROP_L2_CACHE_CONTROL_OVERINSTALL                              0 // OVERRIDE
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_FIRST     0x00000000
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_NORMAL    0x00000001
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_EVICT_LAST      0x00000002
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_READ_SHIFT           0
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_FIRST        0x00000000
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_NORMAL       0x00000010
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_EVICT_LAST         0x00000020
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_READ_SHIFT              4
#define CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_FIRST           0x00000000
#define CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_NORMAL          0x00000100
#define CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_EVICT_LAST            0x00000200
#define CROP_L2_CACHE_CONTROL_CROP_PREFETCH_READ_SHIFT                 8
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_FIRST    0x00000000
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_NORMAL   0x00001000
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_EVICT_LAST     0x00002000
#define CROP_L2_CACHE_CONTROL_CROP_NONINTERLOCKED_WRITE_SHIFT          12
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_FIRST       0x00000000
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_NORMAL      0x00010000
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_EVICT_LAST        0x00020000
#define CROP_L2_CACHE_CONTROL_CROP_INTERLOCKED_WRITE_SHIFT             16
#define CROP_L2_CACHE_CONTROL_USE_LEGACY                               0x00100000
#define CROP_L2_CACHE_CONTROL_DEFAULT                                  CROP_L2_CACHE_CONTROL_USE_LEGACY


#define CUDA_EXCLUDED_GPUS_STRING                                      "19103765"
#define CUDA_EXCLUDED_GPUS_ID                                          0x10354ff8
#define CUDA_EXCLUDED_GPUS_OVERINSTALL                                 0 // OVERRIDE
#define CUDA_EXCLUDED_GPUS_NONE                                        L"none"
#define CUDA_EXCLUDED_GPUS_DEFAULT                                     CUDA_EXCLUDED_GPUS_NONE


#define CULL_BEFORE_FETCH_STRING                                       "48576893"
#define CULL_BEFORE_FETCH_ID                                           0x10510e76
#define CULL_BEFORE_FETCH_OVERINSTALL                                  0 // OVERRIDE
#define CULL_BEFORE_FETCH_DYNAMIC                                      0x00000006
#define CULL_BEFORE_FETCH_ALWAYS                                       0x00000007
#define CULL_BEFORE_FETCH_NEVER                                        0x00000008
#define CULL_BEFORE_FETCH_MIN                                          0x00000006
#define CULL_BEFORE_FETCH_MAX                                          0x00000008
#define CULL_BEFORE_FETCH_DEFAULT                                      CULL_BEFORE_FETCH_DYNAMIC


#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_STRING               "c9d12c"
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_ID                   0x10c9d12c
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_OVERINSTALL          0 // OVERRIDE
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_AUTOSELECT           0x00000000
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL                0x00000001
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_LOCAL_LOW            0x00000002
#define D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_DEFAULT              D3DOGL_DEFAULT_SHADER_DISK_CACHE_LOCATION_AUTOSELECT


#define D3DOGL_GPU_MAX_POWER_STRING                                    "GpuMaxPower"
#define D3DOGL_GPU_MAX_POWER_ID                                        0x10d1ef29
#define D3DOGL_GPU_MAX_POWER_OVERINSTALL                               0 // OVERRIDE
#define D3DOGL_GPU_MAX_POWER_DEFAULTPOWER                              L"0"


#define D3DOGL_SANDBAG_DEVICEID_STRING                                 "0x054eeb"
#define D3DOGL_SANDBAG_DEVICEID_ID                                     0x10054eeb
#define D3DOGL_SANDBAG_DEVICEID_OVERINSTALL                            0 // OVERRIDE
#define D3DOGL_SANDBAG_DEVICEID_DEVID_MASK                             0x00ffffff
#define D3DOGL_SANDBAG_DEVICEID_DEVID_ANY                              0x00ffffff
#define D3DOGL_SANDBAG_DEVICEID_IGNORE_ALLOW_LIST                      0x01000000
#define D3DOGL_SANDBAG_DEVICEID_DEFAULT                                0


#define D3DOGL_UNSANDBAG_VIEWPERF_STRING                               "0x749c79"
#define D3DOGL_UNSANDBAG_VIEWPERF_ID                                   0x10749c79
#define D3DOGL_UNSANDBAG_VIEWPERF_OVERINSTALL                          0 // OVERRIDE
#define D3DOGL_UNSANDBAG_VIEWPERF_DISABLE                              0
#define D3DOGL_UNSANDBAG_VIEWPERF_ENABLE                               0xe25aba79
#define D3DOGL_UNSANDBAG_VIEWPERF_DEFAULT                              D3DOGL_UNSANDBAG_VIEWPERF_DISABLE


#define DACACHELINESIZE_STRING                                         "74095218"
#define DACACHELINESIZE_ID                                             0x10148135
#define DACACHELINESIZE_OVERINSTALL                                    0 // OVERRIDE
#define DACACHELINESIZE_BYTES128                                       0x00000000
#define DACACHELINESIZE_BYTES64                                        0x00000001
#define DACACHELINESIZE_BYTES32                                        0x00000002
#define DACACHELINESIZE_DYNAMIC                                        0x00000003
#define DACACHELINESIZE_MIN                                            0x00000000
#define DACACHELINESIZE_MAX                                            0x00000003
#define DACACHELINESIZE_DEFAULT                                        DACACHELINESIZE_DYNAMIC


#define DEFAULT_ALLOC_LIST_SIZE_STRING                                 "60025699"
#define DEFAULT_ALLOC_LIST_SIZE_ID                                     0x10b55c79
#define DEFAULT_ALLOC_LIST_SIZE_OVERINSTALL                            0 // OVERRIDE
#define DEFAULT_ALLOC_LIST_SIZE_DEFAULT                                0x00000000


#define DEFAULT_PATCH_LIST_SIZE_STRING                                 "60025688"
#define DEFAULT_PATCH_LIST_SIZE_ID                                     0x10c55d78
#define DEFAULT_PATCH_LIST_SIZE_OVERINSTALL                            0 // OVERRIDE
#define DEFAULT_PATCH_LIST_SIZE_DEFAULT                                0x00000000


#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_STRING                         "2022013"
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_ID                             0x10fadc97
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_OVERINSTALL                    1 // MERGE
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_DISABLED                       0x0
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_OFF                            0x0
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_0                              0x0
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_FALSE                          0x0
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_ENABLED                        0x1
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_ON                             0x1
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_1                              0x1
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_TRUE                           0x1
#define DISABLE_ALLOCINUSE_WAR_MSHYBRID_DEFAULT                        DISABLE_ALLOCINUSE_WAR_MSHYBRID_ENABLED


#define DISABLE_MSHYBRID_SYNC_ON_RRI_STRING                            "200189347"
#define DISABLE_MSHYBRID_SYNC_ON_RRI_ID                                0x10fadc86
#define DISABLE_MSHYBRID_SYNC_ON_RRI_OVERINSTALL                       1 // MERGE
#define DISABLE_MSHYBRID_SYNC_ON_RRI_DISABLED                          0x0
#define DISABLE_MSHYBRID_SYNC_ON_RRI_OFF                               0x0
#define DISABLE_MSHYBRID_SYNC_ON_RRI_0                                 0x0
#define DISABLE_MSHYBRID_SYNC_ON_RRI_FALSE                             0x0
#define DISABLE_MSHYBRID_SYNC_ON_RRI_ENABLED                           0x1
#define DISABLE_MSHYBRID_SYNC_ON_RRI_ON                                0x1
#define DISABLE_MSHYBRID_SYNC_ON_RRI_1                                 0x1
#define DISABLE_MSHYBRID_SYNC_ON_RRI_TRUE                              0x1
#define DISABLE_MSHYBRID_SYNC_ON_RRI_DEFAULT                           DISABLE_MSHYBRID_SYNC_ON_RRI_ENABLED


#define DISABLE_POST_L2_COMPRESSION_STRING                             "20200910"
#define DISABLE_POST_L2_COMPRESSION_ID                                 0x101218cf
#define DISABLE_POST_L2_COMPRESSION_OVERINSTALL                        0 // OVERRIDE
#define DISABLE_POST_L2_COMPRESSION_NEVER                              0x00000000
#define DISABLE_POST_L2_COMPRESSION_OFF                                0x00000000
#define DISABLE_POST_L2_COMPRESSION_0                                  0x00000000
#define DISABLE_POST_L2_COMPRESSION_FALSE                              0x00000000
#define DISABLE_POST_L2_COMPRESSION_ALWAYS                             0x00000001
#define DISABLE_POST_L2_COMPRESSION_ON                                 0x00000001
#define DISABLE_POST_L2_COMPRESSION_1                                  0x00000001
#define DISABLE_POST_L2_COMPRESSION_TRUE                               0x00000001
#define DISABLE_POST_L2_COMPRESSION_DISABLE_IF_BUG_3046774             0x00000002
#define DISABLE_POST_L2_COMPRESSION_DEFAULT                            DISABLE_POST_L2_COMPRESSION_NEVER


#define DISABLE_USER_DVM_STRING                                        "09090909"
#define DISABLE_USER_DVM_ID                                            0x101ae753
#define DISABLE_USER_DVM_OVERINSTALL                                   0 // OVERRIDE
#define DISABLE_USER_DVM_OFF                                           0x00000000
#define DISABLE_USER_DVM_DISABLED                                      0x00000000
#define DISABLE_USER_DVM_ON                                            0x00000001
#define DISABLE_USER_DVM_ENABLED                                       0x00000001


#define DISPLAYMUX_INDICATOR_STRING                                    "2521863"
#define DISPLAYMUX_INDICATOR_ID                                        0x10029540
#define DISPLAYMUX_INDICATOR_OVERINSTALL                               0 // OVERRIDE
#define DISPLAYMUX_INDICATOR_OFF                                       0x0
#define DISPLAYMUX_INDICATOR_DISABLED                                  0x0
#define DISPLAYMUX_INDICATOR_ON                                        0x1
#define DISPLAYMUX_INDICATOR_ENABLED                                   0x1
#define DISPLAYMUX_INDICATOR_DEFAULT                                   DISPLAYMUX_INDICATOR_OFF


#define DISPLAY_MUX_SWITCH_FLAGS_STRING                                "2677349"
#define DISPLAY_MUX_SWITCH_FLAGS_ID                                    0x10e75807
#define DISPLAY_MUX_SWITCH_FLAGS_OVERINSTALL                           1 // MERGE
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_1_SEC                  0x000003E8
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_2_SEC                  0x000007D0
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_3_SEC                  0x00000BB8
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_4_SEC                  0x00000FA0
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_5_SEC                  0x00001388
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_6_SEC                  0x00001770
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_7_SEC                  0x00001B58
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_8_SEC                  0x00001F40
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_9_SEC                  0x00002328
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_10_SEC                 0x00002710
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_15_SEC                 0x00003A98
#define DISPLAY_MUX_SWITCH_FLAGS_D_TO_I_TIMEOUT_20_SEC                 0x00004E20
#define DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_NVDLIST               0x00010000
#define DISPLAY_MUX_SWITCH_FLAGS_MUX_SWITCH_FROM_CORE_UMD              0x00020000
#define DISPLAY_MUX_SWITCH_FLAGS_DEFAULT                               0x00010bb8


#define DRIVERINFOOVERLAY_STRING                                       "13975394"
#define DRIVERINFOOVERLAY_ID                                           0x104a7524
#define DRIVERINFOOVERLAY_OVERINSTALL                                  0 // OVERRIDE
#define DRIVERINFOOVERLAY_OFF                                          0x34045364
#define DRIVERINFOOVERLAY_DISABLED                                     0x34045364
#define DRIVERINFOOVERLAY_ON                                           0x24554582
#define DRIVERINFOOVERLAY_ENABLED                                      0x24554582
#define DRIVERINFOOVERLAY_DEFAULT                                      DRIVERINFOOVERLAY_OFF


#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_STRING                "16374916"
#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_ID                    0x10e75806
#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_OVERINSTALL           1 // MERGE
#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_DISALLOW_BY_DEFAULT   0x00000001
#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_ALLOW_BY_DEFAULT      0x00000002
#define DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_DEFAULT               DYNAMIC_DISPLAY_MUX_SWITCH_DRIVER_POLICY_DISALLOW_BY_DEFAULT


#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_STRING    "16374918"
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ID        0x10e75809
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_OVERINSTALL 1 // MERGE
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_DISABLED  0x0
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_OFF       0x0
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_0         0x0
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_FALSE     0x0
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ENABLED   0x1
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ON        0x1
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_1         0x1
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_TRUE      0x1
#define DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_DEFAULT   DYNAMIC_MUX_SWITCH_DESKTOPAPPS_HANDLING_POWER_SAVING_ENABLED


#define EARLYZHYSTERESIS_STRING                                        "74095215"
#define EARLYZHYSTERESIS_ID                                            0x1073e558
#define EARLYZHYSTERESIS_OVERINSTALL                                   0 // OVERRIDE
#define EARLYZHYSTERESIS_INSTANTANEOUS                                 0x0
#define EARLYZHYSTERESIS__16                                           0x1
#define EARLYZHYSTERESIS__32                                           0x2
#define EARLYZHYSTERESIS__64                                           0x3
#define EARLYZHYSTERESIS__128                                          0x4
#define EARLYZHYSTERESIS__256                                          0x5
#define EARLYZHYSTERESIS__512                                          0x6
#define EARLYZHYSTERESIS__1024                                         0x7
#define EARLYZHYSTERESIS__2048                                         0x8
#define EARLYZHYSTERESIS__4096                                         0x9
#define EARLYZHYSTERESIS__8192                                         0xa
#define EARLYZHYSTERESIS__16384                                        0xb
#define EARLYZHYSTERESIS__32768                                        0xc
#define EARLYZHYSTERESIS__65536                                        0xd
#define EARLYZHYSTERESIS_LATEZ_INFINITE                                0xe
#define EARLYZHYSTERESIS_LATEZ_ALWAYS                                  0xf


#define EARLYZ_EXPERIMENTS_STRING                                      "74099215"
#define EARLYZ_EXPERIMENTS_ID                                          0x10dd5f61
#define EARLYZ_EXPERIMENTS_OVERINSTALL                                 0 // OVERRIDE
#define EARLYZ_EXPERIMENTS_FORCE_EARLYZ                                0x00000001
#define EARLYZ_EXPERIMENTS_MASK                                        0x00000001
#define EARLYZ_EXPERIMENTS_DEFAULTS                                    0x00000000


#define ENABLE_ASYNC_WIN32_CALLS_STRING                                "1242273"
#define ENABLE_ASYNC_WIN32_CALLS_ID                                    0x10fadc98
#define ENABLE_ASYNC_WIN32_CALLS_OVERINSTALL                           1 // MERGE
#define ENABLE_ASYNC_WIN32_CALLS_DISABLED                              0x0
#define ENABLE_ASYNC_WIN32_CALLS_OFF                                   0x0
#define ENABLE_ASYNC_WIN32_CALLS_0                                     0x0
#define ENABLE_ASYNC_WIN32_CALLS_FALSE                                 0x0
#define ENABLE_ASYNC_WIN32_CALLS_ENABLED                               0x1
#define ENABLE_ASYNC_WIN32_CALLS_ON                                    0x1
#define ENABLE_ASYNC_WIN32_CALLS_1                                     0x1
#define ENABLE_ASYNC_WIN32_CALLS_TRUE                                  0x1
#define ENABLE_ASYNC_WIN32_CALLS_DEFAULT                               ENABLE_ASYNC_WIN32_CALLS_ENABLED


#define ENABLE_BLURAY3D_STRING                                         "EnableBluray3D"
#define ENABLE_BLURAY3D_ID                                             0x10ad7687
#define ENABLE_BLURAY3D_OVERINSTALL                                    0 // OVERRIDE
#define ENABLE_BLURAY3D_OFF                                            0
#define ENABLE_BLURAY3D_DISABLED                                       0
#define ENABLE_BLURAY3D_ON                                             1
#define ENABLE_BLURAY3D_ENABLED                                        1
#define ENABLE_BLURAY3D_DEFAULT                                        ENABLE_BLURAY3D_ON


#define ENABLE_CE_COMPONENT_REMAPPING_STRING                           "200161427"
#define ENABLE_CE_COMPONENT_REMAPPING_ID                               0x10fadc94
#define ENABLE_CE_COMPONENT_REMAPPING_OVERINSTALL                      1 // MERGE
#define ENABLE_CE_COMPONENT_REMAPPING_DISABLED                         0x0
#define ENABLE_CE_COMPONENT_REMAPPING_OFF                              0x0
#define ENABLE_CE_COMPONENT_REMAPPING_0                                0x0
#define ENABLE_CE_COMPONENT_REMAPPING_FALSE                            0x0
#define ENABLE_CE_COMPONENT_REMAPPING_ENABLED                          0x1
#define ENABLE_CE_COMPONENT_REMAPPING_ON                               0x1
#define ENABLE_CE_COMPONENT_REMAPPING_1                                0x1
#define ENABLE_CE_COMPONENT_REMAPPING_TRUE                             0x1
#define ENABLE_CE_COMPONENT_REMAPPING_DEFAULT                          ENABLE_CE_COMPONENT_REMAPPING_ENABLED


#define ENABLE_CE_DIRECT_FLIP_STRING                                   "1242272"
#define ENABLE_CE_DIRECT_FLIP_ID                                       0x10fadc85
#define ENABLE_CE_DIRECT_FLIP_OVERINSTALL                              1 // MERGE
#define ENABLE_CE_DIRECT_FLIP_DISABLED                                 0x0
#define ENABLE_CE_DIRECT_FLIP_OFF                                      0x0
#define ENABLE_CE_DIRECT_FLIP_0                                        0x0
#define ENABLE_CE_DIRECT_FLIP_FALSE                                    0x0
#define ENABLE_CE_DIRECT_FLIP_ENABLED                                  0x1
#define ENABLE_CE_DIRECT_FLIP_ON                                       0x1
#define ENABLE_CE_DIRECT_FLIP_1                                        0x1
#define ENABLE_CE_DIRECT_FLIP_TRUE                                     0x1
#define ENABLE_CE_DIRECT_FLIP_DEFAULT                                  ENABLE_CE_DIRECT_FLIP_DISABLED


#define ENABLE_CE_MS_HYBRID_STRING                                     "1242271"
#define ENABLE_CE_MS_HYBRID_ID                                         0x10fadc84
#define ENABLE_CE_MS_HYBRID_OVERINSTALL                                1 // MERGE
#define ENABLE_CE_MS_HYBRID_DISABLED                                   0x0
#define ENABLE_CE_MS_HYBRID_OFF                                        0x0
#define ENABLE_CE_MS_HYBRID_0                                          0x0
#define ENABLE_CE_MS_HYBRID_FALSE                                      0x0
#define ENABLE_CE_MS_HYBRID_ENABLED                                    0x1
#define ENABLE_CE_MS_HYBRID_ON                                         0x1
#define ENABLE_CE_MS_HYBRID_1                                          0x1
#define ENABLE_CE_MS_HYBRID_TRUE                                       0x1
#define ENABLE_CE_MS_HYBRID_DEFAULT                                    ENABLE_CE_MS_HYBRID_ENABLED


#define ENABLE_INVARIANT_RENDERING_STRING                              "53d30c"
#define ENABLE_INVARIANT_RENDERING_ID                                  0x1053d30c
#define ENABLE_INVARIANT_RENDERING_OVERINSTALL                         0 // OVERRIDE
#define ENABLE_INVARIANT_RENDERING_OFF                                 91917306
#define ENABLE_INVARIANT_RENDERING_DISABLED                            91917306
#define ENABLE_INVARIANT_RENDERING_ON                                  11519843
#define ENABLE_INVARIANT_RENDERING_ENABLED                             11519843
#define ENABLE_INVARIANT_RENDERING_DEFAULT                             ENABLE_INVARIANT_RENDERING_OFF


#define EXPORT_PERF_COUNTERS_STRING                                    "74095214"
#define EXPORT_PERF_COUNTERS_ID                                        0x108f0841
#define EXPORT_PERF_COUNTERS_OVERINSTALL                               1 // MERGE
#define EXPORT_PERF_COUNTERS_OFF                                       0x00000000
#define EXPORT_PERF_COUNTERS_DISABLED                                  0x00000000
#define EXPORT_PERF_COUNTERS_ON                                        0x00000001
#define EXPORT_PERF_COUNTERS_ENABLED                                   0x00000001
#define EXPORT_PERF_COUNTERS_DEFAULT                                   EXPORT_PERF_COUNTERS_OFF


#define EXTERNAL_QUIET_MODE_STRING                                     "f1846874"
#define EXTERNAL_QUIET_MODE_ID                                         0x10115c8d
#define EXTERNAL_QUIET_MODE_OVERINSTALL                                0 // OVERRIDE
#define EXTERNAL_QUIET_MODE_ON                                         0x00000001
#define EXTERNAL_QUIET_MODE_OFF                                        0x00000000
#define EXTERNAL_QUIET_MODE_DEFAULT                                    EXTERNAL_QUIET_MODE_OFF


#define FERMI_DUMP_NVIR_FLAG_STRING                                    "50299698"
#define FERMI_DUMP_NVIR_FLAG_ID                                        0x105ba0cb
#define FERMI_DUMP_NVIR_FLAG_OVERINSTALL                               0 // OVERRIDE
#define FERMI_DUMP_NVIR_FLAG_OFF                                       0x00000000
#define FERMI_DUMP_NVIR_FLAG_DISABLED                                  0x00000000
#define FERMI_DUMP_NVIR_FLAG_ON                                        0x00000001
#define FERMI_DUMP_NVIR_FLAG_ENABLED                                   0x00000001
#define FERMI_DUMP_NVIR_FLAG_DEFAULT                                   FERMI_DUMP_NVIR_FLAG_OFF


#define FERMI_SET_L2_CACHE_CONTROL_STRING                              ""
#define FERMI_SET_L2_CACHE_CONTROL_ID                                  0x10001fd3
#define FERMI_SET_L2_CACHE_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_FIRST                     0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_NORMAL                    0x00000001
#define FERMI_SET_L2_CACHE_CONTROL_VAF_EVICT_LAST                      0x00000002
#define FERMI_SET_L2_CACHE_CONTROL_VAF_SHIFT                           0
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_FIRST 0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_NORMAL 0x00000010
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_EVICT_LAST  0x00000020
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_READ_SHIFT       4
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_FIRST    0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_NORMAL   0x00000100
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_EVICT_LAST     0x00000200
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_READ_SHIFT          8
#define FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_FIRST       0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_NORMAL      0x00001000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_EVICT_LAST        0x00002000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_PREFETCH_READ_SHIFT             12
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_FIRST 0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_NORMAL 0x00010000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_EVICT_LAST 0x00020000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_NONINTERLOCKED_WRITE_SHIFT      16
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_FIRST   0x00000000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_NORMAL  0x00100000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_EVICT_LAST    0x00200000
#define FERMI_SET_L2_CACHE_CONTROL_ROP_INTERLOCKED_WRITE_SHIFT         20
#define FERMI_SET_L2_CACHE_CONTROL_CLASS_DEFAULT                       0x00101001
#define FERMI_SET_L2_CACHE_CONTROL_DX10_DEFAULT                        0x00001000
#define FERMI_SET_L2_CACHE_CONTROL_OGL_DEFAULT                         0x00111111
#define FERMI_SET_L2_CACHE_CONTROL_DEFAULT                             FERMI_SET_L2_CACHE_CONTROL_CLASS_DEFAULT


#define FERMI_SET_PRIM_CB_THROTTLE_STRING                              "B40D9E03d"
#define FERMI_SET_PRIM_CB_THROTTLE_ID                                  0x10951b32
#define FERMI_SET_PRIM_CB_THROTTLE_OVERINSTALL                         0 // OVERRIDE
#define FERMI_SET_PRIM_CB_THROTTLE_MIN                                 0x00000000
#define FERMI_SET_PRIM_CB_THROTTLE_AUTOMATIC                           0x00000000
#define FERMI_SET_PRIM_CB_THROTTLE_MAX                                 0x003fffff
#define FERMI_SET_PRIM_CB_THROTTLE_DEFAULT                             0


#define FERMI_SHADER_HEAP_SIZE_STRING                                  "50299699"
#define FERMI_SHADER_HEAP_SIZE_ID                                      0x10a77a06
#define FERMI_SHADER_HEAP_SIZE_OVERINSTALL                             0 // OVERRIDE
#define FERMI_SHADER_HEAP_SIZE_DEFAULT                                 0x00000000


#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_STRING                         "0x639bc3"
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_ID                             0x10639bc3
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_OVERINSTALL                    0 // OVERRIDE
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_OFF                            0
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_DISABLED                       0
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_ON                             1
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_ENABLED                        1
#define FORCE_FLUSH_ON_ACQUIRE_RESOURCE_DEFAULT                        FORCE_FLUSH_ON_ACQUIRE_RESOURCE_OFF


#define FPSINDICATOR_STRING                                            "13975395"
#define FPSINDICATOR_ID                                                0x108853e6
#define FPSINDICATOR_OVERINSTALL                                       0 // OVERRIDE
#define FPSINDICATOR_OFF                                               0x34045364
#define FPSINDICATOR_DISABLED                                          0x34045364
#define FPSINDICATOR_ON                                                0x24554582
#define FPSINDICATOR_ENABLED                                           0x24554582
#define FPSINDICATOR_DEFAULT                                           FPSINDICATOR_OFF


#define FRL_FPS_STRING                                                 "00008605"
#define FRL_FPS_ID                                                     0x10835002
#define FRL_FPS_OVERINSTALL                                            1 // MERGE
#define FRL_FPS_DISABLED                                               0x00000000
#define FRL_FPS_MIN                                                    0x00000000
#define FRL_FPS_MAX                                                    0x000003ff
#define FRL_FPS_DEFAULT                                                FRL_FPS_DISABLED


#define FRL_FPS_NVCPL_STRING                                           "0000860A"
#define FRL_FPS_NVCPL_ID                                               0x1083500a
#define FRL_FPS_NVCPL_OVERINSTALL                                      1 // MERGE
#define FRL_FPS_NVCPL_DISABLED                                         0x00000000
#define FRL_FPS_NVCPL_MIN                                              0x00000000
#define FRL_FPS_NVCPL_MAX                                              0x000003ff
#define FRL_FPS_NVCPL_DEFAULT                                          FRL_FPS_NVCPL_DISABLED


#define FRL_LOW_LATENCY_STRING                                         "00008603"
#define FRL_LOW_LATENCY_ID                                             0x10835000
#define FRL_LOW_LATENCY_OVERINSTALL                                    1 // MERGE
#define FRL_LOW_LATENCY_OFF                                            0x00000000
#define FRL_LOW_LATENCY_DISABLED                                       0x00000000
#define FRL_LOW_LATENCY_PASSIVE                                        0x00000000
#define FRL_LOW_LATENCY_ON                                             0x00000001
#define FRL_LOW_LATENCY_ENABLED                                        0x00000001
#define FRL_LOW_LATENCY_DEFAULT                                        FRL_LOW_LATENCY_OFF


#define FRL_LOW_LATENCY_BUFFER_STRING                                  "00008604"
#define FRL_LOW_LATENCY_BUFFER_ID                                      0x10835001
#define FRL_LOW_LATENCY_BUFFER_OVERINSTALL                             0 // OVERRIDE
#define FRL_LOW_LATENCY_BUFFER_DEFAULT                                 800


#define FRL_LOW_LATENCY_BUFFER_MAX_STRING                              "00008647"
#define FRL_LOW_LATENCY_BUFFER_MAX_ID                                  0x1083501f
#define FRL_LOW_LATENCY_BUFFER_MAX_OVERINSTALL                         0 // OVERRIDE
#define FRL_LOW_LATENCY_BUFFER_MAX_DEFAULT                             1500


#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_STRING                       "00008623"
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_ID                           0x1083500b
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_OVERINSTALL                  0 // OVERRIDE
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_MASK_US                      0x000003ff
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_EXCLUDE_OVERLAP              0x10000000
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_TEST_ENABLE                  0x08000000
#define FRL_LOW_LATENCY_CPU_RENDER_MARGIN_DEFAULT                      0x0000012c


#define FRL_LOW_LATENCY_GAIN_A_STRING                                  "00008606"
#define FRL_LOW_LATENCY_GAIN_A_ID                                      0x10835003
#define FRL_LOW_LATENCY_GAIN_A_OVERINSTALL                             0 // OVERRIDE
#define FRL_LOW_LATENCY_GAIN_A_DEFAULT                                 500


#define FRL_LOW_LATENCY_GAIN_B_STRING                                  "00008607"
#define FRL_LOW_LATENCY_GAIN_B_ID                                      0x10835004
#define FRL_LOW_LATENCY_GAIN_B_OVERINSTALL                             0 // OVERRIDE
#define FRL_LOW_LATENCY_GAIN_B_DEFAULT                                 20


#define FRL_LOW_LATENCY_GAP_TARGET_STRING                              "00008620"
#define FRL_LOW_LATENCY_GAP_TARGET_ID                                  0x10835008
#define FRL_LOW_LATENCY_GAP_TARGET_OVERINSTALL                         0 // OVERRIDE
#define FRL_LOW_LATENCY_GAP_TARGET_MIN                                 0x00000000
#define FRL_LOW_LATENCY_GAP_TARGET_MAX                                 0x000003e8
#define FRL_LOW_LATENCY_GAP_TARGET_DEFAULT                             100


#define FRL_LOW_LATENCY_MAX_SLEEP_PCT_STRING                           "00008646"
#define FRL_LOW_LATENCY_MAX_SLEEP_PCT_ID                               0x1083501e
#define FRL_LOW_LATENCY_MAX_SLEEP_PCT_OVERINSTALL                      0 // OVERRIDE
#define FRL_LOW_LATENCY_MAX_SLEEP_PCT_DEFAULT                          48


#define FRL_LOW_LATENCY_OVERLAP_TARGET_STRING                          "00008619"
#define FRL_LOW_LATENCY_OVERLAP_TARGET_ID                              0x10835007
#define FRL_LOW_LATENCY_OVERLAP_TARGET_OVERINSTALL                     0 // OVERRIDE
#define FRL_LOW_LATENCY_OVERLAP_TARGET_MIN                             0x00000000
#define FRL_LOW_LATENCY_OVERLAP_TARGET_MAX                             0x00002710
#define FRL_LOW_LATENCY_OVERLAP_TARGET_DEFAULT                         1500


#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_STRING                         "00008618"
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_ID                             0x10835015
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_OVERINSTALL                    0 // OVERRIDE
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_OFF                            0
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_DISABLED                       0
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_ON                             1
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_ENABLED                        1
#define FRL_LOW_LATENCY_PROACTIVE_FLUSH_DEFAULT                        FRL_LOW_LATENCY_PROACTIVE_FLUSH_OFF


#define FRL_LOW_LATENCY_RTBO_TARGET_STRING                             "00008645"
#define FRL_LOW_LATENCY_RTBO_TARGET_ID                                 0x1083501d
#define FRL_LOW_LATENCY_RTBO_TARGET_OVERINSTALL                        0 // OVERRIDE
#define FRL_LOW_LATENCY_RTBO_TARGET_DEFAULT                            100


#define FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR_STRING               "00008644"
#define FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR_ID                   0x1083501c
#define FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR_OVERINSTALL          0 // OVERRIDE
#define FRL_LOW_LATENCY_SMALL_BUFFER_BLEND_FACTOR_DEFAULT              0


#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_STRING              "0000aa44"
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_ID                  0x10835ffc
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_OVERINSTALL         0 // OVERRIDE
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_DISABLED            0x0
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_OFF                 0x0
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_0                   0x0
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_FALSE               0x0
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_ENABLED             0x1
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_ON                  0x1
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_1                   0x1
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_TRUE                0x1
#define FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_DEFAULT             FRL_LOW_LATENCY_USE_PRESENT_MARKER_OVERLAP_DISABLED


#define FXAA_ALLOW_STRING                                              "10572898"
#define FXAA_ALLOW_ID                                                  0x1034cb89
#define FXAA_ALLOW_OVERINSTALL                                         0 // OVERRIDE
#define FXAA_ALLOW_DISALLOWED                                          0
#define FXAA_ALLOW_OFF                                                 0
#define FXAA_ALLOW_DISABLED                                            0
#define FXAA_ALLOW_ALLOWED                                             1
#define FXAA_ALLOW_ON                                                  1
#define FXAA_ALLOW_ENABLED                                             1
#define FXAA_ALLOW_DEFAULT                                             FXAA_ALLOW_ALLOWED


#define FXAA_ENABLE_STRING                                             "97263802"
#define FXAA_ENABLE_ID                                                 0x1074c972
#define FXAA_ENABLE_OVERINSTALL                                        1 // MERGE
#define FXAA_ENABLE_OFF                                                0
#define FXAA_ENABLE_DISABLED                                           0
#define FXAA_ENABLE_ON                                                 1
#define FXAA_ENABLE_ENABLED                                            1
#define FXAA_ENABLE_DEFAULT                                            FXAA_ENABLE_OFF


#define FXAA_INDICATOR_ENABLE_STRING                                   "68fb9c"
#define FXAA_INDICATOR_ENABLE_ID                                       0x1068fb9c
#define FXAA_INDICATOR_ENABLE_OVERINSTALL                              0 // OVERRIDE
#define FXAA_INDICATOR_ENABLE_OFF                                      0
#define FXAA_INDICATOR_ENABLE_DISABLED                                 0
#define FXAA_INDICATOR_ENABLE_ON                                       1
#define FXAA_INDICATOR_ENABLE_ENABLED                                  1
#define FXAA_INDICATOR_ENABLE_DEFAULT                                  FXAA_INDICATOR_ENABLE_OFF


#define G80_MODEB_OVERRIDE_STRING                                      "74098073"
#define G80_MODEB_OVERRIDE_ID                                          0x10fc00ff
#define G80_MODEB_OVERRIDE_OVERINSTALL                                 0 // OVERRIDE
#define G80_MODEB_OVERRIDE_DISABLE                                     0x00000000
#define G80_MODEB_OVERRIDE_ENABLE                                      0x00000001
#define G80_MODEB_OVERRIDE_DEFAULT                                     G80_MODEB_OVERRIDE_DISABLE


#define GFN_FRL_FPS_STRING                                             "0000860B"
#define GFN_FRL_FPS_ID                                                 0x1083500f
#define GFN_FRL_FPS_OVERINSTALL                                        0 // OVERRIDE
#define GFN_FRL_FPS_DISABLED                                           0x00000000
#define GFN_FRL_FPS_MIN                                                0x00000000
#define GFN_FRL_FPS_MAX                                                0x000003ff
#define GFN_FRL_FPS_DEFAULT                                            GFN_FRL_FPS_DISABLED


#define GRAPHICS_SHADER_PREFETCH_STRING                                "0x121044"
#define GRAPHICS_SHADER_PREFETCH_ID                                    0x10121044
#define GRAPHICS_SHADER_PREFETCH_OVERINSTALL                           0 // OVERRIDE
#define GRAPHICS_SHADER_PREFETCH_DEFAULT                               0x4000


#define GSYNC_COMPATIBILITY_STRING                                     "81598022"
#define GSYNC_COMPATIBILITY_ID                                         0x109db0d3
#define GSYNC_COMPATIBILITY_OVERINSTALL                                1 // MERGE
#define GSYNC_COMPATIBILITY_NO                                         0x0
#define GSYNC_COMPATIBILITY_YES                                        0x1
#define GSYNC_COMPATIBILITY_DEFAULT                                    GSYNC_COMPATIBILITY_NO


#define HDRINDICATOR_STRING                                            "111bae27"
#define HDRINDICATOR_ID                                                0x107b1e3e
#define HDRINDICATOR_OVERINSTALL                                       0 // OVERRIDE
#define HDRINDICATOR_OFF                                               0x0
#define HDRINDICATOR_DISABLED                                          0x0
#define HDRINDICATOR_ON                                                0x1
#define HDRINDICATOR_ENABLED                                           0x1
#define HDRINDICATOR_DEFAULT                                           HDRINDICATOR_OFF


#define HYBRIDPERFSLIENABLE_STRING                                     "19726778"
#define HYBRIDPERFSLIENABLE_ID                                         0x109a6a85
#define HYBRIDPERFSLIENABLE_OVERINSTALL                                0 // OVERRIDE
#define HYBRIDPERFSLIENABLE_OFF                                        0x51616260
#define HYBRIDPERFSLIENABLE_DISABLED                                   0x51616260
#define HYBRIDPERFSLIENABLE_ON                                         0x02906797
#define HYBRIDPERFSLIENABLE_ENABLED                                    0x02906797
#define HYBRIDPERFSLIENABLE_DEFAULT                                    HYBRIDPERFSLIENABLE_OFF


#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_STRING                    "2165ae"
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_ID                        0x102165ae
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_OVERINSTALL               0 // OVERRIDE
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_OFF                       0x0
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_DISABLED                  0x0
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_ON                        0x1
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_ENABLED                   0x1
#define KEPLER_BALANCED_PRIM_TIMESLICED_MODE_DEFAULT                   KEPLER_BALANCED_PRIM_TIMESLICED_MODE_OFF


#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_STRING                 "2165ad"
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_ID                     0x102165ad
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_OVERINSTALL            0 // OVERRIDE
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_OFF                    0x0
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_DISABLED               0x0
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_ON                     0x1
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_ENABLED                0x1
#define KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_DEFAULT                KEPLER_BALANCED_PRIM_UNPARTITIONED_MODE_OFF


#define KEPLER_L1_CACHE_WAR_BUG_986473_STRING                          "0x528ab2"
#define KEPLER_L1_CACHE_WAR_BUG_986473_ID                              0x10528ab2
#define KEPLER_L1_CACHE_WAR_BUG_986473_OVERINSTALL                     0 // OVERRIDE
#define KEPLER_L1_CACHE_WAR_BUG_986473_OFF                             0
#define KEPLER_L1_CACHE_WAR_BUG_986473_DISABLED                        0
#define KEPLER_L1_CACHE_WAR_BUG_986473_ON                              1
#define KEPLER_L1_CACHE_WAR_BUG_986473_ENABLED                         1
#define KEPLER_L1_CACHE_WAR_BUG_986473_DEFAULT                         KEPLER_L1_CACHE_WAR_BUG_986473_ON


#define KEPLER_USE_SHUFFLE_INSTRUCTION_STRING                          "BBAADDDD"
#define KEPLER_USE_SHUFFLE_INSTRUCTION_ID                              0x10a1b2f8
#define KEPLER_USE_SHUFFLE_INSTRUCTION_OVERINSTALL                     0 // OVERRIDE
#define KEPLER_USE_SHUFFLE_INSTRUCTION_OFF                             0
#define KEPLER_USE_SHUFFLE_INSTRUCTION_DISABLED                        0
#define KEPLER_USE_SHUFFLE_INSTRUCTION_ON                              1
#define KEPLER_USE_SHUFFLE_INSTRUCTION_ENABLED                         1
#define KEPLER_USE_SHUFFLE_INSTRUCTION_DEFAULT                         KEPLER_USE_SHUFFLE_INSTRUCTION_ON


#define LATENCY_INDICATOR_AUTOALIGN_STRING                             "53304098"
#define LATENCY_INDICATOR_AUTOALIGN_ID                                 0x1095f170
#define LATENCY_INDICATOR_AUTOALIGN_OVERINSTALL                        0 // OVERRIDE
#define LATENCY_INDICATOR_AUTOALIGN_DISABLED                           0x0
#define LATENCY_INDICATOR_AUTOALIGN_OFF                                0x0
#define LATENCY_INDICATOR_AUTOALIGN_ENABLED                            0x1
#define LATENCY_INDICATOR_AUTOALIGN_ON                                 0x1
#define LATENCY_INDICATOR_AUTOALIGN_DEFAULT                            LATENCY_INDICATOR_AUTOALIGN_ENABLED


#define LATENCY_INDICATOR_DRAW_NEGATIVE_STRING                         "A0022605"
#define LATENCY_INDICATOR_DRAW_NEGATIVE_ID                             0x10824f19
#define LATENCY_INDICATOR_DRAW_NEGATIVE_OVERINSTALL                    0 // OVERRIDE
#define LATENCY_INDICATOR_DRAW_NEGATIVE_OFF                            0
#define LATENCY_INDICATOR_DRAW_NEGATIVE_DISABLED                       0
#define LATENCY_INDICATOR_DRAW_NEGATIVE_ON                             1
#define LATENCY_INDICATOR_DRAW_NEGATIVE_ENABLED                        1
#define LATENCY_INDICATOR_DRAW_NEGATIVE_DEFAULT                        LATENCY_INDICATOR_DRAW_NEGATIVE_OFF


#define LATENCY_INDICATOR_DURATION_STRING                              "A0022604"
#define LATENCY_INDICATOR_DURATION_ID                                  0x10824f18
#define LATENCY_INDICATOR_DURATION_OVERINSTALL                         0 // OVERRIDE
#define LATENCY_INDICATOR_DURATION_DEFAULT                             0xFA


#define LATENCY_INDICATOR_ENABLE_STRING                                "A0122705"
#define LATENCY_INDICATOR_ENABLE_ID                                    0x10833f19
#define LATENCY_INDICATOR_ENABLE_OVERINSTALL                           0 // OVERRIDE
#define LATENCY_INDICATOR_ENABLE_OFF                                   0
#define LATENCY_INDICATOR_ENABLE_DISABLED                              0
#define LATENCY_INDICATOR_ENABLE_ON                                    1
#define LATENCY_INDICATOR_ENABLE_ENABLED                               1
#define LATENCY_INDICATOR_ENABLE_DEFAULT                               LATENCY_INDICATOR_ENABLE_OFF


#define LATENCY_INDICATOR_HEIGHT_STRING                                "A0018604"
#define LATENCY_INDICATOR_HEIGHT_ID                                    0x10844f18
#define LATENCY_INDICATOR_HEIGHT_OVERINSTALL                           0 // OVERRIDE
#define LATENCY_INDICATOR_HEIGHT_MIN                                   0x00000000
#define LATENCY_INDICATOR_HEIGHT_MAX                                   0x000000ff
#define LATENCY_INDICATOR_HEIGHT_DEFAULT_SIZE                          0x00000008


#define LATENCY_INDICATOR_POS_X_STRING                                 "A0008601"
#define LATENCY_INDICATOR_POS_X_ID                                     0x10834f15
#define LATENCY_INDICATOR_POS_X_OVERINSTALL                            0 // OVERRIDE
#define LATENCY_INDICATOR_POS_X_MIN                                    0x00000000
#define LATENCY_INDICATOR_POS_X_MAX                                    0x00000064
#define LATENCY_INDICATOR_POS_X_DEFAULT                                LATENCY_INDICATOR_POS_X_MIN


#define LATENCY_INDICATOR_POS_Y_STRING                                 "A0008602"
#define LATENCY_INDICATOR_POS_Y_ID                                     0x10834f16
#define LATENCY_INDICATOR_POS_Y_OVERINSTALL                            0 // OVERRIDE
#define LATENCY_INDICATOR_POS_Y_MIN                                    0x00000000
#define LATENCY_INDICATOR_POS_Y_MAX                                    0x00000064
#define LATENCY_INDICATOR_POS_Y_DEFAULT_POS_Y                          0x00000032


#define LATENCY_INDICATOR_WIDTH_STRING                                 "A0008603"
#define LATENCY_INDICATOR_WIDTH_ID                                     0x10834f17
#define LATENCY_INDICATOR_WIDTH_OVERINSTALL                            0 // OVERRIDE
#define LATENCY_INDICATOR_WIDTH_MIN                                    0x00000000
#define LATENCY_INDICATOR_WIDTH_MAX                                    0x000000ff
#define LATENCY_INDICATOR_WIDTH_DEFAULT_SIZE                           0x00000004


#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_STRING                         "54312268"
#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_ID                             0x108f0843
#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_OVERINSTALL                    1 // MERGE
#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_MIN                            0x1
#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_MAX                            0x4
#define MAXGPUS_MULTIGPU_BROADCAST_SHIM_DEFAULT                        0x4


#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_STRING                 "0xbd10fb"
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_ID                     0x10bd10fb
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_OVERINSTALL            0 // OVERRIDE
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_FIRST                  0
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_NORMAL                 1
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_LAST                   2
#define MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_DEFAULT                MAXWELL_CIRCULAR_BUFFER_EVICTION_POLICY_LAST


#define MAXWELL_LOW_LOD_OPTIMIZATION_STRING                            "0x524dc7"
#define MAXWELL_LOW_LOD_OPTIMIZATION_ID                                0x10524dc7
#define MAXWELL_LOW_LOD_OPTIMIZATION_OVERINSTALL                       0 // OVERRIDE
#define MAXWELL_LOW_LOD_OPTIMIZATION_ENABLE                            1
#define MAXWELL_LOW_LOD_OPTIMIZATION_TESSELLATION_ONLY                 2
#define MAXWELL_LOW_LOD_OPTIMIZATION_DEFAULT                           0


#define MAXWELL_MMU_WAR_BUG_1317235_STRING                             "0x5234d4"
#define MAXWELL_MMU_WAR_BUG_1317235_ID                                 0x105234d4
#define MAXWELL_MMU_WAR_BUG_1317235_OVERINSTALL                        0 // OVERRIDE
#define MAXWELL_MMU_WAR_BUG_1317235_OFF                                0
#define MAXWELL_MMU_WAR_BUG_1317235_DISABLED                           0
#define MAXWELL_MMU_WAR_BUG_1317235_ON                                 1
#define MAXWELL_MMU_WAR_BUG_1317235_ENABLED                            1
#define MAXWELL_MMU_WAR_BUG_1317235_DEFAULT                            MAXWELL_MMU_WAR_BUG_1317235_OFF


#define MAXWELL_PIXEL_SHADER_BARRIER_STRING                            "0x523dc9"
#define MAXWELL_PIXEL_SHADER_BARRIER_ID                                0x10523dc9
#define MAXWELL_PIXEL_SHADER_BARRIER_OVERINSTALL                       0 // OVERRIDE
#define MAXWELL_PIXEL_SHADER_BARRIER_OFF                               0
#define MAXWELL_PIXEL_SHADER_BARRIER_DISABLED                          0
#define MAXWELL_PIXEL_SHADER_BARRIER_ON                                1
#define MAXWELL_PIXEL_SHADER_BARRIER_ENABLED                           1
#define MAXWELL_PIXEL_SHADER_BARRIER_DEFAULT                           MAXWELL_PIXEL_SHADER_BARRIER_ON


#define MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT_STRING                       "0xb134fc"
#define MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT_ID                           0x10b134fc
#define MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT_OVERINSTALL                  0 // OVERRIDE
#define MAXWELL_SCG_COMPUTE1_MAX_SM_COUNT_DEFAULT                      256


#define MAXWELL_SCG_FLAGS_STRING                                       "0xb134fd"
#define MAXWELL_SCG_FLAGS_ID                                           0x10b134fd
#define MAXWELL_SCG_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define MAXWELL_SCG_FLAGS_NONE                                         0x00000000
#define MAXWELL_SCG_FLAGS_DISABLE_BLITS_ON_ASYNC_COMPUTE               0x00000010
#define MAXWELL_SCG_FLAGS_FORCE_I2M_FOR_ASYNC_COMPUTE_BLITS            0x00000020
#define MAXWELL_SCG_FLAGS_FORCE_CE_FOR_ASYNC_COMPUTE_BLITS             0x00000040
#define MAXWELL_SCG_FLAGS_USE_HELPER_CH_FOR_PROGRESS_FORWARD           0x00000080
#define MAXWELL_SCG_FLAGS_DEFAULT                                      MAXWELL_SCG_FLAGS_NONE


#define MAXWELL_SM_WAR_BUG_1318757_STRING                              "0x58a234"
#define MAXWELL_SM_WAR_BUG_1318757_ID                                  0x1058a234
#define MAXWELL_SM_WAR_BUG_1318757_OVERINSTALL                         0 // OVERRIDE
#define MAXWELL_SM_WAR_BUG_1318757_OFF                                 0
#define MAXWELL_SM_WAR_BUG_1318757_DISABLED                            0
#define MAXWELL_SM_WAR_BUG_1318757_ON                                  1
#define MAXWELL_SM_WAR_BUG_1318757_ENABLED                             1
#define MAXWELL_SM_WAR_BUG_1318757_DEFAULT                             MAXWELL_SM_WAR_BUG_1318757_OFF


#define MAXWELL_TILEDCACHE_STRING                                      "0x523dc0"
#define MAXWELL_TILEDCACHE_ID                                          0x10523dc0
#define MAXWELL_TILEDCACHE_OVERINSTALL                                 0 // OVERRIDE
#define MAXWELL_TILEDCACHE_OFF                                         0
#define MAXWELL_TILEDCACHE_DISABLED                                    0
#define MAXWELL_TILEDCACHE_ON                                          1
#define MAXWELL_TILEDCACHE_ENABLED                                     1
#define MAXWELL_TILEDCACHE_DEFAULT                                     MAXWELL_TILEDCACHE_ON


#define MAXWELL_TILEDCACHE_BUFFERINTERLEAVE_STRING                     "0x523dc2"
#define MAXWELL_TILEDCACHE_BUFFERINTERLEAVE_ID                         0x10523dc2
#define MAXWELL_TILEDCACHE_BUFFERINTERLEAVE_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_TILEDCACHE_BUFFERINTERLEAVE_DEFAULT                    0x0000210A


#define MAXWELL_TILEDCACHE_CONTROL_STRING                              "0x523dc3"
#define MAXWELL_TILEDCACHE_CONTROL_ID                                  0x10523dc3
#define MAXWELL_TILEDCACHE_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define MAXWELL_TILEDCACHE_CONTROL_DEFAULT                             0x08080202


#define MAXWELL_TILEDCACHE_CONTROL_EXTENDED_STRING                     "0x523dd3"
#define MAXWELL_TILEDCACHE_CONTROL_EXTENDED_ID                         0x10523dd3
#define MAXWELL_TILEDCACHE_CONTROL_EXTENDED_OVERINSTALL                0 // OVERRIDE
#define MAXWELL_TILEDCACHE_CONTROL_EXTENDED_DEFAULT                    0x00000008


#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_STRING          "0x523dc6"
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_ID              0x10523dc6
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_OVERINSTALL     0 // OVERRIDE
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_OFF             0
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_DISABLED        0
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_ON              1
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_ENABLED         1
#define MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_DEFAULT         MAXWELL_TILEDCACHE_FORCE_DISCARD_ON_DOWNSAMPLE_OFF


#define MAXWELL_TILEDCACHE_L2_USAGE_STRING                             "0x523dc5"
#define MAXWELL_TILEDCACHE_L2_USAGE_ID                                 0x10523dc5
#define MAXWELL_TILEDCACHE_L2_USAGE_OVERINSTALL                        0 // OVERRIDE
#define MAXWELL_TILEDCACHE_L2_USAGE_DEFAULT                            0.3f


#define MAXWELL_TILEDCACHE_STATETHRESHOLD_STRING                       "0x523dc4"
#define MAXWELL_TILEDCACHE_STATETHRESHOLD_ID                           0x10523dc4
#define MAXWELL_TILEDCACHE_STATETHRESHOLD_OVERINSTALL                  0 // OVERRIDE
#define MAXWELL_TILEDCACHE_STATETHRESHOLD_DEFAULT                      0x00080001


#define MAXWELL_TILEDCACHE_TILESIZE_STRING                             "0x523dc1"
#define MAXWELL_TILEDCACHE_TILESIZE_ID                                 0x10523dc1
#define MAXWELL_TILEDCACHE_TILESIZE_OVERINSTALL                        0 // OVERRIDE
#define MAXWELL_TILEDCACHE_TILESIZE_DEFAULT                            0x00400040


#define MAXWELL_WDDM2_FORCE_128K_PTE_STRING                            ""
#define MAXWELL_WDDM2_FORCE_128K_PTE_ID                                0x10c158ad
#define MAXWELL_WDDM2_FORCE_128K_PTE_OVERINSTALL                       0 // OVERRIDE
#define MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_OFF                         0
#define MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_ON                          1
#define MAXWELL_WDDM2_FORCE_128K_PTE_DEFAULT                           MAXWELL_WDDM2_FORCE_128K_PTE_FORCE_OFF


#define MCAFRSHOWOVERLAP_STRING                                        "1eee1671"
#define MCAFRSHOWOVERLAP_ID                                            0x101a3258
#define MCAFRSHOWOVERLAP_OVERINSTALL                                   0 // OVERRIDE
#define MCAFRSHOWOVERLAP_OFF                                           0x34045364
#define MCAFRSHOWOVERLAP_DISABLED                                      0x34045364
#define MCAFRSHOWOVERLAP_ON                                            0x24554582
#define MCAFRSHOWOVERLAP_ENABLED                                       0x24554582
#define MCAFRSHOWOVERLAP_DEFAULT                                       MCAFRSHOWOVERLAP_OFF


#define MCALLOWUNRESTRICTEDAFR_STRING                                  "fd4c5f"
#define MCALLOWUNRESTRICTEDAFR_ID                                      0x10fd4c5f
#define MCALLOWUNRESTRICTEDAFR_OVERINSTALL                             0 // OVERRIDE
#define MCALLOWUNRESTRICTEDAFR_OFF                                     0x49368db
#define MCALLOWUNRESTRICTEDAFR_DISABLED                                0x49368db
#define MCALLOWUNRESTRICTEDAFR_ON                                      0x1f296c1
#define MCALLOWUNRESTRICTEDAFR_ENABLED                                 0x1f296c1
#define MCALLOWUNRESTRICTEDAFR_DEFAULT                                 MCALLOWUNRESTRICTEDAFR_OFF


#define MCCOMPAT_STRING                                                "67207556"
#define MCCOMPAT_ID                                                    0x1095def8
#define MCCOMPAT_OVERINSTALL                                           0 // OVERRIDE
#define MCCOMPAT_AUTOSELECT                                            0x00000000
#define MCCOMPAT_ENABLE_SLI_AUTOSELECT                                 0x00000000
#define MCCOMPAT_FORCE_AFR                                             0x00000001
#define MCCOMPAT_FORCE_2AFR                                            0x00000001
#define MCCOMPAT_FORCE_2_AFR                                           0x00000001
#define MCCOMPAT_FORCE_SFR                                             0x00000002
#define MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_2AFR                       0x00000003
#define MCCOMPAT_DISABLE_SLI                                           0x00000004
#define MCCOMPAT_FORCE_SINGLE                                          0x00000004
#define MCCOMPAT_FORCE_4AFR                                            0x00000005
#define MCCOMPAT_FORCE_4_AFR                                           0x00000005
#define MCCOMPAT_FORCE_3AFR                                            0x00000006
#define MCCOMPAT_FORCE_3_AFR                                           0x00000006
#define MCCOMPAT_FORCE_AFR_OF_SFR__FALLBACK_3AFR                       0x00000007
#define MCCOMPAT_SLI_MODE_MASK                                         0x00000007
#define MCCOMPAT_RESERVED4                                             0x00000008
#define MCCOMPAT_STATIC_OR_WRITEONLY_VB_IN_HOST                        0x00000010
#define MCCOMPAT_LOCKABLE_TEXTURES_IN_HOST                             0x00000020
#define MCCOMPAT_RELEASE_GPU_FOR_CUDA                                  0x00000040
#define MCCOMPAT_IGNORE_TINY_LOCKS                                     0x00000080
#define MCCOMPAT_IGNORE_LOCK_ON_PRIMARY                                0x00000100
#define MCCOMPAT_IGNORE_PIXELQUERY                                     0x00000200
#define MCCOMPAT_AFR_DISCARD_TEXTURING_SYNC                            0x00000400
#define MCCOMPAT_APPBUG_FORCE_FLIPCHAIN_SYNC                           0x00000800
#define MCCOMPAT_LASTMINUTE_FIXES                                      0x00001000
#define MCCOMPAT_IGNORE_EVENTQUERY                                     0x00002000
#define MCCOMPAT_DISABLE_TEXTURE_PUSH                                  0x00004000
#define MCCOMPAT_LIMIT_EARLY_PUSH_UP_TO_MIDSIZE_SURFACES               0x00008000
#define MCCOMPAT_DISCARD_TEXTURING_SYNC_ON_ZB                          0x00010000
#define MCCOMPAT_AFR_DISCARD_SYNC_TEXTURE_LARGER_THAN_PRIMARY          0x00020000
#define MCCOMPAT_RESERVED19                                            0x00040000
#define MCCOMPAT_DISCARD_CONTENT_OF_CUBE_MIP_TEXTURES                  0x00080000
#define MCCOMPAT_AFR_DISCARD_ALL_BUT_TINY_TEXTURING_SYNC               0x00100000
#define MCCOMPAT_SFR_ON_TEXTURES                                       0x00200000
#define MCCOMPAT_DISCARD_RT_CONTENTS_ON_SRT                            0x00400000
#define MCCOMPAT_ASSUME_NOINTERFRAME_BLITS                             0x00800000
#define MCCOMPAT_LIMIT_EARLY_PUSH_TO_TINY_SURFACES_ONLY                0x01000000
#define MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT                    0x02000000
#define MCCOMPAT_AFR2_FLAGS                                            0x02400000
#define MCCOMPAT_FORCE_2_AFR2                                          0x02400001
#define MCCOMPAT_FORCE_3_AFR2                                          0x02400006
#define MCCOMPAT_FORCE_4_AFR2                                          0x02400005
#define MCCOMPAT_OPTIMAL                                               0x02400001
#define MCCOMPAT_DISCARD_RT_CONTENTS_ON_PARTIAL_SRT2                   0x04000000
#define MCCOMPAT_RESERVED27                                            0x08000000
#define MCCOMPAT_RESERVED28                                            0x10000000
#define MCCOMPAT_RESERVED29                                            0x20000000
#define MCCOMPAT_DISCARD_RT_CONTENTS_WHEN_BLENDING                     0x40000000
#define MCCOMPAT_OVERRIDE_BIT                                          0x80000000
#define MCCOMPAT_DEFAULT                                               MCCOMPAT_AUTOSELECT


#define MCSFRLOADBALANCE_STRING                                        "57567671"
#define MCSFRLOADBALANCE_ID                                            0x103c2e03
#define MCSFRLOADBALANCE_OVERINSTALL                                   0 // OVERRIDE
#define MCSFRLOADBALANCE_STATIC                                        0x28384382
#define MCSFRLOADBALANCE_DYNAMIC                                       0x60606064
#define MCSFRLOADBALANCE_DEFAULT                                       MCSFRLOADBALANCE_DYNAMIC


#define MCSFRSHOWSPLIT_STRING                                          "1ee11671"
#define MCSFRSHOWSPLIT_ID                                              0x10287051
#define MCSFRSHOWSPLIT_OVERINSTALL                                     0 // OVERRIDE
#define MCSFRSHOWSPLIT_DISABLED                                        0x34534064
#define MCSFRSHOWSPLIT_OFF                                             0x34534064
#define MCSFRSHOWSPLIT_ENABLED                                         0x24545582
#define MCSFRSHOWSPLIT_ON                                              0x24545582
#define MCSFRSHOWSPLIT_DEFAULT                                         MCSFRSHOWSPLIT_DISABLED


#define MCTIMELINE_STRING                                              "1671ee11"
#define MCTIMELINE_ID                                                  0x10de0e9f
#define MCTIMELINE_OVERINSTALL                                         0 // OVERRIDE
#define MCTIMELINE_OFF                                                 0x40345364
#define MCTIMELINE_DISABLED                                            0x40345364
#define MCTIMELINE_ON                                                  0x24545582
#define MCTIMELINE_ENABLED                                             0x24545582
#define MCTIMELINE_DEFAULT                                             MCTIMELINE_OFF


#define MESSAGE_BOX_ON_GPU_DISCONNECT_STRING                           "200205511"
#define MESSAGE_BOX_ON_GPU_DISCONNECT_ID                               0x10fadc95
#define MESSAGE_BOX_ON_GPU_DISCONNECT_OVERINSTALL                      0 // OVERRIDE
#define MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_SAFE_EXIT                   0x00000001
#define MESSAGE_BOX_ON_GPU_DISCONNECT_SHOW                             0x00000002
#define MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_NOEXIT                      0x00000004
#define MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_UNSAFE_EXIT                 0x00000008
#define MESSAGE_BOX_ON_GPU_DISCONNECT_DEFAULT                          MESSAGE_BOX_ON_GPU_DISCONNECT_HIDE_NOEXIT


#define MIPMAPMODE_STRING                                              "03385531"
#define MIPMAPMODE_ID                                                  0x10c73892
#define MIPMAPMODE_OVERINSTALL                                         0 // OVERRIDE
#define MIPMAPMODE_MASK                                                0x0000000f
#define MIPMAPMODE_NONE                                                0x00000000
#define MIPMAPMODE_BILINEAR                                            0x00000001
#define MIPMAPMODE_TRILINEAR                                           0x00000002
#define MIPMAPMODE_DEFAULT                                             MIPMAPMODE_NONE


#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_STRING            "200330308"
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ID                0x10fadc96
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_OVERINSTALL       1 // MERGE
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_DISABLED          0x0
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_OFF               0x0
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_0                 0x0
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_FALSE             0x0
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ENABLED           0x1
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ON                0x1
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_1                 0x1
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_TRUE              0x1
#define MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_DEFAULT           MSHYBRID_D3D12_PRESENT_FEATURE_OPTIMIZATIONS_ENABLED


#define MS_HYBRID_COPY_QUEUE_FLAGS_STRING                              "1242270"
#define MS_HYBRID_COPY_QUEUE_FLAGS_ID                                  0x10fadc83
#define MS_HYBRID_COPY_QUEUE_FLAGS_OVERINSTALL                         1 // MERGE
#define MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_3D               0x00000001
#define MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COMPUTE          0x00000002
#define MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COPY             0x00000004
#define MS_HYBRID_COPY_QUEUE_FLAGS_DEFAULT                             MS_HYBRID_COPY_QUEUE_FLAGS_COMMAND_QUEUE_FLAG_COPY


#define MULTIGPU_BROADCAST_SHIM_STRING                                 "54312267"
#define MULTIGPU_BROADCAST_SHIM_ID                                     0x108f0842
#define MULTIGPU_BROADCAST_SHIM_OVERINSTALL                            1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_OFF                                    0x00000000
#define MULTIGPU_BROADCAST_SHIM_DISABLED                               0x00000000
#define MULTIGPU_BROADCAST_SHIM_ON                                     0x00000001
#define MULTIGPU_BROADCAST_SHIM_ENABLED                                0x00000001
#define MULTIGPU_BROADCAST_SHIM_DEFAULT                                MULTIGPU_BROADCAST_SHIM_ON


#define MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME_STRING                   "54312270"
#define MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME_ID                       0x108f0845
#define MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME_OVERINSTALL              1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_DUMP_APP_NAME_DEFAULT                  ""


#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_STRING                 "54312269"
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_ID                     0x108f0844
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_OVERINSTALL            1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_OFF                    0x00000000
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_DISABLED               0x00000000
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_ON                     0x00000001
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_ENABLED                0x00000001
#define MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_DEFAULT                MULTIGPU_BROADCAST_SHIM_DUMP_BACKBUFFER_OFF


#define MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER_STRING               "54312271"
#define MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER_ID                   0x108f0846
#define MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER_OVERINSTALL          1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_DUMP_FRAME_NUMBER_DEFAULT              0x20


#define MULTIGPU_BROADCAST_SHIM_DUMP_PATH_STRING                       "54312272"
#define MULTIGPU_BROADCAST_SHIM_DUMP_PATH_ID                           0x108f0847
#define MULTIGPU_BROADCAST_SHIM_DUMP_PATH_OVERINSTALL                  1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_DUMP_PATH_DEFAULT                      "C:\\FD"


#define MULTIGPU_BROADCAST_SHIM_LOG_STRING                             "54312273"
#define MULTIGPU_BROADCAST_SHIM_LOG_ID                                 0x108f0848
#define MULTIGPU_BROADCAST_SHIM_LOG_OVERINSTALL                        1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_LOG_OFF                                0x00000000
#define MULTIGPU_BROADCAST_SHIM_LOG_DISABLED                           0x00000000
#define MULTIGPU_BROADCAST_SHIM_LOG_ON                                 0x00000001
#define MULTIGPU_BROADCAST_SHIM_LOG_ENABLED                            0x00000001
#define MULTIGPU_BROADCAST_SHIM_LOG_DEFAULT                            MULTIGPU_BROADCAST_SHIM_LOG_OFF


#define MULTIGPU_BROADCAST_SHIM_LOG_FILE_STRING                        "54312274"
#define MULTIGPU_BROADCAST_SHIM_LOG_FILE_ID                            0x108f0874
#define MULTIGPU_BROADCAST_SHIM_LOG_FILE_OVERINSTALL                   1 // MERGE
#define MULTIGPU_BROADCAST_SHIM_LOG_FILE_DEFAULT                       "C:\\log"


#define MULTIGPU_EOF_COPY_LOOP_STRING                                  "93284741"
#define MULTIGPU_EOF_COPY_LOOP_ID                                      0x10f9dc01
#define MULTIGPU_EOF_COPY_LOOP_OVERINSTALL                             0 // OVERRIDE
#define MULTIGPU_EOF_COPY_LOOP_DEFAULT                                 0x00000000


#define NGX_CDN_MODE_STRING                                            "11515748"
#define NGX_CDN_MODE_ID                                                0x10afb764
#define NGX_CDN_MODE_OVERINSTALL                                       0 // OVERRIDE
#define NGX_CDN_MODE_NGX_CDN_MODE_PRODUCTION                           0x0000
#define NGX_CDN_MODE_NGX_CDN_MODE_STAGING                              0x0001
#define NGX_CDN_MODE_NGX_CDN_MODE_DISABLED                             0xFFFF
#define NGX_CDN_MODE_DEFAULT                                           NGX_CDN_MODE_NGX_CDN_MODE_PRODUCTION


#define NGX_CDN_PRODUCTION_URI_STRING                                  "11515749"
#define NGX_CDN_PRODUCTION_URI_ID                                      0x10afb765
#define NGX_CDN_PRODUCTION_URI_OVERINSTALL                             0 // OVERRIDE
#define NGX_CDN_PRODUCTION_URI_DEFAULT                                 "https://static.nvidiagrid.net/models/org/nvidia/team/ngx/models/"


#define NGX_CDN_STAGING_URI_STRING                                     "11515750"
#define NGX_CDN_STAGING_URI_ID                                         0x10afb766
#define NGX_CDN_STAGING_URI_OVERINSTALL                                0 // OVERRIDE
#define NGX_CDN_STAGING_URI_DEFAULT                                    "https://static.nvidiagrid.net/stg-models/org/nvidia/team/ngx/models/"


#define NGX_DLSS_MODE_STRING                                           "11515752"
#define NGX_DLSS_MODE_ID                                               0x10afb768
#define NGX_DLSS_MODE_OVERINSTALL                                      0 // OVERRIDE
#define NGX_DLSS_MODE_NGX_DLSS_MODE_PERFORMANCE                        0x0000
#define NGX_DLSS_MODE_NGX_DLSS_MODE_BALANCED                           0x0001
#define NGX_DLSS_MODE_NGX_DLSS_MODE_QUALITY                            0x0002
#define NGX_DLSS_MODE_NGX_DLSS_MODE_SNIPPET_CONTROLLED                 0x0003
#define NGX_DLSS_MODE_DEFAULT                                          NGX_DLSS_MODE_NGX_DLSS_MODE_SNIPPET_CONTROLLED


#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_STRING                      "11515756"
#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_ID                          0x10afb76c
#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_OVERINSTALL                 0 // OVERRIDE
#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NONE 0x0000
#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_PERF_TO_9X 0x0001
#define NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_DEFAULT                     NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NGX_DLSS_OVERRIDE_OPTIMAL_SETTINGS_NONE


#define NGX_DLSS_SHARPNESS_SETTING_STRING                              "11515751"
#define NGX_DLSS_SHARPNESS_SETTING_ID                                  0x10afb767
#define NGX_DLSS_SHARPNESS_SETTING_OVERINSTALL                         0 // OVERRIDE
#define NGX_DLSS_SHARPNESS_SETTING_DEFAULT                             ""


#define NGX_DLSS_TYPE_STRING                                           "11515753"
#define NGX_DLSS_TYPE_ID                                               0x10afb769
#define NGX_DLSS_TYPE_OVERINSTALL                                      0 // OVERRIDE
#define NGX_DLSS_TYPE_NGX_DLSS_TYPE_DLTSS                              0x0000
#define NGX_DLSS_TYPE_NGX_DLSS_TYPE_NvTAA4x                            0x0001
#define NGX_DLSS_TYPE_DEFAULT                                          NGX_DLSS_TYPE_NGX_DLSS_TYPE_DLTSS


#define NGX_LOG_PATH_STRING                                            "11515755"
#define NGX_LOG_PATH_ID                                                0x10afb76b
#define NGX_LOG_PATH_OVERINSTALL                                       0 // OVERRIDE
#define NGX_LOG_PATH_DEFAULT                                           ""


#define NGX_OVERRIDE_HW_CHECK_STRING                                   "11515757"
#define NGX_OVERRIDE_HW_CHECK_ID                                       0x10e41df2
#define NGX_OVERRIDE_HW_CHECK_OVERINSTALL                              0 // OVERRIDE
#define NGX_OVERRIDE_HW_CHECK_OFF                                      0
#define NGX_OVERRIDE_HW_CHECK_DISABLED                                 0
#define NGX_OVERRIDE_HW_CHECK_ON                                       1
#define NGX_OVERRIDE_HW_CHECK_ENABLED                                  1
#define NGX_OVERRIDE_HW_CHECK_DEFAULT                                  NGX_OVERRIDE_HW_CHECK_OFF


#define NGX_PRIVATE_FLAGS_STRING                                       "11515754"
#define NGX_PRIVATE_FLAGS_ID                                           0x10afb76a
#define NGX_PRIVATE_FLAGS_OVERINSTALL                                  0 // OVERRIDE
#define NGX_PRIVATE_FLAGS_ENABLE_ZBC_TURING                            0x00000001
#define NGX_PRIVATE_FLAGS_ENABLE_ZBC_AMPERE                            0x00000002
#define NGX_PRIVATE_FLAGS_ENABLE_ZBC_AFTER_AMPERE                      0x00000004
#define NGX_PRIVATE_FLAGS_ENABLE_DVS_CYCLESTATS                        0x00000008
#define NGX_PRIVATE_FLAGS_ENABLE_DVS_PUSHBUFFER_DUMP                   0x00000010


#define NOFLOATMADENABLE_STRING                                        "19286545"
#define NOFLOATMADENABLE_ID                                            0x109f5848
#define NOFLOATMADENABLE_OVERINSTALL                                   0 // OVERRIDE
#define NOFLOATMADENABLE_OFF                                           0x16528890
#define NOFLOATMADENABLE_DISABLED                                      0x16528890
#define NOFLOATMADENABLE_ON                                            0x65481281
#define NOFLOATMADENABLE_ENABLED                                       0x65481281
#define NOFLOATMADENABLE_DEFAULT                                       NOFLOATMADENABLE_OFF


#define NVDEVTOOLS_ENABLE_DEBUGGER_STRING                              "20120516"
#define NVDEVTOOLS_ENABLE_DEBUGGER_ID                                  0x10b787c3
#define NVDEVTOOLS_ENABLE_DEBUGGER_OVERINSTALL                         0 // OVERRIDE
#define NVDEVTOOLS_ENABLE_DEBUGGER_OFF                                 0x00000000
#define NVDEVTOOLS_ENABLE_DEBUGGER_DISABLED                            0x00000000
#define NVDEVTOOLS_ENABLE_DEBUGGER_ON                                  0x00000001
#define NVDEVTOOLS_ENABLE_DEBUGGER_ENABLED                             0x00000001
#define NVDEVTOOLS_ENABLE_DEBUGGER_DEFAULT                             NVDEVTOOLS_ENABLE_DEBUGGER_OFF


#define NVFEATURES_ALLOW_STRING                                        "0xb135fe"
#define NVFEATURES_ALLOW_ID                                            0x10b135fe
#define NVFEATURES_ALLOW_OVERINSTALL                                   0 // OVERRIDE
#define NVFEATURES_ALLOW_DISALLOWED                                    0
#define NVFEATURES_ALLOW_OFF                                           0
#define NVFEATURES_ALLOW_DISABLED                                      0
#define NVFEATURES_ALLOW_ALLOWED                                       1
#define NVFEATURES_ALLOW_ON                                            1
#define NVFEATURES_ALLOW_ENABLED                                       1
#define NVFEATURES_ALLOW_DEFAULT                                       NVFEATURES_ALLOW_ALLOWED


#define NVINDICATOR_STRING                                             "1f42d4b3"
#define NVINDICATOR_ID                                                 0x10029ab8
#define NVINDICATOR_OVERINSTALL                                        0 // OVERRIDE
#define NVINDICATOR_OFF                                                0x0
#define NVINDICATOR_DISABLED                                           0x0
#define NVINDICATOR_ON                                                 0x1
#define NVINDICATOR_ENABLED                                            0x1
#define NVINDICATOR_DEFAULT                                            NVINDICATOR_OFF


#define NV_QUALITY_UPSCALING_STRING                                    "0x444444"
#define NV_QUALITY_UPSCALING_ID                                        0x10444444
#define NV_QUALITY_UPSCALING_OVERINSTALL                               1 // MERGE
#define NV_QUALITY_UPSCALING_OFF                                       0
#define NV_QUALITY_UPSCALING_DISABLED                                  0
#define NV_QUALITY_UPSCALING_ON                                        1
#define NV_QUALITY_UPSCALING_ENABLED                                   1
#define NV_QUALITY_UPSCALING_DEFAULT                                   NV_QUALITY_UPSCALING_OFF


#define OCGCONTROL_FP16_SUPPORT_STRING                                 "0xe0036b"
#define OCGCONTROL_FP16_SUPPORT_ID                                     0x10e0036b
#define OCGCONTROL_FP16_SUPPORT_OVERINSTALL                            0 // OVERRIDE
#define OCGCONTROL_FP16_SUPPORT_DISABLE                                0x00000000
#define OCGCONTROL_FP16_SUPPORT_ENABLE                                 0x00000001
#define OCGCONTROL_FP16_SUPPORT_DEFAULT                                OCGCONTROL_FP16_SUPPORT_ENABLE


#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_STRING                     "0x7b4428"
#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_ID                         0x107b4428
#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_OVERINSTALL                0 // OVERRIDE
#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_DISABLE                    0x00000000
#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_ENABLE                     0x00000001
#define OCGCONTROL_FP16_USE_FP32_CONVERTERS_DEFAULT                    OCGCONTROL_FP16_USE_FP32_CONVERTERS_ENABLE


#define OCGCONTROL_GS_STRING                                           "92809063"
#define OCGCONTROL_GS_ID                                               0x10550492
#define OCGCONTROL_GS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_GS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_GS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_GS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_GS_DEFAULT                                          0x00000003


#define OCGCONTROL_HS_STRING                                           "4189FAC3"
#define OCGCONTROL_HS_ID                                               0x10940f02
#define OCGCONTROL_HS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_HS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_HS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_HS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_HS_DEFAULT                                          0x00000003


#define OCGCONTROL_KNOBS_STRING_STRING                                 "CA345840"
#define OCGCONTROL_KNOBS_STRING_ID                                     0x10e107e0
#define OCGCONTROL_KNOBS_STRING_OVERINSTALL                            0 // OVERRIDE
#define OCGCONTROL_KNOBS_STRING_DEFAULT                                ""


#define OCGCONTROL_LATENCY_GS_STRING                                   "92809064"
#define OCGCONTROL_LATENCY_GS_ID                                       0x109bbccd
#define OCGCONTROL_LATENCY_GS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_GS_DEFAULT                                  0x00000003


#define OCGCONTROL_LATENCY_HS_STRING                                   "80772310"
#define OCGCONTROL_LATENCY_HS_ID                                       0x10fbcf49
#define OCGCONTROL_LATENCY_HS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_HS_DEFAULT                                  0x00000003


#define OCGCONTROL_LATENCY_MS_STRING                                   "A3AB0301"
#define OCGCONTROL_LATENCY_MS_ID                                       0x10a3ab03
#define OCGCONTROL_LATENCY_MS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_MS_DEFAULT                                  0x00000003


#define OCGCONTROL_LATENCY_MTS_STRING                                  "A3AB0201"
#define OCGCONTROL_LATENCY_MTS_ID                                      0x10a3ab02
#define OCGCONTROL_LATENCY_MTS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_LATENCY_MTS_DEFAULT                                 0x00000003


#define OCGCONTROL_LATENCY_PS_STRING                                   "92179064"
#define OCGCONTROL_LATENCY_PS_ID                                       0x104a6e33
#define OCGCONTROL_LATENCY_PS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_PS_DEFAULT                                  0x00000003


#define OCGCONTROL_LATENCY_TS_STRING                                   "800C2310"
#define OCGCONTROL_LATENCY_TS_ID                                       0x10a491a9
#define OCGCONTROL_LATENCY_TS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_TS_DEFAULT                                  0x00000003


#define OCGCONTROL_LATENCY_VS_STRING                                   "85612310"
#define OCGCONTROL_LATENCY_VS_ID                                       0x1010c152
#define OCGCONTROL_LATENCY_VS_OVERINSTALL                              0 // OVERRIDE
#define OCGCONTROL_LATENCY_VS_DEFAULT                                  0x00000003


#define OCGCONTROL_MAXINSTINBASICBLOCK_GS_STRING                       "62317182"
#define OCGCONTROL_MAXINSTINBASICBLOCK_GS_ID                           0x102d16ca
#define OCGCONTROL_MAXINSTINBASICBLOCK_GS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_GS_DEFAULT                      0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_HS_STRING                       "C023777F"
#define OCGCONTROL_MAXINSTINBASICBLOCK_HS_ID                           0x1041fa09
#define OCGCONTROL_MAXINSTINBASICBLOCK_HS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_HS_DEFAULT                      0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_MS_STRING                       "A3AB0901"
#define OCGCONTROL_MAXINSTINBASICBLOCK_MS_ID                           0x10a3ab09
#define OCGCONTROL_MAXINSTINBASICBLOCK_MS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_MS_DEFAULT                      0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_MTS_STRING                      "A3AB0801"
#define OCGCONTROL_MAXINSTINBASICBLOCK_MTS_ID                          0x10a3ab08
#define OCGCONTROL_MAXINSTINBASICBLOCK_MTS_OVERINSTALL                 0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_MTS_DEFAULT                     0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_PS_STRING                       "94812574"
#define OCGCONTROL_MAXINSTINBASICBLOCK_PS_ID                           0x10689da1
#define OCGCONTROL_MAXINSTINBASICBLOCK_PS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_PS_DEFAULT                      0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_TS_STRING                       "A7044887"
#define OCGCONTROL_MAXINSTINBASICBLOCK_TS_ID                           0x1093f019
#define OCGCONTROL_MAXINSTINBASICBLOCK_TS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_TS_DEFAULT                      0x00000000


#define OCGCONTROL_MAXINSTINBASICBLOCK_VS_STRING                       "80546710"
#define OCGCONTROL_MAXINSTINBASICBLOCK_VS_ID                           0x100af0f1
#define OCGCONTROL_MAXINSTINBASICBLOCK_VS_OVERINSTALL                  0 // OVERRIDE
#define OCGCONTROL_MAXINSTINBASICBLOCK_VS_DEFAULT                      0x00000000


#define OCGCONTROL_MS_STRING                                           "A3AB0101"
#define OCGCONTROL_MS_ID                                               0x10a3ab01
#define OCGCONTROL_MS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_MS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_MS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_MS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_MS_DEFAULT                                          0x00000003


#define OCGCONTROL_MTS_STRING                                          "A3AB0001"
#define OCGCONTROL_MTS_ID                                              0x10a3ab00
#define OCGCONTROL_MTS_OVERINSTALL                                     0 // OVERRIDE
#define OCGCONTROL_MTS_OCG_ENABLE                                      0x00000001
#define OCGCONTROL_MTS_OCG_BRANCH_OPT                                  0x00000002
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_ENABLE                      0x00000008
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_MASK                        0x00000030
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O0                          0x00000000
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O1                          0x00000010
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O2                          0x00000020
#define OCGCONTROL_MTS_OCG_OPT_FORCE_LEVEL_O3                          0x00000030
#define OCGCONTROL_MTS_DEFAULT                                         0x00000003


#define OCGCONTROL_ORI_STRING                                          "92350358"
#define OCGCONTROL_ORI_ID                                              0x10c209bb
#define OCGCONTROL_ORI_OVERINSTALL                                     0 // OVERRIDE
#define OCGCONTROL_ORI_DEFAULT                                         0x00000000


#define OCGCONTROL_PS_STRING                                           "92179063"
#define OCGCONTROL_PS_ID                                               0x10c64d06
#define OCGCONTROL_PS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_PS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_PS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_PS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_PS_DEFAULT                                          0x00000003


#define OCGCONTROL_TEXBATCH_GS_STRING                                  "92809065"
#define OCGCONTROL_TEXBATCH_GS_ID                                      0x10109bc3
#define OCGCONTROL_TEXBATCH_GS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_GS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXBATCH_HS_STRING                                  "9F279065"
#define OCGCONTROL_TEXBATCH_HS_ID                                      0x106ff684
#define OCGCONTROL_TEXBATCH_HS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_HS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXBATCH_MS_STRING                                  "A3AB0501"
#define OCGCONTROL_TEXBATCH_MS_ID                                      0x10a3ab05
#define OCGCONTROL_TEXBATCH_MS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_MS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXBATCH_MTS_STRING                                 "A3AB0401"
#define OCGCONTROL_TEXBATCH_MTS_ID                                     0x10a3ab04
#define OCGCONTROL_TEXBATCH_MTS_OVERINSTALL                            0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_MTS_DEFAULT                                0x00000000


#define OCGCONTROL_TEXBATCH_PS_STRING                                  "92179065"
#define OCGCONTROL_TEXBATCH_PS_ID                                      0x10385209
#define OCGCONTROL_TEXBATCH_PS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_PS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXBATCH_TS_STRING                                  "9AA29065"
#define OCGCONTROL_TEXBATCH_TS_ID                                      0x1058199d
#define OCGCONTROL_TEXBATCH_TS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_TS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXBATCH_VS_STRING                                  "85612311"
#define OCGCONTROL_TEXBATCH_VS_ID                                      0x10f75a0a
#define OCGCONTROL_TEXBATCH_VS_OVERINSTALL                             0 // OVERRIDE
#define OCGCONTROL_TEXBATCH_VS_DEFAULT                                 0x00000000


#define OCGCONTROL_TEXMINPHASE_GS_STRING                               "92809066"
#define OCGCONTROL_TEXMINPHASE_GS_ID                                   0x107a30b3
#define OCGCONTROL_TEXMINPHASE_GS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_GS_DEFAULT                              0x00000000


#define OCGCONTROL_TEXMINPHASE_HS_STRING                               "17AA230C"
#define OCGCONTROL_TEXMINPHASE_HS_ID                                   0x10f54313
#define OCGCONTROL_TEXMINPHASE_HS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_HS_DEFAULT                              0x00000000


#define OCGCONTROL_TEXMINPHASE_MS_STRING                               "A3AB0701"
#define OCGCONTROL_TEXMINPHASE_MS_ID                                   0x10a3ab07
#define OCGCONTROL_TEXMINPHASE_MS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_MS_DEFAULT                              0x00000000


#define OCGCONTROL_TEXMINPHASE_MTS_STRING                              "A3AB0601"
#define OCGCONTROL_TEXMINPHASE_MTS_ID                                  0x10a3ab06
#define OCGCONTROL_TEXMINPHASE_MTS_OVERINSTALL                         0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_MTS_DEFAULT                             0x00000000


#define OCGCONTROL_TEXMINPHASE_PS_STRING                               "92179066"
#define OCGCONTROL_TEXMINPHASE_PS_ID                                   0x10421fb3
#define OCGCONTROL_TEXMINPHASE_PS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_PS_DEFAULT                              0x00000000


#define OCGCONTROL_TEXMINPHASE_TS_STRING                               "4889AC02"
#define OCGCONTROL_TEXMINPHASE_TS_ID                                   0x109ad328
#define OCGCONTROL_TEXMINPHASE_TS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_TS_DEFAULT                              0x00000000


#define OCGCONTROL_TEXMINPHASE_VS_STRING                               "85612312"
#define OCGCONTROL_TEXMINPHASE_VS_ID                                   0x10ead8d9
#define OCGCONTROL_TEXMINPHASE_VS_OVERINSTALL                          0 // OVERRIDE
#define OCGCONTROL_TEXMINPHASE_VS_DEFAULT                              0x00000000


#define OCGCONTROL_TS_STRING                                           "A7149200"
#define OCGCONTROL_TS_ID                                               0x10661a36
#define OCGCONTROL_TS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_TS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_TS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_TS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_TS_DEFAULT                                          0x00000003


#define OCGCONTROL_TXDBATCHSIZE_PS_STRING                              "56196962"
#define OCGCONTROL_TXDBATCHSIZE_PS_ID                                  0x10fc0cb9
#define OCGCONTROL_TXDBATCHSIZE_PS_OVERINSTALL                         0 // OVERRIDE
#define OCGCONTROL_TXDBATCHSIZE_PS_DEFAULT                             0x00000002


#define OCGCONTROL_VS_STRING                                           "85612309"
#define OCGCONTROL_VS_ID                                               0x10bad271
#define OCGCONTROL_VS_OVERINSTALL                                      0 // OVERRIDE
#define OCGCONTROL_VS_OCG_ENABLE                                       0x00000001
#define OCGCONTROL_VS_OCG_BRANCH_OPT                                   0x00000002
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_ENABLE                       0x00000008
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_MASK                         0x00000030
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O0                           0x00000000
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O1                           0x00000010
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O2                           0x00000020
#define OCGCONTROL_VS_OCG_OPT_FORCE_LEVEL_O3                           0x00000030
#define OCGCONTROL_VS_DEFAULT                                          0x00000003


#define OPTIMUS_DEBUG_STRING                                           "93284751"
#define OPTIMUS_DEBUG_ID                                               0x10f9dc03
#define OPTIMUS_DEBUG_OVERINSTALL                                      0 // OVERRIDE
#define OPTIMUS_DEBUG_NULL_RENDER_TRANSPORT                            0x00000001
#define OPTIMUS_DEBUG_NULL_DISPLAY_TRANSPORT                           0x00000002
#define OPTIMUS_DEBUG_DISABLE_CE_USAGE                                 0x00000004
#define OPTIMUS_DEBUG_DETECT_FRONT_BUFFER_RENDERING_MISSING_SYNC       0x00000008
#define OPTIMUS_DEBUG_DEFAULT                                          0


#define OPTIMUS_HCLONE_STRING                                          "42429123"
#define OPTIMUS_HCLONE_ID                                              0x10f9ae81
#define OPTIMUS_HCLONE_OVERINSTALL                                     0 // OVERRIDE
#define OPTIMUS_HCLONE_ALLOWED                                         0x00000001
#define OPTIMUS_HCLONE_ENABLED                                         0x00000002
#define OPTIMUS_HCLONE_DEFAULT                                         0


#define OPTIMUS_MAXAA_STRING                                           "52180886"
#define OPTIMUS_MAXAA_ID                                               0x10f9dc83
#define OPTIMUS_MAXAA_OVERINSTALL                                      0 // OVERRIDE
#define OPTIMUS_MAXAA_MIN                                              0
#define OPTIMUS_MAXAA_MAX                                              16
#define OPTIMUS_MAXAA_DEFAULT                                          0


#define PASCAL_SCG_COMPUTE1_MIN_SM_COUNT_STRING                        "0xb134ff"
#define PASCAL_SCG_COMPUTE1_MIN_SM_COUNT_ID                            0x10b134ff
#define PASCAL_SCG_COMPUTE1_MIN_SM_COUNT_OVERINSTALL                   0 // OVERRIDE
#define PASCAL_SCG_COMPUTE1_MIN_SM_COUNT_DEFAULT                       0


#define PASCAL_SCG_COMPUTE1_SM_FACTOR_STRING                           "0x234098"
#define PASCAL_SCG_COMPUTE1_SM_FACTOR_ID                               0x10234098
#define PASCAL_SCG_COMPUTE1_SM_FACTOR_OVERINSTALL                      0 // OVERRIDE
#define PASCAL_SCG_COMPUTE1_SM_FACTOR_DEFAULT                          0.6f


#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_STRING              "0xb134fe"
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ID                  0x10b134fe
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_OVERINSTALL         0 // OVERRIDE
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_OFF                 0
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_DISABLED            0
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ON                  1
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ENABLED             1
#define PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_DEFAULT             PASCAL_SCG_USE_ALL_SMS_IN_ALL_COMPUTE_MODE_ON


#define PERF_TESLA_UNIT_SELECTION_STRING                               "505365c"
#define PERF_TESLA_UNIT_SELECTION_ID                                   0x10dc2830
#define PERF_TESLA_UNIT_SELECTION_OVERINSTALL                          0 // OVERRIDE
#define PERF_TESLA_UNIT_SELECTION_TPC_MASK                             0x000000ff
#define PERF_TESLA_UNIT_SELECTION_ROP_MASK                             0x0000ff00
#define PERF_TESLA_UNIT_SELECTION_FIRST_SM_MASK                        0x000f0000
#define PERF_TESLA_UNIT_SELECTION_LAST_SM_MASK                         0x00f00000
#define PERF_TESLA_UNIT_SELECTION_DEFAULT                              0x00000000


#define PHYSXINDICATOR_STRING                                          "73304097"
#define PHYSXINDICATOR_ID                                              0x1094f16f
#define PHYSXINDICATOR_OVERINSTALL                                     0 // OVERRIDE
#define PHYSXINDICATOR_DISABLED                                        0x34534064
#define PHYSXINDICATOR_OFF                                             0x34534064
#define PHYSXINDICATOR_ENABLED                                         0x24545582
#define PHYSXINDICATOR_ON                                              0x24545582
#define PHYSXINDICATOR_DEFAULT                                         PHYSXINDICATOR_DISABLED


#define PHYSX_APPLICATION_STRING                                       "30170611"
#define PHYSX_APPLICATION_ID                                           0x10e3293a
#define PHYSX_APPLICATION_OVERINSTALL                                  0 // OVERRIDE
#define PHYSX_APPLICATION_OFF                                          0x0
#define PHYSX_APPLICATION_DISABLED                                     0x0
#define PHYSX_APPLICATION_NO                                           0x0
#define PHYSX_APPLICATION_ON                                           0x1
#define PHYSX_APPLICATION_ENABLED                                      0x1
#define PHYSX_APPLICATION_YES                                          0x1
#define PHYSX_APPLICATION_DEFAULT                                      PHYSX_APPLICATION_OFF


#define PREFERRED_PSTATE_STRING                                        "12039265"
#define PREFERRED_PSTATE_ID                                            0x1057eb71
#define PREFERRED_PSTATE_OVERINSTALL                                   1 // MERGE
#define PREFERRED_PSTATE_ADAPTIVE                                      0x00000000
#define PREFERRED_PSTATE_PREFER_MAX                                    0x00000001
#define PREFERRED_PSTATE_DRIVER_CONTROLLED                             0x00000002
#define PREFERRED_PSTATE_PREFER_CONSISTENT_PERFORMANCE                 0x00000003
#define PREFERRED_PSTATE_PREFER_MIN                                    0x00000004
#define PREFERRED_PSTATE_OPTIMAL_POWER                                 0x00000005
#define PREFERRED_PSTATE_MIN                                           0x00000000
#define PREFERRED_PSTATE_MAX                                           0x00000005
#define PREFERRED_PSTATE_DEFAULT                                       PREFERRED_PSTATE_OPTIMAL_POWER
#define PREFERRED_PSTATE_DEFAULT_GL                                    PREFERRED_PSTATE_DRIVER_CONTROLLED


#define PREVENT_UI_AF_OVERRIDE_STRING                                  "AfOverride"
#define PREVENT_UI_AF_OVERRIDE_ID                                      0x103bccb5
#define PREVENT_UI_AF_OVERRIDE_OVERINSTALL                             0 // OVERRIDE
#define PREVENT_UI_AF_OVERRIDE_OFF                                     0
#define PREVENT_UI_AF_OVERRIDE_DISABLED                                0
#define PREVENT_UI_AF_OVERRIDE_ON                                      1
#define PREVENT_UI_AF_OVERRIDE_ENABLED                                 1
#define PREVENT_UI_AF_OVERRIDE_DEFAULT                                 PREVENT_UI_AF_OVERRIDE_OFF


#define PS_ALPHABETA_STRING                                            "39867584"
#define PS_ALPHABETA_ID                                                0x106044ce
#define PS_ALPHABETA_OVERINSTALL                                       0 // OVERRIDE
#define PS_ALPHABETA_STATIC                                            0x00000000
#define PS_ALPHABETA_DYNAMIC_SHADER                                    0x00000001
#define PS_ALPHABETA_DYNAMIC_VBIB                                      0x00000002
#define PS_ALPHABETA_DEFAULT                                           PS_ALPHABETA_STATIC


#define PS_ALPHABETA_FRACTION_STRING                                   "49867584"
#define PS_ALPHABETA_FRACTION_ID                                       0x10842563
#define PS_ALPHABETA_FRACTION_OVERINSTALL                              0 // OVERRIDE
#define PS_ALPHABETA_FRACTION_MIN                                      0x00000000
#define PS_ALPHABETA_FRACTION_MAX                                      0x000000ff
#define PS_ALPHABETA_FRACTION_DEFAULT                                  63


#define PS_ALPHABETA_STATS_STRING                                      "56418352"
#define PS_ALPHABETA_STATS_ID                                          0x10768dd3
#define PS_ALPHABETA_STATS_OVERINSTALL                                 0 // OVERRIDE
#define PS_ALPHABETA_STATS_OFF                                         0x00000000
#define PS_ALPHABETA_STATS_DISABLED                                    0x00000000
#define PS_ALPHABETA_STATS_ON                                          0x00000001
#define PS_ALPHABETA_STATS_ENABLED                                     0x00000001


#define PS_APPSHADEROPT_CANIGNOREINF_STRING                            "6af9fa3f"
#define PS_APPSHADEROPT_CANIGNOREINF_ID                                0x1078d9c8
#define PS_APPSHADEROPT_CANIGNOREINF_OVERINSTALL                       0 // OVERRIDE
#define PS_APPSHADEROPT_CANIGNOREINF_OFF                               0x97395a35
#define PS_APPSHADEROPT_CANIGNOREINF_DISABLED                          0x97395a35
#define PS_APPSHADEROPT_CANIGNOREINF_ON                                0xde325a38
#define PS_APPSHADEROPT_CANIGNOREINF_ENABLED                           0xde325a38
#define PS_APPSHADEROPT_CANIGNOREINF_DEFAULT                           PS_APPSHADEROPT_CANIGNOREINF_OFF


#define PS_APPSHADEROPT_CANIGNORENAN_STRING                            "6af9fa2f"
#define PS_APPSHADEROPT_CANIGNORENAN_ID                                0x1078d9a8
#define PS_APPSHADEROPT_CANIGNORENAN_OVERINSTALL                       0 // OVERRIDE
#define PS_APPSHADEROPT_CANIGNORENAN_OFF                               0x97395a35
#define PS_APPSHADEROPT_CANIGNORENAN_DISABLED                          0x97395a35
#define PS_APPSHADEROPT_CANIGNORENAN_ON                                0xde325a38
#define PS_APPSHADEROPT_CANIGNORENAN_ENABLED                           0xde325a38
#define PS_APPSHADEROPT_CANIGNORENAN_DEFAULT                           PS_APPSHADEROPT_CANIGNORENAN_OFF


#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_STRING                     "6af9fa4f"
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_ID                         0x1078d9d8
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_OVERINSTALL                0 // OVERRIDE
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_OFF                        0x97395a35
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_DISABLED                   0x97395a35
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_ON                         0xde325a38
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_ENABLED                    0xde325a38
#define PS_APPSHADEROPT_CANIGNORESIGNEDZERO_DEFAULT                    PS_APPSHADEROPT_CANIGNORESIGNEDZERO_OFF


#define PS_CYCLESTATS_STRING                                           "87f6275666"
#define PS_CYCLESTATS_ID                                               0x10f36127
#define PS_CYCLESTATS_OVERINSTALL                                      0 // OVERRIDE
#define PS_CYCLESTATS_OFF                                              0x00000000
#define PS_CYCLESTATS_DISABLED                                         0x00000000
#define PS_CYCLESTATS_ON                                               0x00000001
#define PS_CYCLESTATS_ENABLED                                          0x00000001


#define PS_CYCLESTATS_BUCKET_FLAGS_STRING                              "97f727566e"
#define PS_CYCLESTATS_BUCKET_FLAGS_ID                                  0x10c5c18e
#define PS_CYCLESTATS_BUCKET_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_MASK                     0x0000000f
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_API_CALL                 0x00000000
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SAME_STATE               0x00000001
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_SEGMENT                  0x00000002
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_CMDBUF                   0x00000003
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_FRAME                    0x00000004
#define PS_CYCLESTATS_BUCKET_FLAGS_OUTER_MODE_START_END                0x00000005
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_MASK                     0x000f0000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_API_CALL                 0x00000000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SAME_STATE               0x00010000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_SEGMENT                  0x00020000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_CMDBUF                   0x00030000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_FRAME                    0x00040000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_MODE_START_END                0x00050000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_MASK                  0x00f00000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_NONE                  0x00000000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIG                0x00100000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_PM_MODE_PMTRIGEND             0x00200000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_MASK                 0x0f000000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_NONE                 0x00000000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_GPUIDLE              0x01000000
#define PS_CYCLESTATS_BUCKET_FLAGS_INNER_WFI_MODE_ALWAYS               0x02000000
#define PS_CYCLESTATS_BUCKET_FLAGS_SEPARATE_REPLAYER_STATE             0x10000000


#define PS_CYCLESTATS_CAPTURE_FLAGS_STRING                             "97f627566e"
#define PS_CYCLESTATS_CAPTURE_FLAGS_ID                                 0x10cc518e
#define PS_CYCLESTATS_CAPTURE_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_BUCKET_COUNT               0x00000001
#define PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_PER_FRAME_DATA             0x00000002
#define PS_CYCLESTATS_CAPTURE_FLAGS_CAPTURE_MERGED_STATE               0x00000004
#define PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_BOOKMARKS                 0x00000100
#define PS_CYCLESTATS_CAPTURE_FLAGS_GENERATE_ENCODED_PMTRIGGERID       0x00000200
#define PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_GPUIDLE_BUCKETS               0x00001000
#define PS_CYCLESTATS_CAPTURE_FLAGS_HIDE_REPLAYER_BUCKETS              0x00002000
#define PS_CYCLESTATS_CAPTURE_FLAGS_USE_PTIMER_TIMEBASE                0x00008000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_MASK               0x00ff0000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_DISABLED           0x00000000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_1K                 0x00010000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_2K                 0x00020000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_4K                 0x00030000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_8K                 0x00040000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_16K                0x00050000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_32K                0x00060000
#define PS_CYCLESTATS_CAPTURE_FLAGS_TIMEBASE_CYCLES_64K                0x00070000
#define PS_CYCLESTATS_CAPTURE_FLAGS_USE_LARGE_CAPTURE_BUFFER           0x01000000
#define PS_CYCLESTATS_CAPTURE_FLAGS_PROCESS_SNAPSHOTS_AT_END           0x02000000
#define PS_CYCLESTATS_CAPTURE_FLAGS_AUTOEXIT_AT_END_FRAME              0x10000000


#define PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG_STRING                      "97f6275680"
#define PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG_ID                          0x107f047d
#define PS_CYCLESTATS_COMMAND_QUEUE_TO_LOG_OVERINSTALL                 0 // OVERRIDE


#define PS_CYCLESTATS_DEVICE_TO_LOG_STRING                             "97f6275670"
#define PS_CYCLESTATS_DEVICE_TO_LOG_ID                                 0x106f047d
#define PS_CYCLESTATS_DEVICE_TO_LOG_OVERINSTALL                        0 // OVERRIDE


#define PS_CYCLESTATS_DIRECTORY_STRING                                 "97f627566b"
#define PS_CYCLESTATS_DIRECTORY_ID                                     0x1092404a
#define PS_CYCLESTATS_DIRECTORY_OVERINSTALL                            0 // OVERRIDE


#define PS_CYCLESTATS_DX12_TAGS_HACK_STRING                            "01648913"
#define PS_CYCLESTATS_DX12_TAGS_HACK_ID                                0x102c8747
#define PS_CYCLESTATS_DX12_TAGS_HACK_OVERINSTALL                       0 // OVERRIDE
#define PS_CYCLESTATS_DX12_TAGS_HACK_OFF                               0x00000000
#define PS_CYCLESTATS_DX12_TAGS_HACK_DISABLED                          0x00000000
#define PS_CYCLESTATS_DX12_TAGS_HACK_ON                                0x00000001
#define PS_CYCLESTATS_DX12_TAGS_HACK_ENABLED                           0x00000001
#define PS_CYCLESTATS_DX12_TAGS_HACK_DEFAULT                           PS_CYCLESTATS_DX12_TAGS_HACK_OFF


#define PS_CYCLESTATS_END_FRAME_STRING                                 "97f6275669"
#define PS_CYCLESTATS_END_FRAME_ID                                     0x106f045d
#define PS_CYCLESTATS_END_FRAME_OVERINSTALL                            0 // OVERRIDE


#define PS_CYCLESTATS_FLAGS_STRING                                     "97f6275666"
#define PS_CYCLESTATS_FLAGS_ID                                         0x10af471b
#define PS_CYCLESTATS_FLAGS_OVERINSTALL                                0 // OVERRIDE
#define PS_CYCLESTATS_FLAGS_TAGS                                       0x00000001
#define PS_CYCLESTATS_FLAGS_RT                                         0x00000002
#define PS_CYCLESTATS_FLAGS_PSHADER                                    0x00000004
#define PS_CYCLESTATS_FLAGS_VSHADER                                    0x00000008
#define PS_CYCLESTATS_FLAGS_FOG                                        0x00000010
#define PS_CYCLESTATS_FLAGS_COLORWRITE                                 0x00000020
#define PS_CYCLESTATS_FLAGS_DEPTHTEST                                  0x00000040
#define PS_CYCLESTATS_FLAGS_ALPHATEST                                  0x00000080
#define PS_CYCLESTATS_FLAGS_STENCILENABLE                              0x00000100
#define PS_CYCLESTATS_FLAGS_CLIPPLANE                                  0x00000200
#define PS_CYCLESTATS_FLAGS_VB_TYPE                                    0x00000400
#define PS_CYCLESTATS_FLAGS_TEXTURE                                    0x00000800
#define PS_CYCLESTATS_FLAGS_LIGHTING                                   0x00001000
#define PS_CYCLESTATS_FLAGS_BLEND                                      0x00002000
#define PS_CYCLESTATS_FLAGS_GSHADER                                    0x00004000
#define PS_CYCLESTATS_FLAGS_STREAMOUT                                  0x00008000
#define PS_CYCLESTATS_FLAGS_RES_HANDLE                                 0x00010000
#define PS_CYCLESTATS_FLAGS_CULL                                       0x00020000
#define PS_CYCLESTATS_FLAGS_PERFSTRAT                                  0x00040000
#define PS_CYCLESTATS_FLAGS_IB_TYPE                                    0x00080000
#define PS_CYCLESTATS_FLAGS_PRIM_TYPE                                  0x00100000
#define PS_CYCLESTATS_FLAGS_MINIMIZE_RT                                0x00200000
#define PS_CYCLESTATS_FLAGS_API_STATE                                  0x00400000
#define PS_CYCLESTATS_FLAGS_POLYGON                                    0x00800000
#define PS_CYCLESTATS_FLAGS_QUERIES                                    0x04000000
#define PS_CYCLESTATS_FLAGS_APPSTATE                                   0x08000000
#define PS_CYCLESTATS_FLAGS_TESS                                       0x10000000
#define PS_CYCLESTATS_FLAGS_COMPUTE                                    0x20000000
#define PS_CYCLESTATS_FLAGS_DRIVERSTATE                                0x40000000
#define PS_CYCLESTATS_FLAGS_BUCKET_COUNT                               0x02000000
#define PS_CYCLESTATS_FLAGS_PER_FRAME_DATA                             0x80000000


#define PS_CYCLESTATS_FLAGS2_STRING                                    "97f627566a"
#define PS_CYCLESTATS_FLAGS2_ID                                        0x100bb035
#define PS_CYCLESTATS_FLAGS2_OVERINSTALL                               0 // OVERRIDE
#define PS_CYCLESTATS_FLAGS2_RT                                        0x00000001
#define PS_CYCLESTATS_FLAGS2_EARLYZ                                    0x00000002
#define PS_CYCLESTATS_FLAGS2_ZCULL                                     0x00000004
#define PS_CYCLESTATS_FLAGS2_IDX                                       0x00000008
#define PS_CYCLESTATS_FLAGS2_VSHADER                                   0x00000010
#define PS_CYCLESTATS_FLAGS2_GSHADER                                   0x00000020
#define PS_CYCLESTATS_FLAGS2_PSHADER                                   0x00000040
#define PS_CYCLESTATS_FLAGS2_TEXHEADER                                 0x00000100
#define PS_CYCLESTATS_FLAGS2_TEXSAMPLER                                0x00000200
#define PS_CYCLESTATS_FLAGS2_ALPHA_TEST                                0x00001000
#define PS_CYCLESTATS_FLAGS2_DEPTH_TEST                                0x00002000
#define PS_CYCLESTATS_FLAGS2_STENCIL_TEST                              0x00004000
#define PS_CYCLESTATS_FLAGS2_POLYGON_OFFSET                            0x00010000
#define PS_CYCLESTATS_FLAGS2_CULL                                      0x00020000
#define PS_CYCLESTATS_FLAGS2_POINTSPRITE                               0x00040000
#define PS_CYCLESTATS_FLAGS2_BLEND                                     0x00080000
#define PS_CYCLESTATS_FLAGS2_USERCLIP                                  0x00100000
#define PS_CYCLESTATS_FLAGS2_STREAMOUT                                 0x00200000
#define PS_CYCLESTATS_FLAGS2_PEEK_AT_DRV_MASKS                         0x04000000
#define PS_CYCLESTATS_FLAGS2_PTE_TRAVERSAL                             0x08000000
#define PS_CYCLESTATS_FLAGS2_NO_TILEDREGION                            0x10000000
#define PS_CYCLESTATS_FLAGS2_NO_ZCULL_DETAILS                          0x20000000
#define PS_CYCLESTATS_FLAGS2_NO_PTE_COUNTS                             0x40000000


#define PS_CYCLESTATS_GPU_TO_LOG_STRING                                "97f6275672"
#define PS_CYCLESTATS_GPU_TO_LOG_ID                                    0x106f047f
#define PS_CYCLESTATS_GPU_TO_LOG_OVERINSTALL                           0 // OVERRIDE


#define PS_CYCLESTATS_HOTKEY_STRING                                    "01648912"
#define PS_CYCLESTATS_HOTKEY_ID                                        0x102c8746
#define PS_CYCLESTATS_HOTKEY_OVERINSTALL                               0 // OVERRIDE
#define PS_CYCLESTATS_HOTKEY_DEFAULT                                   0x75


#define PS_CYCLESTATS_LAUNCH_FLAGS_STRING                              "a766215670"
#define PS_CYCLESTATS_LAUNCH_FLAGS_ID                                  0x106c51f0
#define PS_CYCLESTATS_LAUNCH_FLAGS_OVERINSTALL                         0 // OVERRIDE
#define PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_DEFER_INIT                   0x00000001
#define PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_DWM                     0x00000002
#define PS_CYCLESTATS_LAUNCH_FLAGS_DO_NOT_INIT                         0x00000004
#define PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_COMPUTE_ONLY                 0x00000008
#define PS_CYCLESTATS_LAUNCH_FLAGS_IGNORE_NON_COMPUTE_ONLY             0x00000010
#define PS_CYCLESTATS_LAUNCH_FLAGS_DONT_IGNORE_METRO_APPS              0x00000020


#define PS_CYCLESTATS_MAX_APP_REGIME_DEPTH_STRING                      "97f6275487"
#define PS_CYCLESTATS_MAX_APP_REGIME_DEPTH_ID                          0x10f68487
#define PS_CYCLESTATS_MAX_APP_REGIME_DEPTH_OVERINSTALL                 0 // OVERRIDE


#define PS_CYCLESTATS_MERGE_FLAGS_STRING                               "97f627566d"
#define PS_CYCLESTATS_MERGE_FLAGS_ID                                   0x105bbe5a
#define PS_CYCLESTATS_MERGE_FLAGS_OVERINSTALL                          0 // OVERRIDE
#define PS_CYCLESTATS_MERGE_FLAGS_TAGS                                 0x00000001
#define PS_CYCLESTATS_MERGE_FLAGS_RT                                   0x00000002
#define PS_CYCLESTATS_MERGE_FLAGS_PSHADER                              0x00000004
#define PS_CYCLESTATS_MERGE_FLAGS_VSHADER                              0x00000008
#define PS_CYCLESTATS_MERGE_FLAGS_FOG                                  0x00000010
#define PS_CYCLESTATS_MERGE_FLAGS_COLORWRITE                           0x00000020
#define PS_CYCLESTATS_MERGE_FLAGS_DEPTHTEST                            0x00000040
#define PS_CYCLESTATS_MERGE_FLAGS_ALPHATEST                            0x00000080
#define PS_CYCLESTATS_MERGE_FLAGS_STENCILENABLE                        0x00000100
#define PS_CYCLESTATS_MERGE_FLAGS_CLIPPLANE                            0x00000200
#define PS_CYCLESTATS_MERGE_FLAGS_VB_TYPE                              0x00000400
#define PS_CYCLESTATS_MERGE_FLAGS_TEXTURE                              0x00000800
#define PS_CYCLESTATS_MERGE_FLAGS_LIGHTING                             0x00001000
#define PS_CYCLESTATS_MERGE_FLAGS_BLEND                                0x00002000
#define PS_CYCLESTATS_MERGE_FLAGS_GSHADER                              0x00004000
#define PS_CYCLESTATS_MERGE_FLAGS_STREAMOUT                            0x00008000
#define PS_CYCLESTATS_MERGE_FLAGS_RES_HANDLE                           0x00010000
#define PS_CYCLESTATS_MERGE_FLAGS_CULL                                 0x00020000
#define PS_CYCLESTATS_MERGE_FLAGS_PERFSTRAT                            0x00040000
#define PS_CYCLESTATS_MERGE_FLAGS_IB_TYPE                              0x00080000
#define PS_CYCLESTATS_MERGE_FLAGS_PRIM_TYPE                            0x00100000
#define PS_CYCLESTATS_MERGE_FLAGS_DISPATCH_TYPE                        0x00200000
#define PS_CYCLESTATS_MERGE_FLAGS_API_ARGS                             0x00400000
#define PS_CYCLESTATS_MERGE_FLAGS_POLYGON                              0x00800000
#define PS_CYCLESTATS_MERGE_FLAGS_QUERIES                              0x04000000
#define PS_CYCLESTATS_MERGE_FLAGS_APPSTATE                             0x08000000
#define PS_CYCLESTATS_MERGE_FLAGS_TESS                                 0x10000000
#define PS_CYCLESTATS_MERGE_FLAGS_COMPUTE                              0x20000000
#define PS_CYCLESTATS_MERGE_FLAGS_DRIVERSTATE                          0x40000000


#define PS_CYCLESTATS_PM_CONFIG_STRING                                 "b7f6275666"
#define PS_CYCLESTATS_PM_CONFIG_ID                                     0x10ec5979
#define PS_CYCLESTATS_PM_CONFIG_OVERINSTALL                            0 // OVERRIDE


#define PS_CYCLESTATS_PROCESS_TO_LOG_STRING                            "97f6275671"
#define PS_CYCLESTATS_PROCESS_TO_LOG_ID                                0x106f047e
#define PS_CYCLESTATS_PROCESS_TO_LOG_OVERINSTALL                       0 // OVERRIDE


#define PS_CYCLESTATS_PROFILER_FLAGS_STRING                            "97f627566f"
#define PS_CYCLESTATS_PROFILER_FLAGS_ID                                0x10cc518f
#define PS_CYCLESTATS_PROFILER_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define PS_CYCLESTATS_PROFILER_FLAGS_ENABLE                            0x00000001
#define PS_CYCLESTATS_PROFILER_FLAGS_FORCE_SINGLE_INSTANCE             0x00000100
#define PS_CYCLESTATS_PROFILER_FLAGS_AUTOEXIT_AFTER_N_LOOPS_MASK       0xff000000


#define PS_CYCLESTATS_START_FRAME_STRING                               "97f6275668"
#define PS_CYCLESTATS_START_FRAME_ID                                   0x10f68558
#define PS_CYCLESTATS_START_FRAME_OVERINSTALL                          0 // OVERRIDE


#define PS_CYCLESTATS_XFLAGS_STRING                                    "97f6275667"
#define PS_CYCLESTATS_XFLAGS_ID                                        0x10cc5188
#define PS_CYCLESTATS_XFLAGS_OVERINSTALL                               0 // OVERRIDE
#define PS_CYCLESTATS_XFLAGS_READ_PM_USING_CPU                         0x00000001
#define PS_CYCLESTATS_XFLAGS_IDENTIFY_BUCKETS                          0x00000002
#define PS_CYCLESTATS_XFLAGS_NO_STALL_CHECK                            0x00000004
#define PS_CYCLESTATS_XFLAGS_SKIP_DEAD_FRAMES                          0x00000008
#define PS_CYCLESTATS_XFLAGS_REPORT_TRANSITIONS                        0x00000010
#define PS_CYCLESTATS_XFLAGS_VPM_ENABLE_EOT                            0x00000020
#define PS_CYCLESTATS_XFLAGS_NO_TIMESTAMPS                             0x00000040
#define PS_CYCLESTATS_XFLAGS_MERGE_SEGMENTS                            0x00000080
#define PS_CYCLESTATS_XFLAGS_SORT_BY_MASK                              0x00000300
#define PS_CYCLESTATS_XFLAGS_SORT_BY_NAME                              0x00000000
#define PS_CYCLESTATS_XFLAGS_SORT_BY_APPEARANCE                        0x00000100
#define PS_CYCLESTATS_XFLAGS_SORT_BY_TIME                              0x00000200
#define PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_CLEAR                         0x00001000
#define PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_TRANS                         0x00002000
#define PS_CYCLESTATS_XFLAGS_DUMP_BEFORE_FLIP                          0x00004000
#define PS_CYCLESTATS_XFLAGS_DUMP_SELECTION                            0x00008000
#define PS_CYCLESTATS_XFLAGS_HTML_REPORT                               0x00020000
#define PS_CYCLESTATS_XFLAGS_REPORT_PMTRIGGERCT                        0x00040000
#define PS_CYCLESTATS_XFLAGS_TAG_OWN_PB_METHODS                        0x00080000
#define PS_CYCLESTATS_XFLAGS_WAIT_UNTIL_KB_TRIGGER                     0x00100000
#define PS_CYCLESTATS_XFLAGS_ANNOTATE                                  0x00200000
#define PS_CYCLESTATS_XFLAGS_FORCE_DONOTWAIT                           0x00400000
#define PS_CYCLESTATS_XFLAGS_VPM_SIGNAL_START_END                      0x00800000
#define PS_CYCLESTATS_XFLAGS_MINIMIZE_WFI_PMTRIG                       0x01000000
#define PS_CYCLESTATS_XFLAGS_MERGE_3DSTATEBUCKETS                      0x02000000
#define PS_CYCLESTATS_XFLAGS_NO_TRANSITION_RESET                       0x04000000
#define PS_CYCLESTATS_XFLAGS_RESET_PMTRIGGERCT                         0x08000000
#define PS_CYCLESTATS_XFLAGS_REPORT_RENDBATCHCT                        0x10000000
#define PS_CYCLESTATS_XFLAGS_FULL_FRAME_MODE                           0x20000000
#define PS_CYCLESTATS_XFLAGS_MERGE_SCG                                 0x40000000
#define PS_CYCLESTATS_XFLAGS_START_WITH_PM_PAUSED                      0x80000000


#define PS_DUMPREGISTERS_STRING                                        "d13733f12"
#define PS_DUMPREGISTERS_ID                                            0x10dd1fa3
#define PS_DUMPREGISTERS_OVERINSTALL                                   0 // OVERRIDE
#define PS_DUMPREGISTERS_OFF                                           0x00000000
#define PS_DUMPREGISTERS_DISABLED                                      0x00000000
#define PS_DUMPREGISTERS_ON                                            0x00000001
#define PS_DUMPREGISTERS_ENABLED                                       0x00000001


#define PS_DUMPREGISTERS_INPUT_FILE_STRING                             "df1f9812"
#define PS_DUMPREGISTERS_INPUT_FILE_ID                                 0x10dd1fa4
#define PS_DUMPREGISTERS_INPUT_FILE_OVERINSTALL                        0 // OVERRIDE


#define PS_FRAMERATE_LIMITER_STRING                                    "00008600"
#define PS_FRAMERATE_LIMITER_ID                                        0x10834fee
#define PS_FRAMERATE_LIMITER_OVERINSTALL                               0 // OVERRIDE
#define PS_FRAMERATE_LIMITER_DISABLED                                  0x00000000
#define PS_FRAMERATE_LIMITER_FPS_20                                    0x00000014
#define PS_FRAMERATE_LIMITER_FPS_30                                    0x0000001e
#define PS_FRAMERATE_LIMITER_FPS_40                                    0x00000028
#define PS_FRAMERATE_LIMITER_FPSMASK                                   0x000003ff
#define PS_FRAMERATE_LIMITER_ALLOW_DYNAMIC                             0x00001000
#define PS_FRAMERATE_LIMITER_YIELD_PROCESSOR                           0x00002000
#define PS_FRAMERATE_LIMITER_FORCE_VSYNC_OFF                           0x00040000
#define PS_FRAMERATE_LIMITER_DISALLOWED                                0x00200000
#define PS_FRAMERATE_LIMITER_NO_LAG_OFFSET                             0x00800000
#define PS_FRAMERATE_LIMITER_ALLOW_SLEEP_WITH_REFLEX                   0x02000000
#define PS_FRAMERATE_LIMITER_ACCURATE                                  0x10000000
#define PS_FRAMERATE_LIMITER_ALLOW_WINDOWED                            0x20000000
#define PS_FRAMERATE_LIMITER_FORCEON                                   0x40000000
#define PS_FRAMERATE_LIMITER_ENABLED                                   0x80000000
#define PS_FRAMERATE_LIMITER_OPENGL_REMOTE_DESKTOP                     0xe000003c
#define PS_FRAMERATE_LIMITER_LOW_LATENCY_DEFAULT                       0xb0802000
#define PS_FRAMERATE_LIMITER_MFR_FLAGS                                 0xf0802000
#define PS_FRAMERATE_LIMITER_GFN_FLAGS                                 0xf2803000
#define PS_FRAMERATE_LIMITER_MASK                                      0xf2a433ff
#define PS_FRAMERATE_LIMITER_DEFAULT                                   PS_FRAMERATE_LIMITER_LOW_LATENCY_DEFAULT


#define PS_FRAMERATE_LIMITER_2_CONTROL_STRING                          "00008602"
#define PS_FRAMERATE_LIMITER_2_CONTROL_ID                              0x10834fff
#define PS_FRAMERATE_LIMITER_2_CONTROL_OVERINSTALL                     0 // OVERRIDE
#define PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE                        0x00000000
#define PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_3D                        0x00000001
#define PS_FRAMERATE_LIMITER_2_CONTROL_AVOID_NOOP                      0x00000002
#define PS_FRAMERATE_LIMITER_2_CONTROL_DELAY_CE_PRESENT_3D             0x00000008
#define PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL_MAXWELL               0x00000010
#define PS_FRAMERATE_LIMITER_2_CONTROL_ALLOW_ALL                       0x00000020
#define PS_FRAMERATE_LIMITER_2_CONTROL_FORCE_OFF                       0x00000040
#define PS_FRAMERATE_LIMITER_2_CONTROL_ENABLE_VCE                      0x00000080
#define PS_FRAMERATE_LIMITER_2_CONTROL_DEFAULT_FOR_GM10X               0x00000011
#define PS_FRAMERATE_LIMITER_2_CONTROL_DEFAULT                         0x00000088


#define PS_FRAMERATE_LIMITER_GPS_CTRL_STRING                           "70008600"
#define PS_FRAMERATE_LIMITER_GPS_CTRL_ID                               0x10834f01
#define PS_FRAMERATE_LIMITER_GPS_CTRL_OVERINSTALL                      0 // OVERRIDE
#define PS_FRAMERATE_LIMITER_GPS_CTRL_DISABLED                         0x00000000
#define PS_FRAMERATE_LIMITER_GPS_CTRL_DECREASE_FILTER_MASK             0x000001FF
#define PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_MASK                  0x0000FE00
#define PS_FRAMERATE_LIMITER_GPS_CTRL_PAUSE_TIME_SHIFT                 9
#define PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_MASK          0x00FF0000
#define PS_FRAMERATE_LIMITER_GPS_CTRL_TARGET_RENDER_TIME_SHIFT         16
#define PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_MASK              0x1F000000
#define PS_FRAMERATE_LIMITER_GPS_CTRL_PERF_STEP_SIZE_SHIFT             24
#define PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_MASK             0xE0000000
#define PS_FRAMERATE_LIMITER_GPS_CTRL_INCREASE_FILTER_SHIFT            29
#define PS_FRAMERATE_LIMITER_GPS_CTRL_OPTIMAL_SETTING                  0x4A5A3219
#define PS_FRAMERATE_LIMITER_GPS_CTRL_DEFAULT                          PS_FRAMERATE_LIMITER_GPS_CTRL_DISABLED


#define PS_FRAMERATE_LOGGER_STRING                                     "90008600"
#define PS_FRAMERATE_LOGGER_ID                                         0x10834f03
#define PS_FRAMERATE_LOGGER_OVERINSTALL                                0 // OVERRIDE
#define PS_FRAMERATE_LOGGER_DISABLED                                   0x00000000
#define PS_FRAMERATE_LOGGER_DISPLAY                                    0x00000001
#define PS_FRAMERATE_LOGGER_LOGTOFILE                                  0x00000002
#define PS_FRAMERATE_LOGGER_LOGTOETW                                   0x00000004
#define PS_FRAMERATE_LOGGER_ALLOWDWM                                   0x00000008
#define PS_FRAMERATE_LOGGER_DEFAULT                                    PS_FRAMERATE_LOGGER_DISABLED


#define PS_FRAMERATE_MONITOR_CTRL_STRING                               "B0008600"
#define PS_FRAMERATE_MONITOR_CTRL_ID                                   0x10834f05
#define PS_FRAMERATE_MONITOR_CTRL_OVERINSTALL                          0 // OVERRIDE
#define PS_FRAMERATE_MONITOR_CTRL_DISABLED                             0x00000000
#define PS_FRAMERATE_MONITOR_CTRL_THRESHOLD_PCT_MASK                   0x000000FF
#define PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_MASK                    0x00000F00
#define PS_FRAMERATE_MONITOR_CTRL_MOVING_AVG_X_SHIFT                   8
#define PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_MASK                    0x0000F000
#define PS_FRAMERATE_MONITOR_CTRL_VSYNC_OFFSET_SHIFT                   12
#define PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_MASK                      0x000F0000
#define PS_FRAMERATE_MONITOR_CTRL_FRL_OFFSET_SHIFT                     16
#define PS_FRAMERATE_MONITOR_CTRL_FPS_USE_FRL                          0x00000000
#define PS_FRAMERATE_MONITOR_CTRL_LOW_LATENCY_LOG                      0x00100000
#define PS_FRAMERATE_MONITOR_CTRL_ALLOW_AUTOFL_WITH_REFLEX             0x00200000
#define PS_FRAMERATE_MONITOR_CTRL_DISABLE_MAP_GPU_TIMER                0x00400000
#define PS_FRAMERATE_MONITOR_CTRL_ENABLE_ON_VSYNC                      0x00800000
#define PS_FRAMERATE_MONITOR_CTRL_FPS_30                               0x1E000000
#define PS_FRAMERATE_MONITOR_CTRL_FPS_60                               0x3C000000
#define PS_FRAMERATE_MONITOR_CTRL_FPS_MASK                             0xFF000000
#define PS_FRAMERATE_MONITOR_CTRL_FPS_SHIFT                            24
#define PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING                      0x00600364
#define PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING_V2                   0x00680364
#define PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING                0x00E0f364
#define PS_FRAMERATE_MONITOR_CTRL_VSYNC_OPTIMAL_SETTING_V2             0x00E8f364
#define PS_FRAMERATE_MONITOR_CTRL_DEFAULT                              PS_FRAMERATE_MONITOR_CTRL_OPTIMAL_SETTING


#define PS_FRAMERATE_MONITOR_OVERRIDE_STRING                           "C0008600"
#define PS_FRAMERATE_MONITOR_OVERRIDE_ID                               0x10834f06
#define PS_FRAMERATE_MONITOR_OVERRIDE_OVERINSTALL                      0 // OVERRIDE
#define PS_FRAMERATE_MONITOR_OVERRIDE_NONE                             0x00000000
#define PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_ALL                      0x00000001
#define PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_VSYNC                     0x00000002
#define PS_FRAMERATE_MONITOR_OVERRIDE_DISABLE_AND_IGNORE_REQUEST_MAXPERF 0x00000004
#define PS_FRAMERATE_MONITOR_OVERRIDE_IGNORE_MULTI_DEVICE              0x00000008
#define PS_FRAMERATE_MONITOR_OVERRIDE_DEFAULT                          PS_FRAMERATE_MONITOR_OVERRIDE_NONE


#define PS_FRAMERATE_MONITOR_REPORTING_STRING                          "80008600"
#define PS_FRAMERATE_MONITOR_REPORTING_ID                              0x10834f02
#define PS_FRAMERATE_MONITOR_REPORTING_OVERINSTALL                     0 // OVERRIDE
#define PS_FRAMERATE_MONITOR_REPORTING_OFF                             0
#define PS_FRAMERATE_MONITOR_REPORTING_DISABLED                        0
#define PS_FRAMERATE_MONITOR_REPORTING_ON                              1
#define PS_FRAMERATE_MONITOR_REPORTING_ENABLED                         1
#define PS_FRAMERATE_MONITOR_REPORTING_DEFAULT                         PS_FRAMERATE_MONITOR_REPORTING_OFF


#define PS_FRAMERATE_MONITOR_VR_STRING                                 "D0008600"
#define PS_FRAMERATE_MONITOR_VR_ID                                     0x10834f07
#define PS_FRAMERATE_MONITOR_VR_OVERINSTALL                            0 // OVERRIDE
#define PS_FRAMERATE_MONITOR_VR_DISABLED                               0x00000000
#define PS_FRAMERATE_MONITOR_VR_TARGET_RENDER_TIME_MASK                0x0000ffff
#define PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_MASK           0xffff0000
#define PS_FRAMERATE_MONITOR_VR_TARGET_COMPOSITION_TIME_SHIFT          16
#define PS_FRAMERATE_MONITOR_VR_DEFAULT                                PS_FRAMERATE_MONITOR_VR_DISABLED


#define PS_FRL_LOADING_WAR_STRING                                      "A0008600"
#define PS_FRL_LOADING_WAR_ID                                          0x10834f04
#define PS_FRL_LOADING_WAR_OVERINSTALL                                 0 // OVERRIDE
#define PS_FRL_LOADING_WAR_DISABLED                                    0x00000000
#define PS_FRL_LOADING_WAR_SAFE_FPS_MASK                               0x000000FF
#define PS_FRL_LOADING_WAR_FILTER_ON_MASK                              0x00003F00
#define PS_FRL_LOADING_WAR_FILTER_ON_SHIFT                             8
#define PS_FRL_LOADING_WAR_FILTER_OFF_MASK                             0x000FC000
#define PS_FRL_LOADING_WAR_FILTER_OFF_SHIFT                            14
#define PS_FRL_LOADING_WAR_THRESHOLD_US_MASK                           0xFFF00000
#define PS_FRL_LOADING_WAR_THRESHOLD_US_SHIFT                          20
#define PS_FRL_LOADING_WAR_DEFAULT_SETTING                             0xBB814A3C
#define PS_FRL_LOADING_WAR_DEFAULT                                     PS_FRL_LOADING_WAR_DISABLED


#define PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT_STRING                     "0xce2348"
#define PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT_ID                         0x10ce2238
#define PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT_OVERINSTALL                0 // OVERRIDE
#define PS_MAXWELL_PRI_GPC0_SWDX_TC_TIMEOUT_DEFAULT                    0x10000


#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_STRING           "fa35cc4"
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ID               0x10a35cc4
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_OVERINSTALL      0 // OVERRIDE
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_OFF              0x1
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_DISABLED         0x1
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ON               0x0
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ENABLED          0x0
#define PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_DEFAULT          PS_MAXWELL_PRI_GPCS_SWDX_CONFIG_TILED_CACHING_ON


#define PS_PGO_PIECEMEAL_PROFILER_STRING                               "554c9a13"
#define PS_PGO_PIECEMEAL_PROFILER_ID                                   0x105d7198
#define PS_PGO_PIECEMEAL_PROFILER_OVERINSTALL                          0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_OFF                                  0xa2b53761
#define PS_PGO_PIECEMEAL_PROFILER_DISABLED                             0xa2b53761
#define PS_PGO_PIECEMEAL_PROFILER_ON                                   0x79292610
#define PS_PGO_PIECEMEAL_PROFILER_ENABLED                              0x79292610
#define PS_PGO_PIECEMEAL_PROFILER_DEFAULT                              PS_PGO_PIECEMEAL_PROFILER_OFF


#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_STRING                    "c0946a81"
#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_ID                        0x10000009
#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_OVERINSTALL               0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MIN                       1
#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_MAX                       32
#define PS_PGO_PIECEMEAL_PROFILER_BATCH_SIZE_DEFAULT                   0x1


#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_STRING               "00861b73"
#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_ID                   0x1049ce34
#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_OVERINSTALL          0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MIN                  64
#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_MAX                  1073741824
#define PS_PGO_PIECEMEAL_PROFILER_CPUMEM_BUF_SIZE_DEFAULT              0x100


#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_STRING                         "c0946a01"
#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_ID                             0x100f913a
#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_OVERINSTALL                    0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_MIN                            1
#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_MAX                            32
#define PS_PGO_PIECEMEAL_PROFILER_EPOCH_DEFAULT                        0x1


#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_STRING                         "34deabc0"
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_ID                             0x1018a4c7
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_OVERINSTALL                    0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_ALL                 0x00000000
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_PS                  0x00000001
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_CS                  0x00000002
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_TURING_AND_ABOVE               0x00000004
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_AMPERE_AND_ABOVE               0x00000008
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX11_ONLY                      0x00000010
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_DX12_ONLY                      0x00000020
#define PS_PGO_PIECEMEAL_PROFILER_FLAGS_DEFAULT                        PS_PGO_PIECEMEAL_PROFILER_FLAGS_ENABLE_FOR_ALL


#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH_STRING                 "00861a82"
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH_ID                     0x1049ff34
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH_OVERINSTALL            0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASH_DEFAULT                0x0


#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING_STRING        "b5f01a82"
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING_ID            0x10049f4b
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING_OVERINSTALL   0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_FOCUS_ON_HASHES_STRING_DEFAULT       ""


#define PS_PGO_PIECEMEAL_PROFILER_PRESET_STRING                        "34dca8c0"
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_ID                            0x1019a4c6
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_OVERINSTALL                   0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_NONE                          0x00000000
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_HIGH                     0x00000001
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_MEDIUM                        0x00000002
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_LOW                           0x00000004
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_VERY_LOW                      0x00000014
#define PS_PGO_PIECEMEAL_PROFILER_PRESET_DEFAULT                       PS_PGO_PIECEMEAL_PROFILER_PRESET_NONE


#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_STRING                  "34deabc1"
#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_ID                      0x10a2a7c6
#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_OVERINSTALL             0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_DISABLED                0x00000000
#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_ZEROPLOIT               0x00000001
#define PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_DEFAULT                 PS_PGO_PIECEMEAL_PROFILER_PROFILE_KIND_DISABLED


#define PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ_STRING                 "c0457aab"
#define PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ_ID                     0x1000000f
#define PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ_OVERINSTALL            0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_SAMPLING_FREQ_DEFAULT                0.0f


#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_STRING               "c0e4fb91"
#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_ID                   0x1000000e
#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_OVERINSTALL          0 // OVERRIDE
#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MIN                  64
#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_MAX                  1073741824
#define PS_PGO_PIECEMEAL_PROFILER_VIDMEM_BUF_SIZE_DEFAULT              0x100


#define PS_PIXEL_SHADER_STATS_FLAGS_STRING                             "27815290"
#define PS_PIXEL_SHADER_STATS_FLAGS_ID                                 0x10e1e86b
#define PS_PIXEL_SHADER_STATS_FLAGS_OVERINSTALL                        0 // OVERRIDE
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_TSS            0x00000001
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_TSS                0x00000002
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED_REAL           0x00000004
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_HAND_TUNED_REAL               0x00000008
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_NVINST                        0x00000100
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_CONST_HISTOGRAMS              0x00001000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME           0x00010000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED          0x00020000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS         0x00040000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER      0x00080000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME_RUNTIME   0x00100000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_COMPILE_TIME           0x00200000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_RAW_COMBINERS                 0x01000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_TEXTURE_STAGE_INFO            0x02000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_API_BYTECODE           0x04000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SHADER_USAGE_MAP              0x08000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_SURFACE_AND_STATE_INFO        0x10000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS            0x20000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_FLAGS                         0x40000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DUMP_DSR_SHADERS                   0x80000000
#define PS_PIXEL_SHADER_STATS_FLAGS_DEFAULT                            0


#define PS_PUSHBUFFER_DUMP_END_FRAME_STRING                            "97e6275669"
#define PS_PUSHBUFFER_DUMP_END_FRAME_ID                                0x10e68559
#define PS_PUSHBUFFER_DUMP_END_FRAME_OVERINSTALL                       0 // OVERRIDE


#define PS_PUSHBUFFER_DUMP_START_FRAME_STRING                          "97e6275668"
#define PS_PUSHBUFFER_DUMP_START_FRAME_ID                              0x10e68558
#define PS_PUSHBUFFER_DUMP_START_FRAME_OVERINSTALL                     0 // OVERRIDE


#define PS_REDUCTION_HACK_HASH_LIST_STRING                             "fa5840"
#define PS_REDUCTION_HACK_HASH_LIST_ID                                 0x10fa5840
#define PS_REDUCTION_HACK_HASH_LIST_OVERINSTALL                        0 // OVERRIDE
#define PS_REDUCTION_HACK_HASH_LIST_DEFAULT                            ""


#define PS_REDUCTION_KNOBS_LIST_STRING                                 "fa6640"
#define PS_REDUCTION_KNOBS_LIST_ID                                     0x10fa6640
#define PS_REDUCTION_KNOBS_LIST_OVERINSTALL                            0 // OVERRIDE
#define PS_REDUCTION_KNOBS_LIST_DEFAULT                                ""


#define PS_REFLEX_INDICATOR_STRING                                     "A0008604"
#define PS_REFLEX_INDICATOR_ID                                         0x10834f18
#define PS_REFLEX_INDICATOR_OVERINSTALL                                0 // OVERRIDE
#define PS_REFLEX_INDICATOR_OFF                                        0x00000000
#define PS_REFLEX_INDICATOR_0                                          0x00000000
#define PS_REFLEX_INDICATOR_FALSE                                      0x00000000
#define PS_REFLEX_INDICATOR_DISABLED                                   0x00000000
#define PS_REFLEX_INDICATOR_ON                                         0x00000001
#define PS_REFLEX_INDICATOR_1                                          0x00000001
#define PS_REFLEX_INDICATOR_TRUE                                       0x00000001
#define PS_REFLEX_INDICATOR_ENABLED                                    0x00000001
#define PS_REFLEX_INDICATOR_CODE_COVERAGE                              0x00000003
#define PS_REFLEX_INDICATOR_DEFAULT                                    PS_REFLEX_INDICATOR_OFF


#define PS_VERTEX_SHADER_STATS_FLAGS_STRING                            "487074847"
#define PS_VERTEX_SHADER_STATS_FLAGS_ID                                0x10ed52e4
#define PS_VERTEX_SHADER_STATS_FLAGS_OVERINSTALL                       0 // OVERRIDE
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NON_HAND_TUNED               0x00000001
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_HAND_TUNED                   0x00000002
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_VSFP                         0x00000004
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_DECL                         0x00000008
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SYSTEM                       0x00000010
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_NVINST                       0x00000020
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SOURCE_TOKENS                0x00000080
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_ZERO_USAGE_SHADERS           0x00000100
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADERS_AT_CREATE            0x00001000
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_TIME          0x00010000
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_SPEED         0x00020000
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_STALLS        0x00040000
#define PS_VERTEX_SHADER_STATS_FLAGS_DUMP_SHADER_MEASURE_PCSAMPLER     0x00080000


#define PS_ZBC_COLOR_VALUES_STRING                                     "10F2565"
#define PS_ZBC_COLOR_VALUES_ID                                         0x100f2565
#define PS_ZBC_COLOR_VALUES_OVERINSTALL                                0 // OVERRIDE


#define PS_ZBC_DEPTH_VALUES_STRING                                     "10F2566"
#define PS_ZBC_DEPTH_VALUES_ID                                         0x100f2566
#define PS_ZBC_DEPTH_VALUES_OVERINSTALL                                0 // OVERRIDE


#define PS_ZBC_STENCIL_VALUES_STRING                                   "10F2567"
#define PS_ZBC_STENCIL_VALUES_ID                                       0x100f2567
#define PS_ZBC_STENCIL_VALUES_OVERINSTALL                              0 // OVERRIDE


#define QMD_OCC_MAX_ASYNC_STRING                                       "0x1e1070"
#define QMD_OCC_MAX_ASYNC_ID                                           0x101e1070
#define QMD_OCC_MAX_ASYNC_OVERINSTALL                                  0 // OVERRIDE
#define QMD_OCC_MAX_ASYNC_DEFAULT                                      0xFFFFFF


#define QMD_OCC_MAX_NON_RT_STRING                                      "0x1c1045"
#define QMD_OCC_MAX_NON_RT_ID                                          0x101c1045
#define QMD_OCC_MAX_NON_RT_OVERINSTALL                                 0 // OVERRIDE
#define QMD_OCC_MAX_NON_RT_DEFAULT                                     0xFFFFFF


#define QMD_OCC_MAX_RT_STRING                                          "0x1e1045"
#define QMD_OCC_MAX_RT_ID                                              0x101e1045
#define QMD_OCC_MAX_RT_OVERINSTALL                                     0 // OVERRIDE
#define QMD_OCC_MAX_RT_DEFAULT                                         0xFFFFFF


#define QMD_OCC_MAX_SYNC_STRING                                        "0x1e106e"
#define QMD_OCC_MAX_SYNC_ID                                            0x101e106e
#define QMD_OCC_MAX_SYNC_OVERINSTALL                                   0 // OVERRIDE
#define QMD_OCC_MAX_SYNC_DEFAULT                                       0xFFFFFF


#define QMD_OCC_THRESHOLD_ASYNC_STRING                                 "0x1e1069"
#define QMD_OCC_THRESHOLD_ASYNC_ID                                     0x101e1069
#define QMD_OCC_THRESHOLD_ASYNC_OVERINSTALL                            0 // OVERRIDE
#define QMD_OCC_THRESHOLD_ASYNC_DEFAULT                                0x104000


#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL_STRING                    "0x1e106b"
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL_ID                        0x101e106b
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL_OVERINSTALL               0 // OVERRIDE
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_ACCEL_DEFAULT                   0x104000


#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH_STRING                   "0x1e106d"
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH_ID                       0x101e106d
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH_OVERINSTALL              0 // OVERRIDE
#define QMD_OCC_THRESHOLD_ASYNC_RTCORE_LAUNCH_DEFAULT                  0x104000


#define QMD_OCC_THRESHOLD_NON_RT_STRING                                "0x1b1045"
#define QMD_OCC_THRESHOLD_NON_RT_ID                                    0x101b1045
#define QMD_OCC_THRESHOLD_NON_RT_OVERINSTALL                           0 // OVERRIDE
#define QMD_OCC_THRESHOLD_NON_RT_DEFAULT                               0xF0F00


#define QMD_OCC_THRESHOLD_RT_STRING                                    "0x1d1045"
#define QMD_OCC_THRESHOLD_RT_ID                                        0x101d1045
#define QMD_OCC_THRESHOLD_RT_OVERINSTALL                               0 // OVERRIDE
#define QMD_OCC_THRESHOLD_RT_DEFAULT                                   0xF0F00


#define QMD_OCC_THRESHOLD_SYNC_STRING                                  "0x1e1068"
#define QMD_OCC_THRESHOLD_SYNC_ID                                      0x101e1068
#define QMD_OCC_THRESHOLD_SYNC_OVERINSTALL                             0 // OVERRIDE
#define QMD_OCC_THRESHOLD_SYNC_DEFAULT                                 0x104000


#define QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL_STRING                     "0x1e106a"
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL_ID                         0x101e106a
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL_OVERINSTALL                0 // OVERRIDE
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_ACCEL_DEFAULT                    0x040400


#define QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH_STRING                    "0x1e106c"
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH_ID                        0x101e106c
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH_OVERINSTALL               0 // OVERRIDE
#define QMD_OCC_THRESHOLD_SYNC_RTCORE_LAUNCH_DEFAULT                   0x104000


#define QUIET_MODE_STRING                                              "f1846871"
#define QUIET_MODE_ID                                                  0x10115c8a
#define QUIET_MODE_OVERINSTALL                                         0 // OVERRIDE
#define QUIET_MODE_MIN                                                 0x00000001
#define QUIET_MODE_MAX                                                 0x000003ff
#define QUIET_MODE_ENABLED                                             0x10000000
#define QUIET_MODE_DISABLED                                            0x00000000
#define QUIET_MODE_XQM                                                 0x10000028
#define QUIET_MODE_DEFAULT                                             QUIET_MODE_DISABLED


#define QUIET_MODE_APP_FPS_STRING                                      "f1846872"
#define QUIET_MODE_APP_FPS_ID                                          0x10115c8b
#define QUIET_MODE_APP_FPS_OVERINSTALL                                 0 // OVERRIDE
#define QUIET_MODE_APP_FPS_MIN                                         0x00000001
#define QUIET_MODE_APP_FPS_MAX                                         0x000003ff
#define QUIET_MODE_APP_FPS_NO_OVERRIDE                                 0x00000000
#define QUIET_MODE_APP_FPS_DEFAULT                                     QUIET_MODE_APP_FPS_NO_OVERRIDE


#define REFLEX_TEST_MODE_STRING                                        "A0008605"
#define REFLEX_TEST_MODE_ID                                            0x10834f19
#define REFLEX_TEST_MODE_OVERINSTALL                                   0 // OVERRIDE
#define REFLEX_TEST_MODE_OFF                                           0
#define REFLEX_TEST_MODE_DISABLED                                      0
#define REFLEX_TEST_MODE_ON                                            1
#define REFLEX_TEST_MODE_ENABLED                                       1
#define REFLEX_TEST_MODE_DEFAULT                                       REFLEX_TEST_MODE_OFF


#define ROOT_TABLE_PREFETCH_STRING                                     "0x191043"
#define ROOT_TABLE_PREFETCH_ID                                         0x10191043
#define ROOT_TABLE_PREFETCH_OVERINSTALL                                0 // OVERRIDE
#define ROOT_TABLE_PREFETCH_OFF                                        0x00000000
#define ROOT_TABLE_PREFETCH_VERTEX_CULL_BEFORE_FETCH                   0x00000001
#define ROOT_TABLE_PREFETCH_VERTEX                                     0x00000002
#define ROOT_TABLE_PREFETCH_TESSELLATION_INIT                          0x00000004
#define ROOT_TABLE_PREFETCH_TESSELLATION                               0x00000008
#define ROOT_TABLE_PREFETCH_GEOMETRY                                   0x00000010
#define ROOT_TABLE_PREFETCH_PIXEL                                      0x00000020
#define ROOT_TABLE_PREFETCH_ENABLE_ALL                                 0x0000003f
#define ROOT_TABLE_PREFETCH_DEFAULT                                    ROOT_TABLE_PREFETCH_ENABLE_ALL


#define RTCORE_BVH_DUMP_HOTKEY_STRING                                  "0x6136c3"
#define RTCORE_BVH_DUMP_HOTKEY_ID                                      0x106136c3
#define RTCORE_BVH_DUMP_HOTKEY_OVERINSTALL                             0 // OVERRIDE
#define RTCORE_BVH_DUMP_HOTKEY_DEFAULT                                 0x24


#define RTCORE_BVH_DUMP_MODE_STRING                                    "0xb775da"
#define RTCORE_BVH_DUMP_MODE_ID                                        0x10b775da
#define RTCORE_BVH_DUMP_MODE_OVERINSTALL                               0 // OVERRIDE
#define RTCORE_BVH_DUMP_MODE_OFF                                       0x00000000
#define RTCORE_BVH_DUMP_MODE_CONTINUOUS                                0x00000001
#define RTCORE_BVH_DUMP_MODE_HOTKEY                                    0x00000002
#define RTCORE_BVH_DUMP_MODE_SAVE_SYNC_CACHE                           0x00000003
#define RTCORE_BVH_DUMP_MODE_LOAD_SYNC_CACHE                           0x00000004
#define RTCORE_BVH_DUMP_MODE_DEFAULT                                   RTCORE_BVH_DUMP_MODE_OFF


#define RTCORE_BVH_DUMP_PATH_STRING                                    "0xef26c6"
#define RTCORE_BVH_DUMP_PATH_ID                                        0x10ef26c6
#define RTCORE_BVH_DUMP_PATH_OVERINSTALL                               0 // OVERRIDE
#define RTCORE_BVH_DUMP_PATH_DEFAULT                                   "."


#define RTCORE_DEFAULT_CACHE_CONFIG_STRING                             "0x00156d"
#define RTCORE_DEFAULT_CACHE_CONFIG_ID                                 0x1000156d
#define RTCORE_DEFAULT_CACHE_CONFIG_OVERINSTALL                        0 // OVERRIDE
#define RTCORE_DEFAULT_CACHE_CONFIG_PREFER_NONE                        0x00000000
#define RTCORE_DEFAULT_CACHE_CONFIG_PREFER_SHARED                      0x00000001
#define RTCORE_DEFAULT_CACHE_CONFIG_PREFER_L1                          0x00000002
#define RTCORE_DEFAULT_CACHE_CONFIG_PREFER_EQUAL                       0x00000003
#define RTCORE_DEFAULT_CACHE_CONFIG_DEFAULT                            RTCORE_DEFAULT_CACHE_CONFIG_PREFER_NONE


#define RTCORE_DISABLE_SMEM_SPILLS_STRING                              "0x001570"
#define RTCORE_DISABLE_SMEM_SPILLS_ID                                  0x10001570
#define RTCORE_DISABLE_SMEM_SPILLS_OVERINSTALL                         0 // OVERRIDE
#define RTCORE_DISABLE_SMEM_SPILLS_OFF                                 0x00000000
#define RTCORE_DISABLE_SMEM_SPILLS_DISABLED                            0x00000000
#define RTCORE_DISABLE_SMEM_SPILLS_ON                                  0x00000001
#define RTCORE_DISABLE_SMEM_SPILLS_ENABLED                             0x00000001
#define RTCORE_DISABLE_SMEM_SPILLS_DEFAULT                             RTCORE_DISABLE_SMEM_SPILLS_OFF


#define RTCORE_DUMP_MODULE_CUBINS_STRING                               "0x00156e"
#define RTCORE_DUMP_MODULE_CUBINS_ID                                   0x1000156e
#define RTCORE_DUMP_MODULE_CUBINS_OVERINSTALL                          0 // OVERRIDE
#define RTCORE_DUMP_MODULE_CUBINS_OFF                                  0
#define RTCORE_DUMP_MODULE_CUBINS_DISABLED                             0
#define RTCORE_DUMP_MODULE_CUBINS_ON                                   1
#define RTCORE_DUMP_MODULE_CUBINS_ENABLED                              1
#define RTCORE_DUMP_MODULE_CUBINS_DEFAULT                              RTCORE_DUMP_MODULE_CUBINS_OFF


#define RTCORE_DXR_USE_CUDA_STRING                                     "0x001573"
#define RTCORE_DXR_USE_CUDA_ID                                         0x10001573
#define RTCORE_DXR_USE_CUDA_OVERINSTALL                                0 // OVERRIDE
#define RTCORE_DXR_USE_CUDA_NO                                         0
#define RTCORE_DXR_USE_CUDA_OFF                                        0
#define RTCORE_DXR_USE_CUDA_DISABLED                                   0
#define RTCORE_DXR_USE_CUDA_YES                                        1
#define RTCORE_DXR_USE_CUDA_ON                                         1
#define RTCORE_DXR_USE_CUDA_ENABLED                                    1
#define RTCORE_DXR_USE_CUDA_DEFAULT                                    RTCORE_DXR_USE_CUDA_YES


#define RTCORE_EXCEPTION_FLAGS_STRING                                  "0x001572"
#define RTCORE_EXCEPTION_FLAGS_ID                                      0x10001572
#define RTCORE_EXCEPTION_FLAGS_OVERINSTALL                             0 // OVERRIDE
#define RTCORE_EXCEPTION_FLAGS_NONE                                    0x00000000
#define RTCORE_EXCEPTION_FLAGS_STACK_OVERFLOW                          0x00000001
#define RTCORE_EXCEPTION_FLAGS_TRACE_DEPTH                             0x00000002
#define RTCORE_EXCEPTION_FLAGS_RTCORE_DEFAULT                          0xffffffff
#define RTCORE_EXCEPTION_FLAGS_DEFAULT                                 RTCORE_EXCEPTION_FLAGS_RTCORE_DEFAULT


#define RTCORE_KNOBS_STRING                                            "0x001567"
#define RTCORE_KNOBS_ID                                                0x10001567
#define RTCORE_KNOBS_OVERINSTALL                                       0 // OVERRIDE
#define RTCORE_KNOBS_DEFAULT                                           ""


#define RTCORE_LOG_LEVEL_STRING                                        "0x001568"
#define RTCORE_LOG_LEVEL_ID                                            0x10001568
#define RTCORE_LOG_LEVEL_OVERINSTALL                                   0 // OVERRIDE
#define RTCORE_LOG_LEVEL_DEFAULT                                       1


#define RTCORE_MAX_REGISTERS_STRING                                    "0x00156c"
#define RTCORE_MAX_REGISTERS_ID                                        0x1000156c
#define RTCORE_MAX_REGISTERS_OVERINSTALL                               0 // OVERRIDE
#define RTCORE_MAX_REGISTERS_DEFAULT                                   0


#define RTCORE_NUM_ATTRIBUTE_REGS_STRING                               "0x00156a"
#define RTCORE_NUM_ATTRIBUTE_REGS_ID                                   0x1000156a
#define RTCORE_NUM_ATTRIBUTE_REGS_OVERINSTALL                          0 // OVERRIDE
#define RTCORE_NUM_ATTRIBUTE_REGS_DEFAULT                              0


#define RTCORE_PRINT_CONTINUATION_SPILLS_STRING                        "0x00156f"
#define RTCORE_PRINT_CONTINUATION_SPILLS_ID                            0x1000156f
#define RTCORE_PRINT_CONTINUATION_SPILLS_OVERINSTALL                   0 // OVERRIDE
#define RTCORE_PRINT_CONTINUATION_SPILLS_OFF                           0
#define RTCORE_PRINT_CONTINUATION_SPILLS_DISABLED                      0
#define RTCORE_PRINT_CONTINUATION_SPILLS_ON                            1
#define RTCORE_PRINT_CONTINUATION_SPILLS_ENABLED                       1
#define RTCORE_PRINT_CONTINUATION_SPILLS_DEFAULT                       RTCORE_PRINT_CONTINUATION_SPILLS_OFF


#define RTCORE_PROFILING_STRING                                        "0x00156b"
#define RTCORE_PROFILING_ID                                            0x1000156b
#define RTCORE_PROFILING_OVERINSTALL                                   0 // OVERRIDE
#define RTCORE_PROFILING_NONE                                          0x00000000
#define RTCORE_PROFILING_STATEFUNC                                     0x00000001
#define RTCORE_PROFILING_RAYS                                          0x00000002
#define RTCORE_PROFILING_LAUNCHBUFFER                                  0x00000004
#define RTCORE_PROFILING_DEFAULT                                       RTCORE_PROFILING_NONE


#define RTCORE_PROFILING_ALLOCATION_SIZE_STRING                        "0xe6cd57"
#define RTCORE_PROFILING_ALLOCATION_SIZE_ID                            0x10e6cd57
#define RTCORE_PROFILING_ALLOCATION_SIZE_OVERINSTALL                   0 // OVERRIDE
#define RTCORE_PROFILING_ALLOCATION_SIZE_DEFAULT                       4194304


#define RTCORE_PROFILING_DUMP_COUNT_STRING                             "0x782b48"
#define RTCORE_PROFILING_DUMP_COUNT_ID                                 0x10782b48
#define RTCORE_PROFILING_DUMP_COUNT_OVERINSTALL                        0 // OVERRIDE
#define RTCORE_PROFILING_DUMP_COUNT_DEFAULT                            10


#define RTCORE_PROFILING_DUMP_HOTKEY_STRING                            "0x674b85"
#define RTCORE_PROFILING_DUMP_HOTKEY_ID                                0x10674b85
#define RTCORE_PROFILING_DUMP_HOTKEY_OVERINSTALL                       0 // OVERRIDE
#define RTCORE_PROFILING_DUMP_HOTKEY_DEFAULT                           0x21


#define RTCORE_PROFILING_DUMP_MODE_STRING                              "0xbda13e"
#define RTCORE_PROFILING_DUMP_MODE_ID                                  0x10bda13e
#define RTCORE_PROFILING_DUMP_MODE_OVERINSTALL                         0 // OVERRIDE
#define RTCORE_PROFILING_DUMP_MODE_CONTINUOUS                          0x00000000
#define RTCORE_PROFILING_DUMP_MODE_HOTKEY                              0x00000001
#define RTCORE_PROFILING_DUMP_MODE_DEFAULT                             RTCORE_PROFILING_DUMP_MODE_CONTINUOUS


#define RTCORE_USE_CUDA_STRING                                         "0x001571"
#define RTCORE_USE_CUDA_ID                                             0x10001571
#define RTCORE_USE_CUDA_OVERINSTALL                                    0 // OVERRIDE
#define RTCORE_USE_CUDA_NO                                             0
#define RTCORE_USE_CUDA_OFF                                            0
#define RTCORE_USE_CUDA_DISABLED                                       0
#define RTCORE_USE_CUDA_YES                                            1
#define RTCORE_USE_CUDA_ON                                             1
#define RTCORE_USE_CUDA_ENABLED                                        1
#define RTCORE_USE_CUDA_DEFAULT                                        RTCORE_USE_CUDA_YES


#define RTCORE_WARPS_PER_CTA_STRING                                    "0x011532"
#define RTCORE_WARPS_PER_CTA_ID                                        0x10011532
#define RTCORE_WARPS_PER_CTA_OVERINSTALL                               0 // OVERRIDE
#define RTCORE_WARPS_PER_CTA_DEFAULT                                   0


#define RTCORE_WARPS_PER_CTA_AMPERE_STRING                             "0x011534"
#define RTCORE_WARPS_PER_CTA_AMPERE_ID                                 0x10011534
#define RTCORE_WARPS_PER_CTA_AMPERE_OVERINSTALL                        0 // OVERRIDE
#define RTCORE_WARPS_PER_CTA_AMPERE_DEFAULT                            0


#define RTCORE_WARPS_PER_CTA_TURING_STRING                             "0x011533"
#define RTCORE_WARPS_PER_CTA_TURING_ID                                 0x10011533
#define RTCORE_WARPS_PER_CTA_TURING_OVERINSTALL                        0 // OVERRIDE
#define RTCORE_WARPS_PER_CTA_TURING_DEFAULT                            0


#define RTCORE_WAR_BUG_2648362_STRING                                  "0x9cbc33"
#define RTCORE_WAR_BUG_2648362_ID                                      0x109cbc33
#define RTCORE_WAR_BUG_2648362_OVERINSTALL                             0 // OVERRIDE
#define RTCORE_WAR_BUG_2648362_NO                                      0
#define RTCORE_WAR_BUG_2648362_OFF                                     0
#define RTCORE_WAR_BUG_2648362_DISABLED                                0
#define RTCORE_WAR_BUG_2648362_YES                                     1
#define RTCORE_WAR_BUG_2648362_ON                                      1
#define RTCORE_WAR_BUG_2648362_ENABLED                                 1
#define RTCORE_WAR_BUG_2648362_DEFAULT                                 RTCORE_WAR_BUG_2648362_YES


#define SETTICKCONTROL_STRING                                          "74095216"
#define SETTICKCONTROL_ID                                              0x10018809
#define SETTICKCONTROL_OVERINSTALL                                     0 // OVERRIDE
#define SETTICKCONTROL_MIN                                             0x00000000
#define SETTICKCONTROL_MAX                                             0xffffffff


#define SETTICKCONTROLEARLYZ_STRING                                    "74095217"
#define SETTICKCONTROLEARLYZ_ID                                        0x10ae0f30
#define SETTICKCONTROLEARLYZ_OVERINSTALL                               0 // OVERRIDE
#define SETTICKCONTROLEARLYZ_MIN                                       0x00000000
#define SETTICKCONTROLEARLYZ_MAX                                       0xffffffff


#define SET_ASYNC_LAUNCH_QUEUE_1_STRING                                "0x1a1067"
#define SET_ASYNC_LAUNCH_QUEUE_1_ID                                    0x101a1067
#define SET_ASYNC_LAUNCH_QUEUE_1_OVERINSTALL                           0 // OVERRIDE
#define SET_ASYNC_LAUNCH_QUEUE_1_OFF                                   0x00000000
#define SET_ASYNC_LAUNCH_QUEUE_1_DISABLED                              0x00000000
#define SET_ASYNC_LAUNCH_QUEUE_1_ON                                    0x00000001
#define SET_ASYNC_LAUNCH_QUEUE_1_ENABLED                               0x00000001
#define SET_ASYNC_LAUNCH_QUEUE_1_DEFAULT                               SET_ASYNC_LAUNCH_QUEUE_1_ON


#define SET_NON_RT_LAUNCH_QUEUE_1_STRING                               "0x1a1042"
#define SET_NON_RT_LAUNCH_QUEUE_1_ID                                   0x101a1042
#define SET_NON_RT_LAUNCH_QUEUE_1_OVERINSTALL                          0 // OVERRIDE
#define SET_NON_RT_LAUNCH_QUEUE_1_OFF                                  0x00000000
#define SET_NON_RT_LAUNCH_QUEUE_1_DISABLED                             0x00000000
#define SET_NON_RT_LAUNCH_QUEUE_1_ON                                   0x00000001
#define SET_NON_RT_LAUNCH_QUEUE_1_ENABLED                              0x00000001
#define SET_NON_RT_LAUNCH_QUEUE_1_DEFAULT                              SET_NON_RT_LAUNCH_QUEUE_1_OFF


#define SET_RT_LAUNCH_QUEUE_1_STRING                                   "0x1a1044"
#define SET_RT_LAUNCH_QUEUE_1_ID                                       0x101a1044
#define SET_RT_LAUNCH_QUEUE_1_OVERINSTALL                              0 // OVERRIDE
#define SET_RT_LAUNCH_QUEUE_1_OFF                                      0x00000000
#define SET_RT_LAUNCH_QUEUE_1_DISABLED                                 0x00000000
#define SET_RT_LAUNCH_QUEUE_1_ON                                       0x00000001
#define SET_RT_LAUNCH_QUEUE_1_ENABLED                                  0x00000001
#define SET_RT_LAUNCH_QUEUE_1_DEFAULT                                  SET_RT_LAUNCH_QUEUE_1_ON


#define SET_SYNC_LAUNCH_QUEUE_1_STRING                                 "0x1a1066"
#define SET_SYNC_LAUNCH_QUEUE_1_ID                                     0x101a1066
#define SET_SYNC_LAUNCH_QUEUE_1_OVERINSTALL                            0 // OVERRIDE
#define SET_SYNC_LAUNCH_QUEUE_1_OFF                                    0x00000000
#define SET_SYNC_LAUNCH_QUEUE_1_DISABLED                               0x00000000
#define SET_SYNC_LAUNCH_QUEUE_1_ON                                     0x00000001
#define SET_SYNC_LAUNCH_QUEUE_1_ENABLED                                0x00000001
#define SET_SYNC_LAUNCH_QUEUE_1_DEFAULT                                SET_SYNC_LAUNCH_QUEUE_1_OFF


#define SHIM_IGPU_TRANSCODING_STRING                                   "52180906"
#define SHIM_IGPU_TRANSCODING_ID                                       0x10f9dc85
#define SHIM_IGPU_TRANSCODING_OVERINSTALL                              0 // OVERRIDE
#define SHIM_IGPU_TRANSCODING_DISABLE                                  0x00000000
#define SHIM_IGPU_TRANSCODING_ENABLE                                   0x00000001
#define SHIM_IGPU_TRANSCODING_DEFAULT                                  SHIM_IGPU_TRANSCODING_DISABLE


#define SHIM_MAXRES_STRING                                             "52180876"
#define SHIM_MAXRES_ID                                                 0x10f9dc82
#define SHIM_MAXRES_OVERINSTALL                                        0 // OVERRIDE
#define SHIM_MAXRES_DEFAULT                                            0x00000000


#define SHIM_MCCOMPAT_STRING                                           "52180856"
#define SHIM_MCCOMPAT_ID                                               0x10f9dc80
#define SHIM_MCCOMPAT_OVERINSTALL                                      1 // MERGE
#define SHIM_MCCOMPAT_INTEGRATED                                       0x00000000
#define SHIM_MCCOMPAT_ENABLE                                           0x00000001
#define SHIM_MCCOMPAT_USER_EDITABLE                                    0x00000002
#define SHIM_MCCOMPAT_MASK                                             0x00000003
#define SHIM_MCCOMPAT_VIDEO_MASK                                       0x00000004
#define SHIM_MCCOMPAT_VARYING_BIT                                      0x00000008
#define SHIM_MCCOMPAT_AUTO_SELECT                                      0x00000010
#define SHIM_MCCOMPAT_OVERRIDE_BIT                                     0x80000000
#define SHIM_MCCOMPAT_DEFAULT                                          SHIM_MCCOMPAT_AUTO_SELECT


#define SHIM_RENDERING_MODE_STRING                                     "52180866"
#define SHIM_RENDERING_MODE_ID                                         0x10f9dc81
#define SHIM_RENDERING_MODE_OVERINSTALL                                1 // MERGE
#define SHIM_RENDERING_MODE_INTEGRATED                                 0x00000000
#define SHIM_RENDERING_MODE_ENABLE                                     0x00000001
#define SHIM_RENDERING_MODE_USER_EDITABLE                              0x00000002
#define SHIM_RENDERING_MODE_MASK                                       0x00000003
#define SHIM_RENDERING_MODE_VIDEO_MASK                                 0x00000004
#define SHIM_RENDERING_MODE_VARYING_BIT                                0x00000008
#define SHIM_RENDERING_MODE_AUTO_SELECT                                0x00000010
#define SHIM_RENDERING_MODE_OVERRIDE_BIT                               0x80000000
#define SHIM_RENDERING_MODE_DEFAULT                                    SHIM_RENDERING_MODE_AUTO_SELECT


#define SHIM_RENDERING_OPTIONS_STRING                                  "52180896"
#define SHIM_RENDERING_OPTIONS_ID                                      0x10f9dc84
#define SHIM_RENDERING_OPTIONS_OVERINSTALL                             1 // MERGE
#define SHIM_RENDERING_OPTIONS_DEFAULT_RENDERING_MODE                  0x00000000
#define SHIM_RENDERING_OPTIONS_DISABLE_ASYNC_PRESENT                   0x00000001
#define SHIM_RENDERING_OPTIONS_EHSHELL_DETECT                          0x00000002
#define SHIM_RENDERING_OPTIONS_FLASHPLAYER_HOST_DETECT                 0x00000004
#define SHIM_RENDERING_OPTIONS_VIDEO_DRM_APP_DETECT                    0x00000008
#define SHIM_RENDERING_OPTIONS_IGNORE_OVERRIDES                        0x00000010
#define SHIM_RENDERING_OPTIONS_RESERVED1                               0x00000020
#define SHIM_RENDERING_OPTIONS_ENABLE_DWM_ASYNC_PRESENT                0x00000040
#define SHIM_RENDERING_OPTIONS_RESERVED2                               0x00000080
#define SHIM_RENDERING_OPTIONS_ALLOW_INHERITANCE                       0x00000100
#define SHIM_RENDERING_OPTIONS_DISABLE_WRAPPERS                        0x00000200
#define SHIM_RENDERING_OPTIONS_DISABLE_DXGI_WRAPPERS                   0x00000400
#define SHIM_RENDERING_OPTIONS_PRUNE_UNSUPPORTED_FORMATS               0x00000800
#define SHIM_RENDERING_OPTIONS_ENABLE_ALPHA_FORMAT                     0x00001000
#define SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING                        0x00002000
#define SHIM_RENDERING_OPTIONS_DISABLE_CUDA                            0x00004000
#define SHIM_RENDERING_OPTIONS_ALLOW_CP_CAPS_FOR_VIDEO                 0x00008000
#define SHIM_RENDERING_OPTIONS_IGPU_TRANSCODING_FWD_OPTIMUS            0x00010000
#define SHIM_RENDERING_OPTIONS_DISABLE_DURING_SECURE_BOOT              0x00020000
#define SHIM_RENDERING_OPTIONS_INVERT_FOR_QUADRO                       0x00040000
#define SHIM_RENDERING_OPTIONS_INVERT_FOR_MSHYBRID                     0x00080000
#define SHIM_RENDERING_OPTIONS_REGISTER_PROCESS_ENABLE_GOLD            0x00100000
#define SHIM_RENDERING_OPTIONS_HANDLE_WINDOWED_MODE_PERF_OPT           0x00200000
#define SHIM_RENDERING_OPTIONS_HANDLE_WIN7_ASYNC_RUNTIME_BUG           0x00400000
#define SHIM_RENDERING_OPTIONS_EXPLICIT_ADAPTER_OPTED_BY_APP           0x00800000
#define SHIM_RENDERING_OPTIONS_ALLOW_DYNAMIC_DISPLAY_MUX_SWITCH        0x01000000
#define SHIM_RENDERING_OPTIONS_DISALLOW_DYNAMIC_DISPLAY_MUX_SWITCH     0x02000000
#define SHIM_RENDERING_OPTIONS_DISABLE_TURING_POWER_POLICY             0x04000000
#define SHIM_RENDERING_OPTIONS_DEFAULT                                 0x00000000


#define SHOW_OPTIMUS_OVERLAY_STRING                                    "8578b94a"
#define SHOW_OPTIMUS_OVERLAY_ID                                        0x10061221
#define SHOW_OPTIMUS_OVERLAY_OVERINSTALL                               0 // OVERRIDE
#define SHOW_OPTIMUS_OVERLAY_OFF                                       0
#define SHOW_OPTIMUS_OVERLAY_DISABLED                                  0
#define SHOW_OPTIMUS_OVERLAY_ON                                        1
#define SHOW_OPTIMUS_OVERLAY_ENABLED                                   1
#define SHOW_OPTIMUS_OVERLAY_DEFAULT                                   SHOW_OPTIMUS_OVERLAY_OFF


#define SLIVIDEO_STRING                                                "17267978"
#define SLIVIDEO_ID                                                    0x1048e95e
#define SLIVIDEO_OVERINSTALL                                           0 // OVERRIDE
#define SLIVIDEO_OFF                                                   0x51661620
#define SLIVIDEO_DISABLED                                              0x51661620
#define SLIVIDEO_ON                                                    0x60792907
#define SLIVIDEO_ENABLED                                               0x60792907
#define SLIVIDEO_DEFAULT                                               SLIVIDEO_OFF


#define SLI_GPU_COUNT_STRING                                           "SLI_GPU_COUNT"
#define SLI_GPU_COUNT_ID                                               0x1033dcd1
#define SLI_GPU_COUNT_OVERINSTALL                                      1 // MERGE
#define SLI_GPU_COUNT_AUTOSELECT                                       0x00000000
#define SLI_GPU_COUNT_ONE                                              0x00000001
#define SLI_GPU_COUNT_TWO                                              0x00000002
#define SLI_GPU_COUNT_THREE                                            0x00000003
#define SLI_GPU_COUNT_FOUR                                             0x00000004
#define SLI_GPU_COUNT_DEFAULT                                          SLI_GPU_COUNT_AUTOSELECT


#define SLI_PREDEFINED_GPU_COUNT_STRING                                "PREDEFINED_SLI_GPU_COUNT"
#define SLI_PREDEFINED_GPU_COUNT_ID                                    0x1033dcd2
#define SLI_PREDEFINED_GPU_COUNT_OVERINSTALL                           0 // OVERRIDE
#define SLI_PREDEFINED_GPU_COUNT_AUTOSELECT                            0x00000000
#define SLI_PREDEFINED_GPU_COUNT_ONE                                   0x00000001
#define SLI_PREDEFINED_GPU_COUNT_TWO                                   0x00000002
#define SLI_PREDEFINED_GPU_COUNT_THREE                                 0x00000003
#define SLI_PREDEFINED_GPU_COUNT_FOUR                                  0x00000004
#define SLI_PREDEFINED_GPU_COUNT_DEFAULT                               SLI_PREDEFINED_GPU_COUNT_AUTOSELECT


#define SLI_PREDEFINED_GPU_COUNT_DX10_STRING                           "PREDEFINED_SLI_GPU_COUNT_DX10"
#define SLI_PREDEFINED_GPU_COUNT_DX10_ID                               0x1033dcd3
#define SLI_PREDEFINED_GPU_COUNT_DX10_OVERINSTALL                      0 // OVERRIDE
#define SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT                       0x00000000
#define SLI_PREDEFINED_GPU_COUNT_DX10_ONE                              0x00000001
#define SLI_PREDEFINED_GPU_COUNT_DX10_TWO                              0x00000002
#define SLI_PREDEFINED_GPU_COUNT_DX10_THREE                            0x00000003
#define SLI_PREDEFINED_GPU_COUNT_DX10_FOUR                             0x00000004
#define SLI_PREDEFINED_GPU_COUNT_DX10_DEFAULT                          SLI_PREDEFINED_GPU_COUNT_DX10_AUTOSELECT


#define SLI_PREDEFINED_MODE_STRING                                     "SLI_PREDEFINED_MODE"
#define SLI_PREDEFINED_MODE_ID                                         0x1033cec1
#define SLI_PREDEFINED_MODE_OVERINSTALL                                0 // OVERRIDE
#define SLI_PREDEFINED_MODE_AUTOSELECT                                 0x00000000
#define SLI_PREDEFINED_MODE_FORCE_SINGLE                               0x00000001
#define SLI_PREDEFINED_MODE_FORCE_AFR                                  0x00000002
#define SLI_PREDEFINED_MODE_FORCE_AFR2                                 0x00000003
#define SLI_PREDEFINED_MODE_FORCE_SFR                                  0x00000004
#define SLI_PREDEFINED_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR            0x00000005
#define SLI_PREDEFINED_MODE_DEFAULT                                    SLI_PREDEFINED_MODE_AUTOSELECT


#define SLI_PREDEFINED_MODE_DX10_STRING                                "SLI_PREDEFINED_MODE_DX10"
#define SLI_PREDEFINED_MODE_DX10_ID                                    0x1033cec2
#define SLI_PREDEFINED_MODE_DX10_OVERINSTALL                           0 // OVERRIDE
#define SLI_PREDEFINED_MODE_DX10_AUTOSELECT                            0x00000000
#define SLI_PREDEFINED_MODE_DX10_FORCE_SINGLE                          0x00000001
#define SLI_PREDEFINED_MODE_DX10_FORCE_AFR                             0x00000002
#define SLI_PREDEFINED_MODE_DX10_FORCE_AFR2                            0x00000003
#define SLI_PREDEFINED_MODE_DX10_FORCE_SFR                             0x00000004
#define SLI_PREDEFINED_MODE_DX10_FORCE_AFR_OF_SFR__FALLBACK_3AFR       0x00000005
#define SLI_PREDEFINED_MODE_DX10_DEFAULT                               SLI_PREDEFINED_MODE_DX10_AUTOSELECT


#define SLI_RENDERING_MODE_STRING                                      "SLI_RENDERING_MODE"
#define SLI_RENDERING_MODE_ID                                          0x1033ced1
#define SLI_RENDERING_MODE_OVERINSTALL                                 1 // MERGE
#define SLI_RENDERING_MODE_AUTOSELECT                                  0x00000000
#define SLI_RENDERING_MODE_FORCE_SINGLE                                0x00000001
#define SLI_RENDERING_MODE_FORCE_AFR                                   0x00000002
#define SLI_RENDERING_MODE_FORCE_AFR2                                  0x00000003
#define SLI_RENDERING_MODE_FORCE_SFR                                   0x00000004
#define SLI_RENDERING_MODE_FORCE_AFR_OF_SFR__FALLBACK_3AFR             0x00000005
#define SLI_RENDERING_MODE_DEFAULT                                     SLI_RENDERING_MODE_AUTOSELECT


#define SPLIT_ADAPTER_RENDER_DEVICE_STRING                             "19103865"
#define SPLIT_ADAPTER_RENDER_DEVICE_ID                                 0x10354ff9
#define SPLIT_ADAPTER_RENDER_DEVICE_OVERINSTALL                        0 // OVERRIDE
#define SPLIT_ADAPTER_RENDER_DEVICE_OFF                                0
#define SPLIT_ADAPTER_RENDER_DEVICE_DISABLED                           0
#define SPLIT_ADAPTER_RENDER_DEVICE_ON                                 1
#define SPLIT_ADAPTER_RENDER_DEVICE_ENABLED                            1
#define SPLIT_ADAPTER_RENDER_DEVICE_DEFAULT                            SPLIT_ADAPTER_RENDER_DEVICE_OFF


#define STEREO_MCCOMPAT_STRING                                         "49119164"
#define STEREO_MCCOMPAT_ID                                             0x102e048d
#define STEREO_MCCOMPAT_OVERINSTALL                                    0 // OVERRIDE
#define STEREO_MCCOMPAT_LEGACY                                         0x00000001
#define STEREO_MCCOMPAT_BROADCAST                                      0x00000002
#define STEREO_MCCOMPAT_DISABLE_SLI                                    0x00000004
#define STEREO_MCCOMPAT_MASK                                           0x00000007
#define STEREO_MCCOMPAT_OVERRIDE_BIT                                   0x80000000
#define STEREO_MCCOMPAT_DEFAULT                                        STEREO_MCCOMPAT_DISABLE_SLI


#define STEREO_WIN_MODE_IN_SURROUND_STRING                             "WindowedModeStereoInSurround"
#define STEREO_WIN_MODE_IN_SURROUND_ID                                 0x107ecb8d
#define STEREO_WIN_MODE_IN_SURROUND_OVERINSTALL                        0 // OVERRIDE
#define STEREO_WIN_MODE_IN_SURROUND_OFF                                0x00000000
#define STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_SINGLE_MODE            0x00000100
#define STEREO_WIN_MODE_IN_SURROUND_ENABLE_DX10_BROADCAST              0x00000200
#define STEREO_WIN_MODE_IN_SURROUND_ENABLE_MASK_DX10                   0x0000FF00
#define STEREO_WIN_MODE_IN_SURROUND_DEFAULT                            STEREO_WIN_MODE_IN_SURROUND_OFF


#define TESLAINTERTPCARBITRATIONCONTROL_STRING                         "5379259"
#define TESLAINTERTPCARBITRATIONCONTROL_ID                             0x10d9604d
#define TESLAINTERTPCARBITRATIONCONTROL_OVERINSTALL                    0 // OVERRIDE
#define TESLAINTERTPCARBITRATIONCONTROL_MIN                            0x00000
#define TESLAINTERTPCARBITRATIONCONTROL_MAX                            0xfffff


#define TESLAOCTVERTICESPERTPC_STRING                                  "57310220"
#define TESLAOCTVERTICESPERTPC_ID                                      0x10166e3d
#define TESLAOCTVERTICESPERTPC_OVERINSTALL                             0 // OVERRIDE
#define TESLAOCTVERTICESPERTPC_MIN                                     0x000
#define TESLAOCTVERTICESPERTPC_MAX                                     0x1ff


#define TESLAPSWAIT_STRING                                             "54312266"
#define TESLAPSWAIT_ID                                                 0x109c8e50
#define TESLAPSWAIT_OVERINSTALL                                        0 // OVERRIDE
#define TESLAPSWAIT_MIN                                                0x0
#define TESLAPSWAIT_MAX                                                0xffffffff


#define TESLA_ADDDUMMYCREAD_STRING                                     "75494732"
#define TESLA_ADDDUMMYCREAD_ID                                         0x1037df7d
#define TESLA_ADDDUMMYCREAD_OVERINSTALL                                0 // OVERRIDE
#define TESLA_ADDDUMMYCREAD_OFF                                        0
#define TESLA_ADDDUMMYCREAD_DISABLED                                   0
#define TESLA_ADDDUMMYCREAD_ON                                         1
#define TESLA_ADDDUMMYCREAD_ENABLED                                    1
#define TESLA_ADDDUMMYCREAD_DEFAULT                                    TESLA_ADDDUMMYCREAD_OFF


#define TESLA_ANISO_QUALITY_STRING                                     "24189123"
#define TESLA_ANISO_QUALITY_ID                                         0x107c493b
#define TESLA_ANISO_QUALITY_OVERINSTALL                                0 // OVERRIDE
#define TESLA_ANISO_QUALITY_MIN                                        0x00000000
#define TESLA_ANISO_QUALITY_tpsNV30                                    0x00000000
#define TESLA_ANISO_QUALITY_tpsNV40                                    0x00000001
#define TESLA_ANISO_QUALITY_tpsDefault                                 0x00000002
#define TESLA_ANISO_QUALITY_tpsAssertive                               0x00000003
#define TESLA_ANISO_QUALITY_tpsAggressive                              0x00000004
#define TESLA_ANISO_QUALITY_tpsFerocious                               0x00000005
#define TESLA_ANISO_QUALITY_tpsNSettings                               0x6
#define TESLA_ANISO_QUALITY_MAX                                        0x5
#define TESLA_ANISO_QUALITY_DEFAULT                                    TESLA_ANISO_QUALITY_tpsDefault


#define TESLA_REGBANKSIZE_STRING                                       "83451133"
#define TESLA_REGBANKSIZE_ID                                           0x10c38467
#define TESLA_REGBANKSIZE_OVERINSTALL                                  0 // OVERRIDE
#define TESLA_REGBANKSIZE_MIN                                          0x00000000
#define TESLA_REGBANKSIZE_MAX                                          0xffffffff
#define TESLA_REGBANKSIZE_DEFAULT                                      0


#define TESSELLATION_LOD_MULTIPLIER_STRING                             "0x9e1f10"
#define TESSELLATION_LOD_MULTIPLIER_ID                                 0x109e1f10
#define TESSELLATION_LOD_MULTIPLIER_OVERINSTALL                        0 // OVERRIDE
#define TESSELLATION_LOD_MULTIPLIER_DEFAULT                            0x00010000


#define TILE_COALESCER_TILE_SIZE_STRING                                "545221"
#define TILE_COALESCER_TILE_SIZE_ID                                    0x10545221
#define TILE_COALESCER_TILE_SIZE_OVERINSTALL                           0 // OVERRIDE
#define TILE_COALESCER_TILE_SIZE_TILE_SIZE_NOOVERRIDE                  0x00000000
#define TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_16x16             0x00000001
#define TILE_COALESCER_TILE_SIZE_INTERLOCK_TILE_SIZE_8x8               0x00000002
#define TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_16x16          0x00000004
#define TILE_COALESCER_TILE_SIZE_NO_INTERLOCK_TILE_SIZE_8x8            0x00000008
#define TILE_COALESCER_TILE_SIZE_DEFAULT                               TILE_COALESCER_TILE_SIZE_TILE_SIZE_NOOVERRIDE


#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_STRING               "0xc5c1e8"
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_ID                   0x10c5c1e8
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_OVERINSTALL          0 // OVERRIDE
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_OFF                  0x00000000
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_DISABLED             0x00000000
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_ON                   0x00000001
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_ENABLED              0x00000001
#define TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_DEFAULT              TURING_SM_SCG_CONTROL_COMPUTE_IN_GRAPHICS_OFF


#define UMD_HIDE_QUADRO_IDENTITY_STRING                                "0xaaa36c"
#define UMD_HIDE_QUADRO_IDENTITY_ID                                    0x10aaa36c
#define UMD_HIDE_QUADRO_IDENTITY_OVERINSTALL                           0 // OVERRIDE
#define UMD_HIDE_QUADRO_IDENTITY_DISABLE                               0
#define UMD_HIDE_QUADRO_IDENTITY_ENABLE                                1
#define UMD_HIDE_QUADRO_IDENTITY_DEFAULT                               UMD_HIDE_QUADRO_IDENTITY_DISABLE


#define VCAA_HILITE_STRING                                             "78E16B9C"
#define VCAA_HILITE_ID                                                 0x10d3a8ef
#define VCAA_HILITE_OVERINSTALL                                        0 // OVERRIDE
#define VCAA_HILITE_OFF                                                0x22754241
#define VCAA_HILITE_DISABLED                                           0x22754241
#define VCAA_HILITE_ON                                                 0x66855023
#define VCAA_HILITE_ENABLED                                            0x66855023
#define VCAA_HILITE_DEFAULT                                            VCAA_HILITE_OFF


#define VRPRERENDERLIMIT_STRING                                        "0x111133"
#define VRPRERENDERLIMIT_ID                                            0x10111133
#define VRPRERENDERLIMIT_OVERINSTALL                                   1 // MERGE
#define VRPRERENDERLIMIT_MIN                                           0x00
#define VRPRERENDERLIMIT_MAX                                           0xff
#define VRPRERENDERLIMIT_APP_CONTROLLED                                0x00
#define VRPRERENDERLIMIT_DEFAULT                                       0x01


#define VRRFEATUREINDICATOR_STRING                                     "73314097"
#define VRRFEATUREINDICATOR_ID                                         0x1094f157
#define VRRFEATUREINDICATOR_OVERINSTALL                                1 // MERGE
#define VRRFEATUREINDICATOR_DISABLED                                   0x0
#define VRRFEATUREINDICATOR_OFF                                        0x0
#define VRRFEATUREINDICATOR_ENABLED                                    0x1
#define VRRFEATUREINDICATOR_ON                                         0x1
#define VRRFEATUREINDICATOR_DEFAULT                                    VRRFEATUREINDICATOR_ENABLED


#define VRRINDICATOR_STRING                                            "1042d483"
#define VRRINDICATOR_ID                                                0x10029538
#define VRRINDICATOR_OVERINSTALL                                       0 // OVERRIDE
#define VRRINDICATOR_OFF                                               0x0
#define VRRINDICATOR_DISABLED                                          0x0
#define VRRINDICATOR_ON                                                0x1
#define VRRINDICATOR_ENABLED                                           0x1
#define VRRINDICATOR_DEFAULT                                           VRRINDICATOR_OFF


#define VRROVERLAYINDICATOR_STRING                                     "53304097"
#define VRROVERLAYINDICATOR_ID                                         0x1095f16f
#define VRROVERLAYINDICATOR_OVERINSTALL                                0 // OVERRIDE
#define VRROVERLAYINDICATOR_DISABLED                                   0x0
#define VRROVERLAYINDICATOR_OFF                                        0x0
#define VRROVERLAYINDICATOR_ENABLED                                    0x1
#define VRROVERLAYINDICATOR_ON                                         0x1
#define VRROVERLAYINDICATOR_DEFAULT                                    VRROVERLAYINDICATOR_ENABLED


#define VRRREQUESTSTATE_STRING                                         "73314027"
#define VRRREQUESTSTATE_ID                                             0x1094f1f7
#define VRRREQUESTSTATE_OVERINSTALL                                    1 // MERGE
#define VRRREQUESTSTATE_DISABLED                                       0x0
#define VRRREQUESTSTATE_FULLSCREEN_ONLY                                0x1
#define VRRREQUESTSTATE_FULLSCREEN_AND_WINDOWED                        0x2
#define VRRREQUESTSTATE_DEFAULT                                        VRRREQUESTSTATE_FULLSCREEN_ONLY


#define VRR_APP_OVERRIDE_STRING                                        "60461793"
#define VRR_APP_OVERRIDE_ID                                            0x10a879cf
#define VRR_APP_OVERRIDE_OVERINSTALL                                   1 // MERGE
#define VRR_APP_OVERRIDE_ALLOW                                         0
#define VRR_APP_OVERRIDE_FORCE_OFF                                     1
#define VRR_APP_OVERRIDE_DISALLOW                                      2
#define VRR_APP_OVERRIDE_ULMB                                          3
#define VRR_APP_OVERRIDE_FIXED_REFRESH                                 4
#define VRR_APP_OVERRIDE_DEFAULT                                       VRR_APP_OVERRIDE_ALLOW


#define VRR_APP_OVERRIDE_REQUEST_STATE_STRING                          "60461788"
#define VRR_APP_OVERRIDE_REQUEST_STATE_ID                              0x10a879ac
#define VRR_APP_OVERRIDE_REQUEST_STATE_OVERINSTALL                     1 // MERGE
#define VRR_APP_OVERRIDE_REQUEST_STATE_ALLOW                           0
#define VRR_APP_OVERRIDE_REQUEST_STATE_FORCE_OFF                       1
#define VRR_APP_OVERRIDE_REQUEST_STATE_DISALLOW                        2
#define VRR_APP_OVERRIDE_REQUEST_STATE_ULMB                            3
#define VRR_APP_OVERRIDE_REQUEST_STATE_FIXED_REFRESH                   4
#define VRR_APP_OVERRIDE_REQUEST_STATE_DEFAULT                         VRR_APP_OVERRIDE_REQUEST_STATE_ALLOW


#define VRR_DEBUG_OVERRIDE_STRING                                      "72504593"
#define VRR_DEBUG_OVERRIDE_ID                                          0x115fb4e7
#define VRR_DEBUG_OVERRIDE_OVERINSTALL                                 0 // OVERRIDE
#define VRR_DEBUG_OVERRIDE_NONE                                        0x00000000
#define VRR_DEBUG_OVERRIDE_FORCE_ON                                    0x00000001
#define VRR_DEBUG_OVERRIDE_FORCE_OFF                                   0x00000002
#define VRR_DEBUG_OVERRIDE_ENABLE_VIDEOBRIDGE                          0x00000004
#define VRR_DEBUG_OVERRIDE_ENABLE_DWM_SUPPORT                          0x00000008
#define VRR_DEBUG_OVERRIDE_FORCE_TIMER_OFF                             0x00000010
#define VRR_DEBUG_OVERRIDE_DEFAULT                                     VRR_DEBUG_OVERRIDE_NONE


#define VRR_MODE_STRING                                                "73314098"
#define VRR_MODE_ID                                                    0x1194f158
#define VRR_MODE_OVERINSTALL                                           1 // MERGE
#define VRR_MODE_DISABLED                                              0x0
#define VRR_MODE_FULLSCREEN_ONLY                                       0x1
#define VRR_MODE_FULLSCREEN_AND_WINDOWED                               0x2
#define VRR_MODE_DEFAULT                                               VRR_MODE_FULLSCREEN_ONLY


#define VRR_OVERRIDE_CONTROL_STRING                                    "72504592"
#define VRR_OVERRIDE_CONTROL_ID                                        0x115fb4e6
#define VRR_OVERRIDE_CONTROL_OVERINSTALL                               0 // OVERRIDE
#define VRR_OVERRIDE_CONTROL_FORCE_ON                                  0x00000001
#define VRR_OVERRIDE_CONTROL_FORCE_OFF                                 0x00000002
#define VRR_OVERRIDE_CONTROL_ENABLE_VIDEOBRIDGE                        0x00000004
#define VRR_OVERRIDE_CONTROL_ENABLE_DWM_SUPPORT                        0x00000008
#define VRR_OVERRIDE_CONTROL_FORCE_TIMER_OFF                           0x00000010
#define VRR_OVERRIDE_CONTROL_DEFAULT                                   VRR_OVERRIDE_CONTROL_ENABLE_DWM_SUPPORT


#define VRR_WINDOWED_APP_OVERRIDE_STRING                               "60461797"
#define VRR_WINDOWED_APP_OVERRIDE_ID                                   0x10a879ef
#define VRR_WINDOWED_APP_OVERRIDE_OVERINSTALL                          0 // OVERRIDE
#define VRR_WINDOWED_APP_OVERRIDE_ALLOW                                0
#define VRR_WINDOWED_APP_OVERRIDE_FORCE_OFF                            1
#define VRR_WINDOWED_APP_OVERRIDE_DEFAULT                              VRR_WINDOWED_APP_OVERRIDE_ALLOW


#define VR_PERF_LEVEL_STRING                                           "D0018600"
#define VR_PERF_LEVEL_ID                                               0x10834f08
#define VR_PERF_LEVEL_OVERINSTALL                                      0 // OVERRIDE
#define VR_PERF_LEVEL_POWER_SAVINGS                                    0
#define VR_PERF_LEVEL_SUSTAINED_LOW                                    25
#define VR_PERF_LEVEL_SUSTAINED_HIGH                                   50
#define VR_PERF_LEVEL_BOOST                                            75
#define VR_PERF_LEVEL_MAX                                              100
#define VR_PERF_LEVEL_DEFAULT                                          VR_PERF_LEVEL_BOOST


#define VSYNCSMOOTHAFR_STRING                                          "09090919"
#define VSYNCSMOOTHAFR_ID                                              0x101ae763
#define VSYNCSMOOTHAFR_OVERINSTALL                                     1 // MERGE
#define VSYNCSMOOTHAFR_OFF                                             0x00000000
#define VSYNCSMOOTHAFR_DISABLED                                        0x00000000
#define VSYNCSMOOTHAFR_ON                                              0x00000001
#define VSYNCSMOOTHAFR_ENABLED                                         0x00000001
#define VSYNCSMOOTHAFR_DEFAULT                                         VSYNCSMOOTHAFR_OFF


#define VSYNCVRRCONTROL_STRING                                         "60461792"
#define VSYNCVRRCONTROL_ID                                             0x10a879ce
#define VSYNCVRRCONTROL_OVERINSTALL                                    1 // MERGE
#define VSYNCVRRCONTROL_DISABLE                                        0x00000000
#define VSYNCVRRCONTROL_FALSE                                          0x00000000
#define VSYNCVRRCONTROL_0                                              0x00000000
#define VSYNCVRRCONTROL_OFF                                            0x00000000
#define VSYNCVRRCONTROL_ENABLE                                         0x00000001
#define VSYNCVRRCONTROL_TRUE                                           0x00000001
#define VSYNCVRRCONTROL_1                                              0x00000001
#define VSYNCVRRCONTROL_ON                                             0x00000001
#define VSYNCVRRCONTROL_NOTSUPPORTED                                   0x9f95128e
#define VSYNCVRRCONTROL_NONE                                           0x9f95128e
#define VSYNCVRRCONTROL_DEFAULT                                        VSYNCVRRCONTROL_ENABLE


#define VSYNC_BEHAVIOR_FLAGS_STRING                                    "00fdec23"
#define VSYNC_BEHAVIOR_FLAGS_ID                                        0x10fdec23
#define VSYNC_BEHAVIOR_FLAGS_OVERINSTALL                               0 // OVERRIDE
#define VSYNC_BEHAVIOR_FLAGS_NONE                                      0x00000000
#define VSYNC_BEHAVIOR_FLAGS_DEFAULT                                   0x00000000
#define VSYNC_BEHAVIOR_FLAGS_IGNORE_FLIPINTERVAL_MULTIPLE              0x00000001


#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_STRING          "0xfbdf11"
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_ID              0x11fbdf11
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_OVERINSTALL     0 // OVERRIDE
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE      0x1
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_TWO      0x2
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_THREE    0x3
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_FOUR     0x4
#define WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_DEFAULT         WKS_4PLUSGPUS_RESTRICT_SOURCES_IN_EXTENDEDVIEW_SOURCE_ONE


#define WKS_API_STEREO_EYES_EXCHANGE_STRING                            "APIStereoEyesExchange"
#define WKS_API_STEREO_EYES_EXCHANGE_ID                                0x11ae435c
#define WKS_API_STEREO_EYES_EXCHANGE_OVERINSTALL                       1 // MERGE
#define WKS_API_STEREO_EYES_EXCHANGE_OFF                               0
#define WKS_API_STEREO_EYES_EXCHANGE_ON                                1
#define WKS_API_STEREO_EYES_EXCHANGE_DEFAULT                           WKS_API_STEREO_EYES_EXCHANGE_OFF


#define WKS_API_STEREO_MODE_STRING                                     "APIStereoMode"
#define WKS_API_STEREO_MODE_ID                                         0x11e91a61
#define WKS_API_STEREO_MODE_OVERINSTALL                                1 // MERGE
#define WKS_API_STEREO_MODE_SHUTTER_GLASSES                            0
#define WKS_API_STEREO_MODE_VERTICAL_INTERLACED                        1
#define WKS_API_STEREO_MODE_TWINVIEW                                   2
#define WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_AUTO                  3
#define WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC0                  4
#define WKS_API_STEREO_MODE_NV17_SHUTTER_GLASSES_DAC1                  5
#define WKS_API_STEREO_MODE_COLOR_LINE                                 6
#define WKS_API_STEREO_MODE_COLOR_INTERLEAVED                          7
#define WKS_API_STEREO_MODE_ANAGLYPH                                   8
#define WKS_API_STEREO_MODE_HORIZONTAL_INTERLACED                      9
#define WKS_API_STEREO_MODE_SIDE_FIELD                                 10
#define WKS_API_STEREO_MODE_SUB_FIELD                                  11
#define WKS_API_STEREO_MODE_CHECKERBOARD                               12
#define WKS_API_STEREO_MODE_INVERSE_CHECKERBOARD                       13
#define WKS_API_STEREO_MODE_TRIDELITY_SL                               14
#define WKS_API_STEREO_MODE_TRIDELITY_MV                               15
#define WKS_API_STEREO_MODE_SEEFRONT                                   16
#define WKS_API_STEREO_MODE_STEREO_MIRROR                              17
#define WKS_API_STEREO_MODE_FRAME_SEQUENTIAL                           18
#define WKS_API_STEREO_MODE_AUTODETECT_PASSIVE_MODE                    19
#define WKS_API_STEREO_MODE_AEGIS_DT_FRAME_SEQUENTIAL                  20
#define WKS_API_STEREO_MODE_OEM_EMITTER_FRAME_SEQUENTIAL               21
#define WKS_API_STEREO_MODE_DP_INBAND                                  22
#define WKS_API_STEREO_MODE_USE_HW_DEFAULT                             0xffffffff
#define WKS_API_STEREO_MODE_DEFAULT_GL                                 3
#define WKS_API_STEREO_MODE_DEFAULT                                    WKS_API_STEREO_MODE_SHUTTER_GLASSES


#define WKS_API_STEREO_OSD_STRING                                      "STEREO_OSD"
#define WKS_API_STEREO_OSD_ID                                          0x10deadee
#define WKS_API_STEREO_OSD_OVERINSTALL                                 1 // MERGE
#define WKS_API_STEREO_OSD_USE_DRIVER_DEFAULT                          0x00000000
#define WKS_API_STEREO_OSD_FORCE_ENABLE                                0x00000001
#define WKS_API_STEREO_OSD_FORCE_DISABLE                               0x00000002
#define WKS_API_STEREO_OSD_MIN                                         0x00000000
#define WKS_API_STEREO_OSD_MAX                                         0x00000002
#define WKS_API_STEREO_OSD_DEFAULT                                     WKS_API_STEREO_OSD_USE_DRIVER_DEFAULT


#define WKS_CLIENT_ARBITRATION_LOGGING_STRING                          "WksLogging"
#define WKS_CLIENT_ARBITRATION_LOGGING_ID                              0x11e21a53
#define WKS_CLIENT_ARBITRATION_LOGGING_OVERINSTALL                     0 // OVERRIDE
#define WKS_CLIENT_ARBITRATION_LOGGING_OFF                             0
#define WKS_CLIENT_ARBITRATION_LOGGING_ON                              1
#define WKS_CLIENT_ARBITRATION_LOGGING_DBG_DUMP                        2
#define WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_LOGS               4
#define WKS_CLIENT_ARBITRATION_LOGGING_DBG_RESTRICT_ALL                8
#define WKS_CLIENT_ARBITRATION_LOGGING_SWAPGROUP                       16
#define WKS_CLIENT_ARBITRATION_LOGGING_DEFAULT                         WKS_CLIENT_ARBITRATION_LOGGING_OFF


#define WKS_CURSOR_MODE_STRING                                         "WksCursor"
#define WKS_CURSOR_MODE_ID                                             0x11e21666
#define WKS_CURSOR_MODE_OVERINSTALL                                    0 // OVERRIDE
#define WKS_CURSOR_MODE_CURSOR_TYPE_MASK                               0x0000F
#define WKS_CURSOR_MODE_SW_CURSOR                                      0x00001
#define WKS_CURSOR_MODE_CPU_POSITION_WARP                              0x00002
#define WKS_CURSOR_MODE_SOC_EMULATED_CURSOR                            0x00003
#define WKS_CURSOR_MODE_COMBINED_CURSOR                                0x00004
#define WKS_CURSOR_MODE_REDRAW_METHOD_MASK                             0x000F0
#define WKS_CURSOR_MODE_REDRAW_SETPIXEL                                0x00010
#define WKS_CURSOR_MODE_REDRAW_RENDER_BEFORE_FLIP                      0x00020
#define WKS_CURSOR_MODE_REDRAW_DESKTOP                                 0x00040
#define WKS_CURSOR_MODE_REPLACE_CURSOR_SHAPE_MASK                      0x00F00
#define WKS_CURSOR_MODE_REPLACE_OFF                                    0x00000
#define WKS_CURSOR_MODE_REPLACE_ON                                     0x00100
#define WKS_CURSOR_MODE_CURSOR_INFO_MASK                               0x0F000
#define WKS_CURSOR_MODE_CURSOR_INFO_OFF                                0x00000
#define WKS_CURSOR_MODE_CURSOR_INFO_HW                                 0x01000
#define WKS_CURSOR_MODE_CURSOR_INFO_SOC                                0x02000
#define WKS_CURSOR_MODE_CURSOR_INFO_WARP                               0x04000
#define WKS_CURSOR_MODE_DEFAULT                                        0x00000023


#define WKS_DEEP_COLOR_DWM_CONTROL_STRING                              "WksDeepColorDWMControl"
#define WKS_DEEP_COLOR_DWM_CONTROL_ID                                  0x11c21ee5
#define WKS_DEEP_COLOR_DWM_CONTROL_OVERINSTALL                         0 // OVERRIDE
#define WKS_DEEP_COLOR_DWM_CONTROL_OFF                                 0x00000000
#define WKS_DEEP_COLOR_DWM_CONTROL_DISABLE_RGB10A2_SPOOFING            0x00000001
#define WKS_DEEP_COLOR_DWM_CONTROL_DEFAULT                             WKS_DEEP_COLOR_DWM_CONTROL_OFF


#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_STRING                     "DisplayRearrangement"
#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_ID                         0x10d91a4c
#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_OVERINSTALL                0 // OVERRIDE
#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_OFF                        0x0
#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_ON                         0x1
#define WKS_DISPLAY_REARRANGEMENT_WITHIN16K_DEFAULT                    WKS_DISPLAY_REARRANGEMENT_WITHIN16K_ON


#define WKS_DX_SWAPGROUPS_STRING                                       "WKS_DX_SWAPGROUPS"
#define WKS_DX_SWAPGROUPS_ID                                           0x10dead12
#define WKS_DX_SWAPGROUPS_OVERINSTALL                                  1 // MERGE
#define WKS_DX_SWAPGROUPS_USE_DRIVER_DEFAULT                           0x00000004
#define WKS_DX_SWAPGROUPS_FORCE_NVAPI_FLIP_WAIT                        0x00000001
#define WKS_DX_SWAPGROUPS_PRE_PRESENT_WAIT                             0x00000002
#define WKS_DX_SWAPGROUPS_FORCE_WAIT_PREVIOUS_PRESENT                  0x00000004
#define WKS_DX_SWAPGROUPS_DEFAULT                                      WKS_DX_SWAPGROUPS_USE_DRIVER_DEFAULT


#define WKS_FEATURE_DEBUG_CONTROL_STRING                               "WksFeatureDebugControl"
#define WKS_FEATURE_DEBUG_CONTROL_ID                                   0x11e21667
#define WKS_FEATURE_DEBUG_CONTROL_OVERINSTALL                          0 // OVERRIDE
#define WKS_FEATURE_DEBUG_CONTROL_OFF                                  0x00000000
#define WKS_FEATURE_DEBUG_CONTROL_ENABLE_HDR_INDICATOR                 0x00000001
#define WKS_FEATURE_DEBUG_CONTROL_DEFAULT                              WKS_FEATURE_DEBUG_CONTROL_OFF


#define WKS_FEATURE_SUPPORT_CONTROL_STRING                             "WorkstationFeatureControl"
#define WKS_FEATURE_SUPPORT_CONTROL_ID                                 0x11d9dc84
#define WKS_FEATURE_SUPPORT_CONTROL_OVERINSTALL                        1 // MERGE
#define WKS_FEATURE_SUPPORT_CONTROL_OFF                                0x00000000
#define WKS_FEATURE_SUPPORT_CONTROL_SRS_1714_WIN8_STEREO               0x00000001
#define WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_EXPORT_IF_ENABLED      0x00000002
#define WKS_FEATURE_SUPPORT_CONTROL_HDMI_STEREO                        0x00000004
#define WKS_FEATURE_SUPPORT_CONTROL_HDMI_EXCLUSIVE_STEREO              0x00000008
#define WKS_FEATURE_SUPPORT_CONTROL_USE_ANY_FRAME_FLIP_STEREO_MODE_FOR_TFP_AND_SWAPGROUP 0x00000020
#define WKS_FEATURE_SUPPORT_CONTROL_ALLOW_SPLIT_STEREO_PRESENT_BLITS   0x00000040
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DEEP_COLOR_SUPPORT         0x00000080
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_WIN8_STEREO_MODE_REFRESHRATE_EXPORT_BISECTION 0x00000100
#define WKS_FEATURE_SUPPORT_CONTROL_ENABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING_ALL 0x00000200
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_VIDPNOWNERSHIP_CHANGE_BLANKING_SKIPPING 0x00000400
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_SCANOUT_COMP_IFLIP         0x00000800
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_CSC_FOR_NON_DWM_PRIMARIES  0x00001000
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_DWM_STEREO_DFLIP           0x00002000
#define WKS_FEATURE_SUPPORT_CONTROL_DISABLE_INTERNAL_DISPLAY_MS_STEREO_MODES 0x00004000
#define WKS_FEATURE_SUPPORT_CONTROL_EXPORT_HIGH_COLOR_CAPS_ON_10BPC_DISPLAYS 0x00008000
#define WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_NON_DWM 0x00010000
#define WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_PRIVATE_CONTEXT_CHANNEL_FOR_DWM 0x00020000
#define WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SWAPGROUP_DWM_FLIP_BROADCASTING 0x00040000
#define WKS_FEATURE_SUPPORT_CONTROL_WIN8_STEREO_ENFORCE_DIN_SIGNAL     0x00080000
#define WKS_FEATURE_SUPPORT_CONTROL_ENABLE_SMOOTHSCALING_SUPPORT_ON_QUADRO 0x00100000
#define WKS_FEATURE_SUPPORT_CONTROL_ENABLE_DL_DSR_SUPPORT_ON_QUADRO    0x00200000
#define WKS_FEATURE_SUPPORT_CONTROL_DISALLOW_STEREO_OUTPUT_CONTROL_OVERRIDE 0x00400000
#define WKS_FEATURE_SUPPORT_CONTROL_DEFAULT                            0x00086143


#define WKS_MEMORY_ALLOCATION_POLICY_STRING                            "11223344"
#define WKS_MEMORY_ALLOCATION_POLICY_ID                                0x11112233
#define WKS_MEMORY_ALLOCATION_POLICY_OVERINSTALL                       1 // MERGE
#define WKS_MEMORY_ALLOCATION_POLICY_AS_NEEDED                         0x0
#define WKS_MEMORY_ALLOCATION_POLICY_MODERATE_PRE_ALLOCATION           0x1
#define WKS_MEMORY_ALLOCATION_POLICY_AGGRESSIVE_PRE_ALLOCATION         0x2
#define WKS_MEMORY_ALLOCATION_POLICY_DEFAULT                           WKS_MEMORY_ALLOCATION_POLICY_AS_NEEDED


#define WKS_MOSAIC_TOPOLOGY_REQUESTED_STRING                           "0x4fa775"
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_ID                               0x114fa775
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_OVERINSTALL                      0 // OVERRIDE
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_OFF                              0
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_0                                0
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_FALSE                            0
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_REQUEST_DISABLED                 0
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_ON                               1
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_1                                1
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_TRUE                             1
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_REQUEST_ENABLED                  1
#define WKS_MOSAIC_TOPOLOGY_REQUESTED_DEFAULT                          WKS_MOSAIC_TOPOLOGY_REQUESTED_OFF


#define WKS_POST_PROCESSING_ENGINE_CONTROL_STRING                      "WksPostProcessingEngineControl"
#define WKS_POST_PROCESSING_ENGINE_CONTROL_ID                          0x11112256
#define WKS_POST_PROCESSING_ENGINE_CONTROL_OVERINSTALL                 1 // MERGE
#define WKS_POST_PROCESSING_ENGINE_CONTROL_OFF                         0x00000000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_DWM              0x00000001
#define WKS_POST_PROCESSING_ENGINE_CONTROL_EXECUTE_ON_NON_DWM          0x00000002
#define WKS_POST_PROCESSING_ENGINE_CONTROL_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE 0x00000004
#define WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_DLDSR 0x00000008
#define WKS_POST_PROCESSING_ENGINE_CONTROL_USE_DEVICE_RENDER_CHANNEL   0x00000010
#define WKS_POST_PROCESSING_ENGINE_CONTROL_USE_UMD_SHADER_RESOURCE     0x00000020
#define WKS_POST_PROCESSING_ENGINE_CONTROL_DRAW_ON_SCREEN_INDICATOR_UPSCALE 0x00000040
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_ALL_CONTROLLED_BITS 0xFFFF0000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_DWM     0x00010000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_EXECUTE_ON_NON_DWM 0x00020000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_SCRATCH_MEMORY_AS_GPU_PROGRAM_STORAGE 0x00040000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_DLDSR 0x00080000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_DEVICE_RENDER_CHANNEL 0x00100000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_USE_UMD_SHADER_RESOURCE 0x00200000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_MASK_FOR_DRAW_ON_SCREEN_INDICATOR_UPSCALE 0x00400000
#define WKS_POST_PROCESSING_ENGINE_CONTROL_DEFAULT                     0x00000033


#define WKS_SCANOUT_COMPOSITION_CONTROL_STRING                         "WksScanoutCompositionControl"
#define WKS_SCANOUT_COMPOSITION_CONTROL_ID                             0x11112255
#define WKS_SCANOUT_COMPOSITION_CONTROL_OVERINSTALL                    1 // MERGE
#define WKS_SCANOUT_COMPOSITION_CONTROL_OFF                            0x00000000
#define WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_UNICAST        0x00000001
#define WKS_SCANOUT_COMPOSITION_CONTROL_MULTIGPU_MOSAIC_ALLOC_PACKING  0x00000002
#define WKS_SCANOUT_COMPOSITION_CONTROL_ENABLE_GAMMA_FOR_PER_PIXEL_INTENSITY 0x00000004
#define WKS_SCANOUT_COMPOSITION_CONTROL_DEFAULT                        0x00000003


#define WKS_STEREO_DONGLE_SUPPORT_STRING                               "EnableStereoDongleSupport"
#define WKS_STEREO_DONGLE_SUPPORT_ID                                   0x112493bd
#define WKS_STEREO_DONGLE_SUPPORT_OVERINSTALL                          1 // MERGE
#define WKS_STEREO_DONGLE_SUPPORT_OFF                                  0
#define WKS_STEREO_DONGLE_SUPPORT_DAC                                  1
#define WKS_STEREO_DONGLE_SUPPORT_DLP                                  2
#define WKS_STEREO_DONGLE_SUPPORT_DEFAULT                              WKS_STEREO_DONGLE_SUPPORT_DAC


#define WKS_STEREO_SUPPORT_STRING                                      "EnableStereoSupport"
#define WKS_STEREO_SUPPORT_ID                                          0x11aa9e99
#define WKS_STEREO_SUPPORT_OVERINSTALL                                 1 // MERGE
#define WKS_STEREO_SUPPORT_OFF                                         0
#define WKS_STEREO_SUPPORT_ON                                          1
#define WKS_STEREO_SUPPORT_DEFAULT                                     WKS_STEREO_SUPPORT_OFF


#define WKS_STEREO_SWAP_MODE_STRING                                    "33333333"
#define WKS_STEREO_SWAP_MODE_ID                                        0x11333333
#define WKS_STEREO_SWAP_MODE_OVERINSTALL                               1 // MERGE
#define WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL                       0x0
#define WKS_STEREO_SWAP_MODE_PER_EYE                                   0x1
#define WKS_STEREO_SWAP_MODE_PER_EYE_PAIR                              0x2
#define WKS_STEREO_SWAP_MODE_LEGACY_BEHAVIOR                           0x3
#define WKS_STEREO_SWAP_MODE_PER_EYE_FOR_SWAP_GROUP                    0x4
#define WKS_STEREO_SWAP_MODE_DEFAULT                                   WKS_STEREO_SWAP_MODE_APPLICATION_CONTROL


#define YUV_EMULATION_MODE_STRING                                      "WksYuvEmulationMode"
#define YUV_EMULATION_MODE_ID                                          0x11e21665
#define YUV_EMULATION_MODE_OVERINSTALL                                 0 // OVERRIDE
#define YUV_EMULATION_MODE_OVERRIDE_OFF                                0x00000000
#define YUV_EMULATION_MODE_RANGE_OVERRIDE_MASK                         0x00000003
#define YUV_EMULATION_MODE_RANGE_OVERRIDE_NONE                         0x00000000
#define YUV_EMULATION_MODE_RANGE_OVERRIDE_FULL                         0x00000001
#define YUV_EMULATION_MODE_RANGE_OVERRIDE_LIMITED                      0x00000002
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_MASK                   0x00000070
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_NONE                   0x00000000
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT601                  0x00000010
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT709                  0x00000020
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020C                0x00000030
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_BT2020NC               0x00000040
#define YUV_EMULATION_MODE_COLORIMETRY_OVERRIDE_RGB                    0x00000050
#define YUV_EMULATION_MODE_BPC_OVERRIDE_MASK                           0x00000300
#define YUV_EMULATION_MODE_BPC_OVERRIDE_NONE                           0x00000000
#define YUV_EMULATION_MODE_BPC_OVERRIDE_8_BPC                          0x00000100
#define YUV_EMULATION_MODE_BPC_OVERRIDE_10_BPC                         0x00000200
#define YUV_EMULATION_MODE_BPC_OVERRIDE_12_BPC                         0x00000300
#define YUV_EMULATION_MODE_LUT_OVERRIDE_MASK                           0x00001000
#define YUV_EMULATION_MODE_LUT_OVERRIDE_NONE                           0x00000000
#define YUV_EMULATION_MODE_LUT_OVERRIDE_NO_LUT                         0x00001000
#define YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_MASK                       0x00002000
#define YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NONE                       0x00000000
#define YUV_EMULATION_MODE_SAT_HUE_OVERRIDE_NO_SAT_HUE                 0x00002000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_MASK                      0x00070000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_NONE                      0x00000000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_SDR                       0x00010000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_HDR                       0x00020000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_EDR                       0x00030000
#define YUV_EMULATION_MODE_HDR_MODE_OVERRIDE_LDR                       0x00040000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_MASK                   0x01F00000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NONE                   0x00000000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_CSC                 0x00100000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_SCALING             0x00200000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_NO_OETF                0x00400000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_ALL_FORMATS        0x00800000
#define YUV_EMULATION_MODE_HDR_CONTROL_OVERRIDE_HDR_DCIP3_OUTPUT       0x01000000
#define YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_MASK                  0x02000000
#define YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_PREALLOC_HDR          0x02000000
#define YUV_EMULATION_MODE_DEFAULT                                     YUV_EMULATION_MODE_YUV_PREALLOC_OVERRIDE_PREALLOC_HDR


#define ZCULL_SUBREGION_ALIQUOT_LIMIT_STRING                           "8AD8AD00"
#define ZCULL_SUBREGION_ALIQUOT_LIMIT_ID                               0x107cffba
#define ZCULL_SUBREGION_ALIQUOT_LIMIT_OVERINSTALL                      0 // OVERRIDE
#define ZCULL_SUBREGION_ALIQUOT_LIMIT_ZERO                             0x00000000
#define ZCULL_SUBREGION_ALIQUOT_LIMIT_NONE                             0xFFFFFFFF
#define ZCULL_SUBREGION_ALIQUOT_LIMIT_DEFAULT                          ZCULL_SUBREGION_ALIQUOT_LIMIT_NONE


#define ZCULL_SUBREGION_FORMATS_0_STRING                               "808EE280"
#define ZCULL_SUBREGION_FORMATS_0_ID                                   0x107c254a
#define ZCULL_SUBREGION_FORMATS_0_OVERINSTALL                          0 // OVERRIDE
#define ZCULL_SUBREGION_FORMATS_0_Z_16X16X2_4X4                        0x0
#define ZCULL_SUBREGION_FORMATS_0_Z_4X4                                0x0
#define ZCULL_SUBREGION_FORMATS_0_ZS_16X16_4X4                         0x1
#define ZCULL_SUBREGION_FORMATS_0_ZS_4x4                               0x1
#define ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X2                          0x2
#define ZCULL_SUBREGION_FORMATS_0_Z_4X2                                0x2
#define ZCULL_SUBREGION_FORMATS_0_Z_16X16_2X4                          0x3
#define ZCULL_SUBREGION_FORMATS_0_Z_2X4                                0x3
#define ZCULL_SUBREGION_FORMATS_0_Z_16X8_4X4                           0x4
#define ZCULL_SUBREGION_FORMATS_0_Z_8X8_4X2                            0x5
#define ZCULL_SUBREGION_FORMATS_0_Z_8X8_2X4                            0x6
#define ZCULL_SUBREGION_FORMATS_0_Z_16X16_4X8                          0x7
#define ZCULL_SUBREGION_FORMATS_0_Z_4X8_2X2                            0x8
#define ZCULL_SUBREGION_FORMATS_0_ZS_16X8_4X2                          0x9
#define ZCULL_SUBREGION_FORMATS_0_ZS_16X8_2X4                          0xa
#define ZCULL_SUBREGION_FORMATS_0_ZS_8X8_2X2                           0xb
#define ZCULL_SUBREGION_FORMATS_0_Z_4X8_1X1                            0xc
#define ZCULL_SUBREGION_FORMATS_0_NONE                                 0xf
#define ZCULL_SUBREGION_FORMATS_0_ONEHIGH                              0xfffffff8
#define ZCULL_SUBREGION_FORMATS_0_COARSEHIRES                          0x00000000
#define ZCULL_SUBREGION_FORMATS_0_DEFAULT                              0x22555555


#define ZCULL_SUBREGION_FORMATS_1_STRING                               "FAF8A723"
#define ZCULL_SUBREGION_FORMATS_1_ID                                   0x109c67d1
#define ZCULL_SUBREGION_FORMATS_1_OVERINSTALL                          0 // OVERRIDE
#define ZCULL_SUBREGION_FORMATS_1_Z_16X16X2_4X4                        0x0
#define ZCULL_SUBREGION_FORMATS_1_Z_4X4                                0x0
#define ZCULL_SUBREGION_FORMATS_1_ZS_16X16_4X4                         0x1
#define ZCULL_SUBREGION_FORMATS_1_ZS_4x4                               0x1
#define ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X2                          0x2
#define ZCULL_SUBREGION_FORMATS_1_Z_4X2                                0x2
#define ZCULL_SUBREGION_FORMATS_1_Z_16X16_2X4                          0x3
#define ZCULL_SUBREGION_FORMATS_1_Z_2X4                                0x3
#define ZCULL_SUBREGION_FORMATS_1_Z_16X8_4X4                           0x4
#define ZCULL_SUBREGION_FORMATS_1_Z_8X8_4X2                            0x5
#define ZCULL_SUBREGION_FORMATS_1_Z_8X8_2X4                            0x6
#define ZCULL_SUBREGION_FORMATS_1_Z_16X16_4X8                          0x7
#define ZCULL_SUBREGION_FORMATS_1_Z_4X8_2X2                            0x8
#define ZCULL_SUBREGION_FORMATS_1_ZS_16X8_4X2                          0x9
#define ZCULL_SUBREGION_FORMATS_1_ZS_16X8_2X4                          0xa
#define ZCULL_SUBREGION_FORMATS_1_ZS_8X8_2X2                           0xb
#define ZCULL_SUBREGION_FORMATS_1_Z_4X8_1X1                            0xc
#define ZCULL_SUBREGION_FORMATS_1_NONE                                 0xf
#define ZCULL_SUBREGION_FORMATS_1_ONELOW                               0x02222222
#define ZCULL_SUBREGION_FORMATS_1_COARSEHIRES                          0x00000000
#define ZCULL_SUBREGION_FORMATS_1_DEFAULT                              0xff222222


#define ZCULL_SUBREGION_REPORT_TYPE_STRING                             "8AD8A75"
#define ZCULL_SUBREGION_REPORT_TYPE_ID                                 0x1006114d
#define ZCULL_SUBREGION_REPORT_TYPE_OVERINSTALL                        0 // OVERRIDE
#define ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST                         0x00000000
#define ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_NO_ACCEPT               0x00000001
#define ZCULL_SUBREGION_REPORT_TYPE_DEPTH_TEST_LATE_Z                  0x00000002
#define ZCULL_SUBREGION_REPORT_TYPE_STENCIL_TEST                       0x00000003
#define ZCULL_SUBREGION_REPORT_TYPE_AUTOSELECT                         0xFFFFFFFF
#define ZCULL_SUBREGION_REPORT_TYPE_DEFAULT                            ZCULL_SUBREGION_REPORT_TYPE_AUTOSELECT


#define ZCULL_SUBREGION_STRATEGY_STRING                                "18ADD00D"
#define ZCULL_SUBREGION_STRATEGY_ID                                    0x10b083ee
#define ZCULL_SUBREGION_STRATEGY_OVERINSTALL                           0 // OVERRIDE
#define ZCULL_SUBREGION_STRATEGY_FORCE_DISABLE                         0x00000000
#define ZCULL_SUBREGION_STRATEGY_AUTOSELECT                            0x00000001
#define ZCULL_SUBREGION_STRATEGY_EXPLICIT                              0x00000002
#define ZCULL_SUBREGION_STRATEGY_DEFAULT                               ZCULL_SUBREGION_STRATEGY_AUTOSELECT


#define ZROP_L2_CACHE_CONTROL_STRING                                   "0x1fd5"
#define ZROP_L2_CACHE_CONTROL_ID                                       0x10001fd5
#define ZROP_L2_CACHE_CONTROL_OVERINSTALL                              0 // OVERRIDE
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_FIRST     0x00000000
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_NORMAL    0x00000001
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_EVICT_LAST      0x00000002
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_READ_SHIFT           0
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_FIRST        0x00000000
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_NORMAL       0x00000010
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_EVICT_LAST         0x00000020
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_READ_SHIFT              4
#define ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_FIRST           0x00000000
#define ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_NORMAL          0x00000100
#define ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_EVICT_LAST            0x00000200
#define ZROP_L2_CACHE_CONTROL_ZROP_PREFETCH_READ_SHIFT                 8
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_FIRST    0x00000000
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_NORMAL   0x00001000
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_EVICT_LAST     0x00002000
#define ZROP_L2_CACHE_CONTROL_ZROP_NONINTERLOCKED_WRITE_SHIFT          12
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_FIRST       0x00000000
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_NORMAL      0x00010000
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_EVICT_LAST        0x00020000
#define ZROP_L2_CACHE_CONTROL_ZROP_INTERLOCKED_WRITE_SHIFT             16
#define ZROP_L2_CACHE_CONTROL_USE_LEGACY                               0x00100000
#define ZROP_L2_CACHE_CONTROL_DEFAULT                                  ZROP_L2_CACHE_CONTROL_USE_LEGACY


#endif // _G_D3DOGLREG_H_

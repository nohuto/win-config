
/* THIS FILE IS AUTO-GENERATED!  DO NOT EDIT!
**
** To modify this file, regenerate after editing
** any RKY file
*/

#if !defined (_G_DISPREG_H_)
#define _G_DISPREG_H_

#if !defined KERNEL_NOTIFICATION_ID_FLAG 
#define KERNEL_NOTIFICATION_ID_FLAG                                    0x01000000
#define NEEDS_KERNEL_NOTIFICATION(id)                                  (id & KERNEL_NOTIFICATION_ID_FLAG)
#endif // KERNEL_NOTIFICATION_ID_FLAG 

#define DISPLAY_CLONE_GROUP_IDS_STRING                                 ""
#define DISPLAY_CLONE_GROUP_IDS_ID                                     0x5818a91d
#define DISPLAY_CLONE_GROUP_IDS_OVERINSTALL                            1 // MERGE
#define DISPLAY_CLONE_GROUP_IDS_NONE                                   L""
#define DISPLAY_CLONE_GROUP_IDS_DEFAULT                                DISPLAY_CLONE_GROUP_IDS_NONE


#define DISPLAY_COLS_STRING                                            ""
#define DISPLAY_COLS_ID                                                0x58e21bd4
#define DISPLAY_COLS_OVERINSTALL                                       1 // MERGE
#define DISPLAY_COLS_MIN                                               1
#define DISPLAY_COLS_MAX                                               255
#define DISPLAY_COLS_DEFAULT                                           DISPLAY_COLS_MIN


#define DISPLAY_GRID_BRIGHTNESS_STRING                                 ""
#define DISPLAY_GRID_BRIGHTNESS_ID                                     0x5888f014
#define DISPLAY_GRID_BRIGHTNESS_OVERINSTALL                            1 // MERGE
#define DISPLAY_GRID_BRIGHTNESS_MIN                                    0x00000000
#define DISPLAY_GRID_BRIGHTNESS_NORMAL                                 0x42480000
#define DISPLAY_GRID_BRIGHTNESS_MAX                                    0x42C80000
#define DISPLAY_GRID_BRIGHTNESS_DEFAULT                                DISPLAY_GRID_BRIGHTNESS_NORMAL


#define DISPLAY_GRID_CONTRAST_STRING                                   ""
#define DISPLAY_GRID_CONTRAST_ID                                       0x5899d709
#define DISPLAY_GRID_CONTRAST_OVERINSTALL                              1 // MERGE
#define DISPLAY_GRID_CONTRAST_MIN                                      0x00000000
#define DISPLAY_GRID_CONTRAST_NORMAL                                   0x42480000
#define DISPLAY_GRID_CONTRAST_MAX                                      0x42C80000
#define DISPLAY_GRID_CONTRAST_DEFAULT                                  DISPLAY_GRID_CONTRAST_NORMAL


#define DISPLAY_GRID_CSC_STRING                                        ""
#define DISPLAY_GRID_CSC_ID                                            0x5822d5ee
#define DISPLAY_GRID_CSC_OVERINSTALL                                   1 // MERGE
#define DISPLAY_GRID_CSC_NONE                                          L""
#define DISPLAY_GRID_CSC_DEFAULT                                       DISPLAY_GRID_CSC_NONE


#define DISPLAY_GRID_GAMMA_STRING                                      ""
#define DISPLAY_GRID_GAMMA_ID                                          0x58f95c9b
#define DISPLAY_GRID_GAMMA_OVERINSTALL                                 1 // MERGE
#define DISPLAY_GRID_GAMMA_MIN                                         0x3E99999A
#define DISPLAY_GRID_GAMMA_NORMAL                                      0x3f800000
#define DISPLAY_GRID_GAMMA_MAX                                         0x40333333
#define DISPLAY_GRID_GAMMA_DEFAULT                                     DISPLAY_GRID_GAMMA_NORMAL


#define DISPLAY_GRID_GAMMA_RAMP_STRING                                 ""
#define DISPLAY_GRID_GAMMA_RAMP_ID                                     0x58d3388f
#define DISPLAY_GRID_GAMMA_RAMP_OVERINSTALL                            1 // MERGE
#define DISPLAY_GRID_GAMMA_RAMP_NONE                                   L""
#define DISPLAY_GRID_GAMMA_RAMP_DEFAULT                                DISPLAY_GRID_GAMMA_RAMP_NONE


#define DISPLAY_GRID_POS_COL_STRING                                    ""
#define DISPLAY_GRID_POS_COL_ID                                        0x58ba728b
#define DISPLAY_GRID_POS_COL_OVERINSTALL                               1 // MERGE
#define DISPLAY_GRID_POS_COL_MIN                                       0
#define DISPLAY_GRID_POS_COL_MAX                                       100000
#define DISPLAY_GRID_POS_COL_DEFAULT                                   DISPLAY_GRID_POS_COL_MIN


#define DISPLAY_GRID_POS_ROW_STRING                                    ""
#define DISPLAY_GRID_POS_ROW_ID                                        0x584b70fe
#define DISPLAY_GRID_POS_ROW_OVERINSTALL                               1 // MERGE
#define DISPLAY_GRID_POS_ROW_MIN                                       0
#define DISPLAY_GRID_POS_ROW_MAX                                       100000
#define DISPLAY_GRID_POS_ROW_DEFAULT                                   DISPLAY_GRID_POS_ROW_MIN


#define DISPLAY_GRID_ROTATION_STRING                                   ""
#define DISPLAY_GRID_ROTATION_ID                                       0x589fe89a
#define DISPLAY_GRID_ROTATION_OVERINSTALL                              1 // MERGE
#define DISPLAY_GRID_ROTATION_ROTATE_0                                 0
#define DISPLAY_GRID_ROTATION_ROTATE_90                                1
#define DISPLAY_GRID_ROTATION_ROTATE_180                               2
#define DISPLAY_GRID_ROTATION_ROTATE_270                               3
#define DISPLAY_GRID_ROTATION_ROTATE_IGNORED                           4
#define DISPLAY_GRID_ROTATION_DEFAULT                                  DISPLAY_GRID_ROTATION_ROTATE_0


#define DISPLAY_GRID_SCALING_STRING                                    ""
#define DISPLAY_GRID_SCALING_ID                                        0x58d4b0b4
#define DISPLAY_GRID_SCALING_OVERINSTALL                               1 // MERGE
#define DISPLAY_GRID_SCALING_SCALING_TO_CLOSEST                        1
#define DISPLAY_GRID_SCALING_SCALING_MONITOR_SCALING                   1
#define DISPLAY_GRID_SCALING_SCALING_TO_NATIVE                         2
#define DISPLAY_GRID_SCALING_SCALING_ADAPTER_SCALING                   2
#define DISPLAY_GRID_SCALING_SCANOUT_TO_NATIVE                         3
#define DISPLAY_GRID_SCALING_SCALING_CENTERED                          3
#define DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE       5
#define DISPLAY_GRID_SCALING_SCALING_ASPECT_SCALING                    5
#define DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_CLOSEST      6
#define DISPLAY_GRID_SCALING_SCANOUT_TO_CLOSEST                        7
#define DISPLAY_GRID_SCALING_DEFAULT                                   DISPLAY_GRID_SCALING_SCALING_TO_ASPECT_SCANOUT_TO_NATIVE


#define DISPLAY_IDS_STRING                                             ""
#define DISPLAY_IDS_ID                                                 0x58b21e43
#define DISPLAY_IDS_OVERINSTALL                                        1 // MERGE
#define DISPLAY_IDS_NONE                                               L""
#define DISPLAY_IDS_DEFAULT                                            DISPLAY_IDS_NONE


#define DISPLAY_MODE_STRING                                            ""
#define DISPLAY_MODE_ID                                                0x58c7b07c
#define DISPLAY_MODE_OVERINSTALL                                       1 // MERGE
#define DISPLAY_MODE_NATIVE                                            L"native"
#define DISPLAY_MODE_DEFAULT                                           DISPLAY_MODE_NATIVE


#define DISPLAY_POS_COLS_STRING                                        ""
#define DISPLAY_POS_COLS_ID                                            0x586748c2
#define DISPLAY_POS_COLS_OVERINSTALL                                   1 // MERGE
#define DISPLAY_POS_COLS_NONE                                          L"0"
#define DISPLAY_POS_COLS_DEFAULT                                       DISPLAY_POS_COLS_NONE


#define DISPLAY_POS_ROWS_STRING                                        ""
#define DISPLAY_POS_ROWS_ID                                            0x5879ddc6
#define DISPLAY_POS_ROWS_OVERINSTALL                                   1 // MERGE
#define DISPLAY_POS_ROWS_NONE                                          L"0"
#define DISPLAY_POS_ROWS_DEFAULT                                       DISPLAY_POS_ROWS_NONE


#define DISPLAY_ROTATION_STRING                                        ""
#define DISPLAY_ROTATION_ID                                            0x58decfa8
#define DISPLAY_ROTATION_OVERINSTALL                                   1 // MERGE
#define DISPLAY_ROTATION_NONE                                          L"0"
#define DISPLAY_ROTATION_DEFAULT                                       DISPLAY_ROTATION_NONE


#define DISPLAY_ROWS_STRING                                            ""
#define DISPLAY_ROWS_ID                                                0x5822918d
#define DISPLAY_ROWS_OVERINSTALL                                       1 // MERGE
#define DISPLAY_ROWS_MIN                                               1
#define DISPLAY_ROWS_MAX                                               255
#define DISPLAY_ROWS_DEFAULT                                           DISPLAY_ROWS_MIN


#define DISPLAY_SCALING_STRING                                         ""
#define DISPLAY_SCALING_ID                                             0x587b0428
#define DISPLAY_SCALING_OVERINSTALL                                    1 // MERGE
#define DISPLAY_SCALING_NONE                                           L"0"
#define DISPLAY_SCALING_DEFAULT                                        DISPLAY_SCALING_NONE


#define OVERLAP_COLS_STRING                                            ""
#define OVERLAP_COLS_ID                                                0x58eb619d
#define OVERLAP_COLS_OVERINSTALL                                       1 // MERGE
#define OVERLAP_COLS_NONE                                              L"0"
#define OVERLAP_COLS_DEFAULT                                           OVERLAP_COLS_NONE


#define OVERLAP_ROWS_STRING                                            ""
#define OVERLAP_ROWS_ID                                                0x58dd36c1
#define OVERLAP_ROWS_OVERINSTALL                                       1 // MERGE
#define OVERLAP_ROWS_NONE                                              L"0"
#define OVERLAP_ROWS_DEFAULT                                           OVERLAP_ROWS_NONE


#endif // _G_DISPREG_H_

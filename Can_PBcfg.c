/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Can Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "Can.h"

/*
 * Module Version 1.0.0
 */
#define CAN_PBCFG_SW_MAJOR_VERSION              (1U)
#define CAN_PBCFG_SW_MINOR_VERSION              (0U)
#define CAN_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

/* AUTOSAR Version checking between Can_PBcfg.c and Can.h files */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (CAN_PBCFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (CAN_PBCFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Can_PBcfg.c and Can.h files */
#if ((CAN_PBCFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||  (CAN_PBCFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||  (CAN_PBCFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Can_Init API */
Can_ConfigType Can_Configuration = {
                                      .CanGeneral =
                                      {
                                           .CanMainFunctionRWPeriods =
                                           {
                                            .CanMainFunctionPeriod= CAN_MAIN_FUNCTION_PERIOD
                                           }
                                      },

                                      .CanConfigSet =
                                      {
                                           .CanController =
                                           {
                                             {
                                                .CanControllerId = CAN0_CONTROLLER_ID,
                                                .CanControllerBaudrateConfig =
                                                {
                                                 .BaudRate = CanConf_CAN0_CONTROLLER_BAUDRATE,
                                                 .PropSeg = CanConf_CAN0_CONTROLLER_PROPSEG,
                                                 .PhaseSeg1 = CanConf_CAN0_CONTROLLER_SEG1,
                                                 .PhaseSeg2 = CanConf_CAN0_CONTROLLER_SEG2,
                                                 .SyncJumpWidth = CanConf_CAN0_CONTROLLER_SYNC_JUMP_WIDTH
                                                }
                                             },

                                            {
                                                .CanControllerId = CAN1_CONTROLLER_ID,
                                                .CanControllerBaudrateConfig =
                                                {
                                                 .BaudRate = CanConf_CAN1_CONTROLLER_BAUDRATE,
                                                 .PropSeg = CanConf_CAN1_CONTROLLER_PROPSEG,
                                                 .PhaseSeg1 = CanConf_CAN1_CONTROLLER_SEG1,
                                                 .PhaseSeg2 = CanConf_CAN1_CONTROLLER_SEG2,
                                                 .SyncJumpWidth = CanConf_CAN1_CONTROLLER_SYNC_JUMP_WIDTH
                                                }
                                            }
                                           },

                                           .CanHardwareObject =
                                           {
                                               {
                                                .CanHandleType = CAN_HOH_HANDLETYPE_0,
                                                .CanHardwareObjectCount = CAN_HOH_COUNT_0,
                                                .CanIdType = CAN_HOH_ID_TYPE_0,
                                                .CanObjectId = CAN_HOH_ID_0,
                                                .CanObjectType = CAN_HOH_TYPE_0,
                                                .CanControllerRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_0],
                                                .CanHwFilter =
                                                    {
                                                     .CanHwFilterCode = CAN_HW_FILTER_CODE_0 ,
                                                     .CanHwFilterMask = CAN_HW_FILTER_MASK_0
                                                    }
                                               },

                                               {
                                                .CanHandleType = CAN_HOH_HANDLETYPE_1,
                                                .CanHardwareObjectCount = CAN_HOH_COUNT_1,
                                                .CanIdType = CAN_HOH_ID_TYPE_1,
                                                .CanObjectId = CAN_HOH_ID_1,
                                                .CanObjectType = CAN_HOH_TYPE_1,
                                                .CanControllerRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_1],
                                                .CanHwFilter =
                                                    {
                                                     .CanHwFilterCode = CAN_HW_FILTER_CODE_1 ,
                                                     .CanHwFilterMask = CAN_HW_FILTER_MASK_1
                                                    }
                                               },

                                               {
                                                .CanHandleType = CAN_HOH_HANDLETYPE_2,
                                                .CanHardwareObjectCount = CAN_HOH_COUNT_2,
                                                .CanIdType = CAN_HOH_ID_TYPE_2,
                                                .CanObjectId = CAN_HOH_ID_2,
                                                .CanObjectType = CAN_HOH_TYPE_2,
                                                .CanControllerRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_2],
                                                .CanHwFilter =
                                                    {
                                                     .CanHwFilterCode = CAN_HW_FILTER_CODE_2,
                                                     .CanHwFilterMask = CAN_HW_FILTER_MASK_2
                                                    }
                                               },

                                               {
                                                .CanHandleType = CAN_HOH_HANDLETYPE_3,
                                                .CanHardwareObjectCount = CAN_HOH_COUNT_3,
                                                .CanIdType = CAN_HOH_ID_TYPE_3,
                                                .CanObjectId = CAN_HOH_ID_3,
                                                .CanObjectType = CAN_HOH_TYPE_3,
                                                .CanControllerRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_3],
                                                .CanHwFilter =
                                                    {
                                                     .CanHwFilterCode = CAN_HW_FILTER_CODE_3,
                                                     .CanHwFilterMask = CAN_HW_FILTER_MASK_3
                                                    }
                                               },

                                               {
                                                .CanHandleType = CAN_HOH_HANDLETYPE_4,
                                                .CanHardwareObjectCount = CAN_HOH_COUNT_4,
                                                .CanIdType = CAN_HOH_ID_TYPE_4,
                                                .CanObjectId = CAN_HOH_ID_4,
                                                .CanObjectType = CAN_HOH_TYPE_4,
                                                .CanControllerRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_4],
                                                .CanHwFilter =
                                                    {
                                                     .CanHwFilterCode = CAN_HW_FILTER_CODE_4 ,
                                                     .CanHwFilterMask = CAN_HW_FILTER_MASK_4
                                                    }
                                               }
                                           }
                                      }

                                 };

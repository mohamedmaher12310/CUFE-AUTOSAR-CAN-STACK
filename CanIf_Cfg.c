/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf_Cfg.c
 *
 * Description: Source file for CanIf Pre-Compile Configurations.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include of CanIf_Cfg Header Filer*/
#include "CanIf.h"


const CanIf_ConfigType CanIf_Configuration =
                            {
                             .CanIfCtrlDrvCfg =
                                 {
                                  .CanIfCtrlDrvInitHohConfigRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[ZERO],

                                  .CanIfCtrlCfg =
                                  {
                                      {
                                        .CanIfCtrlId = CAN0_CONTROLLER_ID,
                                        .CanIfCtrlCanCtrlRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_0]
                                      },
                                      {
                                         .CanIfCtrlId = CAN1_CONTROLLER_ID,
                                         .CanIfCtrlCanCtrlRef = &Can_Configuration.CanConfigSet.CanController[CAN_HOH_REF_1]
                                      }
                                  }
                                 },

                               .CanIfInitCfg =
                                   {
                                    .CanIfBufferCfg =
                                        {
                                             {
                                              .CanIfBufferSize = 1,
                                              .CanIfBufferHthRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[ZERO].CanIfHthCfg[0]
                                             },
                                             {
                                              .CanIfBufferSize = 1,
                                              .CanIfBufferHthRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[ZERO].CanIfHthCfg[0]
                                             }
                                        },
                                    .CanIfInitHohCfg =
                                       {
                                         {
                                              .CanIfHthCfg =
                                              {
                                                      {
                                                       .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[ZERO],
                                                       .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[1]
                                                      },
                                                      {
                                                       .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[ZERO],
                                                       .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[3]
                                                      },
                                                      {
                                                       .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[ZERO],
                                                       .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[4]
                                                      }
                                              }
                                          }
                                        },
                                     .CanIfTxPduCfg =
                                         {
                                              {
                                               .CanIfTxPduCanId = CanIfTxPduCanId_0,
                                               .CanIfTxPduCanIdMask = CanIfTxPduCanIdMask_0,
                                               .CanIfTxPduCanIdType = CanIfTxPduCanIdType_0,
                                               .CanIfTxPduId = CanIfTxPduId_0,
                                               .CanIfTxPduTruncation = FALSE,
                                               .CanIfTxPduType = CanIfTxPduType_0,
                                               .CanIfTxPduBufferRef = &CanIf_Configuration.CanIfInitCfg.CanIfBufferCfg[0U]
                                              },
                                              {
                                               .CanIfTxPduCanId = CanIfTxPduCanId_1,
                                               .CanIfTxPduCanIdMask = CanIfTxPduCanIdMask_1,
                                               .CanIfTxPduCanIdType = CanIfTxPduCanIdType_1,
                                               .CanIfTxPduId = CanIfTxPduId_1,
                                               .CanIfTxPduTruncation = FALSE,
                                               .CanIfTxPduType = CanIfTxPduType_1,
                                               .CanIfTxPduBufferRef = &CanIf_Configuration.CanIfInitCfg.CanIfBufferCfg[0U]
                                              },
                                         }
                                   },
                            };

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
  .CanIfCtrlDrvInitHohConfigRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID],
  .CanIfCtrlDrvNameRef = &Can_Configuration.CanGeneral,
  .CanIfCtrlCfg =
  {
   {
    .CanIfCtrlId = CanIfCtrlId_0,
    .CanIfCtrlCanCtrlRef = &Can_Configuration.CanConfigSet.CanController[CAN0_CONTROLLER_ID]
   },
   {
    .CanIfCtrlId = CanIfCtrlId_1,
    .CanIfCtrlCanCtrlRef = &Can_Configuration.CanConfigSet.CanController[CAN1_CONTROLLER_ID]
   }
  }
 },

 .CanIfInitCfg =
 {
  .CanIfBufferCfg =
  {
   {
    .CanIfBufferSize = 1,
    .CanIfBufferHthRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHthCfg[HTH0_ID]
   },
   {
    .CanIfBufferSize = 1,
    .CanIfBufferHthRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHthCfg[HTH1_ID]
   },
   {
    .CanIfBufferSize = 1,
    .CanIfBufferHthRef = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHthCfg[HTH2_ID]
   }
  },

  .CanIfInitHohCfg =
  {
   {
    .CanIfHthCfg =
    {
     {
      .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[CAN0_CONTROLLER_ID],
      .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[CAN_HOH_ID_1]
     },
     {
      .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[CAN0_CONTROLLER_ID],
      .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[CAN_HOH_ID_3]
     },
     {
      .CanIfHthCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[CAN0_CONTROLLER_ID],
      .CanIfHthIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[CAN_HOH_ID_4]
     }
    },
    .CanIfHrhCfg =
    {
     {
      .CanIfHrhCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[CAN0_CONTROLLER_ID],
      .CanIfHrhIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[CAN_HOH_ID_0],
      .CanIfHrhSoftwareFilter=TRUE,
      .CanIfHrhRangeCfg=
      {
       .CanIfHrhRangeRxPduLowerCanId=CanIfHrhRangeRxPduLowerCanId_0,
       .CanIfHrhRangeRxPduUpperCanId=CanIfHrhRangeRxPduUpperCanId_0
      }
     },
     {
      .CanIfHrhCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[CAN0_CONTROLLER_ID],
      .CanIfHrhIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[CAN_HOH_ID_2],
      .CanIfHrhSoftwareFilter=TRUE,
      .CanIfHrhRangeCfg=
      {
       .CanIfHrhRangeRxPduLowerCanId=CanIfHrhRangeRxPduLowerCanId_1,
       .CanIfHrhRangeRxPduUpperCanId=CanIfHrhRangeRxPduUpperCanId_1
      }
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
#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
    .CanIfTxPduReadNotifyStatus=FALSE,
#endif /*CanIfPublicReadTxPduNotifyStatusApi */
    .CanIfTxPduTruncation = FALSE,
    .CanIfTxPduType = CanIfTxPduType_0,
    .CanIfTxPduUserTxConfirmationUL = CanIfTxPduUserTxConfirmationUL_0,
    .CanIfTxPduBufferRef = &CanIf_Configuration.CanIfInitCfg.CanIfBufferCfg[HTH0_ID]
   },
   {
    .CanIfTxPduCanId = CanIfTxPduCanId_1,
    .CanIfTxPduCanIdMask = CanIfTxPduCanIdMask_1,
    .CanIfTxPduCanIdType = CanIfTxPduCanIdType_1,
    .CanIfTxPduId = CanIfTxPduId_1,
#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
    .CanIfTxPduReadNotifyStatus=FALSE,
#endif /*CanIfPublicReadTxPduNotifyStatusApi */
    .CanIfTxPduTruncation = FALSE,
    .CanIfTxPduType = CanIfTxPduType_1,
    .CanIfTxPduUserTxConfirmationUL = CanIfTxPduUserTxConfirmationUL_1,
    .CanIfTxPduBufferRef = &CanIf_Configuration.CanIfInitCfg.CanIfBufferCfg[HTH1_ID]
   }
  },
  .CanIfRxPduCfg =
  {
   {
    .CanIfRxPduCanId = CanIfRxPduCanId_0,
    .CanIfRxPduCanIdMask =CanIfRxPduCanIdMask_0,
    .CanIfRxPduHrhIdRef=&CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHrhCfg[HRH0_ID],
#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
    .CanIf_RxPduReadNotifyStatus=TRUE,
#endif /*CanIfPublicReadRxPduNotifyStatusApi */
    .CanIfRxPduCanIdType = STANDARD_CAN_Rx,
    .CanIfRxPduId = CanIfRxPduId_0,
    .CanIfRxPduDataLength=CanIfRxPduDataLength_0,
#if(STD_ON == CanIfPublicReadRxPduDataApi)
    .CanIf_RxPduReadData=TRUE,
#endif /*CanIfPublicReadRxPduDataApi*/
    .CanIfRxPduUserRxIndicationName=CanIfRxPduUserRxIndicationName_0
   },
   {
    .CanIfRxPduCanId = CanIfRxPduCanId_1,
    .CanIfRxPduCanIdMask =CanIfRxPduCanIdMask_1,
    .CanIfRxPduHrhIdRef=&CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHrhCfg[HRH1_ID],
#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
    .CanIf_RxPduReadNotifyStatus=TRUE,
#endif /*CanIfPublicReadRxPduNotifyStatusApi */
    .CanIfRxPduCanIdType = STANDARD_CAN_Rx,
    .CanIfRxPduId = CanIfRxPduId_1,
    .CanIfRxPduDataLength=CanIfRxPduDataLength_1,
#if(STD_ON == CanIfPublicReadRxPduDataApi)
    .CanIf_RxPduReadData=TRUE,
#endif /*CanIfPublicReadRxPduDataApi*/
    .CanIfRxPduUserRxIndicationName=CanIfRxPduUserRxIndicationName_1
   }
  }
 }
};

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
    },
    /* RX_TEAM */
    .CanIfHrhCfg =
    {
     {
      .CanIfHrhCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[ZERO],
      .CanIfHrhIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[0], /*How!!!!!!!!!!!!!!!!!!!*/
      .CanIfHrhSoftwareFilter=TRUE,
      .CanIfHrhRangeCfg=
      {
       .CanIfHrhRangeBaseId=0,
       .CanIfHrhRangeMask=0,
       .CanIfHrhRangeRxPduLowerCanId=0,
       .CanIfHrhRangeRxPduUpperCanId=0x1FFFFFFF,
       .CanIfHrhRangeRxPduRangeCanIdType= STANDARD


      }
     },
     {
      .CanIfHrhCanCtrlIdRef = &CanIf_Configuration.CanIfCtrlDrvCfg.CanIfCtrlCfg[ZERO],
      .CanIfHrhIdSymRef = &Can_Configuration.CanConfigSet.CanHardwareObject[2],
      .CanIfHrhSoftwareFilter=TRUE,
      .CanIfHrhRangeCfg=
      {
       .CanIfHrhRangeBaseId=0,
       .CanIfHrhRangeMask=0,
       .CanIfHrhRangeRxPduLowerCanId=0,
       .CanIfHrhRangeRxPduUpperCanId=0x1FFFFFFF,
       .CanIfHrhRangeRxPduRangeCanIdType= STANDARD


      }
     }



    }
   }
   /* ----------------------------  */
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
   }
  },
  .CanIfRxPduCfg =
  {
   {
    .CanIfRxPduHrhIdRef=&CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[0].CanIfHrhCfg[0],

#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
    .CanIf_RxPduReadNotifyStatus=FALSE,
#endif /*CanIfPublicReadRxPduNotifyStatusApi */
    .CanIfRxPduUserRxIndicationName=PDUR,
    .CanIfRxPduCanIdType = STANDARD_CAN,
    .CanIfRxPduId = CanIfRxPduId_0,
    .CanIfRxPduDataLength=8,
#if(STD_ON == CanIfPublicReadRxPduDataApi)
    .CanIf_RxPduReadData=FALSE,
#endif /*CanIfPublicReadRxPduDataApi*/
    .CanIfRxPduCanId = CanIfCtrlId_0,
    .CanIfRxPduCanIdMask =CanIfRxPduCanIdMask_0

   },
   {
    .CanIfRxPduHrhIdRef=&CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[0].CanIfHrhCfg[0],
#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
    .CanIf_RxPduReadNotifyStatus=FALSE,
#endif /*CanIfPublicReadRxPduNotifyStatusApi */
    .CanIfRxPduUserRxIndicationName=PDUR,
    .CanIfRxPduCanIdType = STANDARD_CAN,
    .CanIfRxPduId = CanIfRxPduId_1,
    .CanIfRxPduDataLength=8,
#if(STD_ON == CanIfPublicReadRxPduDataApi)
    .CanIf_RxPduReadData=FALSE,
#endif /*CanIfPublicReadRxPduDataApi*/
    .CanIfRxPduCanId = CanIfCtrlId_1,
    .CanIfRxPduCanIdMask = CanIfRxPduCanIdMask_1
   },
  }
 },
};

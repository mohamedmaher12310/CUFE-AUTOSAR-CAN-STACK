/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_PBcfg.c
 *
 * Description: Post Build Configuration Source file for  - PduR module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "PduR.h"

const PduR_PBConfigType PduR_Configuration =
{
 .PduRRoutingPaths[ZERO] =
 {

  .PduRConfigurationId = PduR_Configuration_ID_0,
  .PduRDestPdu =
  { .PduRDestPduDataProvision = PduR_DestData_Provision,
    .PduRDestPduRef = (CanIfTxPduCfg*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ZERO],
    .PduRDestPduHandleId = PduRDestPduHandleId_0
  },
  .PduRRoutingPath =
  { .PduRQueueDepth = PduR_Queue_Depth_0,
    .PduRDestPduRef = (PduRDestPdu*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ZERO],
    .PduRSrcPduRef = (PduRSrcPdu*)&Com.ComIPdu[ZERO]
  },
  .PduRSrcPdu=
  { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
    .PduRSrcPduRef = (ComIPdu*)&Com.ComIPdu[ZERO],
    .PduRSrcPduHandleId = PduRSrcPduHandleId_0
  }

 },
 .PduRRoutingPaths[ONE] =
 {
   .PduRConfigurationId = PduR_Configuration_ID_1,
   .PduRDestPdu =
   { .PduRDestPduDataProvision = PduR_DestData_Provision,
     .PduRDestPduRef = (CanIfTxPduCfg*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ONE],
     .PduRDestPduHandleId = PduRDestPduHandleId_1
   },
   .PduRRoutingPath =
   { .PduRQueueDepth = PduR_Queue_Depth_1,
     .PduRDestPduRef = (PduRDestPdu*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ONE],
     .PduRSrcPduRef = (PduRSrcPdu*)&Com.ComIPdu[ONE]
   },
   .PduRSrcPdu=
   { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
     .PduRSrcPduRef = (ComIPdu*)&Com.ComIPdu[ONE],
     .PduRSrcPduHandleId = PduRSrcPduHandleId_1
   }
 },
 .PduRRoutingPaths[TWO] =
 {
   .PduRConfigurationId = PduR_Configuration_ID_2,
   .PduRDestPdu =
   { .PduRDestPduDataProvision = PduR_DestData_Provision,
     .PduRDestPduRef = (CanIfTxPduCfg*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TWO],
     .PduRDestPduHandleId = PduRDestPduHandleId_2
   },
   .PduRRoutingPath =
   { .PduRQueueDepth = PduR_Queue_Depth_2,
     .PduRDestPduRef = (PduRDestPdu*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TWO],
     .PduRSrcPduRef = (PduRSrcPdu*)&Com.ComIPdu[TWO]
   },
   .PduRSrcPdu=
   { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
     .PduRSrcPduRef = (ComIPdu*)&Com.ComIPdu[TWO],
     .PduRSrcPduHandleId = PduRSrcPduHandleId_2
   }
  }
};


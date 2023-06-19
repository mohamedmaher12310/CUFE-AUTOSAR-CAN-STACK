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
 .PduRRoutingPaths[0] =
 {

  .PduRConfigurationId = PduR_Configuration_ID1,
  .PduRDestPdu =
  { .PduRDestPduDataProvision = PduR_DestData_Provision,
    .PduRDestPduRef = &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ZERO],
    .PduRDestPduHandleId = 42
  },
  .PduRRoutingPath =
  { .PduRQueueDepth = PduR_Queue_Depth,
    .PduRDestPduRRef = (PduRDestPdu*)&PduR_Configuration.PduRRoutingPaths[ZERO].PduRDestPdu,
    .PduRSrcPduRRef = (PduRSrcPdu*)&PduR_Configuration.PduRRoutingPaths[ZERO].PduRSrcPdu
  },
  .PduRSrcPdu=
  { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
    .PduRSrcPduRef = &Com.ComIPdu[ZERO],
    .PduRSrcPduHandleId = 1
  }

 },
 .PduRRoutingPaths[1] =
 {
   .PduRConfigurationId = PduR_Configuration_ID2,
   .PduRDestPdu =
   { .PduRDestPduDataProvision = PduR_DestData_Provision,
     .PduRDestPduRef = &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ONE],
     .PduRDestPduHandleId = 42
   },
   .PduRRoutingPath =
   { .PduRQueueDepth = PduR_Queue_Depth,
     .PduRDestPduRRef = (PduRDestPdu*)&PduR_Configuration.PduRRoutingPaths[ONE].PduRDestPdu,
     .PduRSrcPduRRef = (PduRSrcPdu*)&PduR_Configuration.PduRRoutingPaths[ONE].PduRSrcPdu
   },
   .PduRSrcPdu=
   { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
     .PduRSrcPduRef = &Com.ComIPdu[ONE],
     .PduRSrcPduHandleId = 2
   }
 },
 .PduRRoutingPaths[2] =
 {
   .PduRConfigurationId = PduR_Configuration_ID3,
   .PduRDestPdu =
   { .PduRDestPduDataProvision = PduR_DestData_Provision,
     .PduRDestPduRef = &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TWO],
     .PduRDestPduHandleId = 42
   },
   .PduRRoutingPath =
   { .PduRQueueDepth = PduR_Queue_Depth,
     .PduRDestPduRRef = (PduRDestPdu*)&PduR_Configuration.PduRRoutingPaths[TWO].PduRDestPdu,
     .PduRSrcPduRRef = (PduRSrcPdu*)&PduR_Configuration.PduRRoutingPaths[TWO].PduRSrcPdu
   },
   .PduRSrcPdu=
   { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation,
     .PduRSrcPduRef = &Com.ComIPdu[TWO],
     .PduRSrcPduHandleId = 3
   }
  }
};


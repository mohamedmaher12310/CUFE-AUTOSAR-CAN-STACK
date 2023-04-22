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
 .PduRRoutingPaths =
 {
  {
   .PduRConfigurationId = PduR_Configuration_ID1,
   .PduRDestPdu =
   { .PduRDestPduDataProvision = PduR_DestData_Provision,
     .PduRDestPduRef = &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[ZERO]
   },
   .PduRRoutingPath =
   { .PduRQueueDepth = PduR_Queue_Depth,
     .PduRDestPduRRef = (PduRDestPdu*)&PduR_Configuration.PduRRoutingPaths[ZERO].PduRDestPdu,
     .PduRSrcPduRRef = (PduRSrcPdu*)&PduR_Configuration.PduRRoutingPaths[ZERO].PduRSrcPdu
   },
   .PduRSrcPdu=
   { .PduRSrcPduUpTxConf = PduR_SrcPduUp_TxConfirmation
     //.PduRSrcPduRef = &
   }
  }
 }
};


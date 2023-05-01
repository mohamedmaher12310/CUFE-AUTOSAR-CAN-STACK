/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_Com.c
 *
 * Description: Source file for PDU Router Upper Layer Interface Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include the Det header file*/
#include "Det.h"

#include "PduR_Com.h"

uint8 check_flag=0;

/************************************************************************************
 * Service Name: Com_RxIndication
 * Service ID[hex]: 0x42
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): RxPduId ID of the received PDU.
 *                  PduInfoPtr Contains the length (SduLength) of the received PDU,
 *                  a pointer to a buffer (SduDataPtr) containing the PDU, and the
 *                  MetaData related to this PDU.
 *
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:Indication of a received PDU from a
 *             lower layer communication interface module.
 ************************************************************************************/
void Com_RxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr)
{

    uint8 pdu_id = Com.ComIPdu[RxPduId].ComIPduHandleId;

    if( RECEIVE== Com.ComIPdu[pdu_id].ComIPduDirection)
    {
        /* Copy data */
        PDU[pdu_id].SduLength = PduInfoPtr->SduLength;
        PDU[pdu_id].SduDataPtr = PduInfoPtr->SduDataPtr;
        PDU[pdu_id].MetaDataPtr = PduInfoPtr->MetaDataPtr;
    }
    else
    {
        /*Do Nothing*/
    }
    if( DEFERRED == Com.ComIPdu[pdu_id].ComIPduSignalProcessing)
    {
        check_flag = 1;
    }
    else    /*immediate*/
    {


    }
}

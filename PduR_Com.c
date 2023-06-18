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
    uint8 pdu_counter,signal_counter,return_value;
    //    uint8 pdu_id = Com.ComIPdu[RxPduId].ComIPduHandleId;

    if( RECEIVE== Com.ComIPdu[RxPduId].ComIPduDirection)
    {
        /* Copy data */
        PDU[RxPduId].SduLength = PduInfoPtr->SduLength;
        *(PDU[RxPduId].SduDataPtr) = *(PduInfoPtr->SduDataPtr);
        *(PDU[RxPduId].MetaDataPtr) = *(PduInfoPtr->MetaDataPtr);
        if( DEFERRED == Com.ComIPdu[RxPduId].ComIPduSignalProcessing)
        {
            check_flag = 1;
        }
        else    /*immediate*/
        {
            /*i reached here during context of my ISR so do the unpacking here ;)*/
            /*check flow of receiving*/
                for(signal_counter=0;signal_counter<MAX_NUM_OF_SIGNAL;signal_counter++)
                {
                    /*i think if we implemented the update bits will free me from this for loop*/
                    /*check the update bit which will ease it for me to update the specific needed signals*/
                    /**/
                    return_value=  Com_ReceiveSignal(Com.ComSignal[signal_counter].ComHandleId,&SignalObject[signal_counter]);
                    return_value=  Com_ReceiveSignal(Com.ComSignal[signal_counter].ComHandleId,&SignalObject[signal_counter]);
                    if( E_OK == return_value )
                    {

                        /*void Com_CbkRxAck(void);*/
                    }
                    else
                    {
                        /*handling the COM_SERVICE_NOT_AVAILABLE and COM_BUSY cases*/
                    }

                }





        }
    }
    else
    {
        /*Do Nothing*/
    }

}

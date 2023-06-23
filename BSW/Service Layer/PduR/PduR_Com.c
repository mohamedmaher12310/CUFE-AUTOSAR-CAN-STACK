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
#include "../Det/Det.h"

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
#if(COM_DEV_ERROR_DETECT == STD_ON)
    /* Check if the module is initialized or not*/
    if ( ComCurrent_State ==  COM_UNINIT)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, Com_RxIndication_SID, COM_E_UNINIT);
    }
    else
    {
        /* MISRA*/
    }

    if(RxPduId>ComMaxIPduCnt)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, Com_RxIndication_SID, COM_E_PARAM);
    }

    else
    {
        /* MISRA*/
    }

    /* check if the input configuration pointer is not a NULL_PTR */
    if ( PduInfoPtr == NULL_PTR )
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, Com_RxIndication_SID, COM_E_PARAM_POINTER);

    }
    else
#endif
    {
        uint8 pdu_counter,signal_counter,return_value,i;
        void (*NotficationAdress)(void);
        ComSignal* signal_per_pdu;
        //    uint8 pdu_id = Com.ComIPdu[RxPduId].ComIPduHandleId;

        if( RECEIVE== Com.ComIPdu[RxPduId].ComIPduDirection)
        {
            /* Copy data */
            PDU[RxPduId].SduLength = PduInfoPtr->SduLength;
            PDU[RxPduId].SduDataPtr  = PduInfoPtr->SduDataPtr;
            (PDU[RxPduId].MetaDataPtr) = (PduInfoPtr->MetaDataPtr);
            if( DEFERRED == Com.ComIPdu[RxPduId].ComIPduSignalProcessing)
            {
                PDU_INDEX=RxPduId;
                check_flag = 1;
            }
            else    /*immediate*/
            {
                uint8 signal_index_in_signal_buffer=Com.ComIPdu[RxPduId].ComIPduSignalRef[RxPduId]->ComHandleId;
                signal_per_pdu=Com.ComIPdu[RxPduId].ComIPduSignalRef[RxPduId];
                /*i reached here during context of my ISR so do the unpacking here ;)*/
                for(i=0;i<PDU[RxPduId].SduLength;i++)
                {
                    SignalObject[signal_index_in_signal_buffer+i]=(PDU[RxPduId].SduDataPtr)[i];
                    NotficationAdress= signal_per_pdu->ComNotification;
                    NotficationAdress();
                    signal_per_pdu++;
                }
            }
        }
        else
        {
            /*Do Nothing*/
        }
    }
}

/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com.c
 *
 * Description: Source file for Com Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include the Det header file*/
#include "Det.h"

/*Include the module header file*/
#include "Com.h"

/*Include other modules header file*/
#include "PduR_Com.h"

Com_StatusType ComCurrent_State = COM_UNINIT;

STATIC ComSignal SignalBuffer[MAX_NUM_OF_SIGNAL];

STATIC uint8 SignalObject[MAX_NUM_OF_SIGNAL];

STATIC PduInfoType PDU[ComMaxIPduCnt];

/************************************************************************************
 * Service Name: Com_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): config Pointer to the AUTOSAR COM module's configuration data.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This service initializes internal and external interfaces
 *              and variables of the AUTOSAR COM module layer for the further processing.
 *              After calling this function the inter-ECU communication is still disabled.
 ************************************************************************************/
void Com_Init(const Com_ConfigType* config )
{
#if(COM_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == config)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INIT_SID, COM_E_PARAM_POINTER);
    }
    else
    {
        /* Do Nothing*/
    }

    if(config != &Com)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_INIT_SID, COM_E_INIT_FAILED);

    }
    else
    {
        /* Do Nothing*/
    }

#endif
    uint8 counter_signal;
    uint8 counter_pdu;
    uint8 byte_counter;

    /*Loop to initialize each PDU*/
    for(counter_pdu=0;counter_pdu<ComMaxIPduCnt;counter_pdu++)
    {
        PDU[counter_pdu].SduLength = PDU_LEN_IN_BYTES;
        for(byte_counter=0;byte_counter<8;byte_counter++)
        {

            /* The AUTOSAR COM module shall initialize each I-PDU during
             * execution of Com_Init (SWS_Com_00432), firstly byte wise with the
             * ComTxIPduUnusedAreasDefault value
             */
            *(PDU[counter_pdu].SduDataPtr) = (config->ComIPdu[counter_pdu].ComTxIPdu.ComTxIPduUnusedAreasDefault)<<byte_counter;

            /* The AUTOSAR COM module shall clear all update-bits during
             * initialization.
             */
            /*not needed*/
            *(PDU[counter_pdu].SduDataPtr) &=~(1<<(config->ComIPdu[counter_pdu].ComIPduSignalRef[counter_pdu])->ComUpdateBitPosition);
        }
    }

    for(counter_signal=0;counter_signal<MAX_NUM_OF_SIGNAL;counter_signal++)
    {
        /* The AUTOSAR COM module shall initialize each signal of n-bit
         * sized signal type on sender and receiver side with the lower n-bits of its configuration
         * parameter ComSignalInitValue
         */
        SignalBuffer[counter_signal].ComSignalInitValue = config->ComSignal[counter_signal].ComSignalInitValue;

    }
    ComCurrent_State = COM_INIT;
}



/************************************************************************************
 *Service name: Com_SendSignal
 *Syntax: uint8 Com_SendSignal(Com_SignalIdType SignalId,const void* SignalDataPtr)
 *Service ID[hex]: 0x0a
 *Sync/Async: Asynchronous
 *Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 *Parameters (in): -SignalId Id of signal to be sent.
                  -SignalDataPtr Reference to the signal data to be transmitted.
 *Parameters (inout):None
 *Parameters (out): None
 *Return value: uint8 E_OK: service has been accepted
                COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group
                was stopped (or service failed due to development error)
                COM_BUSY: in case the TP-Buffer is locked for large data types handling
 *Description: The service Com_SendSignal updates the signal object identified by SignalId with
               the signal referenced by the SignalDataPtr parameter.
 ************************************************************************************/
uint8 Com_SendSignal(Com_SignalIdType SignalId,const void* SignalDataPtr)
{

    uint8  Com_SendSignal_Return;

#if(COM_DEV_ERROR_DETECT == STD_ON)
    /* Check if the module is initialized or not*/
    if ( ComCurrent_State ==  COM_UNINIT)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_UNINIT);
        Com_SendSignal_Return=COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
        /* MISRA*/
    }

    if(SignalId>MAX_NUM_OF_SIGNAL)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_PARAM);
        Com_SendSignal_Return=COM_SERVICE_NOT_AVAILABLE;
    }

    else
    {
        /* MISRA*/
    }

    /* check if the input configuration pointer is not a NULL_PTR */
    if ( SignalDataPtr == NULL_PTR )
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_PARAM_POINTER);
        Com_SendSignal_Return=COM_SERVICE_NOT_AVAILABLE;

    }
    else
#endif

        /*flow:1-find the id of the signal
         *     2-update the data of the signal with the new data
         *     3-
         */
    {

        uint8 PDU_INDEX ;

        uint8 SIGNAL_INDEX ;

        /* find the signal of SignalId */   //i assumed that we store the signal in index= id
        Com_SignalIdType Signal_ID = Com.ComSignal[SignalId].ComHandleId  ;

        /* update the Signal buffer with the signal data */   //i assumed that we store the signal in index= id
      //  SignalBuffer[Signal_ID].ComSystemTemplateSystemSignalRef=  SignalDataPtr;  //is that right????  do we need casting??

        SignalObject[Signal_ID]= *((uint8 *)SignalDataPtr);

        Com_SendSignal_Return=E_OK;
        /*  switch( SignalBuffer[Signal_ID].ComTransferProperty )

        {

        case:PENDING

        break;

        case:TRIGGERED

        break;

        default:
            break;


        }*/



    }

    return Com_SendSignal_Return;

}



/************************************************************************************
 *Service name: Com_ReceiveSignal
 *Syntax: uint8 Com_ReceiveSignal(Com_SignalIdType SignalId, void* SignalDataPtr)
 *Service ID[hex]: 0x0b
 *Sync/Async: Synchronous
 *Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 *Parameters (in): SignalId Id of signal to be received.
 *Parameters (inout):None
 *Parameters (out): SignalDataPtr Reference to the location where the received signal data shall be stored
 *Return value: -uint8 E_OK: service has been accepted
               -COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group was stopped (or service failed due to development error)
                -COM_BUSY: in case the TP-Buffer is locked for large data types handling
 *Description: Com_ReceiveSignal copies the data of the signal identified by SignalId to the location specified by SignalDataPtr.
 ************************************************************************************/

uint8 Com_ReceiveSignal(Com_SignalIdType SignalId, void* SignalDataPtr)
{

    uint8 Com_ReceiveSignal_Return;

#if(COM_DEV_ERROR_DETECT == STD_ON)
    /* Check if the module is initialized or not*/
    if ( ComCurrent_State ==  COM_UNINIT)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_UNINIT);
        Com_ReceiveSignal_Return=COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
        /* MISRA*/
    }

    if(SignalId>MAX_NUM_OF_SIGNAL)
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_PARAM);
        Com_ReceiveSignal_Return=COM_SERVICE_NOT_AVAILABLE;
    }

    else
    {
        /* MISRA*/
    }

    /* check if the input configuration pointer is not a NULL_PTR */
    if ( SignalDataPtr == NULL_PTR )
    {
        Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SEND_SIGNAL_SID, COM_E_PARAM_POINTER);
        Com_ReceiveSignal_Return=COM_SERVICE_NOT_AVAILABLE;

    }
    else
#endif
    {
        uint8 PDU_INDEX ;
        uint8  SIGNAL_INDEX;
        ComIPdu *IPdu;

        /* find the signal of SignalId */   //i assumed that we store the signal in index= id
        Com_SignalIdType Signal_ID = Com.ComSignal[SignalId].ComHandleId  ;
        for (  PDU_INDEX =0 ; PDU_INDEX < ComMaxIPduCnt  ; PDU_INDEX ++)
        {
            for ( SIGNAL_INDEX =0; SIGNAL_INDEX < ComMaxIPduCnt  ; SIGNAL_INDEX ++)
            {
                if( Com.ComIPdu[PDU_INDEX].ComIPduSignalRef[SIGNAL_INDEX]->ComHandleId == Signal_ID)
                {
                    IPdu=&Com.ComIPdu[PDU_INDEX];
                }
                else
                {
                    /*MISRA*/
                }

            }


        }

        if(IPdu->ComIPduDirection == RECEIVE)
        {

            /* update the Signal buffer with the signal data */   //i assumed that we store the signal in index= id
      //      SignalBuffer[Signal_ID].ComSystemTemplateSystemSignalRef=  SignalDataPtr;  //is that right????  do we need casting??
            SignalObject[Signal_ID]= *((uint8 *)SignalDataPtr);
            Com_ReceiveSignal_Return=E_OK;

        }

        else
        {
            Com_ReceiveSignal_Return=COM_SERVICE_NOT_AVAILABLE;
        }


    }

    return Com_ReceiveSignal_Return;
}


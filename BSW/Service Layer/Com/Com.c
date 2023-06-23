/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com.c
 *
 * Description: Source file for COM Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include the Det header file*/
#include "../Det/Det.h"

/*Include the module header file*/
#include "Com.h"

/*Include other modules header file*/
#include "../PduR/PduR_Com.h"

Com_StatusType ComCurrent_State = COM_UNINIT;

STATIC ComSignal SignalBuffer[MAX_NUM_OF_SIGNAL];

uint8 SignalObject[MAX_NUM_OF_SIGNAL];

PduInfoType PDU[ComMaxIPduCnt];

uint8 PDU_INDEX=0;
uint8 Com_Trigger_Flag[MAX_NUM_OF_SIGNAL] ={0};

/* LOCAL STATIC FUNCTION USED TO CONCATINATE THE PDUs. */
static void Pdu_Concatnate(void);

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
#endif
    {
        uint8 counter_signal;
        uint8 counter_pdu;
        uint8 byte_counter;

        /*Loop to initialize each PDU*/
        for(counter_pdu=0;counter_pdu<ComMaxIPduCnt;counter_pdu++)
        {
            PDU[counter_pdu].SduLength = PDU_LEN_IN_BYTES;
            PDU[counter_pdu].SduDataPtr = &(config->ComIPdu[counter_pdu].ComTxIPdu.ComTxIPduUnusedAreasDefault);
            for(byte_counter=0;byte_counter<PDU_LEN_IN_BYTES;byte_counter++)
            {

                /* The AUTOSAR COM module shall initialize each I-PDU during
                 * execution of Com_Init (SWS_Com_00432), firstly byte wise with the
                 * ComTxIPduUnusedAreasDefault value
                 */
                PDU[counter_pdu].SduDataPtr[byte_counter] = (config->ComIPdu[counter_pdu].ComTxIPdu.ComTxIPduUnusedAreasDefault)<<byte_counter;

                /* The AUTOSAR COM module shall clear all update-bits during
                 * initialization.
                 */
                /*not needed*/
                //            *(PDU[counter_pdu].SduDataPtr) &=~(1<<(config->ComIPdu[counter_pdu].ComIPduSignalRef[counter_pdu])->ComUpdateBitPosition);
            }
        }
        for(counter_signal=0;counter_signal<MAX_NUM_OF_SIGNAL;counter_signal++)
        {
            /* The AUTOSAR COM module shall initialize each signal of n-bit
             * sized signal type on sender and receiver side with the lower n-bits of its configuration
             * parameter ComSignalInitValue
             */
            SignalBuffer[counter_signal].ComSignalInitValue = config->ComSignal[counter_signal].ComSignalInitValue;

            /* initialize the data signal buffer with the configured initial values. */
            SignalObject[counter_signal] = SignalBuffer[counter_signal].ComSignalInitValue;

        }
        ComCurrent_State = COM_INIT;
    }
}
/************************************************************************************
 * Service Name: Com_SendSignal
 * Service ID[hex]: 0x0a
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 * Parameters (in): SignalId; Id of signal to be sent.
 *                  SignalDataPtr; Reference to the signal data to be transmitted.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: uint8 E_OK: service has been accepted
 *                           COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group
 *                           was stopped (or service failed due to development error)
 *                           COM_BUSY: in case the TP-Buffer is locked for large data types
 *                           handling
 * Description: The service Com_SendSignal updates the signal object identified by SignalId with
 *              the signal referenced by the SignalDataPtr parameter.
 *
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
         *     3-return
         */
    {
        /* find the signal of SignalId */
        Com_SignalIdType Signal_ID = Com.ComSignal[SignalId].ComHandleId  ;

        /* update the Signal buffer with the signal data */
        //check this
        uint8 iter;
        for (iter=0;iter<Com.ComSignal[Signal_ID].ComSignalLength;iter++)
        {
            SignalObject[Signal_ID+iter]= ((uint8 *)SignalDataPtr)[iter];
        }

        /* Update the signal transmission flag */
        //nes2al 3l update bits wel implementation bta3na
        Com_Trigger_Flag[SignalId] = 1;

        Com_SendSignal_Return=E_OK;

        return Com_SendSignal_Return;
    }

}

/************************************************************************************
 * Service Name: Com_ReceiveSignal
 * Service ID[hex]: 0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 * Parameters (in): SignalId; Id of signal to be received.
 * Parameters (inout): None
 * Parameters (out): SignalDataPtr Reference to the location where the received signal data shall be
 *                                 stored.
 * Return value: uint8 E_OK: service has been accepted
 *                           COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group
 *                           was stopped (or service failed due to development error)
 *                           COM_BUSY: in case the TP-Buffer is locked for large data types
 *                           handling
 * Description: Com_ReceiveSignal copies the data of the signal identified by SignalId to the
 *              location specified by SignalDataPtr.
 *
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
        uint8* Signal_Value;
        /* Get the byte value of the signal from the signal buffer */
        Signal_Value = &SignalObject[SignalId];

        /* Copy the signal byte value to the output signal data pointer */
        //check this
        uint8 iter;
        for (iter=0;iter<Com.ComSignal[SignalId].ComSignalLength;iter++)
        {
            ((uint8*)SignalDataPtr)[iter]  = Signal_Value[iter];
        }
        Com_ReceiveSignal_Return=E_OK;

    }

    return Com_ReceiveSignal_Return;
}

/* LOCAL STATIC FUNCTION USED TO CONCATINATE THE PDUs. */
static void Pdu_Concatnate(void)
{
    /*signal number sequentially*/
    uint8 signal_counter;
    /*pdu number i have*/
    uint8 pdu_counter;
    /*counts signals in each pdu ,range 0:7*/
    uint8 signal_counter_per_pdu;
    /***************************************PDU CONCATINATION****************************************************/
    signal_counter=0;

    for(pdu_counter=0;pdu_counter<ComMaxIPduCnt;pdu_counter++)
    {
        PDU[pdu_counter].SduDataPtr = &SignalObject[signal_counter];
        for(signal_counter_per_pdu=0;signal_counter_per_pdu<PDU_LEN_IN_BYTES;signal_counter_per_pdu++)
        {
            if(LITTLE_ENDIAN ==Com.ComSignal[signal_counter].ComSignalEndianness){
                /* put the updated signal value in the pdu data field to concatenate the whole LPDU */
                PDU[pdu_counter].SduDataPtr[(uint8)((Com.ComSignal[signal_counter].ComBitPosition)/8)] = SignalObject[signal_counter];

            }
            else if(BIG_ENDIAN ==Com.ComSignal[signal_counter].ComSignalEndianness){
                /* put the updated signal value in the pdu data field to concatenate the whole LPDU */
                (PDU[pdu_counter].SduDataPtr)[(8)-((uint8)((Com.ComSignal[signal_counter].ComBitPosition)/8))-1] = SignalObject[signal_counter];

            }
            signal_counter++;
        }

    }
}

/************************************************************************************
 * Service Name: Com_MainFunctionTx
 * Service ID[hex]: 0x19
 * Return value: None
 * Description: This function performs the processing of the AUTOSAR
 * COM module's transmission activities that are not directly handled
 * within the COM's function invoked by
 * the RTE, for example Com_SendSignal.
 ************************************************************************************/
void Com_MainFunctionTx(void)
{
    /*signal number sequentially*/
    uint8 signal_counter;
    /*pdu number i have*/
    uint8 pdu_counter;
    /*counts signals in each pdu ,range 0:7*/
    uint8 signal_counter_per_pdu;
    if(COM_UNINIT == ComCurrent_State)
    {
        return;
    }
    else
    {
        /***************************************PDU CONCATINATION****************************************************/
        Pdu_Concatnate();
        for(pdu_counter=0;pdu_counter<ComMaxIPduCnt;pdu_counter++)
        {
            if( SEND == Com.ComIPdu[pdu_counter].ComIPduDirection)
            {
                if(PERIODIC_Tx == Com.ComIPdu[pdu_counter].ComTxIPdu.ComTxMode.ComTxModeMode)
                {
                    /*do i need to check the (time calculated> ComTxModeTimePeriod)
                     * if true : call PduR_ComTransmit
                     * else donot call
                     * or it will be handled by OS
                     * */
                    //                    if(sw_timer>Com.ComIPdu[pdu_counter].ComTxIPdu.ComTxMode.ComTxModeTimePeriod)
                    //                    {
                    PduR_ComTransmit( Com.ComIPdu[pdu_counter].ComIPduHandleId, &PDU[pdu_counter]);
                }
                else if(DIRECT_Tx == Com.ComIPdu[pdu_counter].ComTxIPdu.ComTxMode.ComTxModeMode)
                {
                    /*loop on signals of this pdu*/
                    for(signal_counter_per_pdu=0;signal_counter_per_pdu<8;signal_counter_per_pdu++)
                    {
                        if(PENDING == Com.ComSignal[Com.ComIPdu[pdu_counter].ComIPduSignalRef[pdu_counter]->ComHandleId + signal_counter_per_pdu].ComTransferProperty)
                        {

                        }
                        else
                        {

                            PduR_ComTransmit( Com.ComIPdu[pdu_counter].ComIPduHandleId, &PDU[pdu_counter]);
                            /*end the request of this direct lpdu as it is done and sent*/
                            break;
                        }

                    }

                }
                else
                {
                    /*Do Nothing*/
                }
            }
            else
            {
                /*Do Nothing*/
            }
        }
    }
}

/************************************************************************************
 * Service Name: Com_MainFunctionRx
 * Service ID[hex]: 0x18
 * Return value: None
 * Description: This function performs the processing of the AUTOSAR COM module's receive
 *              processing that are not directly handled within the COM's functions invoked by the
 *              PDU-R, for example Com_RxIndication.
 ************************************************************************************/
void Com_MainFunctionRx(void)
{
    uint8 pdu_counter,signal_counter,return_value;
    void (*NotficationAdress)(void);
    ComSignal* signal_per_pdu;
    uint8 i;
    if(COM_UNINIT == ComCurrent_State)
    {
        return;
    }
    else
    {

        if(check_flag == 1)
        {
            check_flag=0;
            uint8 signal_index_in_signal_buffer=Com.ComIPdu[PDU_INDEX].ComIPduSignalRef[PDU_INDEX]->ComHandleId;
            signal_per_pdu=Com.ComIPdu[PDU_INDEX].ComIPduSignalRef[PDU_INDEX];
            for(i=0;i<PDU[PDU_INDEX].SduLength;i++){
                SignalObject[signal_index_in_signal_buffer+i]=(PDU[PDU_INDEX].SduDataPtr)[i];
                NotficationAdress= signal_per_pdu->ComNotification;
                NotficationAdress();
                signal_per_pdu++;
            }

        }
        else    /*CHECK FLAG NOT SET*/
        {

        }
    }
}

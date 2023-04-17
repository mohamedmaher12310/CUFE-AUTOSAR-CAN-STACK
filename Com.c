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

    uint8 pdu_data;
    for(counter_pdu=0;counter_pdu<ComMaxIPduCnt;counter_pdu++)
    {
        PDU[counter_pdu].SduLength = 8;

/*refrence the ptr*/
        0x0000000f
        for(i;;)
        {
        *(PDU[counter_pdu].SduDataPtr) =((config->ComIPdu[counter_pdu].ComTxIPdu.ComTxIPduUnusedAreasDefault));
        }
        pdu_data = PDU[counter_pdu].SduDataPtr;
        /* clear the update-bits */
        pdu_data &=!(1<<(config->ComIPdu[counter_pdu].ComIPduSignalRef[counter_pdu]->ComUpdateBitPosition));

        PDU[counter_pdu].SduDataPtr= pdu_data;
    }
    for(counter_signal=0;counter_signal<MAX_NUM_OF_SIGNAL;counter_signal++)
    {
        SignalBuffer[counter_signal].ComSignalInitValue = config->ComSignal[counter_signal].ComSignalInitValue;


    }

}

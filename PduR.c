/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR.c
 *
 * Description: Source file for PduR Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include the Det header file*/
#include "Det.h"

/*Include the module header file*/
#include "PduR.h"

PduR_StateType PduRCurrent_State  = PDUR_UNINIT;

/************************************************************************************
 * Service Name: PduR_Init
 * Service ID[hex]: 0xf0
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr - Pointer to post build configuration.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize the PDU Router.
 ************************************************************************************/
void PduR_Init(const PduR_PBConfigType* ConfigPtr)
{

#if( PduRDevErrorDetect == STD_ON  )

    /* check if NULL pointer is passed as an argument */
    if (NULL_PTR == ConfigPtr)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_INIT_SID, PDUR_E_PARAM_POINTER);
    }
    /* check if the configuration parameter is invalid */
    if(ConfigPtr != &PduR_Configuration)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_INIT_SID, PDUR_E_INIT_FAILED);
    }
#endif

    PduRCurrent_State = PDUR_ONLINE;
}

/************************************************************************************
 * Service Name: PduR_ComTransmit
 * Service ID[hex]: 0x49
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): TxPduId - Identifier of the PDU to be transmitted.
 *                  PduInfoPtr - Length of and pointer to the PDU data and pointer to MetaData.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Transmit request has been accepted.
 *                                E_NOT_OK: Transmit request has not been accepted.
 * Description: Function to Request transmission of a PDU.
 ************************************************************************************/
Std_ReturnType PduR_ComTransmit( PduIdType TxPduId, const PduInfoType* PduInfoPtr )
{
    Std_ReturnType Pdur_ComTransmitReturn ;
#if( PduRDevErrorDetect == STD_ON  )

    /* Check if the module is initialized or not*/
    if (PDUR_UNINIT == PduRCurrent_State)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COMTRANSMIT_SID, PDUR_E_UNINIT);
        Pdur_ComTransmitReturn = E_NOT_OK;
    }

    /*  [SWS_PduR_00221] If development error detection is enabled, a PDU identifier is
     * not within the specified range, and the PDU identifier is configured to be used by the
     * PDU Router module, the PDU Router module shall report the error
     * PDUR_E_PDU_ID_INVALID to the DET module, when PduRDevErrorDetect is
     * enabled.
     */

    if (PduR_MaxPduID < TxPduId)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COMTRANSMIT_SID, PDUR_E_PDU_ID_INVALID);
        Pdur_ComTransmitReturn = E_NOT_OK;
    }

    /* check if NULL pointer is passed as an argument */
    if (NULL_PTR == PduInfoPtr)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_COMTRANSMIT_SID, PDUR_E_PARAM_POINTER);
        Pdur_ComTransmitReturn = E_NOT_OK;
    }
#endif

    PduIdType Pdu_ID = PduR_Configuration.PduRRoutingPaths[TxPduId].PduRDestPdu.PduRDestPduRef->CanIfTxPduId;
    Pdur_ComTransmitReturn = CanIf_Transmit(Pdu_ID, PduInfoPtr);

    return Pdur_ComTransmitReturn;
}






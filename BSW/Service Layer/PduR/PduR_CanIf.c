/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_CanIf.c
 *
 * Description: Source file for PDU Router Callback
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include the Det header file*/
#include "../Det/Det.h"

/*Include the module header file*/
#include "PduR_CanIf.h"


/************************************************************************************
 * Service Name: PduR_CanIfTxConfirmation
 * Service ID[hex]: 0x48
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): id - Identification of the transmitted I-PDU.
 *                  result - Result of the transmission of the I-PDU.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: This function is called after the I-PDU has been transmitted on its network, the
 *              result indicates whether the transmission was successful or not.
 ************************************************************************************/
#if(STD_ON == PduRTransmissionConfirmation)
void PduR_CanIfTxConfirmation(PduIdType id,Std_ReturnType result)
{

#if( PduRDevErrorDetect == STD_ON  )
    /* Check if the module is initialized or not*/
    if (PDUR_UNINIT == PduRCurrent_State)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFTXCONFIRMATION_SID, PDUR_E_UNINIT);
    }
    else
    {
        /*Do Nothing*/
    }

    /*  [SWS_PduR_00221] If development error detection is enabled, a PDU identifier is
     * not within the specified range, and the PDU identifier is configured to be used by the
     * PDU Router module, the PDU Router module shall report the error
     * PDUR_E_PDU_ID_INVALID to the DET module, when PduRDevErrorDetect is
     * enabled.
     */

    if (PduR_MaxPduID < id)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFTXCONFIRMATION_SID, PDUR_E_PDU_ID_INVALID);
    }
    else
#endif /*PduRDevErrorDetect*/
    {
        /*
         * [SWS_PduR_00627] When the communication interface module calls
         * PduR_<Lo>TxConfirmation the PDU Router shall call <Up>_TxConfirmation in the
         * upper module and forward the transmission result from the lower to the upper layer
         * interface.
         */
        uint8 iter=ZERO;
        for (iter = ZERO; iter < PduRMaxRoutingPathCnt ; iter ++)
        {
            if (id == PduR_Configuration.PduRRoutingPaths[iter].PduRDestPdu.PduRDestPduHandleId)
            {
                PduIdType Pdu_ID = PduR_Configuration.PduRRoutingPaths[iter].PduRSrcPdu.PduRSrcPduRef->ComIPduHandleId;
                // result = Com_TxConfirmation(Pdu_ID, PduInfoPtr);
            }
            else
            {
                /*Do Nothing*/
            }
        }
    }
}
#endif /* PduRTransmissionConfirmation */

/************************************************************************************
 * Service Name: PduR_CanIfRxIndication
 * Service ID[hex]: 0x42
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): RxPduId - ID of the received PDU..
 *                  PduInfoPtr - Contains the length (SduLength) of the received PDU,
 *                               a pointer to a buffer (SduDataPtr) containing the PDU,
 *                               and the MetaData related to this PDU.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Indicate a received PDU from a lower layer communication
 *              interface module.
 ************************************************************************************/
void PduR_CanIfRxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr)
{
#if (PduRDevErrorDetect == STD_ON)
    /* Check if the module is initialized or not*/
    if (PDUR_UNINIT == PduRCurrent_State)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFRXINDICATION_SID, PDUR_E_UNINIT);
    }
    else
    {
        /*Do Nothing*/
    }
    /*
     * [SWS_PduR_00221] If development error detection is enabled, a PDU identifier is
     * not within the specified range, and the PDU identifier is configured to be used by the
     * PDU Router module, the PDU Router module shall report the error
     * PDUR_E_PDU_ID_INVALID to the DET module, when PduRDevErrorDetect is
     * enabled.
     */

    if (PduR_MaxPduID < RxPduId)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFRXINDICATION_SID, PDUR_E_PDU_ID_INVALID);
    }
    else
    {
        /*Do Nothing*/
    }
    /* check if NULL pointer is passed as an argument */
    if (NULL_PTR == PduInfoPtr)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFRXINDICATION_SID, PDUR_E_PARAM_POINTER);
    }
    else
#endif /*PduRDevErrorDetect*/
    {
        /*
         * [SWS_PduR_00621] When the PduR_<Lo>RxIndication is called the PDU Router
         * module shall call <Up>_RxIndication for each destination upper module.
         */
        uint8 iter=ZERO;
        for (iter = ZERO; iter < PduRMaxRoutingPathCnt ; iter ++)
        {
            if (RxPduId == PduR_Configuration.PduRRoutingPaths[iter].PduRDestPdu.PduRDestPduHandleId)
            {
                PduIdType Pdu_ID = PduR_Configuration.PduRRoutingPaths[iter].PduRSrcPdu.PduRSrcPduRef->ComIPduHandleId;
                Com_RxIndication(Pdu_ID, &PduInfoPtr);
            }
            else
            {
                /*Do Nothing*/
            }
        }



    }
}

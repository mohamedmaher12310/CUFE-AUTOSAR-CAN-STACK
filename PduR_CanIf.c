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
#include "Det.h"

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
#endif
  /*  PduIdType Pdu_ID = PduR_Configuration.PduRRoutingPaths[id].PduRSrcPdu.PduRSrcPduRef.   get id from Com Module  */
   // Com_TxConfirmation(Pdu_ID,E_OK);
}
#endif /* PduR_CanIfTxConfirmation */

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
#if( PduRDevErrorDetect == STD_ON  )
    /* Check if the module is initialized or not*/
    if (PDUR_UNINIT == PduRCurrent_State)
    {
        Det_ReportError(PDUR_MODULE_ID, PDUR_INSTANCE_ID, PDUR_CANIFRXINDICATION_SID, PDUR_E_UNINIT);
    }
#endif





}



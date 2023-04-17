/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_CanIf.h
 *
 * Description: Header file for PDU Router Callback
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef PDUR_CANIF_H_
#define PDUR_CANIF_H_

#include "PduR.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for CanIf Trigger Transmit API*/
#define PDUR_CANIFRXINDICATION_SID              (uint8)0x42
#define PDUR_CANIFTXCONFIRMATION_SID              (uint8)0x48



/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

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
void PduR_CanIfRxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr);

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
void PduR_CanIfTxConfirmation(PduIdType id,Std_ReturnType result);

/************************PduRBswModules Container************************/
/*
 * Specifies if the BSW module supports the TxConfirmation API or not.
 * Value true the API is supported.
 */
#define PduRTxConfirmation                              (STD_ON)



#endif /* PDUR_CANIF_H_ */

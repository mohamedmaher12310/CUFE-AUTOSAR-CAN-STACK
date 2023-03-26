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

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/




#endif /* PDUR_CANIF_H_ */

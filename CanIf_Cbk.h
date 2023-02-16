/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf_Cbk.h
 *
 * Description: Header file for Can Interface Callback
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CANIF_CBK_H_
#define CANIF_CBK_H_

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for CanIf Trigger Transmit API*/
#define CANIF_TRIGGER_TRANSMIT_SID              (uint8)0x41

/* Service ID for CanIf Tx Confirmation API*/
#define CANIF_TX_CONFIRMATION_SID               (uint8)0x13

/* Service ID for CanIf Rx Indication API*/
#define CANIF_RX_INDICATION_SID                 (uint8)0x14

/* Service ID for CanIf Controller Mode Indication API*/
#define CANIF_CONTROLLER_MODE_INDICATION_SID    (uint8)0x17

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/************************************************************************************
 * Service Name: CanIf_TriggerTransmit
 * Service ID[hex]: 0x41
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): TxPduId - ID of the SDU that is requested to be transmitted.
 * Parameters (inout): PduInfoPtr - Contains a pointer to a buffer (SduDataPtr) to where
 *                                  the SDU data shall be copied, and the available buffer
 *                                  size in SduLengh. On return, the service will indicate
 *                                  the length of the copied SDU data in SduLength.
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: SDU has been copied and SduLength indicates the number
 *                                      of copied bytes.
 *                                E_NOT_OK:  No SDU data has been copied. PduInfoPtr must not be
 *                                           used since it may contain a NULL pointer or point
 *                                           to invalid data.
 * Description: Within this API, the upper layer module (called module) shall check
 *              whether the available data fits into the buffer size reported by PduInfoPtr->SduLength.
 *              If it fits, it shall copy its data into the buffer provided by
 *              PduInfoPtr->SduDataPtr and update the length of the actual copied data
 *              in PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing
 *              PduInfoPtr.
 ************************************************************************************/
Std_ReturnType CanIf_TriggerTransmit(PduIdType TxPduId,PduInfoType* PduInfoPtr);

/************************************************************************************
 * Service Name: CanIf_TxConfirmation
 * Service ID[hex]: 0x13
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): CanTxPduId - L-PDU handle of CAN L-PDU successfully transmitted.
 *                               This ID specifies the corresponding CAN L-PDU ID
 *                               and implicitly the CAN Driver instance as well as the
 *                               corresponding CAN controller device.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to confirm a previously successfully processed transmission
                of a CAN TxPDU.
 ************************************************************************************/
void CanIf_TxConfirmation(PduIdType CanTxPduId);

/************************************************************************************
 * Service Name: CanIf_RxIndication
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Mailbox - Identifies the HRH and its corresponding CAN Controller
 *                  PduInfoPtr - Pointer to the received L-PDU
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to indicate a successful reception of a received CAN Rx L-PDU
 *              to the CanIf after passing all filters and validation checks.
 ************************************************************************************/
void CanIf_RxIndication(const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr);

/************************************************************************************
 * Service Name: CanIf_ControllerModeIndication
 * Service ID[hex]: 0x17
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ControllerId - Abstract CanIf ControllerId which is assigned to a
 *                                 CAN controller, which state has been transitioned.
 *                  ControllerMode - Mode to which the CAN controller transitioned
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to indicate a controller state transition referring to the
 *              corresponding CAN controller with the abstract CanIf ControllerId.
 ************************************************************************************/
void CanIf_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode);

#endif /* CANIF_CBK_H_ */
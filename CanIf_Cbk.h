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

#include "CanIf.h"

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

/************************************************************************************
 * Service Name: <User_RxIndication>
 * Sync/Async: Synchronous
 *Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in):
 *          RxPduId: ID of the received PDU.
 *          PduInfoPtr :Contains the length (SduLength) of the received
 *                      PDU, a pointer to a buffer (SduDataPtr) containing
 *                      the PDU, and the MetaData related to this PDU.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value:     None
 * Description: Indication of a received PDU from a lower layer communication interface
 *              module
 ************************************************************************************/
void PDUR_RxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr);

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/*CanIf Recieve Buffer (ReadAPI)*/
#if (STD_ON == CanIfPublicReadRxPduDataApi)
extern Can_PduType CanIf_RxBuffer[CanIfMaxRxPduCfg];
#endif /*CanIfPublicReadRxPduDataApi*/

/*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
extern CanIf_NotifStatusType CanIf_RxNotificationFlag[CanIfMaxRxPduCfg];
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/

/*Tx Notification Flags*/
#if (STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
extern CanIf_NotifStatusType CanIf_TxNotificationFlag[CanIfMaxTxPduCfg];
#endif /*CanIfPublicReadTxPduNotifyStatusApi*/

#endif /* CANIF_CBK_H_ */

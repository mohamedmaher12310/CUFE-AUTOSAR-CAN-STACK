/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf.h
 *
 * Description: Header file for Can Interface Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef CANIF_H_
#define CANIF_H_

/* Id for the company in the AUTOSAR
 * for example Omar Khedr's ID = 1000 :) */
#define CANIF_VENDOR_ID    (1000U)

/* CanIf Module Id */
#define CANIF_MODULE_ID    (60U)

/* Can Instance Id */
#define CANIF_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define CANIF_SW_MAJOR_VERSION           (1U)
#define CANIF_SW_MINOR_VERSION           (0U)
#define CANIF_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define CANIF_AR_RELEASE_MAJOR_VERSION   (4U)
#define CANIF_AR_RELEASE_MINOR_VERSION   (3U)
#define CANIF_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Macros for CanIf Module Status
 */
#define CANIF_INITIALIZED                (1U)
#define CANIF_NOT_INITIALIZED            (0U)

/* CanIf Pre-Compile Configuration Header file */
#include "CanIf_Cfg.h"
/* AUTOSAR Version checking between CanIf_Cfg.h and CanIf.h files */
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)\
        ||  (CANIF_CFG_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)\
        ||  (CANIF_CFG_AR_RELEASE_PATCH_VERSION != CANIF_AR_RELEASE_PATCH_VERSION))
#error "The AR version of CanIf_Cfg.h does not match the expected version"
#endif

/* Software Version checking between CanIf_Cfg.h and CanIf.h files */
#if ((CANIF_CFG_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION)\
        ||  (CANIF_CFG_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION)\
        ||  (CANIF_CFG_SW_PATCH_VERSION != CANIF_SW_PATCH_VERSION))
#error "The SW version of CanIf_Cfg.h does not match the expected version"
#endif

/*CANIF Types Header file*/
#include "CanIf_Types.h"

/*CanDrv Header file*/
#include "Can.h"
/* AUTOSAR Version checking between CanIf.h and Can.h files */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (CANIF_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (CANIF_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can.h does not match the expected version"
#endif

/* Software Version checking between CanIf.h and Can.h files */
#if ((CANIF_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||   (CANIF_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||   (CANIF_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of Can.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for CanIf Init API */
#define CANIF_INIT_SID                    (uint8)0x01

/* Service ID for CanIf De-Init API */
#define CANIF_DE_INIT_SID                 (uint8)0x02

/* Service ID for CanIf Set Controller Mode API*/
#define CANIF_SET_CONTROLLER_MODE_SID     (uint8)0x03

/* Service ID for CanIf Transmit API*/
#define CANIF_TRANSMIT_SID                (uint8)0x49

/* Service ID for CanIf Set PDU Mode API*/
#define CANIF_SET_PDU_MODE_SID            (uint8)0x09

/* Service ID for CanIf Set Dynamic Tx Id API*/
#define CANIF_SET_DYNAMIC_TXID_SID        (uint8)0x0c

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report that an API Service called with wrong parameter */
#define CANIF_E_PARAM_CANID                 (uint8)10
#define CANIF_E_PARAM_HOH                   (uint8)12
#define CANIF_E_PARAM_LPDU                  (uint8)13
#define CANIF_E_PARAM_CONTROLLERID          (uint8)15
#define CANIF_E_PARAM_CTRLMODE              (uint8)21
#define CANIF_E_PARAM_PDU_MODE              (uint8)22

/* DET Code to report that an API Service used without initialization */
#define CANIF_E_UNINIT                      (uint8)30

/* DET code to report that an API service called with invalid pointer */
#define CANIF_E_PARAM_POINTER               (uint8)20

/* DET code to report that Transmit PDU ID is invalid */
#define CANIF_E_INVALID_TXPDUID             (uint8)50

/* DET code to report that Recieve PDU ID is invalid */
#define CANIF_E_INVALID_RXPDUID             (uint8)60

/* DET Code to report that CAN Interface initialization failed*/
#define CANIF_E_INIT_FAILED                 (uint8)80



/*******************************************************************************
 *                     RUN TIME Error Codes                                        *
 *******************************************************************************/
/*RUN TIME Code to report that CAN Interface Fails Data Length Check*/
#define CANIF_E_INVALID_DATA_LENGTH  (uint8)  61



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: CanIf_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr - Pointer to configuration parameter set.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize internal and external interfaces of the
 *              CAN Interface for the further processing
 ************************************************************************************/
void CanIf_Init(const CanIf_ConfigType* ConfigPtr);

/************************************************************************************
 * Service Name: CanIf_DeInit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to De-initialize the CanIf module.
 ************************************************************************************/
void CanIf_DeInit(void);

/************************************************************************************
 * Service Name: CanIf_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant (Not for the same controller)
 * Parameters (in): ControllerId - Abstracted CanIf ControllerId which is assigned to a
 *                                 CAN controller, which is requested for mode transition.
 *                  ControllerMode - Requested mode transition
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Controller mode request has been accepted
 *                                E_NOT_OK: Controller mode request hasn't been accepted
 * Description: Function to call the corresponding CAN Driver service for changing of
                the CAN controller mode.
 ************************************************************************************/
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType ControllerMode);

/************************************************************************************
 * Service Name: CanIf_Transmit
 * Service ID[hex]: 0x49
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): TxPduId - Identifier of the PDU to be transmitted
 *                  PduInfoPtr - Length of and pointer to the PDU data and pointer
 *                               to MetaData.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Transmit request has been accepted.
 *                                E_NOT_OK: Transmit request hasn't been accepted
 * Description: Function to Request transmission of a PDU.
 ************************************************************************************/
Std_ReturnType CanIf_Transmit(PduIdType TxPduId,const PduInfoType* PduInfoPtr);

/************************************************************************************
 * Service Name: CanIf_SetPduMode
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ControllerId - All PDUs of the own ECU connected to the corresponding
 *                                 CanIf ControllerId, which is assigned to a physical
 *                                 CAN controller are addressed.
 *                  PduModeRequest - Requested PDU mode change.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Request for mode transition has been accepted.
 *                                E_NOT_OK:  Request for mode transition hasn't been accepted
 * Description: Function to set the requested mode at the L-PDUs of a predefined logical
 *              PDU channel.
 ************************************************************************************/
Std_ReturnType CanIf_SetPduMode(uint8 ControllerId,CanIf_PduModeType PduModeRequest);

/************************************************************************************
 * Service Name: CanIf_SetDynamicTxId
 * Service ID[hex]: 0x0c
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): CanIfTxSduId - L-SDU handle to be transmitted. This handle specifies
 *                                 the corresponding CAN L-SDU ID and implicitly the
 *                                 CAN Driver instance as well as the corresponding CAN controller
 *                                 device.
 *                  CanId - Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD
 *                          or conventional CAN frame.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to reconfigure the corresponding CAN identifier of the
 *              requested CAN L-PDU.
 ************************************************************************************/
void CanIf_SetDynamicTxId(PduIdType CanIfTxSduId,Can_IdType CanId);




/************************************************************************************
 * Service Name: CanIf_RxIndication
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy:  Reentrant
 * Parameters (in):
 *          Mailbox: Identifies the HRH and its corresponding CAN Controller
 *          PduInfoPtr :Pointer to the received L-PDUParameters (inout): None
 * Parameters (out): None
 * Return value:     None
 * Description: This service indicates a successful reception of a received CAN Rx LPDU
 *              to the CanIf after passing all filters and validation checks.
 ************************************************************************************/
void CanIf_RxIndication(const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr);
/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/
#define CANNIF_STANDARD_MAX    0x7FF
#define CANNIF_EXTENDED_MAX    0x1FFFFFFF
#define Max_SDU_LENGTH         0x08

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/


extern const CanIf_ConfigType CanIf_Configuration ;


#endif /* CANIF_H_ */

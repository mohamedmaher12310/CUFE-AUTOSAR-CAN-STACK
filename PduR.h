/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR.h
 *
 * Description: Header file for PDU Router Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef PDUR_H_
#define PDUR_H_

/* Id for the company in the AUTOSAR
 * for example Omar Khedr's ID = 1000 :) */
#define PDUR_VENDOR_ID    (1000U)

/* PduR Module Id */
#define PDUR_MODULE_ID    (51U)

/* PduR Instance Id */
#define PDUR_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PDUR_SW_MAJOR_VERSION           (1U)
#define PDUR_SW_MINOR_VERSION           (0U)
#define PDUR_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PDUR_AR_RELEASE_MAJOR_VERSION   (4U)
#define PDUR_AR_RELEASE_MINOR_VERSION   (3U)
#define PDUR_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Macros for CanIf Module Status
 */
#define PDUR_INITIALIZED                (1U)
#define PDUR_NOT_INITIALIZED            (0U)

/* PduR Pre-Compile Configuration Header file */
#include "PduR_Cfg.h"
/* AUTOSAR Version checking between CanIf_Cfg.h and CanIf.h files */
#if ((PDUR_CFG_AR_RELEASE_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION)\
 ||  (PDUR_CFG_AR_RELEASE_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION)\
 ||  (PDUR_CFG_AR_RELEASE_PATCH_VERSION != PDUR_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PduR_Cfg.h does not match the expected version"
#endif

/* Software Version checking between PduR_Cfg.h and PduR.h files */
#if ((PDUR_CFG_SW_MAJOR_VERSION != PDUR_SW_MAJOR_VERSION)\
 ||  (PDUR_CFG_SW_MINOR_VERSION != PDUR_SW_MINOR_VERSION)\
 ||  (PDUR_CFG_SW_PATCH_VERSION != PDUR_SW_PATCH_VERSION))
#error "The SW version of PduR_Cfg.h does not match the expected version"
#endif

/*PduR Types Header file*/
#include "PduR_Types.h"

/*Including Det module for developmnet error reporting*/
#if (STD_ON == PduRDevErrorDetect)
#include "Det.h"

/* AUTOSAR Version checking between Det and CanIf Modules */
#if ((DET_AR_MAJOR_VERSION != PDUR_AR_RELEASE_MAJOR_VERSION)\
  || (DET_AR_MINOR_VERSION != PDUR_AR_RELEASE_MINOR_VERSION)\
  || (DET_AR_PATCH_VERSION != PDUR_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for CanIf Init API */
#define CANIF_INIT_SID                    (uint8)0x01



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



/*******************************************************************************
 *                     RUN TIME Error Codes                                        *
 *******************************************************************************/
/*RUN TIME Code to report that CAN Interface Fails Data Length Check*/
#define CANIF_E_INVALID_DATA_LENGTH  (uint8)  61





/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

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
void PduR_Init(const PduR_PBConfigType* ConfigPtr);

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
Std_ReturnType PduR_ComTransmit( PduIdType TxPduId, const PduInfoType* PduInfoPtr );




/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/



/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

extern CanIf_State CanIfCurrent_State ;
extern const CanIf_ConfigType CanIf_Configuration ;


#endif /* PDUR_H_ */

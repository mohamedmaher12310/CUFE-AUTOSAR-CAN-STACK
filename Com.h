/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com.h
 *
 * Description: Header file for COM Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef CUFE_AUTOSAR_CAN_STACK_COM_H_
#define CUFE_AUTOSAR_CAN_STACK_COM_H_

/* Id for the company in the AUTOSAR
 * for example COM VENDOR's ID = 1000 :) */
#define COM_VENDOR_ID    (1000U)

/* COM Module Id */
#define COM_MODULE_ID    (50U)

/* COM Instance Id */
#define COM_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define COM_SW_MAJOR_VERSION           (1U)
#define COM_SW_MINOR_VERSION           (0U)
#define COM_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define COM_AR_RELEASE_MAJOR_VERSION   (4U)
#define COM_AR_RELEASE_MINOR_VERSION   (3U)
#define COM_AR_RELEASE_PATCH_VERSION   (1U)

/* Include of Communication Stack Types*/

#include "CommStack_Types.h"


#include "Com_Cbk.h"
/*
 * Macros for Com Module Status
 */
#define COM_INITIALIZED                (1U)
#define COM_NOT_INITIALIZED            (0U)

/* PduR Pre-Compile Configuration Header file */
#include "Com_Cfg.h"
/* AUTOSAR Version checking between Com_Cfg.h and Com.h files */
#if ((COM_CFG_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)\
        ||  (COM_CFG_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION)\
        ||  (COM_CFG_AR_RELEASE_PATCH_VERSION != COM_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Com_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Com_Cfg.h and Com.h files */
#if ((COM_CFG_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION)\
        ||  (COM_CFG_SW_MINOR_VERSION != COM_SW_MINOR_VERSION)\
        ||  (COM_CFG_SW_PATCH_VERSION != COM_SW_PATCH_VERSION))
#error "The SW version of Com_Cfg.h does not match the expected version"
#endif

/*Including Det module for developmnet error reporting*/
#if (STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"

/* AUTOSAR Version checking between Det and CanIf Modules */
#if ((DET_AR_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)\
        || (DET_AR_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION)\
        || (DET_AR_PATCH_VERSION != COM_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/


/* Service ID for Com Init API */
#define COM_INIT_SID                    (uint8)0x01

/* Service ID for Com_SendSignal API */
#define COM_SEND_SIGNAL_SID                    (uint8)0x0A

/*the service is currently not available e.g.
 *the corresponding I-PDU group is stopped
 *(or a development error has been detected)
 */
#define COM_SERVICE_NOT_AVAILABLE       0x80

/*Successful execution of this function is
 *currently not possible, because a resource
 *is currently in use.
 */
#define COM_BUSY                        0x81

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* API service called with wrong parameter */
#define COM_E_PARAM                     (uint8)0x01

/* Error code if any other API service, except Com_GetStatus, is
 * called before the AUTOSAR COM module was initialized with Com_Init or after a call
 * to Com_Deinit
 */
#define COM_E_UNINIT                    (uint8)0x02

/* NULL pointer checking */
#define COM_E_PARAM_POINTER             (uint8)0x03

/* Invalid configuration set selection */
#define COM_E_INIT_FAILED               (uint8)0x04

/*******************************************************************************
 *                     RUN TIME Error Codes                                        *
 *******************************************************************************/

/* Transmission request was skipped */
#define COM_E_SKIPPED_TRANSMISSION      (uint8)0x05

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

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
void Com_Init(const Com_ConfigType* config );

/************************************************************************************
 * Service Name: Com_SendSignal
 * Service ID[hex]: 0x0a
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 * Parameters (in): SignalId; Id of signal to be sent.
 *                  SignalDataPtr; Reference to the signal data to be transmitted.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: uint8 E_OK: service has been accepted
 *                           COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group
 *                           was stopped (or service failed due to development error)
 *                           COM_BUSY: in case the TP-Buffer is locked for large data types
 *                           handling
 * Description: The service Com_SendSignal updates the signal object identified by SignalId with
 *              the signal referenced by the SignalDataPtr parameter.
 *
 ************************************************************************************/
uint8 Com_SendSignal(Com_SignalIdType SignalId,const void* SignalDataPtr);

/************************************************************************************
 * Service Name: Com_ReceiveSignal
 * Service ID[hex]: 0x0b
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant for the same signal. Reentrant for different signals.
 * Parameters (in): SignalId; Id of signal to be received.
 * Parameters (inout): None
 * Parameters (out): SignalDataPtr Reference to the location where the received signal data shall be
 *                                 stored.
 * Return value: uint8 E_OK: service has been accepted
 *                           COM_SERVICE_NOT_AVAILABLE: corresponding I-PDU group
 *                           was stopped (or service failed due to development error)
 *                           COM_BUSY: in case the TP-Buffer is locked for large data types
 *                           handling
 * Description: Com_ReceiveSignal copies the data of the signal identified by SignalId to the
 *              location specified by SignalDataPtr.
 *
 ************************************************************************************/
uint8 Com_ReceiveSignal(Com_SignalIdType SignalId,void* SignalDataPtr);

/************************************************************************************
 * Service Name: Com_MainFunctionTx
 * Service ID[hex]: 0x19
 * Return value: None
 * Description: This function performs the processing of the AUTOSAR
 * COM module's transmission activities that are not directly handled
 * within the COM's function invoked by
 * the RTE, for example Com_SendSignal.
 ************************************************************************************/
void Com_MainFunctionTx(void);

/************************************************************************************
 * Service Name: Com_MainFunctionRx
 * Service ID[hex]: 0x18
 * Return value: None
 * Description: This function performs the processing of the AUTOSAR COM module's receive
 *              processing that are not directly handled within the COM's functions invoked by the
 *              PDU-R, for example Com_RxIndication.
 ************************************************************************************/
void Com_MainFunctionRx(void);


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern  const Com_ConfigType Com ;
extern  PduInfoType PDU[ComMaxIPduCnt];
extern  uint8 SignalObject[MAX_NUM_OF_SIGNAL];

#endif /* CUFE_AUTOSAR_CAN_STACK_COM_H_ */

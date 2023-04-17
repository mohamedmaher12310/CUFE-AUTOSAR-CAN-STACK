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
 *                       External Variables                                    *
 *******************************************************************************/


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
//void Com_Init(const Com_ConfigType* config );




#endif /* CUFE_AUTOSAR_CAN_STACK_COM_H_ */

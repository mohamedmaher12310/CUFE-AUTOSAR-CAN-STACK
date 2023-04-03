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

/*Com Types Header file*/
#include "CommStack_Types.h"

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





#endif /* CUFE_AUTOSAR_CAN_STACK_COM_H_ */

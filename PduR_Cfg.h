/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for PduR Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef PDUR_CFG_H_
#define PDUR_CFG_H_

/*
 * Module version
 */
#define PDUR_CFG_SW_MAJOR_VERSION            (1U)
#define PDUR_CFG_SW_MINOR_VERSION            (0U)
#define PDUR_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define PDUR_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define PDUR_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define PDUR_CFG_AR_RELEASE_PATCH_VERSION    (1U)

/*CanIf Header file*/
#include "CanIf.h"
/* AUTOSAR Version checking between PduR.h and CanIf.h files */
#if ((PDUR_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)\
 ||  (PDUR_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)\
 ||  (PDUR_AR_RELEASE_PATCH_VERSION != CANIF_AR_RELEASE_PATCH_VERSION))
#error "The AR version of CanIf.h does not match the expected version"
#endif

/* Software Version checking between PduR.h and CanIf.h files */
#if ((CANIF_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||   (CANIF_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||   (CANIF_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of Can.h does not match the expected version"
#endif


/************************PduRGeneral Container*******************************/
#define PduRDevErrorDetect                      (STD_ON)


#endif /* PDUR_CFG_H_ */

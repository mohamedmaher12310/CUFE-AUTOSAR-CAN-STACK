/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for CanIf Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CANIF_CFG_H_
#define CANIF_CFG_H_

/*
 * Module version
 */
#define CANIF_CFG_SW_MAJOR_VERSION            (1U)
#define CANIF_CFG_SW_MINOR_VERSION            (0U)
#define CANIF_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define CANIF_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define CANIF_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define CANIF_CFG_AR_RELEASE_PATCH_VERSION    (1U)

/* Include of CanDrv Configuration file*/
#include "Can_Cfg.h"

/* AUTOSAR Version checking between Can_PBcfg.c and Can.h files */
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION != CAN_CFG_AR_RELEASE_MAJOR_VERSION)\
 ||  (CANIF_CFG_AR_RELEASE_MINOR_VERSION != CAN_CFG_AR_RELEASE_MINOR_VERSION)\
 ||  (CANIF_CFG_AR_RELEASE_PATCH_VERSION != CAN_CFG_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can_Cfg.c does not match the expected version"
#endif

/* Software Version checking between Can_PBcfg.c and Can.h files */
#if ((CANIF_CFG_SW_MAJOR_VERSION != CAN_CFG_SW_MAJOR_VERSION)\
 ||  (CANIF_CFG_SW_MINOR_VERSION != CAN_CFG_SW_MINOR_VERSION)\
 ||  (CANIF_CFG_SW_PATCH_VERSION != CAN_CFG_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* Include of CanIf Header Filer*/
#include "CanIf.h"

/* AUTOSAR Version checking between Can_PBcfg.c and Can.h files */
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)\
 ||  (CANIF_CFG_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)\
 ||  (CANIF_CFG_AR_RELEASE_PATCH_VERSION != CANIF_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can_Cfg.c does not match the expected version"
#endif

/* Software Version checking between Can_PBcfg.c and Can.h files */
#if ((CANIF_CFG_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION)\
 ||  (CANIF_CFG_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION)\
 ||  (CANIF_CFG_SW_PATCH_VERSION != CANIF_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif



/************************CanIfPrivateCfg Container*******************************/
/*Selects whether Data Length Check is supported.*/
#define CanIfPrivateDataLengthCheck         (STD_ON)

/*
 * Selects the desired software filter mechanism for reception only. Each
 * implemented software filtering method is identified by this enumeration
 * number.
 */
#define CanIf_PrivateSoftwareFilterType      (CanIfPrivateSoftwareFilterType)(BINARY)

/************************CanIfPublicCfg Container*******************************/
/*Switches the development error detection and notification on or off.*/
#define CanIfDevErrorDetect                 (STD_ON)

/*Enable support for dynamic ID handling using L-SDU MetaData.*/
#define CanIfMetaDataSupport                (STD_ON)

/*
 * Configuration parameter to enable/disable dummy API for upper layer
 * modules which allows to request the cancellation of an I-PDU.
 */
#define CanIfPublicCancelTransmitSupport    (STD_ON)

/*
 * This parameter is used to configure the Can_HwHandleType. The
 * Can_HwHandleType represents the hardware object handles of a CAN
 * hardware unit. For CAN hardware units with more than 255 HW objects
 * the extended range shall be used (UINT16).
 */
#define CanIf_PublicHandleTypeEnum           (CanIfPublicHandleTypeEnum)(UINT8)

/*
 * Enables / Disables the API CanIf_ReadRxPduData() for reading
 * received L-SDU data.
 */
#define CanIfPublicReadRxPduDataApi         (STD_ON)

/*
 * Enables and disables the API for reconfiguration of the CAN Identifier
 * for each Transmit L-PDU.
 */
#define CanIfPublicSetDynamicTxIdApi        (STD_ON)

/*
 * Configuration parameter to enable/disable the API to poll for Tx
 * Confirmation state
 */
#define CanIfPublicTxConfirmPollingSupport  (STD_ON)


/************************CanIfTxPduCfg Container*******************************/



/*ECU wide unique, symbolic handle for transmit CAN L-SDU.*/
#define CanIfTxPduId_0          (0U)
#define CanIfTxPduId_1          (1U)

#define CanIfTxPduCanId_0       0x0
#define CanIfTxPduCanId_1       0x1

#define CanIfTxPduCanIdMask_0   0x0
#define CanIfTxPduCanIdMask_1   0x0

#define CanIfTxPduCanIdType_0  (CanIfTxPduCanIdType)STANDARD_CAN
#define CanIfTxPduCanIdType_1  (CanIfTxPduCanIdType)STANDARD_CAN

#define CanIfTxPduType_0       (CanIfTxPduType)DYNAMIC_ID
#define CanIfTxPduType_1       (CanIfTxPduType)DYNAMIC_ID
/*
 *
#define CanIfTxPduId_2          (2U)
#define CanIfTxPduId_3          (3U)
#define CanIfTxPduId_4          (4U)
#define CanIfTxPduId_5          (5U)
*/


#endif /* CANIF_CFG_H_ */

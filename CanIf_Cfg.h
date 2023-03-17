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

/*
 * Enables and disables the API for reading the notification status of
 * receive L-PDUs.
 */
#define CanIfPublicReadRxPduNotifyStatusApi   (STD_ON)

/*
 * Enables and disables the API for reading the notification status of
 * transmit L-PDUs.
 */
#define CanIfPublicReadTxPduNotifyStatusApi   (STD_ON)

/************************CanIfHrhCfg Container*******************************/
/* Number of configured HRH*/
#define HRH_NUMBER                         (2U)
/*HRH Index numbers*/
#define HRH0_ID                            (0U)
#define HRH1_ID                            (1U)

/************************CanIfHthCfg Container*******************************/
/* Number of configured HTH*/
#define HTH_NUMBER                         (3U)
/*HTH Index numbers*/
#define HTH0_ID                            (0U)
#define HTH1_ID                            (1U)
#define HTH2_ID                            (2U)
/* Number of configured Tx Buffers*/
#define CanIf_BUFFER_NUMBER                (HTH_NUMBER)

/************************CanIfTxPduCfg Container*******************************/

/*
 * Maximum number of Pdus. This parameter is needed only in case of
 * post-build loadable implementation using static memory allocation.
 */
#define CanIfMaxTxPduCfg                   (2U)

/*ECU wide unique, symbolic handle for transmit CAN L-SDU.*/
#define CanIfTxPduId_0          (0U)
#define CanIfTxPduId_1          (1U)

/*
 * CAN Identifier of transmit CAN L-PDUs used by the CAN Driver for
 * CAN L-PDU transmission.
 */
#define CanIfTxPduCanId_0       (0b00000000010)
#define CanIfTxPduCanId_1       (0b00000000000)

/*
 * Identifier mask which denotes relevant bits in the CAN Identifier. This
 * parameter may be used to keep parts of the CAN Identifier of dynamic
 * transmit L-PDUs static.
 */
#define CanIfTxPduCanIdMask_0   (0b11111111111)
#define CanIfTxPduCanIdMask_1   (0b11111111111)

/*
 * Type of CAN Identifier of the transmit CAN L-PDU used by the CAN
 * Driver module for CAN L-PDU transmission.
 */
#define CanIfTxPduCanIdType_0  (CanIfTxPduCanIdType)STANDARD_CAN
#define CanIfTxPduCanIdType_1  (CanIfTxPduCanIdType)STANDARD_CAN

/* Defines the type of each transmit CAN L-PDU.*/
#define CanIfTxPduType_0       (CanIfTxPduType)STATIC_ID
#define CanIfTxPduType_1       (CanIfTxPduType)STATIC_ID

/*
 * This parameter defines the upper layer (UL) module to which the
 * confirmation of the successfully transmitted CANTXPDUID has to be
 * routed via the <User_TxConfirmation>. This <User_TxConfirmation>
 * has to be invoked when the confirmation of the configured
 * CANTXPDUID will be received by a Tx confirmation event from the
 * CAN Driver module. If no upper layer (UL) module is configured, no
 * <User_TxConfirmation> has to be called in case of a Tx confirmation
 * event of the CANTXPDUID from the CAN Driver module.
 */
#define CanIfTxPduUserTxConfirmationUL_0       (CanIfUser)PDUR
#define CanIfTxPduUserTxConfirmationUL_1       (CanIfUser)PDUR

/************************CanIfRxPduCfg Container*******************************/

/*
 * Maximum number of Pdus. This parameter is needed only in case of
 * post-build loadable implementation using static memory allocation.
 */
#define CanIfMaxRxPduCfg                         (2U)

/*
 * ECU wide unique, symbolic handle for receive CAN L-SDU. It shall
 * fulfill ANSI/AUTOSAR definitions for constant defines.
 * Range: 0..max. number of defined CanRxPduIds
 */
#define CanIfRxPduId_0            (0U)
#define CanIfRxPduId_1            (1U)

/*
 * Identifier mask which denotes relevant bits in the CAN Identifier. This
 * parameter defines a CAN Identifier range in an alternative way to
 * CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
 * Identifier that must match the received CAN Identifier. Range: 11 bits
 * for Standard CAN Identifier, 29 bits for Extended CAN Identifier.
 */
#define CanIfRxPduCanIdMask_0   (0b11111111111)
#define CanIfRxPduCanIdMask_1   (0b11111111111)

/*
 * CAN Identifier of Receive CAN L-PDUs used by the CAN Interface.
 * Exa: Software Filtering. This parameter is used if exactly one Can
 * Identifier is assigned to the Pdu. If a range is assigned then the
 * CanIfRxPduCanIdRange parameter shall be used.
 */
#define CanIfRxPduCanId_0       (0b00000000000)
#define CanIfRxPduCanId_1       (0b00000000000)

/*This parameter defines the name of the <User_RxIndication>.*/
#define CanIfRxPduUserRxIndicationName_0          (CanIfUser)(PDUR)
#define CanIfRxPduUserRxIndicationName_1          (CanIfUser)(PDUR)

/*Data length of the received CAN L-PDUs used by the CAN Interface.*/
#define CanIfRxPduDataLength_0                    (8U)
#define CanIfRxPduDataLength_1                    (8U)


/************************CanIfCtrlCfg Container*******************************/
/*Number of Configured CanDrvs*/
#define Can_DRIVERS_NUMBER                 (1U)

/*
 * This parameter abstracts from the CAN Driver specific parameter
 * Controller. Each controller of all connected CAN Driver modules shall
 * be assigned to one specific ControllerId of the CanIf. Range:
 * 0..number of configured controllers of all CAN Driver modules
 */
#define CanIfCtrlId_0   CAN0_CONTROLLER_ID
#define CanIfCtrlId_1   CAN1_CONTROLLER_ID

/************************CanIfHrhCfg Container*******************************/

/*
 * Lower CAN Identifier of a receive CAN L-PDU for identifier range
 * definition, in which all CAN Ids shall pass the software filtering.
 */
#define CanIfHrhRangeRxPduLowerCanId_0              (0b00000000000)
#define CanIfHrhRangeRxPduLowerCanId_1              (0b00000000000)

/*
 * Upper CAN Identifier of a receive CAN L-PDU for identifier range
 * definition, in which all CAN Ids shall pass the software filtering.
 */
#define CanIfHrhRangeRxPduUpperCanId_0              (0b11111111111)
#define CanIfHrhRangeRxPduUpperCanId_1              (0b11111111111)

/*
 * Selects the hardware receive objects by using the HRH range/list from
 * CAN Driver configuration to define, for which HRH a software filtering
 * has to be performed at during receive processing.
 * True: Software filtering is enabled
 * False: Software filtering is disabled
 */
#define CanIfHrhSoftwareFilter_0       (STD_ON)
#define CanIfHrhSoftwareFilter_1       (STD_ON)



#endif /* CANIF_CFG_H_ */

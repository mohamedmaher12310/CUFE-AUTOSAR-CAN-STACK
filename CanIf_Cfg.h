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

#include "Can.h"

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


/**************************
Name: CanIfMaxBufferSize
Parent Container: CanIfInitCfg
Description:Maximum total size of all Tx buffers. This parameter is needed only in
            case of post-build loadable implementation using static memory
            allocation.
 *****************/
#define CanIfMaxBufferSize  (uint64)50
/**************************
Name: CanIfMaxTxPduCfg
Parent Container: CanIfInitCfg
Description:Maximum number of Pdus. This parameter is needed only in case of
            post-build loadable implementation using static memory allocation
 *****************/
#define CanIfMaxTxPduCfg    (uint64)40
/**************************
Name: CanIfMaxRxPduCfg
Parent Container: CanIfInitCfg
Description:Maximum number of Pdus. This parameter is needed only in case of
            post-build loadable implementation using static memory allocation
 *****************/
#define CanIfMaxRxPduCfg    (uint64)10

/**************************
Name: CanIfPublicReadRxPduDataApi
Parent Container: CanIfPublicCfg
Description:Enables / Disables the API CanIf_ReadRxPduData() for reading
            received L-SDU data.
            True: Enabled
            False: Disabled
 *****************/
#define CanIfPublicReadRxPduDataApi         (STD_OFF)
/**************************
Name: CanIfPublicReadRxPduNotifyStatusApi
Parent Container: CanIfPublicCfg
Description:Enables and disables the API for reading the notification status of
            receive L-PDUs.
            True: Enabled
            False: Disabled
 *****************/
#define CanIfPublicReadRxPduNotifyStatusApi     (STD_OFF)
/***********
 Name: CanIfRxPduId
 Parent Container: CanIfRxPduCfg
 Description: ECU wide unique, symbolic handle for receive CAN L-SDU. It shall
              fulfill ANSI/AUTOSAR definitions for constant defines.
              Range: 0..max. number of defined CanRxPduIds
 ****************/
#define CanIfRxPduId_0            (uint32)0
#define CanIfRxPduId_1            (uint32)1
#define CanIfRxPduId_2            (uint32)2
#define CanIfRxPduId_3            (uint32)3
#define CanIfRxPduId_4            (uint32)4
#define CanIfRxPduId_5            (uint32)5
#define CanIfRxPduId_6            (uint32)6
#define CanIfRxPduId_7            (uint32)7
#define CanIfRxPduId_8            (uint32)8
#define CanIfRxPduId_9            (uint32)9
/***********
 Name: CanIfRxPduUserRxIndicationName
 Parent Container: CanIfRxPduCfg
 Description:   This parameter defines the name of the <User_RxIndication>. This
                parameter depends on the parameter
                CANIF_RXPDU_USERRXINDICATION_UL. If
                CANIF_RXPDU_USERRXINDICATION_UL equals CAN_TP,
                CAN_NM, PDUR, XCP, CAN_TSYN, J1939NM or J1939TP, the name
                of the <User_RxIndication> is fixed. If
                CANIF_RXPDU_USERRXINDICATION_UL equals CDD, the name of
                the <User_RxIndication> is selectable.
 ****************/

#define CanIfRxPduUserRxIndicationName      (CanIfRxPduUserRxIndicationUL)PDUR

/**************************
Name: CanIfHrhSoftwareFilter
Parent Container: CanIfHrhCfg
Description:Selects the hardware receive objects by using the HRH range/list from
            CAN Driver configuration to define, for which HRH a software filtering
            has to be performed at during receive processing.
            True: Software filtering is enabled
            False: Software filtering is disabled
 *****************/

#define CanIfHrhSoftwareFilter_0       (STD_ON)
#define CanIfHrhSoftwareFilter_1       (STD_ON)

/**************************
Name: CanIfCtrlId
Parent Container:  CanIfCtrlCfg
Description:This parameter abstracts from the CAN Driver specific parameter
            Controller. Each controller of all connected CAN Driver modules shall
            be assigned to one specific ControllerId of the CanIf. Range:
            0..number of configured controllers of all CAN Driver modules
 *****************/

#define CanIfCtrlId_0   (uint8)0
#define CanIfCtrlId_1   (uint8)1
/**************************
Name: CanIfHrhCanCtrlIdRef
Parent Container: CanIfHrhCfg
Description:Reference to controller Id to which the HRH belongs to. A controller
can contain one or more HRHs.
 *****************/
#define CanIfHrhCanCtrlIdRef_0       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_1       (CanIfCtrlCfg)CanIfCtrlId_0

/***************************
Name: CanIfRxPduCanId
Parent Container : CanIfRxPduCfg
Description:Identifier mask which denotes relevant bits in the CAN Identifier. This
            parameter defines a CAN Identifier range in an alternative way to
            CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
            Identifier that must match the received CAN Identifier. Range: 11 bits
            for Standard CAN Identifier, 29 bits for Extended CAN Identifier.
 ************/
/*
#define CanIfRxPduCanId_0      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_1      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_2      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_3      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_4      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_5      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_6      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_7      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_8      (CanIfRxPduCanIdType)STANDARD_CAN
#define CanIfRxPduCanId_9      (CanIfRxPduCanIdType)STANDARD_CAN
 */


/**************************
Name: CanIfRxPduDataLength
Parent Container :CanIfRxPduCfg
Description:Data length of the received CAN L-PDUs used by the CAN Interface.
            This information is used for Data Length Check. Additionally it might
            specify the valid bits in case of the discrete DLC for CAN FD L-PDUs >
            8 bytes.
            The data area size of a CAN L-PDU can have a range from 0 to 64
            bytes.
 ****************/
/*
#define CanIfRxPduDataLength_0             (uint8)8
#define CanIfRxPduDataLength_1             (uint8)8
#define CanIfRxPduDataLength_2             (uint8)8
#define CanIfRxPduDataLength_3             (uint8)8
#define CanIfRxPduDataLength_4             (uint8)8
#define CanIfRxPduDataLength_5             (uint8)8
#define CanIfRxPduDataLength_6             (uint8)8
#define CanIfRxPduDataLength_7             (uint8)8
#define CanIfRxPduDataLength_8             (uint8)8
#define CanIfRxPduDataLength_9             (uint8)8
 */

/**************************
Name: CanIfRxPduReadData
Parent Container: CanIfRxPduCfg
Description:Enables and disables the Rx buffering for reading of received L-SDU
            data.
            True: Enabled
            False: Disabled
 ****************/
/*
#if(STD_OFF == CANIF_CANPDUID_READDATA_API)

#define CanIfRxPduReadData_0     (STD_OFF)
#define CanIfRxPduReadData_1     (STD_OFF)
#define CanIfRxPduReadData_2     (STD_OFF)
#define CanIfRxPduReadData_3     (STD_OFF)
#define CanIfRxPduReadData_4     (STD_OFF)
#define CanIfRxPduReadData_5     (STD_OFF)
#define CanIfRxPduReadData_6     (STD_OFF)
#define CanIfRxPduReadData_7     (STD_OFF)
#define CanIfRxPduReadData_8     (STD_OFF)
#define CanIfRxPduReadData_9     (STD_OFF)

#endif

 */



/**************************
Name: CanIfRxPduReadNotifyStatus
Parent Container :CanIfRxPduCfg
Description:Enables and disables receive indication for each receive CAN L-SDU
            for reading its notification status.
            True: Enabled False: Disabled

 ****************/
/*
#if(STD_OFF == CANIF_READRXPDU_NOTIFY_STATUS_API)

#define CanIfRxPduReadNotifyStatus_0    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_1    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_2    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_3    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_4    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_5    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_6    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_7    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_8    (STD_OFF)
#define CanIfRxPduReadNotifyStatus_9    (STD_OFF)

#endif
 */

/**************************
Name: CanIfRxPduRef
Parent Container :CanIfRxPduCfg
Description:Reference to the "global" Pdu structure to allow harmonization of
            handle IDs in the COM-Stack.

 ****************?????????????????????????????????????????????????????????????????????????????????*/
/*
#define CanIfRxPduRef_0            (Pdu)
#define CanIfRxPduRef_1            (Pdu)
#define CanIfRxPduRef_2            (Pdu)
#define CanIfRxPduRef_3            (Pdu)
#define CanIfRxPduRef_4            (Pdu)
#define CanIfRxPduRef_5            (Pdu)
#define CanIfRxPduRef_6            (Pdu)
#define CanIfRxPduRef_7            (Pdu)
#define CanIfRxPduRef_8            (Pdu)
#define CanIfRxPduRef_9            (Pdu)
 */


/**************************
Name: CanIfRxPduCanIdMask
Parent Container CanIfTxPduCfg
Description:Identifier mask which denotes relevant bits in the CAN Identifier. This
            parameter defines a CAN Identifier range in an alternative way to
            CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
            Identifier that must match the received CAN Identifier. Range: 11 bits
            for Standard CAN Identifier, 29 bits for Extended CAN Identifier.

 ****************/
/*
#define CanIfRxPduCanIdMask_0    0b11111111111
#define CanIfRxPduCanIdMask_1    0b11111111111
#define CanIfRxPduCanIdMask_2    0b11111111111
#define CanIfRxPduCanIdMask_3    0b11111111111
#define CanIfRxPduCanIdMask_4    0b11111111111
#define CanIfRxPduCanIdMask_5    0b11111111111
#define CanIfRxPduCanIdMask_6    0b11111111111
#define CanIfRxPduCanIdMask_7    0b11111111111
#define CanIfRxPduCanIdMask_8    0b11111111111
#define CanIfRxPduCanIdMask_9    0b11111111111
 */

#endif /* CANIF_CFG_H_ */

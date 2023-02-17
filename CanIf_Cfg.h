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
#define CanIfMaxBufferSize  (uint64)64
/**************************
Name: CanIfMaxTxPduCfg
Parent Container: CanIfInitCfg
Description:Maximum number of Pdus. This parameter is needed only in case of
            post-build loadable implementation using static memory allocation
 *****************/
#define CanIfMaxTxPduCfg    (uint64)10
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
/**************************
Name: CanIfHrhIdSymRef
Parent Container: CanIfHrhCfg
Description:The parameter refers to a particular HRH object in the CanDrv
            configuration (see CanHardwareObject ECUC_Can_00324).
            CanIf receives the following information of the CanDrv module by
            this reference:
            • CanHandleType (see ECUC_Can_00323)
            • CanObjectId (see ECUC_Can_00326)

 *****************/
typedef struct CanIfHrhCfg
{
    CanHardwareObject * CanIfHrhIdSymRef;
}CanIfHrhCfg;

/**************************
Container Name: CanIfRxPduCfg
Description:This container contains the configuration (parameters) of each receive
            CAN L-PDU.
            The SHORT-NAME of "CanIfRxPduConfig" container itself represents
            the symolic name of Receive L-PDU.
            This L-SDU produces a meta data item of type CAN_ID_32
 *****************/
typedef struct  CanIfRxPduCfg
{

    //CanIfRxPduHrhIdRef,
    /**************************
    Name: CanIfRxPduHrhIdRef
    Parent Container :CanIfRxPduCfg
    Description:The HRH to which Rx L-PDU belongs to, is referred through this
                parameter.
     *****************/
    CanIfHrhCfg* CanIfRxPduHrhIdRef;
    //CanIfRxPduReadNotifyStatus,
    //CanIfRxPduRef,
    //CanIfRxPduUserRxIndicationUL,
    //CanIfRxPduCanIdType,
    //CanIfRxPduId,
    //CanIfRxPduDataLength
    //CanIfRxPduReadData
    //CanIfRxPduCanId,
    }CanIfRxPduCfg;
/***************************
Name: CanIfRxPduCanId
Parent Container : CanIfRxPduCfg
Description:Identifier mask which denotes relevant bits in the CAN Identifier. This
            parameter defines a CAN Identifier range in an alternative way to
            CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
            Identifier that must match the received CAN Identifier. Range: 11 bits
            for Standard CAN Identifier, 29 bits for Extended CAN Identifier.
************/
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
/**************************
Name: CanIfRxPduCanIdMask
Parent Container CanIfTxPduCfg
Description:Identifier mask which denotes relevant bits in the CAN Identifier. This
            parameter defines a CAN Identifier range in an alternative way to
            CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
            Identifier that must match the received CAN Identifier. Range: 11 bits
            for Standard CAN Identifier, 29 bits for Extended CAN Identifier.

 ****************/
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
/***********
 Name: CanIfRxPduCanIdType
 Parent Container: CanIfRxPduCfg
 Description:CAN Identifier of receive CAN L-PDUs used by the CAN Driver for
             CAN L-PDU reception.
 ****************/
typedef enum{
    EXTENDED_CAN,      /*CAN 2.0 or CAN FD frame with extended identifier (29 bits)*/
    EXTENDED_FD_CAN,    /**CAN FD frame with extended identifier(29 bits)*/
    EXTENDED_NO_FD_CAN,      /*CAN 2.0 frame with extended identifier(29 bits)*/
    STANDARD_CAN,           /*CAN 2.0 or CAN FD frame with standard identifier (11 bits)*/
    STANDARD_FD_CAN,         /*CAN FD frame with standard identifier(11 bits)*/
    STANDARD_NO_FD_CAN       /*CAN 2.0 frame with standard identifier(11 bits)*/

}CanIfRxPduCanIdType;
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
/**************************
Name: CanIfRxPduReadData
Parent Container: CanIfRxPduCfg
Description:Enables and disables the Rx buffering for reading of received L-SDU
            data.
            True: Enabled
            False: Disabled
 ****************/
#if(STD_ON == CANIF_CANPDUID_READDATA_API)

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
/**************************
Name: CanIfRxPduReadNotifyStatus
Parent Container :CanIfRxPduCfg
Description:Enables and disables receive indication for each receive CAN L-SDU
            for reading its notification status.
            True: Enabled False: Disabled

 ****************/
#if(STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API)

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
/**************************
Name: CanIfRxPduUserRxIndicationUL
Parent Container: CanIfRxPduCfg
Description:This parameter defines the upper layer (UL) module to which the
            indication of the successfully received CANRXPDUID has to be routed
            via <User_RxIndication>. This <User_RxIndication> has to be invoked
            when the indication of the configured CANRXPDUID will be received
            by an Rx indication event from the CAN Driver module. If no upper
            layer (UL) module is configured, no <User_RxIndication> has to be
            called in case of an Rx indication event of the CANRXPDUID from the
            CAN Driver module.
 ****************/
typedef enum
{
    CAN_NM,
    CAN_TP,
    CAN_TSYN,
    CDD,
    J1939NM,
    J1939TP,
    PDUR,
    XCP
}CanIfRxPduUserRxIndicationUL;
/**************************
Name: CanIfRxPduRef
Parent Container :CanIfRxPduCfg
Description:Reference to the "global" Pdu structure to allow harmonization of
            handle IDs in the COM-Stack.

 ****************?????????????????????????????????????????????????????????????????????????????????*/
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
/**************************
Name: CanIfHrhSoftwareFilter
Parent Container: CanIfHrhCfg
Description:Selects the hardware receive objects by using the HRH range/list from
            CAN Driver configuration to define, for which HRH a software filtering
            has to be performed at during receive processing.
            True: Software filtering is enabled
            False: Software filtering is disabled
 *****************/

                /*CAN_0*/
 #define Can0_CanIfHrhSoftwareFilter_0       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_1       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_2       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_3       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_4       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_5       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_6       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_7       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_8       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_9       (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_10      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_11      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_12      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_13      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_14      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_15      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_16      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_17      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_18      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_19      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_20      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_21      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_22      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_23      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_24      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_25      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_26      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_27      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_28      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_29      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_30      (STD_ON)
 #define Can0_CanIfHrhSoftwareFilter_31      (STD_ON)

               /*CAN_1*/
#define Can1_CanIfHrhSoftwareFilter_0       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_1       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_2       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_3       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_4       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_5       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_6       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_7       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_8       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_9       (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_10      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_11      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_12      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_13      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_14      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_15      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_16      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_17      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_18      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_19      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_20      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_21      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_22      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_23      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_24      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_25      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_26      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_27      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_28      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_29      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_30      (STD_ON)
#define Can1_CanIfHrhSoftwareFilter_31      (STD_ON)
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
#define CanIfHrhCanCtrlIdRef_2       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_3       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_4       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_5       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_6       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_7       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_8       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_9       (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_10      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_11      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_12      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_13      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_14      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_15      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_16      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_17      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_18      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_19      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_20      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_21      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_22      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_23      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_24      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_25      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_26      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_27      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_28      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_29      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_30      (CanIfCtrlCfg)CanIfCtrlId_0
#define CanIfHrhCanCtrlIdRef_31      (CanIfCtrlCfg)CanIfCtrlId_0


#endif /* CANIF_CFG_H_ */

/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf_Types.h
 *
 * Description: CanIf type definitions
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/
#ifndef CANIF_TYPES_H_
#define CANIF_TYPES_H_

/* Include of Communication Stack Types*/
#include "CommStack_Types.h"
/* Include of Can General Types*/
#include "Can_GeneralTypes.h"
/* Include of Can Header file*/
#include "Can.h"
#define HTH_NUMBER                          3
#define CanIf_BUFFER_NUMBER                HTH_NUMBER
#define Can_DRIVERS_NUMBER                 (uint8)1

#define CanIfMaxTxPduCfg                   (uint8)2
#define HRH_NUMBER                          3
#define CanIf_Rx_BUFFER_NUMBER                HRH_NUMBER

#define ECU_NETWORK_NUMBER                  3

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*
 *The PduMode of a channel defines its transmit or receive activity.
 *Communication direction (transmission and/or reception) of the channel can
 *be controlled separately or together by upper layers.
 */
typedef enum
{
    CANIF_OFFLINE,
    CANIF_TX_OFFLINE,
    CANIF_TX_OFFLINE_ACTIVE,
    CANIF_ONLINE
} CanIf_PduModeType;

/* Return value of CAN L-PDU notification status. */
typedef enum
{
    CANIF_NO_NOTIFICATION,
    CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

/*
 * This container contains the configuration (parameters) of an adressed
 * CAN controller by an underlying CAN Driver module. This container is
 * configurable per CAN controller.
 */
typedef struct
{
    /*
     * This parameter abstracts from the CAN Driver specific parameter
     * Controller. Each controller of all connected CAN Driver modules shall
     * be assigned to one specific ControllerId of the CanIf. Range:
     * 0..number of configured controllers of all CAN Driver modules
     */
    uint8 CanIfCtrlId;

    /*
     * This parameter references to the logical handle of the underlying CAN
     * controller from the CAN Driver module to be served by the CAN
     * Interface module. The following parameters of CanController config
     * container shall be referenced by this link: CanControllerId,
     * CanWakeupSourceRef
     */
    CanController* CanIfCtrlCanCtrlRef;

    boolean CanIfCtrlWakeupSupport;


} CanIfCtrlCfg;

/*
 * Specifies whether a configured Range of CAN Ids shall only consider
 *standard CAN Ids or extended CAN Ids.
 **/
typedef enum
{
    EXTENDED,
    STANDARD

}CanIfHrhRangeRxPduRangeCanIdType;


/* This container contains parameters related to each HTH.*/
typedef struct
{
    CanIfCtrlCfg* CanIfHthCanCtrlIdRef;
    CanHardwareObject* CanIfHthIdSymRef;
} CanIfHthCfg ;
typedef struct CanIfHrhRangeCfg
{
    /*CAN Identifier used as base value in combination with
     *CanIfHrhRangeMask for a masked ID range in which all CAN Ids shall
     *pass the software filtering. The size of this parameter is limited by
     *CanIfHrhRangeRxPduRangeCanIdType.*/
    uint32 CanIfHrhRangeBaseId;

    /* Used as mask value in combination with CanIfHrhRangeBaseId for a
     *masked ID range in which all CAN Ids shall pass the software filtering.
     *The size of this parameter is limited by
     *CanIfHrhRangeRxPduRangeCanIdType.
     * */
    uint32 CanIfHrhRangeMask;
    /*
     * Lower CAN Identifier of a receive CAN L-PDU for identifier range
     *definition, in which all CAN Ids shall pass the software filtering.
     * */
    uint32 CanIfHrhRangeRxPduLowerCanId;
    /*
     * Upper CAN Identifier of a receive CAN L-PDU for identifier range
     *definition, in which all CAN Ids shall pass the software filtering.
     * */
    uint32 CanIfHrhRangeRxPduUpperCanId;
    /*
     * Specifies whether a configured Range of CAN Ids shall only consider
     *standard CAN Ids or extended CAN Ids.
     **/
    CanIfHrhRangeRxPduRangeCanIdType CanIfHrhRangeRxPduRangeCanIdType;

}CanIfHrhRangeCfg;
/**************************
Container Name: CanIfHrhCfg
Description:This container contains configuration parameters for each hardware
            receive object (HRH).
 *****************/

typedef struct CanIfHrhCfg
{
    CanIfCtrlCfg* CanIfHrhCanCtrlIdRef;

    CanHardwareObject* CanIfHrhIdSymRef;

    boolean CanIfHrhSoftwareFilter ;

    CanIfHrhRangeCfg CanIfHrhRange_config;
}CanIfHrhCfg;
/*
 * This container contains the references to the configuration setup of
 * each underlying CAN Driver.
 */
typedef struct
{
    CanIfHthCfg CanIfHthCfg[HTH_NUMBER];
    CanIfHrhCfg  CanIfHrh_config[HRH_NUMBER];

} CanIfInitHohCfg;

/*
 * Selects the desired software filter mechanism for reception only. Each
 * implemented software filtering method is identified by this enumeration
 * number.
 */
typedef enum
{
    BINARY,
    INDEX,
    LINEAR,
    TABLE
} CanIfPrivateSoftwareFilterType;

/*
 * Type of CAN Identifier of the transmit CAN L-PDU used by the CAN
 * Driver module for CAN L-PDU transmission.
 */
typedef enum
{
    EXTENDED_CAN,
    EXTENDED_FD_CAN,
    STANDARD_CAN,
    STANDARD_FD_CAN
} CanIfTxPduCanIdType;
typedef enum
{
    EXTENDED_CAN_RX,
    EXTENDED_FD_CAN_RX,
    EXTENDED_NO_FD_CAN_RX,
    STANDARD_CAN_RX,
    STANDARD_FD_CAN_RX,
    STANDARD_NO_FD_CAN_RX

}CanIfRxPduCanIdType;
/* Defines the type of each transmit CAN L-PDU.*/
typedef enum
{
    DYNAMIC_ID,
    STATIC_ID
} CanIfTxPduType;

/*
 * This parameter is used to configure the Can_HwHandleType. The
 * Can_HwHandleType represents the hardware object handles of a CAN
 * hardware unit. For CAN hardware units with more than 255 HW objects
 * the extended range shall be used (UINT16).
 */
typedef enum
{
    UINT16,
    UINT8
} CanIfPublicHandleTypeEnum;


/*
   This container contains the Txbuffer configuration. Multiple buffers with
    different sizes could be configured. If CanIfBufferSize
    (ECUC_CanIf_00834) equals 0, the CanIf Tx L-PDU only refers via this
    CanIfBufferCfg the corresponding CanIfHthCfg. */

typedef struct
{
    uint8 CanIfBufferSize;
    CanIfHthCfg* CanIfBufferHthRef;

}CanIfBufferCfg;

/*
 * This container contains the configuration (parameters) of a transmit
 * CAN L-PDU. It has to be configured as often as a transmit CAN L-PDU
 * is needed.
 */
typedef struct
{
    /*
     * CAN Identifier of transmit CAN L-PDUs used by the CAN Driver for
     * CAN L-PDU transmission. Range: 11 Bit For Standard CAN Identifier
     * ... 29 Bit For Extended CAN identifier
     */
    uint32 CanIfTxPduCanId;

    /*
     * Identifier mask which denotes relevant bits in the CAN Identifier. This
     * parameter may be used to keep parts of the CAN Identifier of dynamic
     * transmit L-PDUs static. Range: 11 bits for Standard CAN Identifier, 29
     * bits for Extended CAN Identifier.
     */
    uint32 CanIfTxPduCanIdMask;

    /*
     * Type of CAN Identifier of the transmit CAN L-PDU used by the CAN
     * Driver module for CAN L-PDU transmission.
     */
    CanIfTxPduCanIdType CanIfTxPduCanIdType;

    /*ECU wide unique, symbolic handle for transmit CAN L-SDU.*/
    uint32 CanIfTxPduId;

    /*Enables/disables truncation of PDUs that exceed the configured size.*/
    boolean CanIfTxPduTruncation;

    /*Defines the type of each transmit CAN L-PDU.*/
    CanIfTxPduType CanIfTxPduType;

    /*Configurable reference to a CanIf buffer configuration*/
    CanIfBufferCfg* CanIfTxPduBufferRef;

} CanIfTxPduCfg;




/* This container contains the init parameters of the CAN Interface.*/
typedef struct
{
   /*
    * Selects the CAN Interface specific configuration setup. This type of the
    * external data structure shall contain the post build initialization data for
    * the CAN Interface for all underlying CAN Dirvers.
    */
    uint8 CanIfInitCfgSet[ECU_NETWORK_NUMBER];/*l 1 daah bata3 eiih*/ /*mahoor : dah index lel ECU elli me7tag 2a3mel
                                 set lel configurations bata3tha
                                 fa 2a7na fel CAN network bata3tna me7tageen 3 ECU bas ;) */
    /* Sub-Containers */

    /*
     *  This container contains the Txbuffer configuration.
        Multiple buffers with different sizes could be configured.
        If CanIfBufferSize (ECUC_CanIf_00834) equals 0, the
        CanIf Tx L-PDU only refers via this CanIfBufferCfg the
        corresponding CanIfHthCfg*/
    CanIfBufferCfg CanIfBufferCfg[CanIf_BUFFER_NUMBER];

    CanIfInitHohCfg CanIfInitHohCfg[Can_DRIVERS_NUMBER];

    CanIfTxPduCfg CanIfTxPduCfg[CanIfMaxTxPduCfg];

    /* Maximum total size of all Tx buffers. This parameter is needed only in case of post-build loadable implementation using static memory allocation. */
    uint64 CanIfMaxBufferSize;  //
    /* uint32 CanIfNumberOfCanRxPduIds; Maximum number of Pdus.
        This parameter is needed only in case of post-build loadable implementation
        using static memory allocation.*/
    uint64 CanIfMaxRxPduCfg; //


//
//    /** This container contains parameters related to each HTH */
//    CanIfInitHohCfg* CanIfHohConfigPtr;  // Conflict between standerd and AVECORE Code
//
//    /* Rx PDU's list */
//    CanIfRxPduCfg*  CanIfRxPduConfigPtr;
//

} CanIfInitCfg;

/*
 * Configuration parameters for all the underlying CAN Driver modules
 * are aggregated under this container. For each CAN Driver module a
 * seperate instance of this container has to be provided.
 */
typedef struct
{
    /*Reference to the Init Hoh Configuration*/
    CanIfInitHohCfg* CanIfCtrlDrvInitHohConfigRef;

    /*Sub-Container*/
    CanIfCtrlCfg CanIfCtrlCfg[CAN_CONTROLLERS_NUMBER];

    /*howa 2ayeli refrence to can general ro7t 2ashoof l can general mala2etoosh bayadeeni 2ai ma3lomat 3an l x. Driver Name,
    Vendor ID  */
        CanGeneral* CanIfCtrlDrvNameRef;
} CanIfCtrlDrvCfg;

/*
 * This type defines a data structure for the post build parameters of the CAN
 *interface for all underlying CAN drivers. At initialization the CanIf gets a
 *pointer to a structure of this type to get access to its configuration data, which
 *is necessary for initialization.
 */
typedef struct
{
    /*Sub-Containers*/
    CanIfCtrlDrvCfg CanIfCtrlDrvCfg ;
    CanIfInitCfg  CanIfInitCfg;
    /* Reference to the list of channel init configurations. */
    CanIfCtrlCfg* ControllerConfig;
} CanIf_ConfigType;

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
Container Name: CanIfRxPduCfg
Description:This container contains the configuration (parameters) of each receive
            CAN L-PDU.
            The SHORT-NAME of "CanIfRxPduConfig" container itself represents
            the symolic name of Receive L-PDU.
            This L-SDU produces a meta data item of type CAN_ID_32
 *****************/
typedef struct  CanIfRxPduCfg
{
    /**CAN Identifier of Receive CAN L-PDUs used by the CAN Interface.
     *  Exa: Software Filtering. This parameter is used if exactly one Can
     *  Identifier is assigned to the Pdu. If a range is assigned then the
     *  CanIfRxPduCanIdRange parameter shall be used.
     *  Range: 11 Bit For Standard CAN Identifier ... 29 Bit For Extended CAN
     *  identifier*/
    uint32 CanIfRxPduCanId;
    /*Identifier mask which denotes relevant bits in the CAN Identifier. This
parameter defines a CAN Identifier range in an alternative way to
CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
Identifier that must match the received CAN Identifier. Range: 11 bits
for Standard CAN Identifier, 29 bits for Extended CAN Identifier.*/
    uint32 CanIfRxPduCanIdMask;

    /**************************
Name: CanIfRxPduHrhIdRef
Parent Container :CanIfRxPduCfg
Description:The HRH to which Rx L-PDU belongs to, is referred through this
            parameter.
     *****************/
    CanIfHrhCfg* CanIfRxPduHrhIdRef;

    /**************************
Name: CanIfRxPduReadNotifyStatus
Parent Container :CanIfRxPduCfg
Description:Enables and disables receive indication for each receive CAN L-SDU
            for reading its notification status.
            True: Enabled
            False: Disabled
     ****************/
#if(STD_ON == CANIF_READRXPDU_NOTIFY_STATUS_API)
    boolean CanIfRxPduReadNotifyStatus;
#endif

    /**************************
    Name: CanIfRxPduRef
    Parent Container :CanIfRxPduCfg
    Description:Reference to the "global" Pdu structure to allow harmonization of
                handle IDs in the COM-Stack.

     *****************/
//    Pdu * CanIfRxPduRef;

    /*UPPER LAYER USER NAME*/

    CanIfRxPduUserRxIndicationUL RxPduUser;

    CanIfRxPduCanIdType IdType;

    uint8 CanIfRxPduId;

    uint8 CanIfRxPduDataLength;

#if(STD_OFF == CANIF_CANPDUID_READDATA_API)
    boolean CanIfRxPduReadData;
#endif

    /**************************
    Name: CanIfRxPduCanIdMask
    Parent Container CanIfTxPduCfg
    Description:Identifier mask which denotes relevant bits in the CAN Identifier. This
                parameter defines a CAN Identifier range in an alternative way to
                CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
                Identifier that must match the received CAN Identifier. Range: 11 bits
                for Standard CAN Identifier, 29 bits for Extended CAN Identifier.

     ****************/
    //    uint32 CanIfRxPduCanIdMask ;

}CanIfRxPduCfg;
#endif /* CANIF_TYPES_H_ */

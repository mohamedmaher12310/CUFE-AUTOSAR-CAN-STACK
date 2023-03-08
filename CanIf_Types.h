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

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* The State of the CanIf module  */
typedef enum
{
    CANIF_UNINIT,
    CANIF_READY
} CanIf_State;
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


/* This container contains parameters related to each HTH.*/
typedef struct
{
    CanIfCtrlCfg* CanIfHthCanCtrlIdRef;
    CanHardwareObject* CanIfHthIdSymRef;
} CanIfHthCfg ;

/*
 * Defines the parameters required for configurating multiple CANID
 * ranges for a given same HRH.
 */
typedef struct
{
    /*
     * Lower CAN Identifier of a receive CAN L-PDU for identifier range
     * definition, in which all CAN Ids shall pass the software filtering.
     */
    uint32 CanIfHrhRangeRxPduLowerCanId;

    /*
     * Upper CAN Identifier of a receive CAN L-PDU for identifier range
     * definition, in which all CAN Ids shall pass the software filtering.
     */
    uint32 CanIfHrhRangeRxPduUpperCanId;

} CanIfHrhRangeCfg;

/*
 * This container contains configuration parameters for each hardware
 * receive object (HRH).
 */
typedef struct
{
    /*
     * Reference to controller Id to which the HRH belongs to. A controller
     * can contain one or more HRHs.
     */
    CanIfCtrlCfg* CanIfHrhCanCtrlIdRef;

    /*
     * The parameter refers to a particular HRH object in the CanDrv
     * configuration
     */
    CanHardwareObject* CanIfHrhIdSymRef;

    /*
     * Selects the hardware receive objects by using the HRH range/list from
     * CAN Driver configuration to define, for which HRH a software filtering
     * has to be performed at during receive processing.
     */
    boolean CanIfHrhSoftwareFilter ;

    /*Sub-Containers*/
    CanIfHrhRangeCfg CanIfHrhRangeCfg;

} CanIfHrhCfg;

/*
 * This container contains the references to the configuration setup of
 * each underlying CAN Driver.
 */
typedef struct
{
    CanIfHthCfg  CanIfHthCfg[HTH_NUMBER];
    CanIfHrhCfg  CanIfHrhCfg[HRH_NUMBER];
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

/*
 * CAN Identifier of receive CAN L-PDUs used by the CAN Driver for
 * CAN L-PDU reception.
 */
typedef enum
{
    STANDARD_CAN_Rx=0,
    EXTENDED_CAN_Rx=2,
} CanIfRxPduCanIdType;

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
 * This container contains the Txbuffer configuration. Multiple buffers with
 * different sizes could be configured. If CanIfBufferSize
 * (ECUC_CanIf_00834) equals 0, the CanIf Tx L-PDU only refers via this
 * CanIfBufferCfg the corresponding CanIfHthCfg.
 */
typedef struct
{
    uint8 CanIfBufferSize;
    CanIfHthCfg* CanIfBufferHthRef;

} CanIfBufferCfg;

/*
 * This parameter defines the upper layer (UL) module to which the
 * confirmation of the successfully transmitted CANTXPDUID has to be
 * routed via the <User_TxConfirmation>. This <User_TxConfirmation>
 * has to be invoked when the confirmation of the configured
 * CANTXPDUID will be received by a Tx confirmation event from the
 * CAN Driver module. If no upper layer (UL) module is configured, no
 * <User_TxConfirmation> has to be called in case of a Tx confirmation
 * event of the CANTXPDUID from the CAN Driver module.
 * It also defines the upper layer (UL) module to which the
 * indication of the successfully received CANRXPDUID has to be routed
 * via <User_RxIndication>. This <User_RxIndication> has to be invoked
 * when the indication of the configured CANRXPDUID will be received
 * by an Rx indication event from the CAN Driver module. If no upper
 * layer (UL) module is configured, no <User_RxIndication> has to be
 * called in case of an Rx indication event of the CANRXPDUID from the
 * CAN Driver module.
 */
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
} CanIfUser;

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

    /*
     * Enables and disables the API for reading the notification status of
     * transmit L-PDUs.
     */
#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
    boolean CanIfTxPduReadNotifyStatus;
#endif

    /*Enables/disables truncation of PDUs that exceed the configured size.*/
    boolean CanIfTxPduTruncation;

    /*Defines the type of each transmit CAN L-PDU.*/
    CanIfTxPduType CanIfTxPduType;

    /*Defines the upper layer (UL) module to which the confirmation of the successfully transmitted.*/
    CanIfUser CanIfTxPduUserTxConfirmationUL;

    /*Configurable reference to a CanIf buffer configuration*/
    CanIfBufferCfg* CanIfTxPduBufferRef;

} CanIfTxPduCfg;

/*
 * This container contains the configuration (parameters) of each receive
 * CAN L-PDU.
 */
typedef struct
{
    /*
     *  CAN Identifier of Receive CAN L-PDUs used by the CAN Interface.
     *  Exa: Software Filtering. This parameter is used if exactly one Can
     *  Identifier is assigned to the Pdu. If a range is assigned then the
     *  CanIfRxPduCanIdRange parameter shall be used.
     *  Range: 11 Bit For Standard CAN Identifier ... 29 Bit For Extended CAN
     *  identifier
     */
    uint32 CanIfRxPduCanId;

    /*
     * Identifier mask which denotes relevant bits in the CAN Identifier. This
     * parameter defines a CAN Identifier range in an alternative way to
     * CanIfRxPduCanIdRange. It identifies the bits of the configured CAN
     * Identifier that must match the received CAN Identifier. Range: 11 bits
     * for Standard CAN Identifier, 29 bits for Extended CAN Identifier.
     */
    uint32 CanIfRxPduCanIdMask;

    /*
     * The HRH to which Rx L-PDU belongs to, is referred through this
     * parameter.
     */
    CanIfHrhCfg* CanIfRxPduHrhIdRef;

    /*
     * Enables and disables receive indication for each receive CAN L-SDU
     * for reading its notification status.
     * True: Enabled
     * False: Disabled
     */
#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
    boolean CanIf_RxPduReadNotifyStatus;
#endif

    /*
     * CAN Identifier of receive CAN L-PDUs used by the CAN Driver for
     * CAN L-PDU reception.
     */
    CanIfRxPduCanIdType CanIfRxPduCanIdType;

    /*
     * ECU wide unique, symbolic handle for receive CAN L-SDU. It shall
     * fulfill ANSI/AUTOSAR definitions for constant defines.
     */
    uint32 CanIfRxPduId;

    /*
     * Data length of the received CAN L-PDUs used by the CAN Interface.
     * This information is used for Data Length Check. Additionally it might
     * specify the valid bits in case of the discrete DLC for CAN FD L-PDUs >
     * 8 bytes.
     */
    uint8 CanIfRxPduDataLength;

    /*
     * Enables and disables the Rx buffering for reading of received L-SDU
     * data.
     */
#if(STD_ON == CanIfPublicReadRxPduDataApi)
    boolean CanIf_RxPduReadData;
#endif

    /*
     * This parameter defines the upper layer (UL) module to which the
     * indication of the successfully received CANRXPDUID has to be routed
     * via <User_RxIndication>. This <User_RxIndication> has to be invoked
     * when the indication of the configured CANRXPDUID will be received
     * by an Rx indication event from the CAN Driver module. If no upper
     * layer (UL) module is configured, no <User_RxIndication> has to be
     * called in case of an Rx indication event of the CANRXPDUID from the
     * CAN Driver module.
     */
    CanIfUser CanIfRxPduUserRxIndicationName;

}CanIfRxPduCfg;

/* This container contains the init parameters of the CAN Interface.*/
typedef struct
{
    /*
     * Selects the CAN Interface specific configuration setup. This type of the
     * external data structure shall contain the post build initialization data for
     * the CAN Interface for all underlying CAN Dirvers.
     */
    uint8 CanIfInitCfgSet[CAN_HOH_NUMBER];


    /* Maximum total size of all Tx buffers. This parameter is needed only in case of post-build loadable implementation using static memory allocation. */
    uint64 CanIfMaxBufferSize;

    /* Sub-Containers */

    CanIfBufferCfg CanIfBufferCfg[CanIf_BUFFER_NUMBER];

    CanIfInitHohCfg CanIfInitHohCfg[Can_DRIVERS_NUMBER];

    CanIfTxPduCfg CanIfTxPduCfg[CanIfMaxTxPduCfg];

    CanIfRxPduCfg CanIfRxPduCfg[CanIfMaxRxPduCfg];
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

    /*
     * CAN Interface Driver Reference.
     * This reference can be used to get any information (Ex. Driver Name,
     * Vendor ID) from the CAN driver.
     */
    CanGeneral* CanIfCtrlDrvNameRef;

    /*Sub-Container*/
    CanIfCtrlCfg CanIfCtrlCfg[CAN_CONTROLLERS_NUMBER];
} CanIfCtrlDrvCfg;

/*
 * This type defines a data structure for the post build parameters of the CAN
 * interface for all underlying CAN drivers. At initialization the CanIf gets a
 * pointer to a structure of this type to get access to its configuration data, which
 * is necessary for initialization.
 */
typedef struct
{
    /*Sub-Containers*/
    CanIfCtrlDrvCfg CanIfCtrlDrvCfg ;
    CanIfInitCfg  CanIfInitCfg;
    /* Reference to the list of channel init configurations. */
    CanIfCtrlCfg* ControllerConfig;
} CanIf_ConfigType;

#endif /* CANIF_TYPES_H_ */

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

#define CanIf_BUFFER_NUMBER                HTH_NUMBER
#define Can_DRIVERS_NUMBER                 (uint8)1

#define CanIfMaxTxPduCfg                   (uint8)2


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

} CanIfCtrlCfg;


/* This container contains parameters related to each HTH.*/
typedef struct
{
    CanIfCtrlCfg* CanIfHthCanCtrlIdRef;
    CanHardwareObject* CanIfHthIdSymRef;
} CanIfHthCfg ;

/*
 * This container contains the references to the configuration setup of
 * each underlying CAN Driver.
 */
typedef struct
{
    CanIfHthCfg CanIfHthCfg[HTH_NUMBER];

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
    uint8 CanIfInitCfgSet[1];
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
} CanIf_ConfigType;


#endif /* CANIF_TYPES_H_ */

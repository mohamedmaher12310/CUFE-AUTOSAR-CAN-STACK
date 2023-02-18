/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf.h
 *
 * Description: Header file for Can Interface Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef CANIF_H_
#define CANIF_H_

/* Id for the company in the AUTOSAR
 * for example Omar Khedr's ID = 1000 :) */
#define CANIF_VENDOR_ID    (1000U)

/* CanIf Module Id */
#define CANIF_MODULE_ID    (31U)


/*
 * Module Version 1.0.0
 */
#define CANIF_SW_MAJOR_VERSION           (1U)
#define CANIF_SW_MINOR_VERSION           (0U)
#define CANIF_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define CANIF_AR_RELEASE_MAJOR_VERSION   (4U)
#define CANIF_AR_RELEASE_MINOR_VERSION   (3U)
#define CANIF_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Macros for CanIf Module Status
 */
#define CANIF_INITIALIZED                (1U)
#define CANIF_NOT_INITIALIZED            (0U)

/* CanIf Pre-Compile Configuration Header file */
#include "CanIf_Cfg.h"
/* AUTOSAR Version checking between CanIf_Cfg.h and CanIf.h files */
#if ((CANIF_CFG_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)\
        ||  (CANIF_CFG_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)\
        ||  (CANIF_CFG_AR_RELEASE_PATCH_VERSION != CANIF_AR_RELEASE_PATCH_VERSION))
#error "The AR version of CanIf_Cfg.h does not match the expected version"
#endif

/* Software Version checking between CanIf_Cfg.h and CanIf.h files */
#if ((CANIF_CFG_SW_MAJOR_VERSION != CANIF_SW_MAJOR_VERSION)\
        ||  (CANIF_CFG_SW_MINOR_VERSION != CANIF_SW_MINOR_VERSION)\
        ||  (CANIF_CFG_SW_PATCH_VERSION != CANIF_SW_PATCH_VERSION))
#error "The SW version of CanIf_Cfg.h does not match the expected version"
#endif

/*CANIF Types Header file*/
#include "CanIf_Types.h"

/*CanDrv Header file*/
#include "Can.h"
/* AUTOSAR Version checking between CanIf.h and Can.h files */
#if ((CANIF_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (CANIF_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (CANIF_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can.h does not match the expected version"
#endif

/* Software Version checking between CanIf.h and Can.h files */
#if ((CANIF_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||   (CANIF_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||   (CANIF_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of Can.h does not match the expected version"
#endif

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for CanIf Init API */
#define CANIF_INIT_SID                    (uint8)0x01

/* Service ID for CanIf De-Init API */
#define CANIF_DE_INIT_SID                 (uint8)0x02

/* Service ID for CanIf Set Controller Mode API*/
#define CANIF_SET_CONTROLLER_MODE_SID     (uint8)0x03

/* Service ID for CanIf Transmit API*/
#define CANIF_TRANSMIT_SID                (uint8)0x49

/* Service ID for CanIf Set PDU Mode API*/
#define CANIF_SET_PDU_MODE_SID            (uint8)0x09

/* Service ID for CanIf Set Dynamic Tx Id API*/
#define CANIF_SET_DYNAMIC_TXID_SID        (uint8)0x0c

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report that an API Service called with wrong parameter */
#define CANIF_E_PARAM_CANID                 (uint8)10
#define CANIF_E_PARAM_HOH                   (uint8)12
#define CANIF_E_PARAM_LPDU                  (uint8)13
#define CANIF_E_PARAM_CONTROLLERID          (uint8)15
#define CANIF_E_PARAM_CTRLMODE              (uint8)21
#define CANIF_E_PARAM_PDU_MODE              (uint8)22

/* DET Code to report that an API Service used without initialization */
#define CANIF_E_UNINIT                      (uint8)30

/* DET code to report that an API service called with invalid pointer */
#define CANIF_E_PARAM_POINTER               (uint8)20

/* DET code to report that Transmit PDU ID is invalid */
#define CANIF_E_INVALID_TXPDUID             (uint8)50

/* DET code to report that Recieve PDU ID is invalid */
#define CANIF_E_INVALID_RXPDUID             (uint8)60

/* DET Code to report that CAN Interface initialization failed*/
#define CANIF_E_INIT_FAILED                 (uint8)80

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
/*
 * Specifies whether a configured Range of CAN Ids shall only consider
 *standard CAN Ids or extended CAN Ids.
 **/
typedef enum
{
    EXTENDED,
    STANDARD

}CanIfHrhRangeRxPduRangeCanIdType;

typedef struct {

}CanIfCtrlCfg;

typedef struct Pdu{




}Pdu;
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
#if(STD_OFF == CANIF_READRXPDU_NOTIFY_STATUS_API)
    boolean CanIfRxPduReadNotifyStatus;
#endif

    /**************************
    Name: CanIfRxPduRef
    Parent Container :CanIfRxPduCfg
    Description:Reference to the "global" Pdu structure to allow harmonization of
                handle IDs in the COM-Stack.

     *****************/
    Pdu * CanIfRxPduRef;

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
    uint32 CanIfRxPduCanIdMask ;

}CanIfRxPduCfg;
/**************************
Container Name: CanIfInitHohCfg
Description:This container contains the references to the configuration setup of
            each underlying CAN Driver.
 *****************/
typedef struct CanIfInitHohCfg
{

    CanIfHrhCfg CanIfHrh_config;

}CanIfInitHohCfg;

/**************************

Container Name CanIfInitCfg
Description This container contains the init parameters of the CAN Interface.
*************************/
typedef struct{

    /*  Selects the CAN Interface specific configuration setup. This type of the  external data structure shall contain the post build initialization data for
        the CAN Interface for all underlying CAN Dirvers.
     */
    uint32 CanIfInitCfgSet[32]; //

    /* Maximum total size of all Tx buffers. This parameter is needed only in case of post-build loadable implementation using static memory allocation. */
    uint64 CanIfMaxBufferSize;  //

    /* uint32 CanIfNumberOfCanRxPduIds; Maximum number of Pdus.
        This parameter is needed only in case of post-build loadable implementation
        using static memory allocation.*/
    uint64 CanIfMaxRxPduCfg; //

    /* AUTOSAR 4.3 uint32 CanIfMaxTxPduCfg;
        Maximum number of Pdus. This parameter is needed only in case of
        post-build loadable implementation using static memory allocation.*/
    uint64 CanIfMaxTxPduCfg;  //

      /** This container contains parameters related to each HTH */
    CanIfInitHohCfg* CanIfHohConfigPtr;  // Conflict between standerd and AVECORE Code

      /* Rx PDU's list */
    CanIfRxPduCfg*  CanIfRxPduConfigPtr;

    CanIfTxPduCfg* CanIfTxPduConfigPtr;


}CanIfInitCfg;

/*
 * This type defines a data structure for the post build parameters of the CAN
 *interface for all underlying CAN drivers. At initialization the CanIf gets a
 *pointer to a structure of this type to get access to its configuration data, which
 *is necessary for initialization.
 */
typedef struct
{
    /* Reference to the list of channel init configurations. */
       CanIfCtrlCfg* ControllerConfig;

       /* This container contains the init parameters of the CAN Interface. */
       CanIfInitCfg* InitConfig;

} CanIf_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: CanIf_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr - Pointer to configuration parameter set.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize internal and external interfaces of the
 *              CAN Interface for the further processing
 ************************************************************************************/
void CanIf_Init(const CanIf_ConfigType* ConfigPtr);

/************************************************************************************
 * Service Name: CanIf_DeInit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to De-initialize the CanIf module.
 ************************************************************************************/
void CanIf_DeInit(void);

/************************************************************************************
 * Service Name: CanIf_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant (Not for the same controller)
 * Parameters (in): ControllerId - Abstracted CanIf ControllerId which is assigned to a
 *                                 CAN controller, which is requested for mode transition.
 *                  ControllerMode - Requested mode transition
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Controller mode request has been accepted
 *                                E_NOT_OK: Controller mode request hasn't been accepted
 * Description: Function to call the corresponding CAN Driver service for changing of
                the CAN controller mode.
 ************************************************************************************/
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType ControllerMode);

/************************************************************************************
 * Service Name: CanIf_Transmit
 * Service ID[hex]: 0x49
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): TxPduId - Identifier of the PDU to be transmitted
 *                  PduInfoPtr - Length of and pointer to the PDU data and pointer
 *                               to MetaData.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Transmit request has been accepted.
 *                                E_NOT_OK: Transmit request hasn't been accepted
 * Description: Function to Request transmission of a PDU.
 ************************************************************************************/
Std_ReturnType CanIf_Transmit(PduIdType TxPduId,const PduInfoType* PduInfoPtr);

/************************************************************************************
 * Service Name: CanIf_SetPduMode
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ControllerId - All PDUs of the own ECU connected to the corresponding
 *                                 CanIf ControllerId, which is assigned to a physical
 *                                 CAN controller are addressed.
 *                  PduModeRequest - Requested PDU mode change.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Request for mode transition has been accepted.
 *                                E_NOT_OK:  Request for mode transition hasn't been accepted
 * Description: Function to set the requested mode at the L-PDUs of a predefined logical
 *              PDU channel.
 ************************************************************************************/
Std_ReturnType CanIf_SetPduMode(uint8 ControllerId,CanIf_PduModeType PduModeRequest);

/************************************************************************************
 * Service Name: CanIf_SetDynamicTxId
 * Service ID[hex]: 0x0c
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): CanIfTxSduId - L-SDU handle to be transmitted. This handle specifies
 *                                 the corresponding CAN L-SDU ID and implicitly the
 *                                 CAN Driver instance as well as the corresponding CAN controller
 *                                 device.
 *                  CanId - Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD
 *                          or conventional CAN frame.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to reconfigure the corresponding CAN identifier of the
 *              requested CAN L-PDU.
 ************************************************************************************/
void CanIf_SetDynamicTxId(PduIdType CanIfTxSduId,Can_IdType CanId);

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/




/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/







#endif /* CANIF_H_ */

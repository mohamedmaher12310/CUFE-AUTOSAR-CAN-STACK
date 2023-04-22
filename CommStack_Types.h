/******************************************************************************
 *
 * Module: Communication Stack Types
 *
 * File Name: CommStack_Types.h
 *
 * Description: General Communication Stack type definitions
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/

#ifndef COMMSTACK_TYPES_H_
#define COMMSTACK_TYPES_H_

#include "Std_Types.h"

#include "Com_Cfg.h"
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Type definition of the ID of the PDU*/
typedef uint32 PduIdType;

/*Type definition of the Length of the PDU*/
typedef uint32 PduLengthType;

/*Structure that carries the info of the PDU*/
typedef struct
{
    uint8* SduDataPtr; /*Pointer to the data*/
    uint8* MetaDataPtr; /*Pointer to the meta data*/
    PduLengthType SduLength; /*Length of the SDU in bytes*/
} PduInfoType;

/* This is a status value returned by the API service Com_GetStatus(). */
typedef enum{
    COM_UNINIT,
    COM_INIT
}Com_StatusType;

/* The AUTOSAR COM module's signal object identifier. */
typedef uint16 Com_SignalIdType;

/*The direction defines if this I-PDU, and therefore the contributing signals and
 *signal groups, shall be sent or received.
 */
typedef enum
{
    RECEIVE,
    SEND
}ComIPduDirection;

/*For the definition of the two modes Immediate and Deferred.*/
typedef enum
{
    DEFERRED,
    IMMEDIATE
}ComIPduSignalProcessing;

/*Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or if this is a
 *large I-PDU that shall be sent via the Transport Protocol of the underlying bus.
 */
typedef enum
{
    NORMAL,
    TP
}ComIPduType;

/* This parameter defines the action performed upon reception of an invalid signal.
 * Relating to signal groups the action in case if one of the included signals is an
 * invalid signal.
 * If Replace is used the ComSignalInitValue will be used for the replacement.
 */
typedef enum
{
    NOTIFY,
    REPLACE
}ComDataInvalidAction;

/* This parameter defines the action performed upon expiration
 * of the reception deadline monitoring timer.
 */
typedef enum
{
    NONE_Rx,
    REPLACE_Rx,
    SUBSTITUTE_Rx
}ComRxDataTimeoutAction;

/* Defines the endianness of the signal's network representation. */
typedef enum
{
    BIG_ENDIAN,
    LITTLE_ENDIAN,
    OPAQUE
}ComSignalEndianness;


/* Defines when the update-bits of signals or signal groups, contained in this I-PDU,
 * will be cleared.
 */
typedef enum
{
    Confirmation,
    Transmit,
    TriggerTransmit
}ComTxIPduClearUpdateBit;

/* The AUTOSAR type of the signal. Whether or not the signal is signed or unsigned
 * can be found by examining the value of this attribute.
 * This type could also be used to reserved appropriate storage in AUTOSAR COM.
 */
typedef enum
{
    BOOLEAN,
    FLOAT32,
    FLOAT64,
    SINT16,
    SINT32,
    SINT64,
    SINT8,
    UINT16,
    UINT32,
    UINT64,
    UINT8,
    UINT8_DYN,
    UINT8_N
}ComSignalType;

/* Defines if a write access to this signal can trigger the transmission
 * of the corresponding I-PDU. If the I-PDU is triggered,
 * depends also on the transmission mode of the
 * corresponding I-PDU.
 */
typedef enum
{
    PENDING,/*postponed the send of pdu if all signals within the pdu is PENDING*/
    TRIGGERED,
    //    TRIGGE RED_ON_CHANGE,
    //    TRIGGERED_ON_CHANGE_WITHOUT_REPETITION,
    //    TRIGGERED_WITHOUT_REPETITION
}ComTransferProperty;

/* The available transmission modes described in [18] shall
 * be extended by the additional mode None.The transmission mode None
 * shall not have any further sub-attributes in the
 * ComTxMode object.
 */
typedef enum{
    DIRECT_Tx,      /* on trigger when specific signal 7asalaha trigger with Com_SendSignal() */
    //    MIXED_Tx,
    //    NONE_Tx,
    PERIODIC_Tx     /* periodic kol 2ad eih all tansfere property is not needed now*/
}ComTxModeMode;






/************************ComSignal Sub-Container************************/

/* Contains the configuration parameters of the AUTOSAR COM module's signals. */
typedef struct
{
    /* Starting position within the I-PDU. This parameter refers to the position in
     * the I-PDU and not in the shadow buffer. If the endianness conversion is
     * configured to Opaque the parameter ComBitPosition shall define the bit0
     * of the first byte like in little endian byte order
     */
    uint32 ComBitPosition;

    /* The numerical value used as the ID.
     * This ID identifies signals and signal groups in the COM APIs using
     * Com_SignalIdType or Com_SignalGroupIdType parameter respectively.
     */
    uint16 ComHandleId;

    /* This parameter defines that the respective signal's initial value shall be put
     * into the respective PDU but there will not be any update of the value
     * through the RTE. Thus the Com implementation does not need to expect
     * any API calls for this signal (group).
     */
    boolean ComInitialValueOnly;

    /* On sender side: Name of Com_CbkTxAck callback function to be called.
     * On receiver side: Name of Com_CbkRxAck callback function to be called.
     * If this parameter is omitted no notification shall take place.
     */
    void(*ComNotification)(void);

    /* This parameter defines the action performed upon expiration
     * of the reception deadline monitoring timer.
     */
    ComRxDataTimeoutAction ComRxDataTimeoutAction;

    /* Defines the endianness of the signal's network representation. */
    ComSignalEndianness ComSignalEndianness;

    /* Initial value for this signal. In case of UINT8_N the default value is a string
     * of length ComSignalLength with all bytes set to 0x00. In case of
     * UINT8_DYN the initial size shall be 0.
     * In case the ComSignalType is UINT8, UINT16, UINT32, UINT64, SINT8,
     * SINT16, SINT32, SINT64 the string shall be interpreted as defined in the
     * chapter Integer Type in the AUTOSAR EcuC specification.
     * In case the ComSignalType is FLOAT32, FLOAT64 the string shall be
     * interpreted as defined in the chapter Float Type in the AUTOSAR EcuC
     * specification.
     * In case the ComSignalType is BOOLEAN the string shall be interpreted as
     * defined in the chapter Boolean Type in the AUTOSAR EcuC specification.
     * In case the ComSignal is a UINT8_N, UINT8_DYN the string shall be
     * interpreted as a decimal representation of the characters separated by
     * blanks, e.g. "97 98 100" means a string "abd", where the char "a" is in byte
     * 0(lowest address), "b" is in byte 1, and "d" is in byte 2 and (highest
     * address).
     * For the ComSignalType UINT8_DYN the dynamic length shall be set to the
     * number of configured characters. An empty string "" shall be interpreted as
     * 0-sized dynamic signal.
     */
    uint8 ComSignalInitValue;

    /* The AUTOSAR type of the signal. Whether or not the signal is signed or unsigned
     * can be found by examining the value of this attribute.
     * This type could also be used to reserved appropriate storage in AUTOSAR COM.
     */
    ComSignalType ComSignalType;

    /* Defines the length of the deadline monitoring timeout period in seconds.
     * The period for the first timeout period can be configured separately by
     * ECUC_Com_00183.
     */
    float32 ComTimeout;

    /* Defines if a write access to this signal can trigger the transmission
     * of the corresponding I-PDU. If the I-PDU is triggered,
     * depends also on the transmission mode of the
     * corresponding I-PDU.
     */
    ComTransferProperty ComTransferProperty;

    /* Bit position of update-bit inside I-PDU.
     * If this attribute is omitted then there is no update-bit. This setting must be
     * consistently on sender and on receiver side.
     * Range: 0..63 for CAN and LIN,
     * 0..511 for CAN FD,
     * 0..2031 for FlexRay,
     * 0..4294967295 for TP.
     */
    uint8 ComUpdateBitPosition;

    /*refrence to which lpdu this signal belong*/
    void* ComSystemTemplateSystemSignalRef;  //updated

}ComSignal;

/************************ComTxMode Sub-Container************************/

/* This container contains the configuration parameters of the AUTOSAR
 * COM module's transmission modes.
 */
typedef struct
{
    /* The available transmission modes described in [18] shall be extended by the additional mode None.
     * The transmission mode None shall not have any further sub-attributes in the
     * ComTxMode object.
     */
    ComTxModeMode ComTxModeMode;

    /* Defines the number of repetitions for the transmission mode DIRECT and
     * the event driven part of transmission mode MIXED.
     */
    //    uint8 ComTxModeNumberOfRepetitions;

    /* Defines the repetition period in seconds of the multiple transmissions in
     * case ComTxModeNumberOfRepetitions is configured greater than or
     * equal to 1 and ComTxModeMode is configured to DIRECT or MIXED. In
     * case of the mixed transmission mode only the event driven part is affected.
     */
    //    float32 ComTxModeRepetitionPeriod;

    /* Defines the period in seconds between the start of the I-PDU by
     * Com_IpduGroupStart and the first transmission request in case
     * ComTxModeMode is configured to PERIODIC or MIXED. In case of the
     * mixed transmission mode only the periodic part is affected.
     * In case ComTxModeTimeOffset is omitted or configured to 0, the first
     * periodic transmission shall be transmitted within the next invocation of
     * Com_MainFunctionTx.
     */
    //    float32 ComTxModeTimeOffset;

    /* Defines the repetition period in seconds of the periodic transmission requests
     * in case ComTxModeMode is configured to PERIODIC or MIXED. In
     * case of the mixed transmission mode only the periodic part is affected.
     */
    float32 ComTxModeTimePeriod;

}ComTxMode;

/************************ComTxIPdu Sub-Container************************/

/* This container contains additional transmission related configuration
 *  parameters of the AUTOSAR COM module's I-PDUs.
 */
typedef struct
{
    /* Defines the Minimum Delay Time (MDT) between successive transmissions of this I-PDU in seconds. The MDT is independent of the possible
     * different transmission modes. There is only one minimum delay time parameter for one I-PDU. The minimum delay timer is not reset by changing
     * the transmission mode. Hence, it is not allowed to violate the minimum
     * delay time by transmission mode changes. It is not possible to monitor the
     * minimum delay time for I-PDUs that are requested using the
     * Com_TriggerTransmit API.
     */
    float32 ComMinimumDelayTime;

    /* Defines when the update-bits of signals or signal groups, contained in this I-PDU,
     * will be cleared.
     */
    ComTxIPduClearUpdateBit ComTxIPduClearUpdateBit;

    /* The AUTOSAR COM module fills not used areas of an I-PDU with this byte
     * pattern. This attribute is mandatory to avoid undefined behaviour. This
     * byte-pattern will be repeated throughout the I-PDU before any init-values
     * or update-bits were set.
     */
    uint8 ComTxIPduUnusedAreasDefault;

    /*Sub-Contianer*/

    /* This container contains the configuration parameters of the AUTOSAR
     * COM module's transmission modes.
     */
    ComTxMode ComTxMode;



}ComTxIPdu;

/************************ComIPdu Sub-Container************************/
typedef struct
{
    /* This parameter defines the existence and the name of a callout function for
     * the corresponding I-PDU. If this parameter is omitted no I-PDU callout
     * shall take place for the corresponding I-PDU.
     */
    void(*ComIPduCallout)(void);

    /* The direction defines if this I-PDU, and therefore the contributing signals and signal
     * groups, shall be sent or received.
     */
    ComIPduDirection ComIPduDirection;

    /* The numerical value used as the ID of this I-PDU. The ComIPduHandleId
     * is required by the API calls Com_RxIndication, Com_TpRxIndication,
     * Com_StartOfReception and Com_CopyRxData to receive I-PDUs from the
     * PduR (ComIP-duDirection: Receive), as well as the PduId passed to an
     * Rx-I-PDU-callout. For Tx-I-PDUs (ComIPduDirection: Send), this handle Id
     * is used for the APIs calls Com_TxConfirmation, Com_TriggerTransmit,
     * Com_TriggerIPDUSend or Com_TriggerIPDUSendWithMetaData,
     * Com_CopyTxData and Com_TpTxConfirmation to transmit respectively
     * confirm transmissions of I-PDUs, as well as the PduId passed to the Tx-IPDU-callout configured
     * with ComIPduCallout and/or ComIPduTriggerTransmitCallout.
     */
    uint16 ComIPduHandleId;

    /* For the definition of the two modes Immediate and Deferred. */
    ComIPduSignalProcessing ComIPduSignalProcessing;

    /* If there is a trigger transmit callout defined for this I-PDU this parameter
     * contains the name of the callout function.
     */
    void(*ComIPduTriggerTransmitCallout)(void) ;

    /* Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or if this is a
     * large I-PDU that shall be sent via the Transport Protocol of the underlying bus.
     */
    ComIPduType ComIPduType;

    /* Sub-Containers */

    /* References to all signals contained in this I-PDU */
    ComSignal* ComIPduSignalRef[ComMaxIPduCnt];

    /*Reference to the "global" Pdu structure to allow harmonization of handle
     *IDs in the COM-Stack
     * id in RTE think can be stoped and implemented as uint16??
     */
    uint16 ComPduIdRef;
    //PduInfoType* ComPduIdRef;

    /* This container contains additional transmission related configuration
     * parameters of the AUTOSAR COM module's I-PDUs.
     */
    ComTxIPdu ComTxIPdu;

}ComIPdu;

/************************ComConfig Container************************/

/* This container contains the configuration parameters and sub containers of
 * the AUTOSAR COM module.
 */
typedef struct
{

    uint64 ComDataMemSize;

    /*Sub-Containers*/

    /* Contains the configuration parameters of the AUTOSAR COM module's IPDUs. */
    ComIPdu ComIPdu[ComMaxIPduCnt];

    /* Contains the configuration parameters of the AUTOSAR COM module's signals. */
    ComSignal ComSignal[MAX_NUM_OF_SIGNAL];

}Com_ConfigType;

extern const Com_ConfigType Com;

#endif /* COMMSTACK_TYPES_H_ */

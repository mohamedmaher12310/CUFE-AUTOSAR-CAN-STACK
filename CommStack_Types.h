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

/* The AUTOSAR COM module's signal group object identifier. */
typedef uint16 Com_SignalGroupIdType;

/* The AUTOSAR COM I-PDU module's group object identifier. */
typedef uint16 Com_IpduGroupIdType;

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

/*The range of values is specified in the [17] specification, chapter 2.2.2, Reception Filtering.*/
typedef enum
{
    ALWAYS,
    MASKED_NEW_DIFFERS_MASKED_OLD,
    MASKED_NEW_DIFFERS_X,
    MASKED_NEW_EQUALS_X,
    NEVER,
    NEW_IS_OUTSIDE,
    NEW_IS_WITHIN,
    ONE_EVERY_N
}ComFilterAlgorithm;

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
    PENDING,
    TRIGGERED,
    TRIGGERED_ON_CHANGE,
    TRIGGERED_ON_CHANGE_WITHOUT_REPETITION,
    TRIGGERED_WITHOUT_REPETITION
}ComTransferProperty;

/* The available transmission modes described in [18] shall
 * be extended by the additional mode None.The transmission mode None
 * shall not have any further sub-attributes in the
 * ComTxMode object.
 */
typedef enum{
    DIRECT_Tx,
    MIXED_Tx,
    NONE_Tx,
    PERIODIC_Tx
}ComTxModeMode;

/************************ComIPduGroup Sub-Container************************/

/* Contains the configuration parameters of the AUTOSAR COM module's IPDU groups. */
typedef struct
{
    /* The numerical value used as the ID of this I-PDU Group . */
    uint16 ComIPduGroupHandleId;

}ComIPduGroup;

/* References to all I-PDU groups that includes this I-PDU group.
 * If this reference is omitted this I-PDU group does not belong to another I-PDU group.
 */
ComIPduGroup* ComIPduGroupGroupRef;

/************************ComFilter Sub-Container************************/

/* This container contains the configuration parameters of the AUTOSAR
 * COM module's Filters.*/
typedef struct
{
    /* The name of this attribute corresponds to the parameter name in the [17]
     * specification of Reception Filtering.
     */
    sint32 ComFilterMask;

    /* The name of this attribute corresponds to the parameter name in the [17]
     * specification of Reception Filtering.
     */
    sint32 ComFilterMax;

    /* The name of this attribute corresponds to the parameter name in the [17]
     * specification of Reception Filtering.
     */
    sint32 ComFilterMin;

    /* The name of this attribute corresponds to the parameter name in the [17]
     * specification of Reception Filtering.
     */
    uint32 ComFilterOffset;

    /* This parameter defines the period of the ComFilterAlgorithm ONE_EVERY_N.*/
    uint32 ComFilterPeriod;

    /* The name of this attribute corresponds to the parameter name in the [17]
     * specification of Reception Filtering.
     */
    sint32 ComFilterX;

}ComFilter;


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

    /* Size in bits, for integer signal types. For ComSignalType UINT8_N and
     * UINT8_DYN
     * the size shall be configured by ComSignalLength. For ComSignalTypes
     * FLOAT32 and
     * FLOAT64 the size is already defined by the signal type and therefore may
     * be omitted.
     */
    uint8 ComBitSize;

    /* This parameter defines the action performed upon reception of an invalid signal.
     * Relating to signal groups the action in case if one of the included signals is an
     * invalid signal.
     * If Replace is used the ComSignalInitValue will be used for the replacement.
     */
    ComDataInvalidAction ComDataInvalidAction;

    /* Only valid on sender side: Name of Com_CbkTxErr callback function to be
     * called.
     * If this parameter is omitted no error notification shall take place.
     */
    uint8* ComErrorNotification;

    /* Defines the length of the first deadline monitoring timeout period in seconds.
     * This timeout is used immediately after start (or restart) of the deadline
     * monitoring service. The timeout period of the successive periods is
     * configured by ECUC_Com_00263.
     */
    float32 ComFirstTimeout;

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

    /* Only valid on receiver side: Name of Com_CbkInv callback function to be
     * called. Name of the function which notifies the RTE about the reception of
     * an invalidated signal/ signal group. Only applicable if ComDataInvalidAction is
     * configured to NOTIFY.
     */
    //    how to put this condition
    uint8* ComInvalidNotification;

    /* On sender side: Name of Com_CbkTxAck callback function to be called.
     * On receiver side: Name of Com_CbkRxAck callback function to be called.
     * If this parameter is omitted no notification shall take place.
     */
    uint8* ComNotification;

    ComRxDataTimeoutAction ComRxDataTimeoutAction;

    //    ????
    uint8* ComSignalDataInvalidValue;

    /* Defines the endianness of the signal's network representation. */
    ComSignalEndianness ComSignalEndianness;

    /* For ComSignalType UINT8_N this parameter specifies the length n in
     * bytes. For ComSignalType UINT8_DYN it specifies the maximum length in
     * bytes. For all other types this parameter shall be ignored.
     * The supported maximum length is restricted by the used transportation
     * system. For non TP-PDUs the maximum size of a PDU, and therefore also
     * of any included signal, is limited by the concrete bus characteristic. For
     * example, the limit is 8 bytes for CAN and LIN, 64 bytes for CAN FD and
     * 254 for FlexRay.
     */
    uint32 ComSignalLength;

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

    /* On sender side: Name of Com_CbkTxTOut callback function to be called.
     * On receiver side: Name of Com_CbkRxTOut callback function to be called.
     */
    uint8* ComTimeoutNotification;

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
    uint32 ComUpdateBitPosition;

    /*Sub-Container*/

    /* This container contains the configuration parameters of the
     * AUTOSAR COM module's filters.
     * Note: On sender side the container is used to specify the
     * transmission mode conditions.
     */
    ComFilter ComFilter;

}ComSignal;
/************************ComGroupSignal Sub-Container************************/

/* This container contains the configuration parameters of group signals. I.e.
 * signals that are included within a signal group
 */
typedef struct
{
    /* Starting position within the I-PDU. This parameter refers to the position in
     * the I-PDU and not in the shadow buffer. If the endianness conversion is
     * configured to Opaque the parameter ComBitPosition shall define the bit0
     * of the first byte like in little endian byte order
     */
    uint64 ComBitPosition;

    /* Size in bits, for integer signal types. For ComSignalType UINT8_N and UINT8_DYN
     * the size shall be configured by ComSignalLength. For ComSignalTypes
     * FLOAT32 and FLOAT64 the size is already defined by the signal type and therefore may
     * be omitted
     */
    uint8 ComBitSize;

    /* The numerical value used as the ID.
     * This ID identifies signals and signal groups in the COM APIs using
     * Com_SignalIdType or Com_SignalGroupIdType parameter respectively.
     */
    uint16 ComHandleId;

    /* Defines the endianness of the signal's network representation. */
    ComSignalEndianness ComSignalEndianness;

    /* For ComSignalType UINT8_N this parameter specifies the length n in
     * bytes. For ComSignalType UINT8_DYN it specifies the maximum length in
     * bytes. For all other types this parameter shall be ignored.
     * The supported maximum length is restricted by the used transportation
     * system. For non TP-PDUs the maximum size of a PDU, and therefore also
     * of any included signal, is limited by the concrete bus characteristic. For
     * example, the limit is 8 bytes for CAN and LIN, 64 bytes for CAN FD and
     * 254 for FlexRay.
     */
    uint64 ComSignalLength;

    /* The AUTOSAR type of the signal. Whether or not the signal is signed or unsigned
     * can be found by examining the value of this attribute.
     * This type could also be used to reserved appropriate storage in AUTOSAR COM.
     */
    ComSignalType ComSignalType;

    /* Optionally defines whether this group signal shall contribute to the
     * TRIGGERED_ON_CHANGE transfer property of the signal group.
     * If at least one group signal of a signal group has the "ComTransferProperty"
     * configured all other group signals of that signal group shall have
     * the attribute configured as well.
     */
    ComTransferProperty ComTransferProperty;

    /*Sub-Container*/

    /* This container contains the configuration parameters of the
     * AUTOSAR COM module's filters.
     * Note: On sender side the container is used to specify the
     * transmission mode conditions.
     */
    ComFilter ComFilter;
}ComGroupSignal;
/************************ComSignalGroup Sub-Container************************/

/* Contains the configuration parameters of the AUTOSAR COM module's signal groups. */
typedef struct
{
    /* This parameter defines the action performed upon reception of an invalid signal.
     * Relating to signal groups the action in case if one of the included signals is an
     * invalid signal.
     * If Replace is used the ComSignalInitValue will be used for the replacement.
     */
    ComDataInvalidAction ComDataInvalidAction;

    /* Only valid on sender side: Name of Com_CbkTxErr callback function to be
     * called.
     * If this parameter is omitted no error notification shall take place.
     */
    uint8* ComErrorNotification;

    /* Defines the length of the first deadline monitoring timeout
     * period in seconds. This timeout is used immediately after start
     * (or restart) of the deadline monitoring service. The timeout period
     * of the successive periods is configured by ECUC_Com_00263.
     */
    float32 ComFirstTimeout;

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

    /* Only valid on receiver side: Name of Com_CbkInv callback function to be
     * called. Name of the function which notifies the RTE about the reception of
     * an invalidated signal/ signal group. Only applicable if ComDataInvalidAction
     * is configured to NOTIFY.
     */
    uint8* ComInvalidNotification;

    /* On sender side: Name of Com_CbkTxAck callback function to be called.
     * On receiver side: Name of Com_CbkRxAck callback function to be called.
     * If this parameter is omitted no notification shall take place.
     */
    uint8* ComNotification;

    /* This parameter defines the action performed upon expiration of the
     * reception deadline monitoring timer.
     */
    ComRxDataTimeoutAction ComRxDataTimeoutAction;

    /* Defines whether the uint8-array based access
     * shall be used for this ComSignalGroup.
     */
    boolean ComSignalGroupArrayAccess;

    /* Defines the length of the deadline monitoring timeout period in seconds.
     * The period for the first timeout period can be configured separately by
     * ECUC_Com_00183.
     */
    float32 ComTimeout;

    /* On sender side: Name of Com_CbkTxTOut callback function to be called.
     * On receiver side: Name of Com_CbkRxTOut callback function to be called.
     */
    uint8* ComTimeoutNotification;

    /* Defines if a write access to this signal can trigger
     * the transmission of the corresponding I-PDU.
     * If the I-PDU is triggered, depends also on the transmission
     * mode of the corresponding I-PDU.
     */
    ComTransferProperty ComTransferProperty;

    /* Bit position of update-bit inside I-PDU.
     * If this attribute is omitted then there is no update-bit. This setting must be
     * consistently on sender and on receiver side.
     * Range: 0..63 for CAN and LIN,
     * 0..511 for CAN FD,
     * 0..2031 for FlexRay,
     * 0..4294967295 for TP.
     * */
    uint64 ComUpdateBitPosition;

    /*Sub-Container*/

    /* This container contains the configuration parameters of group
     * signals. I.e. signals that are included within a signal group.
     */
    ComGroupSignal ComGroupSignal;

}ComSignalGroup;
/************************ComIPdu Sub-Container************************/
typedef struct
{
    /* This parameter defines the existence and the name of a callout function for
     * the corresponding I-PDU. If this parameter is omitted no I-PDU callout
     * shall take place for the corresponding I-PDU.
     */
    uint8* ComIPduCallout;


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
    uint8* ComIPduTriggerTransmitCallout;

    /* Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or if this is a
     * large I-PDU that shall be sent via the Transport Protocol of the underlying bus.
     */
    ComIPduType ComIPduType;

    /* Sub-Containers */

    /* Reference to the I-PDU groups this I-PDU belongs to. */
    ComIPduGroup* ComIPduGroupRef;

        ComSignalGroup* ComIPduSignalGroupRef;

        ComSignal* ComIPduSignalRef;

    /*Reference to the "global" Pdu structure to allow harmonization of handle
     *IDs in the COM-Stack
     * id in RTE think can be stoped and implemented as uint16
     */
    uint16 ComPduIdRef;

    /*Sub-Container*/
    //    ComIPduCounter ComIPduCounter;
    //    ComIPduReplication ComIPduReplication;
    //    ComTxIPdu ComTxIPdu;


}ComIPdu;








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
    uint8 ComTxModeNumberOfRepetitions;

    /* Defines the repetition period in seconds of the multiple transmissions in
     * case ComTxModeNumberOfRepetitions is configured greater than or
     * equal to 1 and ComTxModeMode is configured to DIRECT or MIXED. In
     * case of the mixed transmission mode only the event driven part is affected.
     */
    float32 ComTxModeRepetitionPeriod;

    /* Defines the period in seconds between the start of the I-PDU by
     * Com_IpduGroupStart and the first transmission request in case
     * ComTxModeMode is configured to PERIODIC or MIXED. In case of the
     * mixed transmission mode only the periodic part is affected.
     * In case ComTxModeTimeOffset is omitted or configured to 0, the first
     * periodic transmission shall be transmitted within the next invocation of
     * Com_MainFunctionTx.
     */
    float32 ComTxModeTimeOffset;

    /* Defines the repetition period in seconds of the periodic transmission requests
     * in case ComTxModeMode is configured to PERIODIC or MIXED. In
     * case of the mixed transmission mode only the periodic part is affected.
     */
    float32 ComTxModeTimePeriod;

}ComTxMode;

/************************ComTxModeTrue Sub-Container************************/

/* This container contains the configuration parameters of the AUTOSAR
 * COM module's transmission modes in the case the ComFilter evaluates to
 * true.
 */
typedef struct
{
    ComTxMode ComTxMode;

}ComTxModeTrue;

/************************ComTxModeFalse Sub-Container************************/

/* This container contains the configuration parameters of the AUTOSAR
 * COM module's transmission modes in the case the ComFilter evaluates to
 * false.
 */
typedef struct
{
    ComTxMode ComTxMode;

}ComTxModeFalse;

/************************ComConfig Container************************/

/* This container contains the configuration parameters and sub containers of
 * the AUTOSAR COM module.
 */
typedef struct
{

    uint64 ComDataMemSize;

    /*Sub-Containers*/

    ComIPdu ComIPdu[ComMaxIPduCnt];

    ComIPduGroup ComIPduGroup[ComSupportedIPduGroups];
#define MAX_NUM_OF_SIGNAL       ComMaxIPduCnt*8

    ComSignal ComSignal[MAX_NUM_OF_SIGNAL];

    ComSignalGroup ComSignalGroup;



}ComConfig;







#endif /* COMMSTACK_TYPES_H_ */

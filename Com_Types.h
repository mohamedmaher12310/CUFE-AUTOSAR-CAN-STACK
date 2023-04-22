/******************************************* ***********************************
 *
 * Module: Com
 *
 * File Name: Com_Types.h
 *
 * Description: Header file for COM Module
 *
 * Author: CUFE 2023 Team
 *******************************************************************************/
#ifndef COM_TYPES_H_
#define COM_TYPES_H_
//
///* Include of Communication Stack Types*/
//#include "CommStack_Types.h"
///* Include of Can General Types*/
//#include "Can_GeneralTypes.h"
///* Include of Can Header file*/
//#include "Can.h"
///* Include of Communication Stack Types*/
#include "CommStack_Types.h"

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*

typedef struct
{

    ComIPdu ComIPdu[ComMaxIPduCnt];

}

ComConfig;

*/

/*
Name: Com_StatusType
Type: Enumeration
Range: COM_INIT -- The AUTOSAR COM module is initialized and usable.
COM_UNINIT 0x00 The AUTOSAR COM module is not initialized or not
usable.
This shall be the default value after reset. This status
shall have the value 0.
Description: This is a status value returned by the API service Com_GetStatus().

 */
typedef enum
{
    COM_INIT,
    COM_UNINIT

} Com_StatusType;

/*
Name: Com_SignalIdType
Type: uint16
Range: 0..<SignalIdmax> -- Zero-based integer number
Description: The AUTOSAR COM module's signal object identifier.
 * */
typedef uint16 Com_SignalIdType;



/*
Name ComIPduDirection
Parent Container ComIPdu
Description The direction defines if this I-PDU, and therefore the contributing signals and signal
groups, shall be sent or received.
Multiplicity 1
Type EcucEnumerationParamDef
Range RECEIVE --
SEND*/

typedef enum
{
    RECEIVE,
    SEND

} ComIPduDirection;

/*Name ComIPduSignalProcessing
Parent Container ComIPdu
Description For the definition of the two modes Immediate and Deferred.
Multiplicity 1
Type EcucEnumerationParamDef
Range DEFERRED signal indication / confirmations are deferred for example to a cyclic task
IMMEDIATE the signal indications / confirmations are
performed in Com_RxIndication/
Com_TxConfirmation*/

typedef enum
{
    DEFERRED,
    IMMEDIATE

} ComIPduSignalProcessing;


/*Name ComIPduType
Parent Container ComIPdu
Description Defines if this I-PDU is a normal I-PDU that can be sent unfragmented or if this is a
large I-PDU that shall be sent via the Transport Protocol of the underlying bus.
Multiplicity 1
Type EcucEnumerationParamDef
Range NORMAL sent or received via normal L-PDU
TP sent or received via TP
 * */

typedef enum
{
    NORMAL,
    TP

} ComIPduType;


/********************ComSignal*********************/
/*Name ComSignalType
Parent Container ComSignal
Description The AUTOSAR type of the signal. Whether or not the signal is signed or unsigned
can be found by examining the value of this attribute.
This type could also be used to reserved appropriate storage in AUTOSAR COM */


typedef enum
{
    BOOLEAN ,
    FLOAT32 ,
    FLOAT64,
    SINT16 ,
    SINT32 ,
    SINT64 ,
    SINT8 ,
    UINT16,
    UINT32,
    UINT64,
    UINT8 ,
    UINT8_DYN ,
    UINT8_N


} ComSignalType;

/*
Container Name ComSignal
Description Contains the configuration parameters of the AUTOSAR COM module's
signals.
*/

typedef struct
{
   uint8 ComBitPosition ; //uint8????
  uint8 ComBitSize;
 uint8 ComHandleId;
 //length in bytes
 uint8 ComSignalLength;
 ComSignalType ComSignalType;
 void* ComSystemTemplateSystemSignalRef;

} ComSignal;




/*
 * Container Name ComIPdu
Description Contains the configuration parameters of the AUTOSAR COM module's IPDUs.

 */

typedef struct
{

    ComIPduDirection ComIPduDirection;

    uint16 ComIPduHandleId;

    ComIPduSignalProcessing ComIPduSignalProcessing;

    ComIPduType ComIPduType;

    ComSignal * ComIPduSignalRef;//??????????????



} ComIPdu;


/*************************** ComTxIPdu ****************************/

/*Name ComMinimumDelayTime
Parent Container ComTxIPdu
Description Defines the Minimum Delay Time (MDT) between successive transmissions of this I-PDU in seconds. The MDT is independent of the possible
different transmission modes. There is only one minimum delay time parameter for one I-PDU. The minimum delay timer is not reset by changing
the transmission mode. Hence, it is not allowed to violate the minimum
delay time by transmission mode changes. It is not possible to monitor the
minimum delay time for I-PDUs that are requested using the
Com_TriggerTransmit API.*/

//#define  ComMinimumDelayTime         (uint8)2



/*Name ComTxIPduClearUpdateBit
Parent Container ComTxIPdu
Description Defines when the update-bits of signals or signal groups, contained in this I-PDU,
will be cleared.*/

typedef enum
{

    Confirmation,
    Transmit,
    TriggerTransmit


} ComTxIPduClearUpdateBit;



/*
Container Name ComTxIPdu
Description This container contains additional transmission related configuration parameters of the AUTOSAR COM module's I-PDUs.
*/
typedef struct
{
    uint8 ComMinimumDelayTime;
    ComTxIPduClearUpdateBit ComTxIPduClearUpdateBit;

    /*The AUTOSAR COM module fills not used areas of an I-PDU with this byte
pattern. This attribute is mandatory to avoid undefined behaviour. This
byte-pattern will be repeated throughout the I-PDU before any init-values
or update-bits were set.*/
    uint8 ComTxIPduUnusedAreasDefault;


} ComTxIPdu;


/**************************ComTxMode*********************************/
/*
Name ComTxModeMode
Parent Container ComTxMode
Description The available transmission modes described in [18] shall be extended by the additional mode None.
The transmission mode None shall not have any further sub-attributes in the
ComTxMode object.
*/

typedef enum
{
    IRECT ,
    MIXED ,
    NONE ,
    PERIODIC

}ComTxModeMode;



/******************************************************/

typedef struct
{
    ComIPdu ComIPdu[ComMaxIPduCnt];


    ComSignal ComSignal[ComMaxSignalCnt];



}

Com_ConfigType;

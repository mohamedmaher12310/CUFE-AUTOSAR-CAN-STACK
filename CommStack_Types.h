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
typedef struct PduInfoType
{
    uint8* SduDataPtr; /*Pointer to the data*/
    uint8* MetaDataPtr; /*Pointer to the meta data*/
    PduLengthType SduLength; /*Length of the SDU in bytes*/
} PduInfoType;



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

/************************ComConfig Container************************/
typedef struct{

    uint64 ComDataMemSize;

    /*Sub-Containers*/

    ComIPdu ComIPdu[ComMaxIPduCnt];

    ComIPduGroup ComIPduGroup[ComSupportedIPduGroups];

//  ??  ComSignal ComSignal;

//  ?? ComSignalGroup ComSignalGroup;



}ComConfig;




/************************ComIPdu Container************************/
typedef struct
{
    ComIPduDirection ComIPduDirection;

    uint16 ComIPduHandleId;

    ComIPduSignalProcessing ComIPduSignalProcessing;

// ???   ComIPduGroup* ComIPduGroupRef;

// ???   ComSignalGroup* ComIPduSignalGroupRef;

// ???   ComSignal* ComIPduSignalRef;

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



#endif /* COMMSTACK_TYPES_H_ */

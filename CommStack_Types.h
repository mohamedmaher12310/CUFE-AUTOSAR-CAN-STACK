/******************************************************************************
 *
 * Module: Communication Stack Types
 *
 * File Name: CommStack_Types.h
 *
 * Description: General Communication Stack type definitions
 *
 * Author: Omar Khedr
 *
 *******************************************************************************/

#ifndef COMMSTACK_TYPES_H_
#define COMMSTACK_TYPES_H_


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


#endif /* COMMSTACK_TYPES_H_ */

/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_Types.h
 *
 * Description: PduR type definitions
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/
#ifndef PDUR_TYPES_H_
#define PDUR_TYPES_H_

/*  Data structure containing post-build-time configuration data of the PDU Router */
typedef struct
{

}PduR_PBConfigType;

/* Identification of the post-build configuration currently used for routing I-PDUs
 *  An ECU may contain several configurations (post-build selectable), each have unique id
 */
typedef uint8   PduR_PBConfigIdType;

/* Identification of a Routing Table */
typedef uint16 PduR_RoutingPathGroupIdType;

/* States of the PDU Router */
typedef enum
{
    PDUR_UNINIT,
    PDUR_ONLINE
}PduR_StateType;






#endif /* PDUR_TYPES_H_ */

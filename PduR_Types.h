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

/*****************Configuration Containers*****************/


/* Specifies how data are provided: direct (as part of the Transmit call) or via
 * the TriggerTransmit callback function. Only required for non-TP gatewayed
 * I-PDUs.
 */
typedef enum
{
    PDUR_DIRECT,
    PDUR_TRIGGERTRANSMIT
}PduRDestPduDataProvision;


/* This container is a subcontainer of PduRRoutingPath and
 * specifies one destination for the PDU to be routed
 */
typedef struct
{
    /* Specifies how data are provided: direct (as part of the Transmit call) or via
     * the TriggerTransmit callback function. Only required for non-TP gatewayed
     * I-PDUs.
     */
    PduRDestPduDataProvision PduRDestPduDataProvision;

    /* PDU identifier assigned by PDU Router. Used by communication interface
     * and transport protocol modules for confirmation
     *(PduR_<Lo>TxConfirmation) and for TriggerTransmit
     *(PduR_<Lo>TriggerTransmit)
     */
    uint16 PduRDestPduHandleId;

    /* Destination PDU reference; reference to unique PDU identifier which shall
     * be used by the PDU Router instead of the source PDU ID when calling the
     * related function of the destination module.
     */
    CanIfTxPduCfg* PduRDestPduRef;

}PduRDestPdu;

/* This container is a subcontainer of PduRRoutingPath and
 * specifies the source of the PDU to be routed.
 */
typedef struct
{

    /* PDU identifier assigned by PDU Router */
    uint16 PduRSrcPduHandleId;


    /* When enabled, the TxConfirmation will be
     * forwarded to the upper layer. Prerequisites: Lower layer and upper layer
     * support TxConfirmation.
     */
    boolean PduRSrcPduUpTxConf;

    /* Source PDU reference; reference to unique PDU identifier which shall be
     * used for the requested PDU Router operation.
     */
    /* ComIPdu* PduRSrcPduRef; */

}PduRSrcPdu;


/* This container is a subcontainer of PduRRoutingTable and
 * specifies the routing path of a PDU.
 */
typedef struct
{
    /* This parameter defines the queue depth for this routing path */
    uint8 PduRQueueDepth;

    /* Reference to [ PduRDestPdu ] */
    PduRDestPdu* PduRDestPduRRef;

    /* Reference to [ PduRSrcPdu ] */
    PduRSrcPdu* PduRSrcPduRRef;

} PduRRoutingPath ;


/*
 * Represents one table of routing paths.
 * This routing table allows multiple configurations that can be used to create
 * several routing tables in the same configuration. This is mainly used for
 * post-build (e.g. post-build selectable) but can be used by pre-compile and
 * link-time for variant handling.
 */
typedef struct
{
    /* Identification of the configuration of the PduR configuration. This
     * identification can be read using the PduR API.
     */
    uint16 PduRConfigurationId;


    /* This container is a subcontainer of PduRRoutingPath and
     * specifies one destination for the PDU to be routed
     */
    PduRDestPdu PduRDestPdu;

    /* This container is a subcontainer of PduRRoutingTable and
     * specifies the routing path of a PDU.
     */
    PduRRoutingPath PduRRoutingPath;

    /* This container is a subcontainer of PduRRoutingPath and
     * specifies the source of the PDU to be routed.
     */
    PduRSrcPdu PduRSrcPdu;

} PduRRoutingPaths ;


/*  Data structure containing post-build-time configuration data of the PDU Router */
typedef struct
{
    PduRRoutingPaths PduRRoutingPaths[PduRMaxRoutingPathCnt];

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

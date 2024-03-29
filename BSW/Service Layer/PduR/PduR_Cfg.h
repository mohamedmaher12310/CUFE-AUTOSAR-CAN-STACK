/******************************************************************************
 *
 * Module: PduR
 *
 * File Name: PduR_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for PduR Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef PDUR_CFG_H_
#define PDUR_CFG_H_

/*
 * Module version
 */
#define PDUR_CFG_SW_MAJOR_VERSION            (1U)
#define PDUR_CFG_SW_MINOR_VERSION            (0U)
#define PDUR_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define PDUR_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define PDUR_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define PDUR_CFG_AR_RELEASE_PATCH_VERSION    (1U)

/*CanIf Header file*/
#include "../../ECUAL/CanIf/CanIf.h"
/* AUTOSAR Version checking between PduR.h and CanIf.h files */
#if ((PDUR_CFG_AR_RELEASE_MAJOR_VERSION != CANIF_AR_RELEASE_MAJOR_VERSION)\
 ||  (PDUR_CFG_AR_RELEASE_MINOR_VERSION != CANIF_AR_RELEASE_MINOR_VERSION)\
 ||  (PDUR_CFG_AR_RELEASE_PATCH_VERSION != CANIF_AR_RELEASE_PATCH_VERSION))
#error "The AR version of CanIf.h does not match the expected version"
#endif

/* Software Version checking between PduR.h and CanIf.h files */
#if ((CANIF_SW_MAJOR_VERSION != PDUR_CFG_SW_MAJOR_VERSION)\
        ||   (CANIF_SW_MINOR_VERSION != PDUR_CFG_SW_MINOR_VERSION)\
        ||   (CANIF_SW_PATCH_VERSION != PDUR_CFG_SW_PATCH_VERSION))
#error "The SW version of CanIf.h does not match the expected version"
#endif

/*CanIf_Cbk Header file*/
#include "../../ECUAL/CanIf/CanIf_Cbk.h"


/************************PduRBswModules Container************************/

/*
 * Specifies if the BSW module supports the Communication Interface APIs
 * or not. Value true the APIs are supported.
 * A module can have both Communication Interface APIs and Transport
 * Protocol APIs (e.g. the COM module).
 */
#define PduRCommunicationInterface                      (STD_ON)

/*
 * The PduRLowerModule will decide who will call the APIs and who will
 * implement the APIs.
 * For example, if the CanIf module is referenced then the PDU Router
 * module will implement the PduR_CanIfRxIndication API. And the PDUR
 * module will call the CanIf_Transmit API. Other APIs are of course also
 * covered.
 */
#define PduRLowerModule                                 (STD_ON)


/*
 * The PduRUpperModule will decide who will call the APIs and who will
 * implement the APIs.
 * For example, if the COM module is referenced then the PDU Router
 * module will implement the PduR_Transmit API. And the PDUR module will
 * call the Com_RxIndication API. Other APIs are of course also covered.
 */
#define PduRUpperModule                                 (STD_ON)

/*
 * This is a reference to one BSW module's configuration (i.e. not the ECUC
 * parameter definition template).
 * Example, there could be several configurations of LinIf and this reference
 * selects one of them.
 */
#define PduRBswModuleRef                                &CanIf_Configuration

/************************PduRGeneral Container************************/
/*Switches the development error detection and notification on or off.*/
#define PduRDevErrorDetect                      (STD_ON)

/************************PduRRoutingPaths Container************************/

    /* Maximum number of RoutingPaths in all RoutingTables. This parameter is
     * needed only in case of post-build loadable implementation using static
     * memory allocation.
     */
#define     PduRMaxRoutingPathCnt   (uint16)3


/************************PduRDestPdu subContainer************************/

/* PDU identifier assigned by PDU Router. Used by communication interface
 * and transport protocol modules for confirmation
 *(PduR_<Lo>TxConfirmation) and for TriggerTransmit
 *(PduR_<Lo>TriggerTransmit)
 */
#define     PduRDestPduHandleId_0   (uint16)0
#define     PduRDestPduHandleId_1   (uint16)1
#define     PduRDestPduHandleId_2   (uint16)2




/* This parameter is only for communication interfaces. Transport protocol
 * modules will always call the TxConfirmation function.
 * If set the destination communication interface module will call the
 * TxConfirmation. However the TxConfirmation may be not called due to
 * error. So the PduR shall not block until the TxConfirmation is called.
 */
#define PduRTransmissionConfirmation                      (STD_ON)

/************************PduRSrcPdu subContainer************************/

/* PDU identifier assigned by PDU Router */
#define     PduRSrcPduHandleId_0   (uint16)0
#define     PduRSrcPduHandleId_1   (uint16)1
#define     PduRSrcPduHandleId_2   (uint16)2



/************************PduRTxBuffer subContainer************************/

 /* Length of the Tx buffer in bytes. This parameter limits the size of buffered routed PDUs.*/
#define     PduRPduMaxLength   (uint32)2

/* Identification of the configuration of the PduR configuration.
 * This identification can be read using the PduR API.
 */
#define PduR_Configuration_ID_0    (uint16)0
#define PduR_Configuration_ID_1    (uint16)1
#define PduR_Configuration_ID_2    (uint16)2

/* Specifies how data are provided: direct (as part of the Transmit call) or via
 *  the TriggerTransmit callback function. Only required for non-TP gatewayed
 *  I-PDUs.
 */
#define PduR_DestData_Provision    PDUR_DIRECT

/* This parameter defines the queue depth for the routing path */
#define PduR_Queue_Depth_0    (uint8) 1
#define PduR_Queue_Depth_1    (uint8) 1
#define PduR_Queue_Depth_2    (uint8) 1

/* When enabled, the TxConfirmation will be
 *  forwarded to the upper layer. Prerequisites: Lower layer and upper layer
 *  support TxConfirmation.
 */
#define PduR_SrcPduUp_TxConfirmation (STD_ON)

/* Maximum PDU ID that Can be routed */
#define PduR_MaxPduID           (uint8) 255

#endif /* PDUR_CFG_H_ */

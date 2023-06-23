/******************************************************************************
 *
 * Module: Com
 *
 * File Name: PduR_Com.h
 *
 * Description:  Header file for PDU Router Upper Layer Interface Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CUFE_AUTOSAR_CAN_STACK_PDUR_COM_H_
#define CUFE_AUTOSAR_CAN_STACK_PDUR_COM_H_

#include "CommStack_Types.h"

/* to use the STATIC PduInfoType PDU[ComMaxIPduCnt];*/
#include "Com.h"

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Com_RxIndication
 * Service ID[hex]: 0x42
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): RxPduId ID of the received PDU.
 *                  PduInfoPtr Contains the length (SduLength) of the received PDU,
 *                  a pointer to a buffer (SduDataPtr) containing the PDU, and the
 *                  MetaData related to this PDU.
 *
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:Indication of a received PDU from a
 *             lower layer communication interface module.
 ************************************************************************************/
void Com_RxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr);

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern uint8 check_flag;



#endif /* CUFE_AUTOSAR_CAN_STACK_PDUR_COM_H_ */

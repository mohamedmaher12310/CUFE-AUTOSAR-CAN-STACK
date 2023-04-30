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

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


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

/* Trigger SVC Exception ... This Macro use the SVC instruction to make SW Interrupt */
/*to trigger software interrupt in case of immediate unpacking of LPDU*/
#define Trigger_SVC_Exception()      __asm(" SVC #0")
#define SVC_PRIORITY_MASK        0x1FFFFFFF
#define SVC_PRIORITY                 0
#define SVC_PRIORITY_BITS_POS        29
/* Assign priority level 0 to the SVC Interrupt */
#define NVIC_SYSTEM_PRI2_REG      (*((volatile unsigned long *)0xE000ED1C))
/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern uint8 check_flag;



#endif /* CUFE_AUTOSAR_CAN_STACK_PDUR_COM_H_ */

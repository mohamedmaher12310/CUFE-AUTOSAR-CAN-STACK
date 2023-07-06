/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can_Regs.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Can Driver Registers
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef CAN_REGS_H_
#define CAN_REGS_H_

#include "../../../Library/Std_Types.h"

/*******************************Base Address for CAN Controllers*******************************/
#define CAN0_BASE_ADDRESS       0x40040000
#define CAN1_BASE_ADDRESS       0x40041000

/*******************************Offset of CAN Registers*******************************/
#define CAN_CTL_OFFSET              0x000
#define CAN_STS_OFFSET              0x004
#define CAN_BIT_OFFSET              0x00C
#define CAN_INT_OFFSET              0x010
#define CAN_BRPE_OFFSET             0x018
#define CAN_IF1CRQ_OFFSET           0x020
#define CAN_IF1CMSK_OFFSET          0x024
#define CAN_IF1MSK1_OFFSET          0x028
#define CAN_IF1MSK2_OFFSET          0x02C
#define CAN_IF1ARB1_OFFSET          0x030
#define CAN_IF1ARB2_OFFSET          0x034
#define CAN_IF1MCTL_OFFSET          0x038
#define CAN_IF1DA1_OFFSET           0x03C

/*******************************Reset values of Registers*******************************/
#define CAN_CTL_RESET              0x00000001
#define CAN_STS_RESET              0x00000000
#define CAN_BIT_RESET              0x00002301
#define CAN_INT_RESET              0x00000000
#define CAN_BRPE_RESET             0x00000000
#define CAN_IF1CRQ_RESET           0x00000001
#define CAN_IF1CMSK_RESET          0x00000001
#define CAN_IF1MSK1_RESET          0x0000FFFF
#define CAN_IF1MSK2_RESET          0x0000FFFF
#define CAN_IF1ARB1_RESET          0x00000000
#define CAN_IF1ARB2_RESET          0x00000000
#define CAN_IF1MCTL_RESET          0x00000000
#define CAN_IF1DA1_RESET           0x00000000

/*******************************Registers used in De-Init Function*******************************/
/* This register controls the clock gating logic in normal Run mode.*/
#define SYSCTL_RCGC0_REG        (*((volatile uint32 *)0x400FE100))
/* This register reset the available CAN modules.*/
#define SYSCTL_SRCAN_REG        (*((volatile uint32 *)0x400FE534))

/*******************************NVIC Registers*******************************/
#define NVIC_EN1                        (*((volatile uint32 *)0xE000E104))
#define NVIC_DIS1                       (*((volatile uint32 *)0xE000E184))
#define NVIC_PRI9                       (*((volatile uint32 *)0xE000E424))

/*******************************Bits inside registers*******************************/
/* CANCTL Register*/
#define INIT_BIT    (0U) /*Initialization*/
#define CCE_BIT     (6U) /*Configuration Change Enable*/
#define IE_BIT      (1U) /*CAN Interrupt Enable*/
#define SIE_BIT     (2U) /*Status Interrupt Enable*/
#define EIE_BIT     (3U) /*Error Interrupt Enable*/

/* CANSTS Register*/
#define BOFF_BIT    (7U) /*Bus-Off Status*/
#define TXOK_BIT    (3U) /*Transmitted a Message successfully*/
#define RXOK_BIT    (4U) /*Received a Message Successfully*/
#define LEC0_BIT    (0U) /*Last Error Code 0 bit*/
#define LEC1_BIT    (1U) /*Last Error Code 1 bit*/
#define LEC2_BIT    (2U) /*Last Error Code 2 bit*/

/* CANINT Register*/
#define STATUS_INTERRUPT        (uint32)0x8000

/* CANIFnCRQ Registers*/
#define BUSY_BIT        (15U) /*Busy Flag*/
#define MNUM_MASK       (0x0000003F)

/* CANIFnCMSK Registers*/
#define WRNRD_BIT       (7U) /*Write, Not Read*/
#define MASK_BIT        (6U) /*Access Mask Bits*/
#define ARB_BIT         (5U) /*Access Arbitration Bits*/
#define CONTROL_BIT     (4U) /*Access Control Bits*/
#define CLRINTPND_BIT   (3U) /*Clear Interrupt Pending Bit*/
#define DATAA_BIT       (1U) /*Access Data Byte 0 to 3*/
#define DATAB_BIT       (0U) /*Access Data Byte 4 to 7*/
#define NEWDAT_BIT_MASK (uint32)0x00000004
#define CMSK_NEWDAT_BIT (2U)

/* CANIFnMSK2 Registers*/
#define MXTD_BIT        (15U) /*Mask Extended Identifier*/

/* CANIFnARB2 Registers*/
#define DIR_BIT         (13U) /*Message Direction*/
#define MSGVAL_BIT      (15U) /*Message Valid*/
#define XTD_BIT         (14U) /*Extended Identifier*/
#define ID_MASK         (uint32)0x00001FFF

/* CANIFnMCTL Registers*/
#define TXRQST_BIT      (8U) /*Transmit Request*/
#define EOB_BIT         (7U) /*End of Buffer*/
#define UMASK_BIT       (12U) /*Use Acceptance Mask*/
#define TXIE_BIT        (11U) /*Transmit Interrupt Enable*/
#define RXIE_BIT        (10U) /*Receive Interrupt Enable*/
#define NEWDAT_BIT      (15U) /*New Data*/
#define DLC_MASK        (uint32)0x0000000F

/* RCGC0 Register*/
#define CAN0_BIT    (24U)
#define CAN1_BIT    (25U)

/* SRCAN Register*/
#define R1_BIT      (1U) /*CAN Module 1 Software Reset*/
#define R0_BIT      (0U) /*CAN Module 0 Software Reset*/

/* NVIC_EN1 & NVIC_DIS1 Registers*/
#define CAN0       (7U) /*CAN0 bit in Interrupt Registers*/
#define CAN1       (8U) /*CAN1 bit in Interrupt Registers*/

/* NVIC_PRI9 Register*/
#define PRIORITY_VALUE_ONE_MASK (uint32)0xE0000000

#endif /* CAN_REGS_H_ */

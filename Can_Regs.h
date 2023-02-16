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

#include "Std_Types.h"

/*Base Address for CAN Controllers*/
#define CAN0_BASE_ADDRESS       0x40040000
#define CAN1_BASE_ADDRESS       0x40041000

/*Offset of CAN Registers*/
#define CAN_CTL_OFFSET              0x000
#define CAN_STS_OFFSET              0x004
#define CAN_ERR_OFFSET              0x008
#define CAN_BIT_OFFSET              0x00C
#define CAN_INT_OFFSET              0x010
#define CAN_TST_OFFSET              0x014
#define CAN_BRPE_OFFSET             0x018
#define CAN_IF1CRQ_OFFSET           0x020
#define CAN_IF1CMSK_OFFSET          0x024
#define CAN_IF1MSK1_OFFSET          0x028
#define CAN_IF1MSK2_OFFSET          0x02C
#define CAN_IF1ARB1_OFFSET          0x030
#define CAN_IF1ARB2_OFFSET          0x034
#define CAN_IF1MCTL_OFFSET          0x038
#define CAN_IF1DA1_OFFSET           0x03C
#define CAN_IF1DA2_OFFSET           0x040
#define CAN_IF1DB1_OFFSET           0x044
#define CAN_IF1DB2_OFFSET           0x048
#define CAN_IF2CRQ_OFFSET           0x080
#define CAN_IF2CMSK_OFFSET          0x084
#define CAN_IF2MSK1_OFFSET          0x088
#define CAN_IF2MSK2_OFFSET          0x08C
#define CAN_IF2ARB1_OFFSET          0x090
#define CAN_IF2ARB2_OFFSET          0x094
#define CAN_IF2MCTL_OFFSET          0x098
#define CAN_IF2DA1_OFFSET           0x09C
#define CAN_IF2DA2_OFFSET           0x0A0
#define CAN_IF2DB1_OFFSET           0x0A4
#define CAN_IF2DB2_OFFSET           0x0A8
#define CAN_TXRQ1_OFFSET            0x100
#define CAN_TXRQ2_OFFSET            0x104
#define CAN_NWDA1_OFFSET            0x120
#define CAN_NWDA2_OFFSET            0x124
#define CAN_MSG1INT_OFFSET          0x140
#define CAN_MSG2INT_OFFSET          0x144
#define CAN_MSG1VAL_OFFSET          0x160
#define CAN_MSG2VAL_OFFSET          0x164

/*Reset values of Registers*/
#define CAN_CTL_RESET              0x00000001
#define CAN_STS_RESET              0x00000000
#define CAN_ERR_RESET              0x00000000
#define CAN_BIT_RESET              0x00002301
#define CAN_INT_RESET              0x00000000
#define CAN_TST_RESET              0x00000000
#define CAN_BRPE_RESET             0x00000000
#define CAN_IF1CRQ_RESET           0x00000001
#define CAN_IF1CMSK_RESET          0x00000001
#define CAN_IF1MSK1_RESET          0x0000FFFF
#define CAN_IF1MSK2_RESET          0x0000FFFF
#define CAN_IF1ARB1_RESET          0x00000000
#define CAN_IF1ARB2_RESET          0x00000000
#define CAN_IF1MCTL_RESET          0x00000000
#define CAN_IF1DA1_RESET           0x00000000
#define CAN_IF1DA2_RESET           0x00000000
#define CAN_IF1DB1_RESET           0x00000000
#define CAN_IF1DB2_RESET           0x00000000
#define CAN_IF2CRQ_RESET           0x00000001
#define CAN_IF2CMSK_RESET          0x00000000
#define CAN_IF2MSK1_RESET          0x0000FFFF
#define CAN_IF2MSK2_RESET          0x0000FFFF
#define CAN_IF2ARB1_RESET          0x00000000
#define CAN_IF2ARB2_RESET          0x00000000
#define CAN_IF2MCTL_RESET          0x00000000
#define CAN_IF2DA1_RESET           0x00000000
#define CAN_IF2DA2_RESET           0x00000000
#define CAN_IF2DB1_RESET           0x00000000
#define CAN_IF2DB2_RESET           0x00000000
#define CAN_TXRQ1_RESET            0x00000000
#define CAN_TXRQ2_RESET            0x00000000
#define CAN_NWDA1_RESET            0x00000000
#define CAN_NWDA2_RESET            0x00000000
#define CAN_MSG1INT_RESET          0x00000000
#define CAN_MSG2INT_RESET          0x00000000
#define CAN_MSG1VAL_RESET          0x00000000
#define CAN_MSG2VAL_RESET          0x00000000


/* This register controls the clock gating logic in normal Run mode.*/
#define SYSCTL_RCGC0_REG        (*((volatile uint32 *)0x400FE100))
/* This register reset the available CAN modules.*/
#define SYSCTL_SRCAN_REG        (*((volatile uint32 *)0x400FE534))
/* This register Disable the interrupts.*/
#define NVIC_DIS1_REG           (*((volatile uint32 *) 0xE000E184))

/* Bits inside registers*/
#define INIT_BIT    (0U)
#define BOFF_BIT    (7U)

#define CAN0_BIT    (24U)
#define CAN1_BIT    (25U)

#define INIT_BIT    (0U)
#define CCE_BIT     (6U)

#define TXOK_BIT    (3U)

#define BUSY_BIT        (15U)
#define WRNRD_BIT       (7U)
#define MASK_BIT        (6U)
#define ARB_BIT         (5U)
#define CONTROL_BIT     (4U)
#define CLRINTPND_BIT   (3U)
#define NEWDAT_BIT      (2U)
#define DATAA_BIT       (1U)
#define DATAB_BIT       (0U)

#define TXRQST_BIT      (8U)
#define EOB_BIT         (7U)

#define DIR_BIT         (13U)
#define MSGVAL_BIT      (15U)
#define XTD_BIT         (14U)

#define MXTD_BIT        (15U)

#define UMASK_BIT       (12U)
#define TXIE_BIT        (11U)
#define RXIE_BIT        (10U)

#define R1_BIT      (1U)
#define R0_BIT      (0U)

#define CANIF1MSK2_MDIR_MXTD_MASK        (uint32)0xC000
#define CANIF1ARB2_MSGVAL_MASK           (uint32)0X8000
#define CANIF1ARB2_XTD_BIT               (uint8)14
#define CANIF1CRQ_BUSY_BIT               (uint8)15

#define CANIF1ARB2_ID_MASK               (uint32)0x00001FFF
#define CANIF1MCTL_NEWDATA_BIT           (uint8)15
#define CANIF1MCTL_DLC_MASK              (uint32)0x0000000F
#define CANIF1CMSK_RX_MASK               (uint32)0x00000073
#define CANIF1CRQ_MNUM_MASK              (uint32)0x0000003F


#define CAN_STS_BOFF            0x00000080  // Bus-Off Status
#define CAN_STS_EWARN           0x00000040  // Warning Status
#define CAN_STS_EPASS           0x00000020  // Error Passive
#define CAN_STS_RXOK            0x00000010  // Received a Message Successfully
#define CAN_STS_TXOK            0x00000008  // Transmitted a Message
                                            // Successfully
#define CAN_STS_TXOK_BIT_NUM    3
#define CAN_STS_LEC_M           0x00000007  // Last Error Code
#define CAN_STS_LEC_NONE        0x00000000  // No Error
#define CAN_STS_LEC_STUFF       0x00000001  // Stuff Error
#define CAN_STS_LEC_FORM        0x00000002  // Format Error
#define CAN_STS_LEC_ACK         0x00000003  // ACK Error
#define CAN_STS_LEC_BIT1        0x00000004  // Bit 1 Error
#define CAN_STS_LEC_BIT0        0x00000005  // Bit 0 Error
#define CAN_STS_LEC_CRC         0x00000006  // CRC Error
#define CAN_STS_LEC_NOEVENT     0x00000007  // No Event



/*NVIC Register*/
//#define CAN_NVIC_EN1_Base                    0xE000E000 // Interrupt 32-63 Set Enable
//#define CAN_NVIC_EN1_offset                   0x104 // Interrupt 32-63 Set Enable
#define CAN_NVIC_EN1                           (*((volatile uint32 *)0xE000E104))
#define CAN_NVIC_DIS1                       (*((volatile uint32 *)0xE000E184 ))// Interrupt 32-63 Set Disable

/*NVIC_Priority Register*/
#define CAN_NVIC_PRI9                   (*((volatile uint32 *)0xE000E424))
#define CAN_NVIC_PRI10                  (*((volatile uint32 *)0xE000E428))


#define CAN0_Enable_Interrupts       (7U)
#define CAN1_Enable_Interrupts       (8U)
#define General_interrupt       (1U)
#define Statues_Interrupt       (2U)
#define Error_Interrupt         (3U)


#define CAN_INT_Status_Interrupt        (uint32)0x8000



#endif /* CAN_REGS_H_ */



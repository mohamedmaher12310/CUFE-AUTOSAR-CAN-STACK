/******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Register Header file for TM4C123GH6PM Microcontroller - Os Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef OS_REGS_H_
#define OS_REGS_H_

#define SYSTICK_STCTRL_REG      *((volatile uint32 *) 0xE000E010)
#define SYSTICK_STRELOAD_REG    *((volatile uint32 *) 0xE000E014)
#define SYSTICK_STCURRENT_REG   *((volatile uint32 *) 0xE000E018)
#define NVIC_SYSTEM_PRI3_REG    *((volatile uint32 *) 0xE000ED20)


#endif /* OS_REGS_H_ */

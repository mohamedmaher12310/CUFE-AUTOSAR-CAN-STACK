/*
 * Os_Regs.h
 *
 *  Created on: Dec 19, 2022
 *      Author: Lenovo
 */

#ifndef OS_REGS_H_
#define OS_REGS_H_

#define SYSTICK_STCTRL_REG      *((volatile uint32 *) 0xE000E010)
#define SYSTICK_STRELOAD_REG    *((volatile uint32 *) 0xE000E014)
#define SYSTICK_STCURRENT_REG   *((volatile uint32 *) 0xE000E018)


#endif /* OS_REGS_H_ */


/******************************************************************************
 *
 * Module: GPT
 *
 * File Name: gpt.c
 *
 * Description: Source file for GPT Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef GPT_H_
#define GPT_H_

#define GPTMCFG_REG               (*((volatile unsigned long *)0x40030000))
#define GPTMTAILR_REG             (*((volatile unsigned long *)0x40030028))
#define RCGCTIMER_REG             (*((volatile unsigned long *)0x400FE604))
#define RCGCGPIO_REG              (*((volatile unsigned long *)0x400FE608))
#define GPIOPCTL_REG              (*((volatile unsigned long *)0x4000552C))
#define GPTMCTL_REG               (*((volatile unsigned long *)0x4003000C))
#define GPTMTAMR_REG              (*((volatile unsigned long *)0x40030004))
#define GPTMIMR_REG               (*((volatile unsigned long *)0x40030018))
#define GPIOAFSEL_REG             (*((volatile unsigned long *)0x40005420))
#define NVIC_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define NVIC_DIS0_REG             (*((volatile unsigned long *)0xE000E180))
#define NVIC_PRI4_REG             (*((volatile unsigned long *)0xE000E410))
#define GPTMICR_REG               (*((volatile unsigned long *)0x40030024))
/* This register shows the current value of the Timer A counter */
/* used in debugging */
#define GPTMTAR_REG               (*((volatile unsigned long *)0x40030048))

#define COUNTS_NEEDED                 8000000
#define T0CCP0                        7
#define T0CCP0_BIT_FILED              24
#define PERIODIC_MOOD                 0x2
#define PERIODIC_MOOD_MASK            0x00000003

void gpt_init(void);

#endif /* GPT_H_ */

/*
 * gpt.c
 *
 *  Created on: 6 Apr 2023
 *      Author: owner
 */

#include "gpt.h"

void gpt_init(void)
{
    /* PB6 to work as T0CCP0  */
    GPIOAFSEL_REG|=(1<<6);

    /* This field controls the configuration for GPIO pin 6. */
    GPIOPCTL_REG |=0x0F000000;

    /* Timer A is disabled. */
    GPTMCTL_REG&=~(1<<0);

    /* For a 16/32-bit timer, this value selects the 32-bit timer configuration */
    GPTMCFG_REG = 0x00000000;

    /* 0x2 Periodic Timer mode */
    GPTMTAMR_REG=   (GPTMTAMR_REG&0xFFFFFFFC) | (0x2 & 0x00000003);

    /*counts up timer*/
    GPTMTAMR_REG|=(1<<4);

    /*this register sets the upper bound for the timeout event.*/
    GPTMTAILR_REG= 16000000;

    /* Interrupt is enabled.GPTM Timer A Time-Out Interrupt Mask */
    GPTMIMR_REG|=(1<<0);

    /* Enable and provide a clock to 16/32-bit general-purpose timer module 0 in Run mode. */
    RCGCTIMER_REG |= (1<<0);

    /*enable clock to portB*/
    RCGCGPIO_REG|= (1<<1);

    /* Timer A is enabled and begins counting or the capture logic is enabled based on the GPTMCFG register. */
    GPTMCTL_REG |= (1<<0);

                      /* NAVIC CONFIGURATIONS  */

    /* give the timer0 priority 2 */

    NVIC_PRI4_REG = (NVIC_PRI4_REG & 0x1FFFFFFF)|(1<<29);

    /* ENABLE BIT 19(TIMER0 INTERRUPT NUMBER) IN INTERRUPT SET ENABLE */
    NVIC_EN0_REG |= (1<<19);


}



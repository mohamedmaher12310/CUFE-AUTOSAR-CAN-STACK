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

#include "gpt.h"
void Timer0_Handler(void){
//    GPIO_PORTF_DATA_REG^=(1<<1);
//    GPIO_PORTF_DATA_REG^=(1<<2);
//    GPIO_PORTF_DATA_REG^=(1<<3);

/* Writing a 1 to this bit clears the TATORIS bit in the GPTMRIS register
 * and the TATOMIS bit in the GPTMMIS register
 */
    GPTMICR_REG |= (1<<0);
}
void gpt_init(void)
{
    volatile unsigned char delay;
    /*enable clock to portB*/
    RCGCGPIO_REG|= (1<<1);
    delay=0;

    /* This field controls the configuration for GPIO pin 6. T0CCP0 equivalent number to be put in GPIOPCTL = 7*/
    GPIOPCTL_REG = (GPIOPCTL_REG & 0xF0FFFFFF) | (T0CCP0 <<T0CCP0_BIT_FILED);

    /* PB6 to work as T0CCP0  */
    GPIOAFSEL_REG|=(1<<6);

    /* Enable and provide a clock to 16/32-bit general-purpose timer module 0 in Run mode. */
    RCGCTIMER_REG |= (1<<0);

    /* Timer A is disabled. */
    GPTMCTL_REG &= ~(1<<0);

    /* For a 16/32-bit timer, this value selects the 32-bit timer configuration */
    GPTMCFG_REG = 0x00000000;

    /* 0x2 Periodic Timer mode */
    GPTMTAMR_REG=   (GPTMTAMR_REG&0xFFFFFFFC) | (PERIODIC_MOOD & PERIODIC_MOOD_MASK);

    /*counts up timer*/
    GPTMTAMR_REG|=(1<<4);

    /*this register sets the upper bound for the timeout event.*/
    GPTMTAILR_REG= COUNTS_NEEDED;

    /* Interrupt is enabled.GPTM Timer A Time-Out Interrupt Mask */
    GPTMIMR_REG|=(1<<0);

    /* NAVIC CONFIGURATIONS  */

    /* give the timer0 priority 2 */
    NVIC_PRI4_REG = (NVIC_PRI4_REG & 0x1FFFFFFF)|(2<<29);

    /* ENABLE BIT 19(TIMER0 INTERRUPT NUMBER) IN INTERRUPT SET ENABLE */
    NVIC_EN0_REG |= (1<<19);

    /* Timer A is enabled and begins counting or the capture logic is enabled based on the GPTMCFG register. */
    GPTMCTL_REG |= (1<<0);
}



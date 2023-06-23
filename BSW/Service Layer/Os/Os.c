/******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Os Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
/*Include the module header file*/
#include "Os.h"

uint32 count=0;

/* Initialize the SysTick timer with Preload value ~= 1ms*/
void SYSTICK_VOIDInit (void)
{
    uint32 Exception_val=Enable_Exceptions();
    CLEAR_BIT(SYSTICK_STCTRL_REG,0); //Disable timer during initialization
    SET_BIT(SYSTICK_STCTRL_REG,1); //Enable Interrupts
    SET_BIT(SYSTICK_STCTRL_REG,2); //Choose System clock source
    SYSTICK_STRELOAD_REG=15999;    //One ms
    SET_BIT(SYSTICK_STCTRL_REG,0); //Enable the timer
    /* Assign priority level 2 to the SysTick Interrupt */
    NVIC_SYSTEM_PRI3_REG =  (NVIC_SYSTEM_PRI3_REG & 0x1FFFFFFF) | (2 << 29);
}

void SysTick_Handler(void)
{
        if(count == 0)
        {
            count++;
        }
        else
        {
            /* Busy delay function to wait for 1ms to pass*/
            while (BIT_IS_CLEAR(SYSTICK_STCTRL_REG,16))
            {
                /* Do Nothing*/
            }
            count++;
        }
}

/* Function to return the value of the counter which counts every 1 ms*/
uint32 GetCounterValue(void)
{
    return count;
}

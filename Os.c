/******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Os Module.
 *
 * Author: Omar Khedr - Nada Mohamed
 ******************************************************************************/

/*Include the module header file*/
#include "Os.h"

/* Initialize the SysTick timer with Preload value ~= 1ms*/
void SYSTICK_VOIDInit (void)
{
    CLEAR_BIT(SYSTICK_STCTRL_REG,0); //Disable timer during initialization
    CLEAR_BIT(SYSTICK_STCTRL_REG,1); //Disable Interrupts
    SET_BIT(SYSTICK_STCTRL_REG,2); //Choose System clock source
    SYSTICK_STRELOAD_REG=15999;    //One ms
    SET_BIT(SYSTICK_STCTRL_REG,0); //Enable the timer
}

/* Function to return the value of the counter which counts every 1 ms*/
uint32 GetCounterValue(void)
{
    STATIC uint32 count=0;
    if(count == 0)
    {
        count++;
        return 0;
    }
    else
    {
        /* Busy delay function to wait for 1ms to pass*/
        while (BIT_IS_CLEAR(SYSTICK_STCTRL_REG,16))
        {
            /* Do Nothing*/
        }
        count++;
        return count;
    }
}

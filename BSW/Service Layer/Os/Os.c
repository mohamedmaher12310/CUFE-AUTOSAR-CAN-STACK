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

/* Global variable store the Os Time */
volatile uint32 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
STATIC uint8 g_New_Time_Tick_Flag = 0;

volatile uint32 Read_write_clear_tick = 0;


unsigned char RecievedChar;
unsigned char Choice;

/*********************************************************************************************/
void Os_start(void)
{
    /*
     * Set the Call Back function to call Os_NewTimerTick
     * this function will be called every SysTick Interrupt (20ms)
     */
    SysTick_SetCallBack(Os_NewTimerTick);

    /* Start SysTickTimer to generate interrupt every 20ms */
    SysTick_Start(OS_BASE_TIME);

    /* Execute the Init Task */
    Init_Task();

    /* Start the Os Scheduler */
    Os_Scheduler();
}

/*********************************************************************************************/
void Os_NewTimerTick(void)
{
    /* Increment the Os time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    Read_write_clear_tick += OS_BASE_TIME;
    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*********************************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {
        /* Code is only executed in case there is a new timer tick */
        if(g_New_Time_Tick_Flag == 1)
        {
            switch(g_Time_Tick_Count)
            {
            case (uint32)(ComTxTimeBase*1000):
            {
                if(ComTxTimeBase == ComRxTimeBase)
                {
                    Com_MainFunctionTx();
                    Com_MainFunctionRx();
                }
                else
                {
                    Com_MainFunctionTx();
                }
                unsigned char i = 0;
                for (i=0;i<24;i++)
                {
                    Com_ReceiveSignal(i, &Array_RTE_Receive[i]);
                    UARTCharPut(0x4000D000, Array_RTE_Receive[i]);
                }
                UARTCharPut(0x4000D000,'\n');
                for(i=0;i<24;i++)
                {
                    SignalObject[i]=0;
                    //  Array_RTE_Receive[i]=0;
                }
                g_New_Time_Tick_Flag = 0;
                g_Time_Tick_Count = 0;
                break;
            }
            }
        }

    }
}



/*********************************************************************************************/

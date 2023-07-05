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
static uint8 g_New_Time_Tick_Flag = 0;


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

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*********************************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {

        //        RecievedChar = UARTCharGet(0x4000D000);
        //        if (RecievedChar == '1')
        //        {
        //            unsigned char i=0;
        //            for ( i=0;i<8;i++)
        //            {
        //                Com_SendSignal(i, &Array_RTE_Send[0][i]);
        //
        //            }
        //
        //        }
        //        else if (RecievedChar == '2')
        //        {
        //
        //            unsigned char i;
        //
        //            for (i=8;i<16;i++)
        //            {
        //                Com_SendSignal(i, &Array_RTE_Send[1][i-8]);
        //            }
        //
        //        }
        //        else if(RecievedChar == '3')
        //        {
        //            unsigned char i;
        //            for ( i=16;i<32;i++)
        //            {
        //                Com_SendSignal(i, &Array_RTE_Send[2][i-16]);
        //            }
        //        }
        //        /***************************************Slave*********************************************/
        //        else if (RecievedChar == '4')
        //        {
        //            unsigned char i = 0;
        //            for (i=0;i<24;i++)
        //            {
        //                Com_ReceiveSignal(i, &Array_RTE_Receive[i]);
        //                UARTCharPut(0x4000D000, Array_RTE_Receive[i]);
        //
        //            }
        //            UARTCharPut(0x4000D000,'\n');
        //
        //        }
        //
        //        else
        //        {
        //            /*Do Nothing*/
        //        }
        //
        //        /*****************************Repeat Process******************************************/
        //        UART1_SendString("\nDo you want to send or recieve a message?\n[1]Yes\n[2]No\n");
        //        Choice= UARTCharGet(0x4000D000);
        //        if (Choice == '1')
        //        {
        //            UART1_SendString("Press: \n[1] Send to Computer (2)\n[2] Send to Computer (3)\n[3] Send to Both (2 & 3)\n[4]Read Recieved Messages\n");
        //            RecievedChar = UARTCharGet(0x4000D000);
        //        }
        //        else if (Choice == '2')
        //        {
        //            RecievedChar = 0;
        //        }
        //        while (RecievedChar == 0)
        //        {
        //            UART1_SendString("You turned off the Network\nTo Re-Establish the Network press the Space bar\n");
        //            unsigned char x = UARTCharGet(0x4000D000);
        //            if (x == ' ')
        //            {
        //                RecievedChar = 5;
        //            }
        //        }
        /* Code is only executed in case there is a new timer tick */
        if(g_New_Time_Tick_Flag == 1)
        {
            unsigned char i = 0;
            for (i=0;i<24;i++)
            {
                Com_ReceiveSignal(i, &Array_RTE_Receive[i]);
                UARTCharPut(0x4000D000, Array_RTE_Receive[i]);
            }
            UARTCharPut(0x4000D000,'\n');
            //g_New_Time_Tick_Flag = 0;

            switch(g_Time_Tick_Count)
            {

            case (uint32)(ComTxTimeBase*1000):
                   if(ComTxTimeBase == ComRxTimeBase)
                   {
                       Com_MainFunctionTx();
                       Com_MainFunctionRx();
                   }
                   else
                   {
                       Com_MainFunctionTx();
                   }
            g_New_Time_Tick_Flag = 0;
            g_Time_Tick_Count = 0;
            break;
            //case ComRxTimeBase:
            //  g_New_Time_Tick_Flag = 0;
            // break;
            }
        }
    }

}
/*********************************************************************************************/

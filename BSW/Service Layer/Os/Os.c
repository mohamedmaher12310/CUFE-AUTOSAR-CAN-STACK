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
volatile uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static uint8 g_New_Time_Tick_Flag = 0;

uint8 Array_RTE_Send[3][8]={"Omar","Maher","Khedr"};
uint8 Array_RTE_Receive[24]={0};
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
        while (RecievedChar == 0)
        {
            UART1_SendString("You turned off the Network\nTo Re-Establish the Network press the Space bar\n");
            unsigned char x = UARTCharGet(0x4000D000);
            if (x == ' ')
            {
                RecievedChar = 5;
            }
        }
        if (RecievedChar == '1')
        {
            //UART1_SendString("Please enter the message then press enter: \n");
            //RecievedString= UART1_RecieveString();
            unsigned char i=0;
            for ( i=0;i<8;i++)
            {
                Com_SendSignal(i, &Array_RTE_Send[0][i]);
                //Tx_Message_Data_Buffer[i] = RecievedString[i];
                // Com_SendSignal(i, &RecievedString[i]);
            }
            // Can_Message_Tx.id=2;
            /*done ;)*/
            //            Com_MainFunctionTx();
            //            Com_MainFunctionTx();

            /*done ;)*/
            //            Com_RxIndication(2,&Tx_Pdu);
            /*done ;)*/
            //            Com_MainFunctionRx();
            //           PduR_ComTransmit(1, &Tx_Pdu);
            //CanIf_Transmit(CanIfTxPduId_0, &Tx_Pdu);
            //Can_Write(CAN_HOH_ID_1,&Can_Message_Tx);
            //            for ( i=0;i<8;i++)
            //            {
            //                RecievedString[i] = '\0';
            //                Tx_Message_Data_Buffer[i] = '\0';
            //            }
            //            //Can_MainFunction_Write();
        }
        else if (RecievedChar == '2')
        {
            //            UART1_SendString("Please enter the message then press enter: \n");
            //            RecievedString= UART1_RecieveString();
            unsigned char i;

            for (i=8;i<16;i++)
            {
                Com_SendSignal(i, &Array_RTE_Send[1][i-8]);
            }
            //            Can_Message_Tx.id=3;
            //          Can_Write(CAN_HOH_ID_1,&Can_Message_Tx);
            //            for ( i=0;i<8;i++)
            //            {
            //                RecievedString[i] = '\0';
            //                Tx_Message_Data_Buffer[i] = '\0';
            //            }
        }
        else if(RecievedChar == '3')
        {
            unsigned char i;
            for ( i=16;i<32;i++)
            {
                Com_SendSignal(i, &Array_RTE_Send[2][i-16]);
            }
        }
        /***************************************Slave*********************************************/
        else if (RecievedChar == '4')
        {
            unsigned char i = 0;
            for (i=0;i<24;i++)
            {
                Com_ReceiveSignal(i, &Array_RTE_Receive[i]);
                UARTCharPut(0x4000D000, Array_RTE_Receive[i]);

            }
            UARTCharPut(0x4000D000,'\n');

        }
        ////            if (Recieve_Count == 0)
        ////            {
        ////                UART1_SendString("\nYou Didn't Recieve any message:\n");
        ////            }
        ////            while (Recieve_Count != 0)
        //  //          {
        //    //            if (MSG_Number_INT[0] == 1)
        //      //          {
        //        //            MSG_Number_INT[0] = 0;
        //                    UART1_SendString("\nYou Recieved Message from Mailbox (1):\n");
        //                    Recieve_Count--;
        //                    unsigned char RecievedCount=0;
        //                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
        //                    {
        //                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
        //                    }
        //                    unsigned char i=0;
        //                    for ( i=0;i<8;i++)
        //                    {
        //                        Temp_Buffer.sdu[i] = '\0';
        //                    }
        //                }
        //                if (MSG_Number_INT[1] == 2)
        //                {
        //                    MSG_Number_INT[1] = 0;
        //                    UART1_SendString("\nYou Recieved Message from Mailbox (2):\n");
        //                    Recieve_Count--;
        //                    unsigned char RecievedCount=0;
        //                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
        //                    {
        //                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
        //                    }
        //                    unsigned char i=0;
        //                    for ( i=0;i<8;i++)
        //                    {
        //                        Temp_Buffer.sdu[i] = '\0';
        //                    }
        //                }
        //                if (MSG_Number_INT[2] == 3)
        //                {
        //                    MSG_Number_INT[2] = 0;
        //                    UART1_SendString("\nYou Recieved Message from Mailbox (3):\n");
        //                    Recieve_Count--;
        //                    unsigned char RecievedCount=0;
        //                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
        //                    {
        //                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
        //                    }
        //                    unsigned char i=0;
        //                    for ( i=0;i<8;i++)
        //                    {
        //                        Temp_Buffer.sdu[i] = '\0';
        //                    }
        //                }
        //            }
        //        }
        else
        {
            /*Do Nothing*/
        }

        /*****************************Repeat Process******************************************/
        UART1_SendString("\nDo you want to send or recieve a message?\n[1]Yes\n[2]No\n");
        Choice= UARTCharGet(0x4000D000);
        if (Choice == '1')
        {
            UART1_SendString("Press: \n[1] Send to Computer (2)\n[2] Send to Computer (3)\n[3] Send to Both (2 & 3)\n[4]Read Recieved Messages\n");
            RecievedChar = UARTCharGet(0x4000D000);
        }
        else if (Choice == '2')
        {
            RecievedChar = 0;
        }
        /* Code is only executed in case there is a new timer tick */
        if(g_New_Time_Tick_Flag == 1)
        {
            switch(g_Time_Tick_Count)
            {

            case (uint8)(ComTxTimeBase*1000):
                                if(ComTxTimeBase == ComRxTimeBase)
                                {
                                    Com_MainFunctionTx();
                                    Com_MainFunctionRx();
                                }
                                else {
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

/******************************************************************************
 *
 * Module: Main
 *
 * File Name: main.c
 *
 * Description: Main Source file to test the Can Driver
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/

/*********************************************Node(1)**********************************************************/
/**********************************CAN bus  controller master & slave firmware****************************/

#include "BSW/MCAL/Port/Port.h"
#include "BSW/MCAL/CanDrv/Can.h"
#include "BSW/MCAL/Uart/UART.h"
#include "BSW/Service Layer/Os/Os.h"
#include "BSW/ECUAL/CanIf/CanIf.h"
#include "BSW/Service Layer/PduR/PduR.h"
#include "BSW/Service Layer/PduR/PduR_Com.h"
#include "BSW/Service Layer/Com/Com.h"
#define EIGHT_BYTES     (8U)
Can_PduType Temp_Buffer;
int main(void)
    {
    /***************************************************************************************
     * Initialize the Port Driver
     ****************************************************************************************/
    Port_Init(&Port_Configuration);

    /***************************************************************************************
     * Initialize the UART Driver
     ****************************************************************************************/
    UART_INIT();

    /***************************************************************************************
     * Initialize the Can Driver
     ****************************************************************************************/
    Can_Init(&Can_Configuration);

    CanIf_Init(&CanIf_Configuration);

    PduR_Init(&PduR_Configuration);
    Com_Init(&Com);
    /***************************************************************************************
     * Initialize the SysTick Timer
     ****************************************************************************************/
    SYSTICK_VOIDInit();

    /***************************************************************************************
     * Enable the CAN for operation.
     ****************************************************************************************/
    CanIf_SetControllerMode(CAN0_CONTROLLER_ID, CAN_CS_STARTED);

    /***************************************************************************************
     * Enable interrupts on the Can Controller 0.
     ****************************************************************************************/

    Can_DisableControllerInterrupts(CAN0_CONTROLLER_ID);
    Can_EnableControllerInterrupts(CAN0_CONTROLLER_ID);


    /***************************************************************************************
     * Initialize the message objects that will be used for sending/receiving CAN messages.
     ****************************************************************************************/
    uint8 Tx_Message_Data_Buffer[8];
    uint8 *SDU_Ptr;
    SDU_Ptr = Tx_Message_Data_Buffer;
    Can_PduType Can_Message_Tx;

    PduInfoType Tx_Pdu;
    Tx_Pdu.SduLength = EIGHT_BYTES;
    Tx_Pdu.SduDataPtr = SDU_Ptr;

    Can_Message_Tx.length= EIGHT_BYTES;
    Can_Message_Tx.swPduHandle = ZERO;
    Can_Message_Tx.sdu = SDU_Ptr;

    unsigned char RecievedChar;
    unsigned char Choice;
    UART1_SendString("Welcome to CAN Network\nPress: \n[1] Send to Computer (2)\n[2] Send to Computer (3)\n[3] Send to Both (2 & 3)\n[4]Read Recieved Messages\n");
    unsigned char *RecievedString;
    RecievedChar = UARTCharGet(0x4000D000);
 //   uint32 x;
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
            UART1_SendString("Please enter the message then press enter: \n");
            RecievedString= UART1_RecieveString();
            unsigned char i;
            for ( i=0;i<8;i++)
            {
                Tx_Message_Data_Buffer[i] = RecievedString[i];
                Com_SendSignal(i, &RecievedString[i]);
            }
            Can_Message_Tx.id=2;
            /*done ;)*/
            Com_MainFunctionTx();
            Com_MainFunctionTx();

            /*done ;)*/
//            Com_RxIndication(2,&Tx_Pdu);
            /*done ;)*/
//            Com_MainFunctionRx();
//           PduR_ComTransmit(1, &Tx_Pdu);
            //CanIf_Transmit(CanIfTxPduId_0, &Tx_Pdu);
            //Can_Write(CAN_HOH_ID_1,&Can_Message_Tx);
            for ( i=0;i<8;i++)
            {
                RecievedString[i] = '\0';
                Tx_Message_Data_Buffer[i] = '\0';
            }
            //Can_MainFunction_Write();
        }
        else if (RecievedChar == '2')
        {
            UART1_SendString("Please enter the message then press enter: \n");
            RecievedString= UART1_RecieveString();
            unsigned char i;
            for ( i=0;i<8;i++)
            {
                Tx_Message_Data_Buffer[i] = RecievedString[i];
            }
            Can_Message_Tx.id=3;
            Can_Write(CAN_HOH_ID_1,&Can_Message_Tx);
            for ( i=0;i<8;i++)
            {
                RecievedString[i] = '\0';
                Tx_Message_Data_Buffer[i] = '\0';
            }
        }
        /***************************************Slave*********************************************/
        else if (RecievedChar == '4')
        {
            if (Recieve_Count == 0)
            {
                UART1_SendString("\nYou Didn't Recieve any message:\n");
            }
            while (Recieve_Count != 0)
            {
                if (MSG_Number_INT[0] == 1)
                {
                    MSG_Number_INT[0] = 0;
                    UART1_SendString("\nYou Recieved Message from Mailbox (1):\n");
                    Recieve_Count--;
                    unsigned char RecievedCount=0;
                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
                    {
                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
                    }
                    unsigned char i=0;
                    for ( i=0;i<8;i++)
                    {
                        Temp_Buffer.sdu[i] = '\0';
                    }
                }
                if (MSG_Number_INT[1] == 2)
                {
                    MSG_Number_INT[1] = 0;
                    UART1_SendString("\nYou Recieved Message from Mailbox (2):\n");
                    Recieve_Count--;
                    unsigned char RecievedCount=0;
                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
                    {
                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
                    }
                    unsigned char i=0;
                    for ( i=0;i<8;i++)
                    {
                        Temp_Buffer.sdu[i] = '\0';
                    }
                }
                if (MSG_Number_INT[2] == 3)
                {
                    MSG_Number_INT[2] = 0;
                    UART1_SendString("\nYou Recieved Message from Mailbox (3):\n");
                    Recieve_Count--;
                    unsigned char RecievedCount=0;
                    for (RecievedCount =0; RecievedCount<Temp_Buffer.length ; RecievedCount++)
                    {
                        UARTCharPut(0x4000D000, Temp_Buffer.sdu[RecievedCount]);
                    }
                    unsigned char i=0;
                    for ( i=0;i<8;i++)
                    {
                        Temp_Buffer.sdu[i] = '\0';
                    }
                }
            }
        }
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

    }
    return 0;
}

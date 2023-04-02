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

#include "Port.h"
#include "Can.h"
#include "UART.h"
#include "Os.h"
#include "CanIf.h"
#include "CanIf_Cbk.h"
#define EIGHT_BYTES     (8U)
Can_PduType Temp_Buffer;


void PDUR_RxIndication(PduIdType RxPduId,const PduInfoType* PduInfoPtr)
{
//    if(1==test_flag){
    UART1_SendString("CanIf_RxIndication works correctly \n");
//    }
}
void PDUR_TxConfirmation(PduIdType TxPduId, Std_ReturnType type_return)
{
//    if(E_OK == type_return)
    {
        UART1_SendString("CanIf_TxConfirmation works correctly \n");
    }
}
int main(void)
    {
    Can_PduType Temp_Buffer;
    uint8* recieved_data;
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
    /***************************************************************************************
     * Initialize the CanIf
     ****************************************************************************************/

    CanIf_Init(&CanIf_Configuration);

    /***************************************************************************************
     * Initialize the SysTick Timer
     ****************************************************************************************/
    SYSTICK_VOIDInit();

    /***************************************************************************************
     * Enable the CAN for operation.
     ****************************************************************************************/
    CanIf_SetControllerMode(CAN0_CONTROLLER_ID, CAN_CS_STARTED);

    CanIf_SetControllerMode(CAN0_CONTROLLER_ID, CAN_CS_STARTED);
    /***************************************************************************************
     * Enable interrupts on the Can Controller 0.
     ****************************************************************************************/

    Can_DisableControllerInterrupts(CAN0_CONTROLLER_ID);
    Can_EnableControllerInterrupts(CAN0_CONTROLLER_ID);

    /***************************************************************************************
     * Initialize the message objects that will be used for sending/receiving CAN messages.
     ****************************************************************************************/
    uint8 Tx_Message_Data_Buffer[8]={0};
    uint8 Rx_Message_Data_Buffer[8]={0};
    uint8 *SDU_Ptr;
    SDU_Ptr = Tx_Message_Data_Buffer;
    //    Can_PduType Can_Message_Tx;

    PduInfoType Tx_Pdu;
    Tx_Pdu.SduLength = EIGHT_BYTES;
    Tx_Pdu.SduDataPtr = SDU_Ptr;

    Can_Message_Tx.length= EIGHT_BYTES;
    Can_Message_Tx.swPduHandle = ZERO;
    Can_Message_Tx.sdu = SDU_Ptr;

    Can_Message_Rx.length= EIGHT_BYTES;
    /***************************************************************************************
     * Initialize the PDU information that will be used for sending/receiving CAN messages.
     ****************************************************************************************/
    PduIdType pdu_id_tx;

    PduInfoType CanIf_Message_Tx;
    PduInfoType CanIf_Message_Rx;
    CanIf_Message_Tx.SduLength = EIGHT_BYTES;
    CanIf_Message_Tx.SduDataPtr = SDU_Ptr;

    CanIf_Message_Rx.SduLength = EIGHT_BYTES;

    Std_ReturnType return_result;
    /***********************************/
    unsigned char RecievedChar;
    unsigned char Choice;
    UART1_SendString("Welcome to CAN Network\nPress: \n[1] Send to Computer (2)\n[2] Send to Computer (3)\n[3] Send to Both (2 & 3)\n[4]Read Recieved Messages\n");
    unsigned char *RecievedString;
    RecievedChar = UARTCharGet(0x4000D000);
    uint32 x;
    while(1)
    {
        //        x = GetCounterValue();
        //        if (( x % (uint32)CAN_MAIN_FUNCTION_PERIOD) == 0)
        //        {
        //            Can_MainFunction_Write();
        //        }

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
            }
            Can_Message_Tx.id=2;
            CanIf_Transmit(CanIfTxPduId_0, &Tx_Pdu);
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
            //            Can_Message_Tx.id=3;
            pdu_id_tx=0;
            return_result = CanIf_Transmit(pdu_id_tx,&CanIf_Message_Tx);
            if(E_OK == return_result )
            {
                /*for polling test*/
                Can_MainFunction_Write();
            }
            else
            {
                UART1_SendString("[CAN controller hardware object is busy]");
            }
            // Can_Write(CAN_HOH_ID_1,&Can_Message_Tx);
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

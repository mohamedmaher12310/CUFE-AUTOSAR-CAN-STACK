/*
 * App.c
 *
 *  Created on: Jul 5, 2023
 *      Author: Mally
 */

#include "App.h"
uint8 Array_RTE_Send[3][8]={"Omar","Maher","Khedr"};
uint8 Array_RTE_Receive[24]={0};

void Init_Task(void)
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
    /***************************************************************************************
     * Initialize the Can Interface
     ****************************************************************************************/
    CanIf_Init(&CanIf_Configuration);
    /***************************************************************************************
     * Initialize the Pdu Router
     ****************************************************************************************/
    PduR_Init(&PduR_Configuration);
    /***************************************************************************************
     * Initialize the Com Module
     ****************************************************************************************/
    Com_Init(&Com);

    /***************************************************************************************
     * Enable the CAN for operation.
     ****************************************************************************************/
    CanIf_SetControllerMode(CAN0_CONTROLLER_ID, CAN_CS_STARTED);

    /***************************************************************************************
     * Enable interrupts on the Can Controller 0.
     ****************************************************************************************/

    Can_DisableControllerInterrupts(CAN0_CONTROLLER_ID);
    Can_EnableControllerInterrupts(CAN0_CONTROLLER_ID);

    unsigned char i=0;
    for (i=0;i<8;i++)
    {
        Com_SendSignal(i, &Array_RTE_Send[0][i]);
    }
    for (i=8;i<16;i++)
    {
        Com_SendSignal(i, &Array_RTE_Send[1][i-8]);
    }
    for (i=16;i<24;i++)
    {
        Com_SendSignal(i, &Array_RTE_Send[2][i-16]);
    }
    /*Greeting Message*/
    //UART1_SendString("Welcome to CAN Network\nPress: \n[1] Send to Computer (2)\n[2] Send to Computer (3)\n[3] Send to Both (2 & 3)\n[4]Read Recieved Messages\n");

}


/*
 * Can_IRQ.c
 *
 *  Created on: 28-1-2023
 *      Author: Nada-Ahmed
 */

#include "Os.h"
#include "Can.h"

volatile boolean MSG_Object_INT_Flag = 0; /* flag to indicate occurrence of interrupt due to message object */
volatile uint8 MSG_Number_INT = 0;  /* variable to store the message object number that caused the interrupt */
volatile boolean Error_Flag = 0; /* flag to detect an error interrupt has occurred */
volatile uint8 Error_Status = 0; /* variable to store the error status */
volatile uint32 Recieve_Count =0; /* variable that increments when a message is received*/
volatile uint32 Transmit_Count =0; /* variable that increments when a message is transmitted*/

extern const Can_ConfigType Can_Configuration;



void CAN0_Handler(void)
{

    MSG_Number_INT =0;  /* clearing the message number variable for re-use */
    MSG_Object_INT_Flag=0;  /* clearing the message object flag for re-use */
	uint32 status = REG_VAL(CAN0_BASE,CAN_INT_OFFSET);  /* reading the CAN_INT register to detect the interrupt cause */
	if (CAN_INT_Status_Interrupt == status )  /* if interrupt is a Status interrupt */
	{
	    Error_Status = REG_VAL(CAN0_BASE,CAN_STS_OFFSET);  /* store the status register in a variable */
	    REG_VAL(CAN0_BASE,CAN_STS_OFFSET) = ~(CAN_STS_RXOK | CAN_STS_TXOK | CAN_STS_LEC_M);  /* clear the RXOK,TXOK,LEC bits in status register */
	    Error_Flag =1 ;  /* raise the error flag to detect that an error has occurred */
	}
	else  /* interrupt is a Message Object interrupt */
	{

	    MSG_Object_INT_Flag =1; /* raise the message object flag to detect that an interrupt occurred */
	    MSG_Number_INT = status; /* store the message number that caused the interrupt in a variable */
	    if(Can_Configuration.Controller[0].HOH[MSG_Number_INT].HardwareObjectType==TRANSMIT) /* interrupt caused by transmit message object */
	    {
	        Transmit_Count++; /* increment the transmit count */
	    }
	    else if(Can_Configuration.Controller[0].HOH[MSG_Number_INT].HardwareObjectType==RECIEVE) /* interrupt caused by receive message object */
	    {
	        Recieve_Count++; /* increment the receive count */
	    }
	    Error_Flag =0;  /* nullify the error flag after successful transmission or reception of message */
	    REG_VAL(CAN0_BASE,CAN_STS_OFFSET);  /* read the CAN_STS register to clear the CAN_INT register */
	}

}

void CAN1_Handler(void)
{

    MSG_Number_INT =0;  /* clearing the message number variable for re-use */
    MSG_Object_INT_Flag=0;  /* clearing the message object flag for re-use */
    uint32 status = REG_VAL(CAN1_BASE,CAN_INT_OFFSET);  /* reading the CAN_INT register to detect the interrupt cause */
    if (CAN_INT_Status_Interrupt == status )  /* if interrupt is a Status interrupt */
    {
        Error_Status = REG_VAL(CAN1_BASE,CAN_STS_OFFSET);  /* store the status register in a variable */
        REG_VAL(CAN1_BASE,CAN_STS_OFFSET) = ~(CAN_STS_RXOK | CAN_STS_TXOK | CAN_STS_LEC_M);  /* clear the RXOK,TXOK,LEC bits in status register */
        Error_Flag =1 ;  /* raise the error flag to detect that an error has occurred */
    }
    else  /* interrupt is a Message Object interrupt */
    {

        MSG_Object_INT_Flag =1; /* raise the message object flag to detect that an interrupt occurred */
        MSG_Number_INT = status; /* store the message number that caused the interrupt in a variable */
        if(Can_Configuration.Controller[1].HOH[MSG_Number_INT].HardwareObjectType==TRANSMIT) /* interrupt caused by transmit message object */
        {
            Transmit_Count++; /* increment the transmit count */
        }
        else if(Can_Configuration.Controller[1].HOH[MSG_Number_INT].HardwareObjectType==RECIEVE) /* interrupt caused by receive message object */
        {
            Recieve_Count++; /* increment the receive count */
        }
        Error_Flag =0;  /* nullify the error flag after successful transmission or reception of message */
        REG_VAL(CAN0_BASE,CAN_STS_OFFSET);  /* read the CAN_STS register to clear the CAN_INT register */
    }

}






/******************************************************************************
 *
 * Module: Can Interrupt Request
 *
 * File Name: Can_IRQ.c
 *
 * Description: Can Interrupt Request Source file for TM4C123GH6PM Microcontroller - Can Driver
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/

#include "Os.h"
#include "Can.h"

volatile boolean MSG_Object_INT_Flag = 0; /* flag to indicate occurrence of interrupt due to message object */
volatile uint8 MSG_Number_INT[32] = {0};  /* variable to store the message object number that caused the interrupt */
volatile boolean Error_Flag = 0; /* flag to detect an error interrupt has occurred */
volatile uint8 Error_Status = 0; /* variable to store the error status */
volatile uint32 Recieve_Count =0; /* variable that increments when a message is received*/
volatile uint32 Transmit_Count =0; /* variable that increments when a message is transmitted*/
uint8 HOH;
void CAN0_Handler(void)
{
    /*CanIf_RxIndication Arguments*/
    Can_HwType CanIfRx_Mailbox;
    PduInfoType CanIfRx_PduInfoPtr;
    Can_IdType CanIfRx_Id;

    MSG_Object_INT_Flag=0;  /* clearing the message object flag for re-use */
    uint32 status = REG_VAL(CAN0_BASE,CAN_INT_OFFSET);  /* reading the CAN_INT register to detect the interrupt cause */
    if (CAN_INT_Status_Interrupt == status )  /* if interrupt is a Status interrupt */
    {
        Error_Status = REG_VAL(CAN0_BASE,CAN_STS_OFFSET);  /* store the status register in a variable */
        REG_VAL(CAN0_BASE,CAN_STS_OFFSET) = ~(CAN_STS_RXOK | CAN_STS_TXOK | CAN_STS_LEC_M);  /* clear the RXOK,TXOK,LEC bits in status register */
        Error_Flag =1 ;  /* raise the error flag to detect that an error has occurred */
    }
    /* interrupt is a Message Object interrupt */
    else
    {
        MSG_Number_INT[status-ONE] = status; /* store the message number that caused the interrupt in a variable */
        HOH=ZERO;
        uint8 Mailbox_Index;
        uint8 iter=Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanHardwareObjectCount;
        while( MSG_Number_INT[status-ONE] > iter )
        {
            HOH++;
            iter+=Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanHardwareObjectCount;
        }
        for (iter = ZERO ; iter< Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanHardwareObjectCount ; iter++)
        {
            if (Object_Check[CAN0_CONTROLLER_ID][HOH][iter].mailbox == MSG_Number_INT[status-ONE])
            {
                Mailbox_Index=iter;
            }
        }

        /* Wait for busy bit to clear */
        while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
        {
            /*Do Nothing*/
        }
        /*
         * Only change the interrupt pending state by setting only the
         * CAN_IF1CMSK_CLRINTPND bit.
         */
        REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET) = 0x00000008;
        /*
         * Send the clear pending interrupt command to the CAN controller.
         */
        REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET) = MSG_Number_INT[status-ONE] & SIX_BIT_MASK;
        /* Wait for busy bit to clear */
        while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
        {
            /*Do Nothing*/
        }

        if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanObjectType==TRANSMIT) /* interrupt caused by transmit message object */
        {
            Object_Check[CAN0_CONTROLLER_ID][HOH][Mailbox_Index].Check = Confirmed;
            /*CanIf_TxConfirmation()*/
            Transmit_Count++; /* increment the transmit count */
        }
        else if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanObjectType==RECIEVE) /* interrupt caused by receive message object */
        {
            /*Lock Mailbox until Reading of Pdu from Users*/
            Object_Check[CAN0_CONTROLLER_ID][HOH][Mailbox_Index].Check = Unconfirmed;
            /*Setting argument values of CanIf_RxIndication*/
            REG_VAL(CAN0_BASE,CAN_IF1CRQ_OFFSET) =  status & (SIX_BIT_MASK);
            /*Check if the ID is standard*/
            if( BIT_IS_CLEAR( REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET),XTD_BIT) )
            {
                CanIfRx_Id = ( REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET) & CANIF1ARB2_ID_MASK ) >> 2;
            }
            else
            {
                /*
                 *   ID is Extended
                 */
                CanIfRx_Id = (( REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET) & CANIF1ARB2_ID_MASK ) <<16) | REG_VAL(CAN0_BASE,CAN_IF1ARB1_OFFSET) ;
            }
            CanIfRx_Mailbox.CanId = CanIfRx_Id;
            /*Controller ID with respect to CanDrv or CanIf ?!*/
            CanIfRx_Mailbox.ControllerId = CAN0_CONTROLLER_ID;
            CanIfRx_Mailbox.Hoh = Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanObjectId;

            /*Is this Right or Wrong?! DATA NORMALIZATION*/

            CanIfRx_PduInfoPtr.SduLength = (REG_VAL(CAN0_BASE,CAN_IF1MCTL_OFFSET) & CANIF1MCTL_DLC_MASK);
            CanIfRx_PduInfoPtr.SduDataPtr = &(REG_VAL(CAN0_BASE,CAN_IF1DA1_OFFSET));

            /*Call User (CanIf) to indicate recieved message*/
            CanIf_RxIndication(&CanIfRx_Mailbox,&CanIfRx_PduInfoPtr);
            /*
             * The hardware object will be immediately released
             * after CanIf_RxIndication() of CanIf returns to avoid loss of data.
             */
            Object_Check[CAN0_CONTROLLER_ID][HOH][Mailbox_Index].Check = Confirmed;
            Recieve_Count++; /* increment the receive count */
        }
        MSG_Object_INT_Flag =1; /* raise the message object flag to detect that an interrupt occurred */
        Error_Flag =0;  /* nullify the error flag after successful transmission or reception of message */
    }
}

void CAN1_Handler(void)
{
    //    MSG_Number_INT =0;  /* clearing the message number variable for re-use */
    //    MSG_Object_INT_Flag=0;  /* clearing the message object flag for re-use */
    //    uint32 status = REG_VAL(CAN1_BASE,CAN_INT_OFFSET);  /* reading the CAN_INT register to detect the interrupt cause */
    //    if (CAN_INT_Status_Interrupt == status )  /* if interrupt is a Status interrupt */
    //    {
    //        Error_Status = REG_VAL(CAN1_BASE,CAN_STS_OFFSET);  /* store the status register in a variable */
    //        REG_VAL(CAN1_BASE,CAN_STS_OFFSET) = ~(CAN_STS_RXOK | CAN_STS_TXOK | CAN_STS_LEC_M);  /* clear the RXOK,TXOK,LEC bits in status register */
    //        Error_Flag =1 ;  /* raise the error flag to detect that an error has occurred */
    //    }
    //    /* interrupt is a Message Object interrupt */
    //    else
    //    {
    //        MSG_Number_INT = status; /* store the message number that caused the interrupt in a variable */
    //        uint8 HOH=ZERO,iter=Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanHardwareObjectCount;
    //        while( MSG_Number_INT > iter )
    //        {
    //            HOH++;
    //            iter+=Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanHardwareObjectCount;
    //        }
    //
    //        /* Wait for busy bit to clear */
    //        while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
    //        {
    //            /*Do Nothing*/
    //        }
    //        /*
    //         * Only change the interrupt pending state by setting only the
    //         * CAN_IF1CMSK_CLRINTPND bit.
    //         */
    //        REG_VAL(CAN1_BASE, CAN_IF1CMSK_OFFSET) = 0x00000008;
    //        /*
    //         * Send the clear pending interrupt command to the CAN controller.
    //         */
    //        REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET) = MSG_Number_INT & SIX_BIT_MASK;
    //        /* Wait for busy bit to clear */
    //        while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
    //        {
    //            /*Do Nothing*/
    //        }
    //
    //        if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanObjectType==TRANSMIT) /* interrupt caused by transmit message object */
    //        {
    //            Object_Check[CAN1_CONTROLLER_ID][HOH][MSG_Number_INT-ONE].Check = Confirmed;
    //            /*CanIf_TxConfirmation()*/
    //            Transmit_Count++; /* increment the transmit count */
    //        }
    //        else if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH].CanObjectType==RECIEVE) /* interrupt caused by receive message object */
    //        {
    //            /*CanIf_Rxindication()*/
    //            Recieve_Count++; /* increment the receive count */
    //        }
    //        MSG_Object_INT_Flag =1; /* raise the message object flag to detect that an interrupt occurred */
    //        Error_Flag =0;  /* nullify the error flag after successful transmission or reception of message */
    //    }
}






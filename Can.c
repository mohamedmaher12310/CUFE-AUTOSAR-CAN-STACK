/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Can Driver.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/*Include the module header file*/
#include "Can.h"
#include "Det.h"
#include "Det.h"
uint32 CPUcpsie(void)
{
    /*
     * Read PRIMASK and enable interrupts.
     */
    __asm("    mrs     r0, PRIMASK\n"
            "    cpsie   i\n"
            "    bx      lr\n");

    /*
     * The following keeps the compiler happy, because it wants to see a
     * return value from this function.  It will generate code to return
     * a zero.  However, the real return is the "bx lr" above, so the
     * return(0) is never executed and the function returns with the value
     * you expect in R0.
     */
    return(0);
}

uint32 CPUcpsid(void)
{
    /*
     *  Read PRIMASK and disable interrupts.
     */
    __asm("    mrs     r0, PRIMASK\n"
            "    cpsid   i\n"
            "    bx      lr\n");

    /*
     * The following keeps the compiler happy, because it wants to see a
     * return value from this function.  It will generate code to return
     * a zero.  However, the real return is the "bx lr" above, so the
     * return(0) is never executed and the function returns with the value
     * you expect in R0.
     */
    return(0);
}

typedef struct
{
    uint16 ui16CmdMaskReg;
    uint16 ui16MaskReg0, ui16MaskReg1;
    uint16 ui16ArbReg0, ui16ArbReg1;
    uint16 ui16MsgCtrl;
}register_val;

STATIC register_val registers[64]={0};

uint32 Enable_Exceptions(void)
{
    /*
     * Enable processor interrupts.
     */
    return(CPUcpsie());
}

uint32 Diable_Exceptions (void)
{
    /*
     * Enable processor interrupts.
     */
    return(CPUcpsid());
}



/*Including Det module for developmnet error reporting*/
#if (STD_ON == CAN_DEV_ERROR_DETECT)
#include "Det.h"

/* AUTOSAR Version checking between Det and port Modules */
#if ((DET_AR_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        || (DET_AR_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        || (DET_AR_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif

#endif

/* Include of OS Module */
#include "Os.h"
/* AUTOSAR Version checking between Det and port Modules */
#if ((OS_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        || (OS_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        || (OS_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Det.h does not match the expected version"
#endif


/*Status variable to check if the module is initialized or not*/
STATIC uint8 Can_Status = CAN_UNINIT;
/*Status variable which holds the state of the CAN controller*/
STATIC Can_ControllerStateType Can_CurrentState[CAN_CONTROLLERS_NUMBER] = {CAN_CS_UNINIT,CAN_CS_UNINIT};

/* Functions used in Set_Controller_Mode */
/*CAN_CS_STARTED state*/
STATIC Std_ReturnType Can_Started_State(uint8 Controller);
/*CAN_CS_STOPPED state*/
STATIC Std_ReturnType Can_Stopped_State(uint8 Controller);

/*-Array of enums to indicate if the message object is free or not
 *-Once a message is requested the message object is set used(unconfirmed) until checked on set back to free(confirmed)
 *and passed to IF*/
Message_Confirmation Object_Check[CAN_CONTROLLERS_NUMBER][CAN_HOH_NUMBER][MAX_HWOBJECT_COUNT];

STATIC uint8 Interrupts_Enable_Disable_Counter = 0;
STATIC uint8 Interrupts_Disable_Flag = 0;


/************************************************************************************
 * Service name: Can_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Controller - CAN controller for which the status shall be changed
 *                  Transition -Transition value to request new CAN controller state
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value: Std_ReturnType E_OK - Request accepted
 *               Std_ReturnType E_NOT_OK - Request not accepted, a development error occurred
 * Description:  This function performs software triggered state transitions of
 *               the CAN controller State machine.
 ************************************************************************************/

Std_ReturnType Can_SetControllerMode(uint8 Controller , Can_ControllerStateType Transition)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    /* Check if the Controller ID is greater than the number of configured controllers*/
    if (Controller >= CAN_CONTROLLERS_NUMBER)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_PARAM_CONTROLLER);
        return E_NOT_OK;
    }
    else
    {
        /* Do nothing*/
    }
    /* Check if the module is initialized*/
    if (Can_Status == CAN_UNINIT)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_UNINIT);
        return E_NOT_OK;
    }
    else
    {
        /* Do Nothing*/
    }
#endif /*CAN_DEV_ERROR_DETECT*/
    /* Switch on the transition state value to perform specific
     * function depending on the transition
     */
    switch (Transition)
    {
    case CAN_CS_STARTED:
        if (Can_Started_State(Controller) == E_OK)
        {
            return E_OK;
        }
        else
        {
            return E_NOT_OK;
        }
        break;
    case CAN_CS_STOPPED:
        if(Can_Stopped_State(Controller) == E_OK)
        {
            return E_OK;
        }
        else
        {
            return E_NOT_OK;
        }
        break;
    default :
        break;
    }
}

/* Started transition function*/
STATIC Std_ReturnType Can_Started_State(uint8 Controller)
{
    if (Controller == CAN0_CONTROLLER_ID)
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /*Check invalid transition ->Transition to CS_STARTED can't be reached
         *                           unless coming from CS_STOPPED
         */
        if(Can_CurrentState[CAN0_CONTROLLER_ID] != CAN_CS_STOPPED)
        {
            Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_TRANSITION);
            return E_NOT_OK;
        }
        else
#endif /*CAN_DEV_ERROR_DETECT*/
        {
            /* To check if CanTimeoutDuration is elapsed -> we need to take a snapshot of
             *                                  time and calculate the actual time elapsed
             */
            uint32 End =ZERO,Start=ZERO;
            Start = GetCounterValue();
            End = Start;
            /* Clear the Init Bit in CANCTL -> to enable the CAN controller to particibate on bus*/
            CLEAR_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),INIT_BIT);
            /* In case the flag signals that the change takes no effect and the
             * maximum time CanTimeoutDuration is elapsed, the function
             * Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall
             * continue to poll the flag.
             */
            while (BIT_IS_SET(REG_VAL(CAN0_BASE,CAN_STS_OFFSET),BOFF_BIT) || ((End - Start)<(TMILLI*CAN_TIMEOUT_DURATION)))
            {
                End = GetCounterValue();
            }
            if(BIT_IS_CLEAR(REG_VAL(CAN0_BASE,CAN_STS_OFFSET),BOFF_BIT))
            {
                Can_CurrentState[CAN0_CONTROLLER_ID] = CAN_CS_STARTED;
                return E_OK;
            }
            else
            {
                /* Can_Mainfunction_Mode shall change its state*/
                return E_OK;
            }
            return E_OK;
        }
    }
    else if (Controller == CAN1_CONTROLLER_ID)
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /*Check invalid transition ->Transition to CS_STARTED can't be reached
         *                           unless coming from CS_STOPPED
         */
        if(Can_CurrentState[CAN1_CONTROLLER_ID] != CAN_CS_STOPPED)
        {
            Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_TRANSITION);
            return E_NOT_OK;
        }
        else
#endif /*CAN_DEV_ERROR_DETECT*/
        {
            /* To check if CanTimeoutDuration is elapsed -> we need to take a snapshot of
             *                                  time and calculate the actual time elapsed
             */
            uint32 End =ZERO,Start=ZERO;
            Start = GetCounterValue();
            End = Start;
            /* Clear the Init Bit in CANCTL -> to enable the CAN controller to particibate on bus*/
            CLEAR_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),INIT_BIT);
            /* In case the flag signals that the change takes no effect and the
             * maximum time CanTimeoutDuration is elapsed, the function
             * Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall
             * continue to poll the flag.
             */
            while (BIT_IS_SET(REG_VAL(CAN1_BASE,CAN_STS_OFFSET),BOFF_BIT) || ((End - Start)<(TMILLI*CAN_TIMEOUT_DURATION)))
            {
                End = GetCounterValue();
            }
            if(BIT_IS_CLEAR(REG_VAL(CAN1_BASE,CAN_STS_OFFSET),BOFF_BIT))
            {
                Can_CurrentState[CAN1_CONTROLLER_ID]= CAN_CS_STARTED;
                return E_OK;
            }
            else
            {
                /* Can_Mainfunction_Mode shall change its state*/
                return E_OK;
            }
            return E_OK;
        }
    }
}

/* Stopped transition function*/
STATIC Std_ReturnType Can_Stopped_State(uint8 Controller)
{
    if (Controller == CAN0_CONTROLLER_ID)
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /*Check invalid transition ->Transition to CS_STOPPED can't be reached
         *                           unless coming from CS_STARTED
         */
        if(Can_CurrentState[CAN0_CONTROLLER_ID] != CAN_CS_STARTED)
        {
            Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_TRANSITION);
            return E_NOT_OK;
        }
        else
#endif /*CAN_DEV_ERROR_DETECT*/
        {
            /* To check if CanTimeoutDuration is elapsed -> we need to take a snapshot of
             *                                  time and calculate the actual time elapsed
             */
            uint32 End =ZERO,Start=ZERO;
            Start = GetCounterValue();
            End = Start;
            /* Clear the Init Bit in CANCTL -> to enable the CAN controller to particibate on bus*/
            SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),INIT_BIT);
            /* In case the flag signals that the change takes no effect and the
             * maximum time CanTimeoutDuration is elapsed, the function
             * Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall
             * continue to poll the flag.
             */
            while (BIT_IS_SET(REG_VAL(CAN0_BASE,CAN_STS_OFFSET),BOFF_BIT) || ((End - Start)<(TMILLI*CAN_TIMEOUT_DURATION)))
            {
                End = GetCounterValue();
            }
            if(BIT_IS_CLEAR(REG_VAL(CAN0_BASE,CAN_STS_OFFSET),BOFF_BIT))
            {
                Can_CurrentState[CAN0_CONTROLLER_ID] = CAN_CS_STOPPED;
                REG_VAL(CAN0_BASE,CAN_STS_OFFSET);
                return E_OK;
            }
            else
            {
                /* Can_Mainfunction_Mode shall change its state*/
                return E_OK;
            }
            return E_OK;
        }
    }
    else if (Controller == CAN1_CONTROLLER_ID)
    {
#if(CAN_DEV_ERROR_DETECT == STD_ON)
        /*Check invalid transition ->Transition to CS_STOPPED can't be reached
         *                           unless coming from CS_STARTED
         */
        if(Can_CurrentState[CAN1_CONTROLLER_ID] != CAN_CS_STARTED)
        {
            Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_SET_CONTROLLER_MODE_SID, CAN_E_TRANSITION);
            return E_NOT_OK;
        }
        else
#endif /*CAN_DEV_ERROR_DETECT*/
        {
            /* To check if CanTimeoutDuration is elapsed -> we need to take a snapshot of
             *                                  time and calculate the actual time elapsed
             */
            uint32 End =ZERO,Start=ZERO;
            Start = GetCounterValue();
            End = Start;
            /* Clear the Init Bit in CANCTL -> to enable the CAN controller to particibate on bus*/
            SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),INIT_BIT);
            /* In case the flag signals that the change takes no effect and the
             * maximum time CanTimeoutDuration is elapsed, the function
             * Can_SetControllerMode shall be left and the function Can_Mainfunction_Mode shall
             * continue to poll the flag.
             */
            while (BIT_IS_SET(REG_VAL(CAN1_BASE,CAN_STS_OFFSET),BOFF_BIT) || ((End - Start)<(TMILLI*CAN_TIMEOUT_DURATION)))
            {
                End = GetCounterValue();
            }
            if(BIT_IS_CLEAR(REG_VAL(CAN1_BASE,CAN_STS_OFFSET),BOFF_BIT))
            {
                Can_CurrentState[CAN1_CONTROLLER_ID] = CAN_CS_STOPPED;
                REG_VAL(CAN1_BASE,CAN_STS_OFFSET);
                return E_OK;
            }
            else
            {
                /* Can_Mainfunction_Mode shall change its state*/
                return E_OK;
            }
            return E_OK;
        }
    }
}

/************************************************************************************
 * Service Name: Can_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Config - Pointer to driver configuration.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the Can module:
 *              After power-up/reset, the Can module shall be in the state
 *              CAN_UNINIT,The function Can_Init shall change the module state to
 *              CAN_READY, after initializing all controllers inside the HW
 *              Unit.
 *              Each CAN controller must then be started separately by calling the function
 *              Can_SetControllerMode(CAN_CS_STARTED).
 *             -Enable Clock for CAN Peripheral.
 *             -Enable Interrupt or Polling defined by configuration.
 *             -Set the configured Baudrate.
 *             -Configure the whole 32 hardware message object for each controller (0-1)
 *              depending on the configuration.
 *             -Transfer the controller state from UNINIT State to STOPPED State.
 ************************************************************************************/

void Can_Init(const Can_ConfigType* Config)
{
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == Config)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID,CAN_E_PARAM_POINTER);
    }
    else
    {
        /* Do Nothing*/
    }
    /*Check for Invalid configuration set selection */
    const Can_ConfigType * Check_Ptr=&Can_Configuration;
    if(Check_Ptr != Config)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_INIT_SID,CAN_E_INIT_FAILED);
    }
    else
#endif /*CAN_DEV_ERROR_DETECT*/
    {
#if(CanConf_CAN0_CONTROLLER_ACTIVATION == STD_ON)
        uint8 delay=ZERO;
        /*Enable Clock to CAN Peripheral*/
        SET_BIT(SYSCTL_RCGC0_REG,CAN0_BIT);
        delay =SYSCTL_RCGC0_REG;
        /*Setting CAN Functionality using PORT Driver*/
        /*Set the Init Bit in CANCTL*/
        SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),INIT_BIT);
        /*Set the Baudrate*/
        /*Set the CCE Bit in CANCTL*/
        SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),CCE_BIT);
        /* Set the Time Segment 1 */
        REG_VAL(CAN0_BASE,CAN_BIT_OFFSET)|= ((Config->CanConfigSet.CanController[CAN0_CONTROLLER_ID].CanControllerBaudrateConfig.PropSeg + Config->CanConfigSet.CanController[CAN0_CONTROLLER_ID].CanControllerBaudrateConfig.PhaseSeg1 -ONE)<< EIGHT_BITS) ;
        /* Set the Time Segment 2 */
        REG_VAL(CAN0_BASE,CAN_BIT_OFFSET)|= ((Config->CanConfigSet.CanController[CAN0_CONTROLLER_ID].CanControllerBaudrateConfig.PhaseSeg2  -ONE)<< TWELVE_BITS) ;
        /* Set the SyncJumpWidth */
        REG_VAL(CAN0_BASE,CAN_BIT_OFFSET)|= ((Config->CanConfigSet.CanController[CAN0_CONTROLLER_ID].CanControllerBaudrateConfig.SyncJumpWidth  -ONE)<< SIX_BITS) ;
        /* Set the BaudRate Prescaler */
        REG_VAL(CAN0_BASE,CAN_BIT_OFFSET)|= (ONE<< ZERO) ;
        REG_VAL(CAN0_BASE,CAN_BRPE_OFFSET)|= (ZERO<< ZERO);

        /*Configure Hardware Message Objects*/
        /*After reset, the CAN controller is left in the disabled state.  However,
         *the memory used for message objects contains undefined values and must be
         *cleared prior to enabling the CAN controller the first time.  This prevents
         *unwanted transmission or reception of data before the message objects are
         *configured.
         */
        /* Wait for busy bit to clear */
        while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
        {
            /*Do Nothing*/
        }
        /*
         * Set WRNRD bit to specify a write to the CANIFnCMASK
         * Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers
         * Set CONTROL bit to transfer the control bits into the interface registers
         * Set MASK bit to Transfer IDMASK + DIR + MXTD of the message object into the Interface registers.
         */
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),WRNRD_BIT);
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),MASK_BIT);
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),ARB_BIT);
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),CONTROL_BIT);

        /*
         * Clear the message value bit in the arbitration register.  This indicates
         * the message is not valid and is a "safe" condition to leave the message
         * object.  The same arb reg is used to program all the message objects.
         */
        REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET)=ZERO;
        REG_VAL(CAN0_BASE,CAN_IF1MCTL_OFFSET)=ZERO;

        /*
         * Set CLRINTPND to clear the INTPND bit in the CANIFnMCTL register
         * Set NEWDAT to clear the NEWDAT bit in the CANNWDAn register
         */
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),CLRINTPND_BIT);
        SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1CMSK_OFFSET),NEWDAT_BIT);

        /* Loop through to program all configured HOH */
        uint8 iter;
        uint8 Object_Count_iter=ZERO;
        for(iter = ZERO; iter < CAN_HOH_NUMBER; iter++)
        {
            /*Setting all the message objects to free*/
            uint8 Check_iter;
            for (Check_iter =ZERO; Check_iter<=Config->CanConfigSet.CanHardwareObject[iter].CanHardwareObjectCount - ONE; Check_iter++)
            {
                Object_Check[CAN0_CONTROLLER_ID][iter][Check_iter].Check = Confirmed ;
                Object_Count_iter++;
                Object_Check[CAN0_CONTROLLER_ID][iter][Check_iter].mailbox = Object_Count_iter;
            }
            /* Wait for busy bit to clear */
            while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
            {
                /*Do Nothing*/
            }
            /*  Initiate programming the message object */
            uint8 iter2;
            for (iter2 = ZERO ; iter2 <= Config->CanConfigSet.CanHardwareObject[iter].CanHardwareObjectCount -ONE ; iter2 ++)
            {
                REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET) = Object_Check[CAN0_CONTROLLER_ID][iter][iter2].mailbox & SIX_BIT_MASK;
            }
        }

        /* Acknowledge any pending status interrupts. */
        REG_VAL(CAN0_BASE,CAN_STS_OFFSET);
        /* Configure the Hardware Message Objects*/
        for (iter = ZERO; iter < CAN_HOH_NUMBER; iter++)
        {
            uint8 iter2;
            for (iter2 = ZERO ; iter2 <= Config->CanConfigSet.CanHardwareObject[iter].CanHardwareObjectCount -ONE ; iter2 ++)
            {
                uint16 ui16CmdMaskReg;
                uint16 ui16MaskReg0, ui16MaskReg1;
                uint16 ui16ArbReg0, ui16ArbReg1;
                uint16 ui16MsgCtrl;
                uint8 bUseExtendedID;
                /* Wait for busy bit to clear */
                while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
                {
                    /*Do Nothing*/
                }
                /* See if we need to use an extended identifier or not.*/
                if(Config->CanConfigSet.CanHardwareObject[iter].CanIdType == ID_EXTENDED)
                {
                    bUseExtendedID = ONE;
                }
                else
                {
                    bUseExtendedID = ZERO;
                }
                /*
                 * This is always a write to the Message object as this call is setting a
                 * message object.  This call always sets all size bits so it sets
                 * both data bits.  The call uses the CONTROL register to set control
                 * bits so this bit needs to be set as well.
                 */
                SET_BIT(ui16CmdMaskReg,WRNRD_BIT);
                SET_BIT(ui16CmdMaskReg,CONTROL_BIT);
                SET_BIT(ui16CmdMaskReg,DATAA_BIT);
                SET_BIT(ui16CmdMaskReg,DATAB_BIT);
                /*
                 * Initialize the values to a known state before filling them in based on
                 * the type of message object that is being configured.
                 */
                ui16ArbReg0 = ZERO;
                ui16ArbReg1 = ZERO;
                ui16MsgCtrl = ZERO;
                ui16MaskReg0 = ZERO;
                ui16MaskReg1 = ZERO;

                /* Configure Transmit HOH*/
                if (Config->CanConfigSet.CanHardwareObject[iter].CanObjectType == TRANSMIT)
                {
                    /*
                     * Set the TXRQST bit and the reset the rest of the register.
                     */
                    SET_BIT(ui16ArbReg1,DIR_BIT);
                }
                /* Configure Recieve HOH*/
                else if (Config->CanConfigSet.CanHardwareObject[iter].CanObjectType == RECIEVE)
                {
                    /*
                     * This clears the DIR bit along with everything else.  The TXRQST
                     * bit was cleared by defaulting ui16MsgCtrl to 0.
                     */
                    ui16ArbReg1 = ZERO;
                }
                /* AUTOSAR doesn't support any other message type*/
                else
                {
                    /* Do Nothing*/
                }
                /*
                 * Configure the Mask Registers.
                 */
                if(bUseExtendedID)
                {
                    /*
                     * Set the 29 bits of Identifier mask that were requested.
                     */
                    ui16MaskReg0 =(uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterMask);
                    ui16MaskReg1 =(((uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterMask) >> SIXTEEN) & THIRTEEN_BIT_MASK);
                }
                else
                {
                    /*
                     * Lower 16 bit are unused so set them to zero.
                     */
                    ui16MaskReg0 = ZERO;
                    /*
                     * Put the 11 bit Mask Identifier into the upper bits of the field
                     * in the register.
                     */
                    ui16MaskReg1 = (((uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterMask) << TWO) & THIRTEEN_BIT_MASK);
                }
                /* Filter on the extended ID bit*/
                SET_BIT(ui16MaskReg1, MXTD_BIT);
                /*
                 * Set the UMASK bit to enable using the mask register.
                 */
                SET_BIT(ui16MsgCtrl,UMASK_BIT);
                /*
                 * Set the MASK bit so that this gets transferred to the Message
                 * Object.
                 */
                SET_BIT(ui16CmdMaskReg,MASK_BIT);
                /*
                 * Set the Arb bit so that this gets transferred to the Message object.
                 */
                SET_BIT(ui16CmdMaskReg,ARB_BIT);
                /*
                 * Configure the Arbitration registers.
                 */
                if(bUseExtendedID)
                {
                    /*
                     * Set the 29 bit version of the Identifier for this message object.
                     */
                    ui16ArbReg0 = (uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterCode);
                    ui16ArbReg1 = (((uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterCode) >> SIXTEEN) & THIRTEEN_BIT_MASK);
                    /*
                     * Mark the message as valid and set the extended ID bit.
                     */
                    SET_BIT(ui16ArbReg1,MSGVAL_BIT);
                    SET_BIT(ui16ArbReg1,XTD_BIT);
                }
                else
                {
                    /*
                     * Set the 11 bit version of the Identifier for this message object.
                     * The lower 18 bits are set to zero.
                     */
                    ui16ArbReg0 = ZERO;
                    ui16ArbReg1 = (((uint16)(Config->CanConfigSet.CanHardwareObject[iter].CanHwFilter.CanHwFilterCode) << TWO) & THIRTEEN_BIT_MASK);
                    /*
                     * Mark the message as valid.
                     */
                    SET_BIT(ui16ArbReg1,MSGVAL_BIT);
                }
                /*If the Hoh Interrupt Processing is enabled*/
                if (Config->CanConfigSet.CanHardwareObject[iter].CanObjectType == RECIEVE)
                {
                    SET_BIT(ui16MsgCtrl,RXIE_BIT);
                }
                else
                {
                    /* Do Nothing*/
                }

                /*
                 * Write out the registers to program the message object.
                 */
                /************** Receiving ***********
                 * Pushing the value to registers of the receiving message objects according to the configuration*/
                if (Config->CanConfigSet.CanHardwareObject[iter].CanObjectType == RECIEVE)
                {

                    REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET) = ui16CmdMaskReg;
                    REG_VAL(CAN0_BASE, CAN_IF1MSK1_OFFSET) = ui16MaskReg0;
                    REG_VAL(CAN0_BASE, CAN_IF1MSK2_OFFSET) = ui16MaskReg1;
                    REG_VAL(CAN0_BASE, CAN_IF1ARB1_OFFSET) = ui16ArbReg0;
                    REG_VAL(CAN0_BASE, CAN_IF1ARB2_OFFSET) = ui16ArbReg1;
                    REG_VAL(CAN0_BASE, CAN_IF1MCTL_OFFSET) = ui16MsgCtrl;
                }
                /************  Transmitting********
                 * Save the value of the registers in a structure to be used later in Can_write for transmitting */
                else
                {
                    registers[iter].ui16ArbReg0 = ui16ArbReg0;
                    registers[iter].ui16ArbReg1 = ui16ArbReg1;
                    registers[iter].ui16MaskReg0 = ui16MaskReg0;
                    registers[iter].ui16MaskReg1 = ui16MaskReg1;
                    registers[iter].ui16CmdMaskReg = ui16CmdMaskReg;
                    registers[iter].ui16MsgCtrl = ui16MsgCtrl;
                }
                /*
                 * Transfer the message object to the message object specified by Hoh ID
                 */
                REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET) = ((Object_Check[CAN0_CONTROLLER_ID][iter][iter2]).mailbox & SIX_BIT_MASK);
            }
        }
        /* Transition of Controller from CS_UNINIT State to CS_STOPPED State*/
        Can_CurrentState[CAN0_CONTROLLER_ID]= CAN_CS_STOPPED;
#endif /*CanConf_CAN0_CONTROLLER_ACTIVATION*/
#if (CanConf_CAN1_CONTROLLER_ACTIVATION == STD_ON)
        uint8 delay=ZERO;
        /*Enable Clock to CAN Peripheral*/
        SET_BIT(SYSCTL_RCGC0_REG,CAN_BIT);
        delay =SYSCTL_RCGC0_REG;
        /*Setting CAN Functionality using PORT Driver*/
        /*Set the Init Bit in CANCTL*/
        SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),INIT_BIT);
        /*Set the Baudrate*/
        /*Set the CCE Bit in CANCTL*/
        SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),CCE_BIT);
        /* Set the Time Segment 1 */
        REG_VAL(CAN1_BASE,CAN_BIT_OFFSET)|= ((Config->Controller[CAN1_CONTROLLER_ID].BaudRate.PropSeg + Config->Controller[CAN1_CONTROLLER_ID].BaudRate.PhaseSeg1 -ONE)<< EIGHT_BITS) ;
        /* Set the Time Segment 2 */
        REG_VAL(CAN1_BASE,CAN_BIT_OFFSET)|= ((Config->Controller[CAN1_CONTROLLER_ID].BaudRate.PhaseSeg2  -ONE)<< TWELVE_BITS) ;
        /* Set the SyncJumpWidth */
        REG_VAL(CAN1_BASE,CAN_BIT_OFFSET)|= ((Config->Controller[CAN1_CONTROLLER_ID].BaudRate.SyncJumpWidth  -ONE)<< SIX_BITS) ;
        /* Set the BaudRate Prescaler */
        REG_VAL(CAN1_BASE,CAN_BIT_OFFSET)|= (ONE<< ZERO) ;
        REG_VAL(CAN1_BASE,CAN_BRPE_OFFSET)|= (ZERO<< ZERO);

        /*Configure Hardware Message Objects*/
        /*After reset, the CAN controller is left in the disabled state.  However,
         *the memory used for message objects contains undefined values and must be
         *cleared prior to enabling the CAN controller the first time.  This prevents
         *unwanted transmission or reception of data before the message objects are
         *configured.
         */
        /* Wait for busy bit to clear */
        while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
        {
            /*Do Nothing*/
        }
        /*
         * Set WRNRD bit to specify a write to the CANIFnCMASK
         * Set ARB bit to transfer the ID, DIR, XTD, and MSGVAL of the message object into the interface registers
         * Set CONTROL bit to transfer the control bits into the interface registers
         * Set MASK bit to Transfer IDMASK + DIR + MXTD of the message object into the Interface registers.
         */
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),WRNRD_BIT);
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),MASK_BIT);
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),ARB_BIT);
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),CONTROL_BIT);

        /*
         * Clear the message value bit in the arbitration register.  This indicates
         * the message is not valid and is a "safe" condition to leave the message
         * object.  The same arb reg is used to program all the message objects.
         */
        REG_VAL(CAN1_BASE,CAN_IF1ARB2_OFFSET)=ZERO;
        REG_VAL(CAN1_BASE,CAN_IF1MCTL_OFFSET)=ZERO;

        /* Loop through to program all 32 message objects */
        uint8 iter;
        for(iter = ONE; iter <= CAN_HARDWARE_OBJECTS_NUMBER; iter++)
        {
            /* Wait for busy bit to clear */
            while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
            {
                /*Do Nothing*/
            }
            /*  Initiate programming the message object */
            REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET) = iter;
        }

        /*
         * Set CLRINTPND to clear the INTPND bit in the CANIFnMCTL register
         * Set NEWDAT to clear the NEWDAT bit in the CANNWDAn register
         */
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),CLRINTPND_BIT);
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1CMSK_OFFSET),NEWDAT_BIT);

        /* Loop through to program all 32 message objects */
        for(iter = ONE; iter <= CAN_HARDWARE_OBJECTS_NUMBER; iter++)
        {
            Message_Confirmation[CAN1_CONTROLLER_ID][iter-1] = Confirmed;
            /* Wait for busy bit to clear */
            while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
            {
                /*Do Nothing*/
            }
            /*  Initiate programming the message object */
            REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET) = iter;
        }

        /* Acknowledge any pending status interrupts. */
        REG_VAL(CAN1_BASE,CAN_STS_OFFSET);
        /* Configure the Hardware Message Objects*/
        for (iter = ZERO; iter < CAN_HARDWARE_OBJECTS_NUMBER; iter++)
        {
            uint16 ui16CmdMaskReg;
            uint16 ui16MaskReg0, ui16MaskReg1;
            uint16 ui16ArbReg0, ui16ArbReg1;
            uint16 ui16MsgCtrl;
            uint8 bUseExtendedID;
            /* Wait for busy bit to clear */
            while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
            {
                /*Do Nothing*/
            }
            /* See if we need to use an extended identifier or not.*/
            if(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].IDType == ID_EXTENDED)
            {
                bUseExtendedID = ONE;
            }
            else
            {
                bUseExtendedID = ZERO;
            }
            /*
             * This is always a write to the Message object as this call is setting a
             * message object.  This call always sets all size bits so it sets
             * both data bits.  The call uses the CONTROL register to set control
             * bits so this bit needs to be set as well.
             */
            SET_BIT(ui16CmdMaskReg,WRNRD_BIT);
            SET_BIT(ui16CmdMaskReg,CONTROL_BIT);
            SET_BIT(ui16CmdMaskReg,DATAA_BIT);
            SET_BIT(ui16CmdMaskReg,DATAB_BIT);
            /*
             * Initialize the values to a known state before filling them in based on
             * the type of message object that is being configured.
             */
            ui16ArbReg0 = ZERO;
            ui16ArbReg1 = ZERO;
            ui16MsgCtrl = ZERO;
            ui16MaskReg0 = ZERO;
            ui16MaskReg1 = ZERO;

            /* Configure Transmit HOH*/
            if (Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].HardwareObjectType == TRANSMIT)
            {
                /*
                 * Set the TXRQST bit and the reset the rest of the register.
                 */
                SET_BIT(ui16ArbReg1,DIR_BIT);
            }
            /* Configure Recieve HOH*/
            else if (Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].HardwareObjectType == RECIEVE)
            {
                /*
                 * This clears the DIR bit along with everything else.  The TXRQST
                 * bit was cleared by defaulting ui16MsgCtrl to 0.
                 */
                ui16ArbReg1 = ZERO;
            }
            /* AUTOSAR doesn't support any other message type*/
            else
            {
                /* Do Nothing*/
            }
            /*
             * Configure the Mask Registers.
             */
            if(bUseExtendedID)
            {
                /*
                 * Set the 29 bits of Identifier mask that were requested.
                 */
                ui16MaskReg0 =(uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Mask);
                ui16MaskReg1 =(((uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Mask) >> SIXTEEN) & THIRTEEN_BIT_MASK);
            }
            else
            {
                /*
                 * Lower 16 bit are unused so set them to zero.
                 */
                ui16MaskReg0 = ZERO;
                /*
                 * Put the 11 bit Mask Identifier into the upper bits of the field
                 * in the register.
                 */
                ui16MaskReg1 = (((uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Mask) << TWO) & THIRTEEN_BIT_MASK);
            }
            /* Filter on the extended ID bit*/
            SET_BIT(ui16MaskReg1, MXTD_BIT);
            /*
             * Set the UMASK bit to enable using the mask register.
             */
            SET_BIT(ui16MsgCtrl,UMASK_BIT);
            /*
             * Set the MASK bit so that this gets transferred to the Message
             * Object.
             */
            SET_BIT(ui16CmdMaskReg,MASK_BIT);
            /*
             * Set the Arb bit so that this gets transferred to the Message object.
             */
            SET_BIT(ui16CmdMaskReg,ARB_BIT);
            /*
             * Configure the Arbitration registers.
             */
            if(bUseExtendedID)
            {
                /*
                 * Set the 29 bit version of the Identifier for this message object.
                 */
                ui16ArbReg0 = (uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Filter);
                ui16ArbReg1 = (((uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Filter) >> SIXTEEN) & THIRTEEN_BIT_MASK);
                /*
                 * Mark the message as valid and set the extended ID bit.
                 */
                SET_BIT(ui16ArbReg1,MSGVAL_BIT);
                SET_BIT(ui16ArbReg1,XTD_BIT);
            }
            else
            {
                /*
                 * Set the 11 bit version of the Identifier for this message object.
                 * The lower 18 bits are set to zero.
                 */
                ui16ArbReg0 = ZERO;
                ui16ArbReg1 = (((uint16)(Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].FilterConfig.Filter) << TWO) & THIRTEEN_BIT_MASK);
                /*
                 * Mark the message as valid.
                 */
                SET_BIT(ui16ArbReg1,MSGVAL_BIT);
            }
            /*If the Hoh Polling Processing is enabled*/
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)

            /* Can Main Function shall Write or Read*/

#else /*Interrupts Processing*/
            if (Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].HardwareObjectType == RECIEVE)
            {
                SET_BIT(ui16MsgCtrl,RXIE_BIT);
            }
            else
            {
                /* Do Nothing*/
            }
#endif /*Interrupts Processing*/
            /*
             * Write out the registers to program the message object.
             */
            /************** Receiving ***********
             * Pushing the value to registers of the receiving message objects according to the configuration*/
            if (Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].HardwareObjectType == RECIEVE)
            {

                REG_VAL(CAN1_BASE, CAN_IF1CMSK_OFFSET) = ui16CmdMaskReg;
                REG_VAL(CAN1_BASE, CAN_IF1MSK1_OFFSET) = ui16MaskReg0;
                REG_VAL(CAN1_BASE, CAN_IF1MSK2_OFFSET) = ui16MaskReg1;
                REG_VAL(CAN1_BASE, CAN_IF1ARB1_OFFSET) = ui16ArbReg0;
                REG_VAL(CAN1_BASE, CAN_IF1ARB2_OFFSET) = ui16ArbReg1;
                REG_VAL(CAN1_BASE, CAN_IF1MCTL_OFFSET) = ui16MsgCtrl;
            }
            /************  Transmitting********
             * Save the value of the registers in a structure to be used later in Can_write for transmitting */
            else
            {
                registers[iter].ui16ArbReg0 = ui16ArbReg0;
                registers[iter].ui16ArbReg1 = ui16ArbReg1;
                registers[iter].ui16MaskReg0 = ui16MaskReg0;
                registers[iter].ui16MaskReg1 = ui16MaskReg1;
                registers[iter].ui16CmdMaskReg = ui16CmdMaskReg;
                registers[iter].ui16MsgCtrl = ui16MsgCtrl;
            }
            /*
             * Transfer the message object to the message object specified by Hoh ID
             */
            REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET) = ((Config->Controller[CAN1_CONTROLLER_ID].HOH[iter].ID) & SIX_BIT_MASK);
        }
        /* Transition of Controller from CS_UNINIT State to CS_STOPPED State*/
        Can_CurrentState[CAN1_CONTROLLER_ID]= CAN_CS_STOPPED;
#endif /*CanConf_CAN1_CONTROLLER_ACTIVATION*/
        /* Transition of Driver from UNINIT State to READY State*/
        Can_Status = CAN_READY;
    }
}


/************************************************************************************
 *Service name: Can_DeInit
 *Syntax: void Can_DeInit(void)
 *Service ID[hex]: 0x10
 *Sync/Async: Synchronous
 *Reentrancy: Non Reentrant
 *Parameters (in): None
 *Parameters (inout):None
 *Parameters (out): None
 *Return value: None
 *Description: This function de-initializes the module.
 *Caveat: Caller of the Can_DeInit function has to be sure no CAN controller is in the state STARTED
 ************************************************************************************/
void Can_DeInit(void)
{

    /*The function Can_DeInit shall raise the error CAN_E_TRANSITION if the driver is not in state CAN_READY*/
#if(CAN_DEV_ERROR_DETECT == STD_ON)
    if(Can_Status != CAN_READY)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DE_INIT_SID, CAN_E_TRANSITION);
    }
    else
    {
        /* Do nothing*/
    }

    /*The function Can_DeInit shall raise the error CAN_E_TRANSITION if any of the CAN controllers is in state STARTED.*/
    if(  (Can_CurrentState[CAN0_CONTROLLER_ID] == CAN_CS_STARTED ) || (Can_CurrentState[CAN1_CONTROLLER_ID] == CAN_CS_STARTED ) )
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DE_INIT_SID, CAN_E_TRANSITION);
    }
    else
#endif /*CAN_DEV_ERROR_DETECT*/
    {
        /*CAN Module 0 Software Reset*/
        SET_BIT(SYSCTL_SRCAN_REG,R0_BIT);
        /*CAN Module 1 Software Reset*/
        SET_BIT(SYSCTL_SRCAN_REG,R1_BIT);

        /*Reset All Registers*/
        /*
        REG_VAL(CAN0_BASE, CAN_CTL_OFFSET ) = CAN_CTL_RESET;
        REG_VAL(CAN0_BASE, CAN_STS_OFFSET ) = CAN_STS_RESET;
        REG_VAL(CAN0_BASE, CAN_ERR_OFFSET ) = CAN_ERR_RESET;
        REG_VAL(CAN0_BASE, CAN_BIT_OFFSET ) = CAN_BIT_RESET;
        REG_VAL(CAN0_BASE, CAN_INT_OFFSET ) = CAN_INT_RESET;
        REG_VAL(CAN0_BASE, CAN_TST_OFFSET ) = CAN_TST_RESET;
        REG_VAL(CAN0_BASE, CAN_BRPE_OFFSET ) = CAN_BRPE_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET ) = CAN_IF1CRQ_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET ) = CAN_IF1CMSK_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1MSK1_OFFSET ) = CAN_IF1MSK1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1MSK2_OFFSET ) = CAN_IF1MSK2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1ARB1_OFFSET ) = CAN_IF1ARB1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1ARB2_OFFSET ) = CAN_IF1ARB2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1MCTL_OFFSET ) = CAN_IF1MCTL_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1DA1_OFFSET ) = CAN_IF1DA1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1DA2_OFFSET ) = CAN_IF1DA2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1DB1_OFFSET ) = CAN_IF1DB1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF1DB2_OFFSET ) = CAN_IF1DB2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2CRQ_OFFSET ) = CAN_IF2CRQ_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2CMSK_OFFSET ) = CAN_IF2CMSK_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2MSK1_OFFSET ) = CAN_IF2MSK1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2MSK2_OFFSET ) = CAN_IF2MSK2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2ARB1_OFFSET ) = CAN_IF2ARB1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2ARB2_OFFSET ) = CAN_IF2ARB2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2MCTL_OFFSET ) = CAN_IF2MCTL_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2DA1_OFFSET ) = CAN_IF2DA1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2DA2_OFFSET ) = CAN_IF2DA2_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2DB1_OFFSET ) = CAN_IF2DB1_RESET;
        REG_VAL(CAN0_BASE, CAN_IF2DB2_OFFSET ) = CAN_IF2DB2_RESET;
        REG_VAL(CAN0_BASE, CAN_TXRQ1_OFFSET ) = CAN_TXRQ1_RESET;
        REG_VAL(CAN0_BASE, CAN_TXRQ2_OFFSET ) = CAN_TXRQ2_RESET;
        REG_VAL(CAN0_BASE, CAN_NWDA1_OFFSET ) = CAN_NWDA1_RESET;
        REG_VAL(CAN0_BASE, CAN_NWDA2_OFFSET ) = CAN_NWDA2_RESET;
        REG_VAL(CAN0_BASE, CAN_MSG1INT_OFFSET ) = CAN_MSG1INT_RESET ;
        REG_VAL(CAN0_BASE, CAN_MSG2INT_OFFSET ) = CAN_MSG2INT_RESET ;
        REG_VAL(CAN0_BASE, CAN_MSG1VAL_OFFSET ) = CAN_MSG1VAL_RESET ;
        REG_VAL(CAN0_BASE, CAN_MSG2VAL_OFFSET ) = CAN_MSG2VAL_RESET;

        REG_VAL(CAN1_BASE, CAN_CTL_OFFSET ) = CAN_CTL_RESET;
        REG_VAL(CAN1_BASE, CAN_STS_OFFSET ) = CAN_STS_RESET;
        REG_VAL(CAN1_BASE, CAN_ERR_OFFSET ) = CAN_ERR_RESET;
        REG_VAL(CAN1_BASE, CAN_BIT_OFFSET ) = CAN_BIT_RESET;
        REG_VAL(CAN1_BASE, CAN_INT_OFFSET ) = CAN_INT_RESET;
        REG_VAL(CAN1_BASE, CAN_TST_OFFSET ) = CAN_TST_RESET;
        REG_VAL(CAN1_BASE, CAN_BRPE_OFFSET ) = CAN_BRPE_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET ) = CAN_IF1CRQ_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1CMSK_OFFSET ) = CAN_IF1CMSK_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1MSK1_OFFSET ) = CAN_IF1MSK1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1MSK2_OFFSET ) = CAN_IF1MSK2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1ARB1_OFFSET ) = CAN_IF1ARB1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1ARB2_OFFSET ) = CAN_IF1ARB2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1MCTL_OFFSET ) = CAN_IF1MCTL_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1DA1_OFFSET ) = CAN_IF1DA1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1DA2_OFFSET ) = CAN_IF1DA2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1DB1_OFFSET ) = CAN_IF1DB1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF1DB2_OFFSET ) = CAN_IF1DB2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2CRQ_OFFSET ) = CAN_IF2CRQ_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2CMSK_OFFSET ) = CAN_IF2CMSK_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2MSK1_OFFSET ) = CAN_IF2MSK1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2MSK2_OFFSET ) = CAN_IF2MSK2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2ARB1_OFFSET ) = CAN_IF2ARB1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2ARB2_OFFSET ) = CAN_IF2ARB2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2MCTL_OFFSET ) = CAN_IF2MCTL_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2DA1_OFFSET ) = CAN_IF2DA1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2DA2_OFFSET ) = CAN_IF2DA2_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2DB1_OFFSET ) = CAN_IF2DB1_RESET;
        REG_VAL(CAN1_BASE, CAN_IF2DB2_OFFSET ) = CAN_IF2DB2_RESET;
        REG_VAL(CAN1_BASE, CAN_TXRQ1_OFFSET ) = CAN_TXRQ1_RESET;
        REG_VAL(CAN1_BASE, CAN_TXRQ2_OFFSET ) = CAN_TXRQ2_RESET;
        REG_VAL(CAN1_BASE, CAN_NWDA1_OFFSET ) = CAN_NWDA1_RESET;
        REG_VAL(CAN1_BASE, CAN_NWDA2_OFFSET ) = CAN_NWDA2_RESET;
        REG_VAL(CAN1_BASE, CAN_MSG1INT_OFFSET ) = CAN_MSG1INT_RESET ;
        REG_VAL(CAN1_BASE, CAN_MSG2INT_OFFSET ) = CAN_MSG2INT_RESET ;
        REG_VAL(CAN1_BASE, CAN_MSG1VAL_OFFSET ) = CAN_MSG1VAL_RESET ;
        REG_VAL(CAN1_BASE, CAN_MSG2VAL_OFFSET ) = CAN_MSG2VAL_RESET;
         */

        /*Change the driver state to UNINT state*/
        Can_Status = CAN_UNINIT;

        /*Change the Controllers state to UNINT state */
        Can_CurrentState[CAN0_CONTROLLER_ID] = CAN_CS_UNINIT ;
        Can_CurrentState[CAN1_CONTROLLER_ID] = CAN_CS_UNINIT ;

        /*Set the Init Bit in CANCTL (Bus-Off)*/
        SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),INIT_BIT);
        SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),INIT_BIT);

        /*Disable Clock to CAN Peripheral*/
        CLEAR_BIT(SYSCTL_RCGC0_REG,CAN0_BIT);
        CLEAR_BIT(SYSCTL_RCGC0_REG,CAN1_BIT);
    }
}

uint8 Can_MessageReceive(uint32 Controller_Base_Address,
                         Can_HwHandleType MessageObj_Num, Can_PduType* Message)
{
    uint16 ui16CmdMaskReg;
    uint16 ui16MaskReg0, ui16MaskReg1;
    uint16 ui16ArbReg0, ui16ArbReg1;
    uint16 ui16MsgCtrl;

    uint8 Flag = ZERO ;
    /*
     * Set the bits in the register to set the message object as receive
     * -Clear the WRNRD bit to specify a write to the CANIFnCMASK register; specify whether to
       transfer the IDMASK, DIR, and MXTD of the message object into the CAN IFn registers using
       the MASK bit
      -Specify whether to transfer the ID, DIR, XTD, and MSGVAL of the message object into the
      interface registers using the ARB bit
      -Specify whether to transfer the control bits into the interface registers using the CONTROL
      bit
     */
    SET_BIT(ui16CmdMaskReg,ARB_BIT);
    SET_BIT(ui16CmdMaskReg,DATAA_BIT);
    SET_BIT(ui16CmdMaskReg,DATAB_BIT);
    SET_BIT(ui16CmdMaskReg,CONTROL_BIT);
    SET_BIT(ui16CmdMaskReg,MASK_BIT);


    /*
     * Push the message object passed to the function to the interface register
     */
    REG_VAL(Controller_Base_Address,CAN_IF1CMSK_OFFSET) =  ui16CmdMaskReg;
    REG_VAL(Controller_Base_Address,CAN_IF1CRQ_OFFSET) =  MessageObj_Num & (SIX_BIT_MASK);

    while (BIT_IS_SET(REG_VAL(Controller_Base_Address,CAN_IF1CRQ_OFFSET),BUSY_BIT) )
    {
        /* Do nothing ,wait for busy bit to clear */
    }

    /*- Holding the value of CAN IF2 Arbitration 1 Register
     *- The register has the value of ID if extended
     */
    ui16ArbReg0 = REG_VAL(Controller_Base_Address,CAN_IF1ARB1_OFFSET);

    /*- Holding the value of CAN IF2 Arbitration 2 Register
     *- The register has the value of ID,DIR(13),ExtndedID(14),MSG Valid(15)
     */
    ui16ArbReg1 = REG_VAL(Controller_Base_Address,CAN_IF1ARB2_OFFSET);

    /*- Holding the value of CAN IF2 Message Control Register
     *- The register has the value of length of data(0-3),NewData(15)
     */
    ui16MsgCtrl = REG_VAL(Controller_Base_Address,CAN_IF1MCTL_OFFSET);

    ui16MaskReg0 = REG_VAL(Controller_Base_Address, CAN_IF1MSK1_OFFSET);

    ui16MaskReg1 = REG_VAL(Controller_Base_Address, CAN_IF1MSK2_OFFSET);

    /*Check if the ID is standard*/

    if( BIT_IS_CLEAR( REG_VAL(Controller_Base_Address,CAN_IF1ARB2_OFFSET),XTD_BIT) )
    {
        Message->id = ( ui16ArbReg1 & CANIF1ARB2_ID_MASK ) >> 2;
    }
    else
    {  /*
     *   ID is Extended
     */
        Message->id = (( ui16ArbReg1 & CANIF1ARB2_ID_MASK ) <<16) | ui16ArbReg0 ;
    }

    /*Read the data from the register according to Message length*/
    if(BIT_IS_SET(ui16MsgCtrl,CANIF1MCTL_NEWDATA_BIT) )
    {
        uint32 Data_Index, Data_Value;
        uint32 Data_REG;
        Flag = ONE ;

        Message->length =  (ui16MsgCtrl & CANIF1MCTL_DLC_MASK);

        Data_REG = (CAN_IF1DA1_OFFSET);

        for(Data_Index = 0; Data_Index < Message->length ;)
        {
            Data_Value = REG_VAL(CAN0_BASE,Data_REG);
            Data_REG+=FOUR;
            Message->sdu[Data_Index++] = (uint8)Data_Value;
            if(Data_Index < Message->length)
            {
                Message->sdu[Data_Index++] = (uint8)(Data_Value >> 8);
            }
            else
            {
                /*Misra*/
            }
        }
        /*
         * Setting The value of New data bit to indicate new message
         */
        REG_VAL(Controller_Base_Address,CAN_IF1CMSK_OFFSET) = 0x00000004;

        REG_VAL(Controller_Base_Address,CAN_IF1CRQ_OFFSET) =  MessageObj_Num & (SIX_BIT_MASK);

        while (BIT_IS_SET(REG_VAL(Controller_Base_Address,CAN_IF1CRQ_OFFSET),BUSY_BIT) )
        {
            /* Do nothing ,wait for busy bit to clear */
        }
    }
    else
    {
        /*Misra*/
    }
    return Flag;
}

/***************************************************************************************************************
 * Service name: Can_MainFunction_Write
 * Syntax: void Can_MainFunction_Write(void)
 *  Service ID[hex]: 0x01
 *  Description: This function performs the polling of TX confirmation when
 *  CAN_TX_PROCESSING is set to POLLING.
 *
 *************************************************************************************************************/
void Can_MainFunction_Write(void)
{
    /*
     * [SWS_Can_00178] The Can module may implement the function
    Can_MainFunction_Write as empty define in case no polling at all is used.(
     */
#if  (POLLING == CanConf_CAN0_TX_PROCESSING) || (POLLING == CanConf_CAN1_TX_PROCESSING)

    /*
     * Check on the errors if the DET is ON
     */

#if(STD_ON == CAN_DEV_ERROR_DETECT)

    /*
     * -Check on the state of the driver
     * -If Driver state in UNINIT ,Function should not be called and error report
     */

    if(Can_Status == CAN_UNINIT)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAINFUNCTION_WRITE_SID, CAN_E_UNINIT);
    }
    else
    {
        /*MISRA : do nothing*/
    }

#endif

#if (STD_ON == CanConf_CAN0_CONTROLLER_ACTIVATION)
    /*
     *The function Can_MainFunction_Write shall perform the
     *polling of TX confirmation when CanTxProcessing
     *is set to POLLING or MIXED. In case of MIXED processing only the hardware
     *objects for which CanHardwareObjectUsesPolling is set to TRUE shall be polled.
     *(SRS_BSW_00432, SRS_BSW_00373, SRS_SPAL_00157)
     * */
#if  (POLLING == CanConf_CAN0_TX_PROCESSING)

    uint8 HOH_Index=ZERO;
    uint8 Mailbox_Index = ZERO;

    for(HOH_Index= ZERO; HOH_Index < CAN_HOH_NUMBER;HOH_Index++ )
    {
        if(TRANSMIT == Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanObjectType)
        {

            /*
             * check if the Reference of CAN Controller 0 to which the HOH is associated to is the same as
             * Configurations of can controller 0.
             */
            if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanControllerRef == &Can_Configuration.CanConfigSet.CanController[CAN0_CONTROLLER_ID])
            {
                for(Mailbox_Index = ZERO;Mailbox_Index <= Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanHardwareObjectCount -ONE; Mailbox_Index++)
                {
                    /*Check if this message object is used but never released*/
                    if(Object_Check[CAN0_CONTROLLER_ID][HOH_Index][Mailbox_Index].Check == Unconfirmed)
                    {
                        REG_VAL(CAN0_BASE_ADDRESS,CAN_IF1CRQ_OFFSET) = Object_Check[CAN0_CONTROLLER_ID][HOH_Index][Mailbox_Index].mailbox & SIX_BIT_MASK;
                        while (BIT_IS_SET(REG_VAL(CAN0_BASE_ADDRESS,CAN_IF1CRQ_OFFSET),BUSY_BIT) )
                        {
                            /* Do nothing ,wait for busy bit to clear */
                        }

                        /*If it is used:
                         * Check if it handled or not by checking on TRXQST bit
                         * If it is cleared,it means that a transmission is handled*/
                        if(BIT_IS_SET(REG_VAL(CAN0_BASE_ADDRESS,CAN_STS_OFFSET),TXOK_BIT))
                        {
                            CLEAR_BIT(REG_VAL(CAN0_BASE_ADDRESS,CAN_STS_OFFSET),TXOK_BIT);
                            /*Switch the message object state back to free*/
                            Object_Check[CAN0_CONTROLLER_ID][HOH_Index][Mailbox_Index].Check = Confirmed;
                            /*[SWS_Can_00016]  The Can module shall call CanIf_TxConfirmation to indicate a
                                    successful transmission. It shall either called by the TX-interrupt service routine of
                                    the corresponding HW resource or inside the Can_MainFunction_Write in case of
                                    polling mode. (SRS_Can_01051
                                     CanIf_TxConfirmation();
                             */
                        }
                        else{
                        /*MISRA : do nothing*/}

                        void CanIf_TxConfirmation( PduIdType CanTxPduId );

                        void CanIf_TxConfirmation( PduIdType CanTxPduId );

                        /*call CanIf_TxConfirmation function*/
                    }

                    else
                    {
                        /*MISRA : do nothing*/
                    }
                }

            }
            else
            {
                /*MISRA : do nothing*/
            }




        }
        else
        {
            /*MISRA : do nothing*/
        }
    }






#endif

#endif
    /*
     * Same configuration and checks but controller 1
     */





#if (STD_ON == CanConf_CAN1_CONTROLLER_ACTIVATION)
    /*
     *The function Can_MainFunction_Write shall perform the
     *polling of TX confirmation when CanTxProcessing
     *is set to POLLING or MIXED. In case of MIXED processing only the hardware
     *objects for which CanHardwareObjectUsesPolling is set to TRUE shall be polled.
     *(SRS_BSW_00432, SRS_BSW_00373, SRS_SPAL_00157)
     * */
#if  (POLLING == CanConf_CAN1_TX_PROCESSING)

    uint8 HO_Index=ZERO;
    uint8 Object_Index = ZERO;

    for(HO_Index= ZERO; HO_Index < CAN_HARDWARE_OBJECTS_NUMBER;HO_Index++ )
    {
        if(TRANSMIT == Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].HardwareObjectType)
        {

            /*
             * check if the Reference of CAN Controller 0 to which the HOH is associated to is the same as
             * Configurations of can controller 0.
             */
            if(Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].Reference == CAN1_CONTROLLER_ID)
            {
                for(Object_Index = ZERO;Object_Index < Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].CanHardwareObjectCount; Object_Index++)
                {
                    /*Check if this message object is used but never released*/
                    if(Message_Confirmation[CAN1_CONTROLLER_ID][HO_Index] == Unconfirmed)
                    {
                        /*If it is used:
                         * Check if it handled or not by checking on TRXQST bit
                         * If it is cleared,it means that a transmission is handled*/
                        if(BIT_IS_CLEAR(REG_VAL(CAN1_BASE_ADDRESS,CAN_IF1MCTL_OFFSET),TXRQST_BIT))
                        {
                            /*Switch the message object state back to free*/
                            Message_Confirmation[CAN1_CONTROLLER_ID][HO_Index] = Confirmed;
                            /*[SWS_Can_00016]  The Can module shall call CanIf_TxConfirmation to indicate a
                                                   successful transmission. It shall either called by the TX-interrupt service routine of
                                                   the corresponding HW resource or inside the Can_MainFunction_Write in case of
                                                   polling mode. (SRS_Can_01051
                                                    CanIf_TxConfirmation();
                             */
                        }
                        else{
                        /*MISRA : do nothing*/}
                    }

                    else
                    {
                        /*MISRA : do nothing*/
                    }
                }

            }
            else
            {
                /*MISRA : do nothing*/
            }




        }
        else
        {
            /*MISRA : do nothing*/
        }
    }






#endif

#endif

#endif

}





/*********************************************************************************************
 * Service name: Can_MainFunction_Read
 * Syntax: void Can_MainFunction_Read(void)
 * Service ID[hex]: 0x08
 * Description: -This function performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
 *              -The Can module may implement the function Can_MainFunction_Read
 *                 as empty define in case no polling at all is used
 *
 ********************************************************************/


void Can_MainFunction_Read(void)
{
    /*Check if any of the Can Controllers Receivers is set to Polling
     * If not -> Can_MainFunction_Read should be empty [SWS_Can_00180]
     */
#if (POLLING == CanConf_CAN0_RX_PROCESSING || POLLING == CanConf_CAN1_RX_PROCESSING )

    /*
     * Check on the errors if the DET is ON
     */
#if(STD_ON == CAN_DEV_ERROR_DETECT)

    /*
     * -Check on the state of the driver
     * -If Driver state in UNINIT ,Function should not be called and error report
     */
    if(Can_Status == CAN_UNINIT)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_MAINFUNCTION_READ_SID, CAN_E_UNINIT) ;
    }
    else
    {
        /*MISRA : do nothing*/
    }
#endif

    /*
     * Structures used for Receiving message object info
     *
     */
    PduInfoType ReceiverPduInfo;
    Can_PduType Can_Msg_Received;
    Can_HwType MSG_Object;



    /*
     * Check if Controller (0) is activated from the configurations
     * -if not configured active -> no processing on Controller (0)
     */
#if (STD_ON == CanConf_CAN0_CONTROLLER_ACTIVATION)
    /*
     * The function Can_MainFunction_Read shall perform the
            polling of RX indications when CanRxProcessing is set to POLLING or MIXED. In
            case of MIXED processing only the hardware objects for which
            CanHardwareObjectUsesPolling is set to TRUE shall be
            polled.(SRS_BSW_00432, SRS_SPAL_00157)
     */
#if (POLLING == CanConf_CAN0_RX_PROCESSING)

    uint8 HOH_Index=ZERO;
    uint8 Mailbox_Index = ZERO;

    for(HOH_Index = ZERO; HOH_Index < CAN_HOH_NUMBER;HOH_Index++)
    {
        /*
         * Check on each Hardware object if it is used as receive object
         */
        if( RECIEVE == Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanObjectType)
        {
            /*
             * check if the Reference of CAN Controller 0 to which the HOH is associated to is the same as
             * Configurations of can controller 0.
             */
            if(Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanControllerRef == &Can_Configuration.CanConfigSet.CanController[CAN1_CONTROLLER_ID])
            {
                /*how to loop CanHardwareObjectCount*/
                for(Mailbox_Index = ZERO ;Mailbox_Index < Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanHardwareObjectCount; Mailbox_Index++)

                {
                    uint8 NEW_DATA_UPDATE = Can_MessageReceive(CAN0_BASE_ADDRESS,Object_Check[CAN0_CONTROLLER_ID][HOH_Index][Mailbox_Index].mailbox,&Can_Msg_Received);

                    /*
                     * Check if the there is a new message in the
                     * message using the new data bit
                     */
                    if(ONE == NEW_DATA_UPDATE )
                    {
                        MSG_Object.CanId =  Can_Msg_Received.id ;
                        MSG_Object.ControllerId = Can_Configuration.CanConfigSet.CanHardwareObject[HOH_Index].CanControllerRef->CanControllerId;
                        MSG_Object.Hoh = HOH_Index;
                        ReceiverPduInfo.SduDataPtr = Can_Msg_Received.sdu;
                        ReceiverPduInfo.SduLength = Can_Msg_Received.length;
                        /*   On L-PDU reception, the Can module shall call the RX
                                    indication callback function CanIf_RxIndication with ID, Hoh, abstract CanIf
                                    ControllerId in parameter Mailbox, and the Data Length and pointer to the L-SDU
                                    buffer in parameter PduInfoPtr. (SRS_Can_01045)
                         *
                         */
                    }

                }
            }
            else
            {
                /*MISRA : do nothing*/
            }
        }
        else
        {
            /*MISRA : do nothing*/
        }
    }
#endif
#endif

    /*
     * Same configuration and checks but controller 1
     */

#if (STD_ON == CanConf_CAN1_CONTROLLER_ACTIVATION)
    /*
     * The function Can_MainFunction_Read shall perform the
           polling of RX indications when CanRxProcessing is set to POLLING or MIXED. In
           case of MIXED processing only the hardware objects for which
           CanHardwareObjectUsesPolling is set to TRUE shall be
           polled.(SRS_BSW_00432, SRS_SPAL_00157)
     */
#if (POLLING == CanConf_CAN01_RX_PROCESSING)

    uint8 HO_Index=ZERO;
    uint8 Object_Index = ZERO;
    for(HO_Index = ZERO; HO_Index < CAN_HARDWARE_OBJECTS_NUMBER;HO_Index++)
    {
        /*
         * Check on each Hardware object if it is used as receive object
         */
        if( RECIEVE == Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].HardwareObjectType)
        {
            /*
             * check if the Reference of CAN Controller 1 to which the HOH is associated to is the same as
             * Configurations of can controller 01
             */
            if(Can_Configuration.Controller[1].HOH[HO_Index].Reference == CAN1_CONTROLLER_ID)
            {
                /*how to loop CanHardwareObjectCount*/
                for(Object_Index = ZERO ;Object_Index < Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].CanHardwareObjectCount; Object_Index++)

                {
                    uint8 NEW_DATA_UPDATE = Can_MessageReceive( CAN1_BASE_ADDRESS, HO_Index, &Can_Msg_Received);

                    /*
                     * Check if the there is a new message in the
                     * message using the new data bit
                     */
                    if(ONE == NEW_DATA_UPDATE )
                    {
                        MSG_Object.CanId =  Can_Msg_Received.id ;
                        MSG_Object.ControllerId = Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].Reference;
                        MSG_Object.Hoh = Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[HO_Index].ID;
                        ReceiverPduInfo.SduDataPtr = Can_Msg_Received.sdu;
                        ReceiverPduInfo.SduLength = Can_Msg_Received.length;
                        /*   On L-PDU reception, the Can module shall call the RX
                                   indication callback function CanIf_RxIndication with ID, Hoh, abstract CanIf
                                   ControllerId in parameter Mailbox, and the Data Length and pointer to the L-SDU
                                   buffer in parameter PduInfoPtr. (SRS_Can_01045)
                         *
                         */
                    }

                }
            }
            else
            {
                /*MISRA : do nothing*/
            }
        }
        else
        {
            /*MISRA : do nothing*/
        }
    }
#endif
#endif
#endif
}




/********************************************************************************************************/
/*Service name: Can_EnableControllerInterrupts
Syntax: void Can_EnableControllerInterrupts(uint8 Controller)
Service ID[hex]: 0x05
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): Controller CAN controller for which interrupts shall be re-enabled
Parameters
(inout):
None
Parameters (out): None
Return value: None
Description: This function enables all allowed interrupts.*/
/********************************************************************************************************/

void Can_EnableControllerInterrupts( uint8 Controller )
{
    //Enable_Exceptions();
    uint32 Exception_val=Enable_Exceptions();
    /*
     * Check on the errors if the DET is ON
     */
#if(STD_ON == CAN_DEV_ERROR_DETECT)

    /*implementation of the DET*/
    if(Can_Status == CAN_UNINIT)
    {

        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_ENABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_UNINIT);

    }
    else if(Controller >= CAN_CONTROLLERS_NUMBER)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_ENABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_PARAM_CONTROLLER);

    }
#endif

    if ( Interrupts_Enable_Disable_Counter != 0)
    {
        Interrupts_Enable_Disable_Counter --;

    }

    if ( ( Interrupts_Disable_Flag==1 )&& (Interrupts_Enable_Disable_Counter == 0) )
    {
#if (CanConf_CAN0_CONTROLLER_ACTIVATION == STD_ON)
        {

            if(Can_CurrentState[CAN0_CONTROLLER_ID] == CAN_CS_STARTED)
            {
                REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET);
                /*Enable interrupts*/
                SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),General_interrupt);      /*General Can interrupt*/
                SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),Statues_Interrupt);      /*Statues Interrupt*/
                SET_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),Error_Interrupt);      /*Error Interrupt*/
                SET_BIT(CAN_NVIC_EN1,CAN0_Enable_Interrupts); /*NVIC*/

                /*Setting interrupt priority to 1*/
                SET_BIT(CAN_NVIC_PRI9,TWENTY_NINE_INTD);
                CLEAR_BIT(CAN_NVIC_PRI9,THIRTY_INTD);
                CLEAR_BIT(CAN_NVIC_PRI9,THIRTY_ONE_INTD);
            }
        }


#endif

#if (CanConf_CAN1_CONTROLLER_ACTIVATION == STD_ON)
        {
            if(Can_CurrentState[CAN1_CONTROLLER_ID] == CAN_CS_STARTED)
            {

                {

                    SET_BIT( REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),General_interrupt);      /*General Can interrupt*/
                    SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),Statues_Interrupt);      /*Statues Interrupt*/
                    SET_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),Error_Interrupt);      /*Error Interrupt*/
                    SET_BIT(CAN_NVIC_EN1,CAN1_Enable_Interrupts); /*NVIC*/
                    /*Setting interrupt priority to 1*/
                    SET_BIT(CAN_NVIC_PRI10,FIVE_INTA);
                    CLEAR_BIT(CAN_NVIC_PRI10,SIX_INTA);
                    CLEAR_BIT(CAN_NVIC_PRI10,SEVEN_INTA);

                }
            }
        }


#endif
    }

}

/*********************************************************************************************
 *Service name: Can_DisableControllerInterrupts
void Can_DisableControllerInterrupts( uint8 Controller )
Syntax:
Service ID[hex]: 0x04
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): Controller CAN controller for which interrupts shall be disabled.
Parameters None
(inout):
Parameters (out): None
Return value: None
Description: This function disables all interrupts for this CAN controller.
 ********************************************************************************************/

void Can_DisableControllerInterrupts( uint8 Controller )
{
#if(STD_ON == CAN_DEV_ERROR_DETECT)

    /*implementation of the DET*/

    if(Can_Status == CAN_UNINIT)
    {

        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DISABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_UNINIT);

    }
    else if(Controller >= CAN_CONTROLLERS_NUMBER)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_DISABLE_CONTROLLER_INTERRUPTS_SID, CAN_E_PARAM_CONTROLLER);



    }
#endif
    /*[SWS_Can_00202] ⌈ When Can_DisableControllerInterrupts has been called several times, Can_EnableControllerInterrupts must be called as many times before
the interrupts are re-enabled..*/
    Interrupts_Disable_Flag =1;
    Interrupts_Enable_Disable_Counter ++ ;

    // if( Interrupts_Enable_Count[Controller]==ZERO){

#if CanConf_CAN0_CONTROLLER_ACTIVATION == STD_ON
    {

        if(Can_CurrentState[CAN0_CONTROLLER_ID] == CAN_CS_STARTED)
        {
            CLEAR_BIT(REG_VAL(CAN0_BASE,CAN_CTL_OFFSET),INIT_BIT);
            SET_BIT(CAN_NVIC_DIS1,7);
        }
    }



#endif
#if CanConf_CAN1_CONTROLLER_ACTIVATION == STD_ON
    {

        if(Can_CurrentState[CAN1_CONTROLLER_ID] == CAN_CS_STARTED)
        {
            CLEAR_BIT(REG_VAL(CAN1_BASE,CAN_CTL_OFFSET),INIT_BIT);
            SET_BIT(CAN_NVIC_DIS1,8); /***********NVIC********/
        }
    }

#endif
}

/************************************************************************************
 *Service name: Can_Write
 *Service ID[hex]: 0x06
 *Sync/Async: Synchronous
 *Reentrancy: Reentrant (thread-safe)
 *Parameters (in): Can_HwHandleType Hth - Information which HW-transmit handle shall
 *                                        be used for transmit.
 *                 const Can_PduType* PduInfo - Pointer to SDU user memory, Data Length
 *                                              and Identifier.
 *Parameters (inout):None
 *Parameters (out): None
 *Return value: Std_ReturnType -  E_OK: Write command has been accepted
 *                                E_NOT_OK: development error occurred
 *                                CAN_BUSY: No TX hardware buffer available or pre-emptive call
 *                                          of Can_Write that can't be implemented re-entrant
 *Description: This function is called by CanIf to pass a CAN message to CanDrv for
 *             transmission.
 ************************************************************************************/
Std_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo)
{
    uint8 Can_Controller_ID = Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanControllerRef->CanControllerId;

    /*
     * SWS_Can_00216] If development error detection for the Can module is enabled:
     *   The function Can_Write shall raise the error CAN_E_UNINIT and shall return
     *   E_NOT_OK if the driver is not yet initialized.
     */
#if(STD_ON == CAN_DEV_ERROR_DETECT)
    /*
     * [SWS_Can_00216]  If development error detection for the Can module is enabled:
     *                    The function Can_Write shall raise the error CAN_E_UNINIT and shall return
     *                    E_NOT_OK if the driver is not yet initialized.
     */
    if(Can_Status == CAN_UNINIT)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_UNINIT) ;
        return E_NOT_OK;
    }
    else
    {
        /*MISRA : do nothing*/
    }

    /* [SWS_Can_00217]  If development error detection for the Can module is enabled:
         The function Can_Write shall raise the error CAN_E_PARAM_HANDLE and shall
         return E_NOT_OK if the parameter Hth is not a configured Hardware Transmit
         Handle. */
    if( RECIEVE == Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanObjectType)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_HANDLE);
        return E_NOT_OK;
    }

    else
    {
        /*MISRA : do nothing*/
    }

    /* [SWS_CAN_00219]  If development error detection for CanDrv is enabled:
         Can_Write() shall raise CAN_E_PARAM_POINTER and shall return E_NOT_OK if the
         parameter PduInfo is a null pointer.*/
    if(NULL_PTR == PduInfo)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    else
    {
        /*MISRA : do nothing*/
    }
    if(PduInfo->length > 8U)
    {
        Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, CAN_WRITE_SID, CAN_E_PARAM_DATA_LENGTH);
        return E_NOT_OK;
    }
    else
#endif
    {
#if (CanConf_CAN0_CONTROLLER_ACTIVATION == STD_ON)
        /*Full CAN*/
        if ((FULL == Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanHandleType) && (Object_Check[Can_Controller_ID][Hth][ZERO].Check == Confirmed))
        {
            /*
             * Initialize the values to a known state before filling them in based on
             * the type of message object that is being configured.
             */
            uint16 ui16MsgCtrl = ZERO;

            /*
             * Set the TXRQST bit and the reset the rest of the register.
             */
            SET_BIT(ui16MsgCtrl, TXRQST_BIT);
            /*
             * Set the data length since this is set for all transfers. This is also a
             * single transfer and not a FIFO transfer so set EOB bit.
             */
            ui16MsgCtrl |= (PduInfo->length & FOUR_BIT_MASK);
            /*
             * Mark this as the last entry if this is not the last entry in a FIFO.
             */
            SET_BIT(ui16MsgCtrl,EOB_BIT);
            /*
             * Configure the Arbitration registers.
             */
            if(Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanIdType == ID_EXTENDED)
            {
                /*
                 * Set the 29 bit version of the Identifier for this message object.
                 */
                registers[Hth].ui16ArbReg0 = (uint16)(PduInfo->id);
                registers[Hth].ui16ArbReg1 = (((uint16)(PduInfo->id) >> SIXTEEN) & THIRTEEN_BIT_MASK);
                /*
                 * Mark the message as valid and set the extended ID bit.
                 */
                SET_BIT(registers[Hth].ui16ArbReg1,MSGVAL_BIT);
                SET_BIT(registers[Hth].ui16ArbReg1,XTD_BIT);
            }
            else
            {
                /*
                 * Set the 11 bit version of the Identifier for this message object.
                 * The lower 18 bits are set to zero.
                 */
                registers[Hth].ui16ArbReg0 = ZERO;
                registers[Hth].ui16ArbReg1 = (((uint16)(PduInfo->id) << TWO) & THIRTEEN_BIT_MASK);
                /*
                 * Mark the message as valid.
                 */
                SET_BIT(registers[Hth].ui16ArbReg1,MSGVAL_BIT);
            }
            /*
             * Write the data out to the CAN Data registers
             */
            uint32 Data_Index, Data_Value;
            uint32 Data_REG;
            Data_REG = (CAN_IF1DA1_OFFSET);
            for(Data_Index = ZERO; Data_Index < PduInfo->length ;)
            {
                Data_Value =PduInfo->sdu[Data_Index++];
                if(Data_Index < PduInfo->length)
                {
                    (Data_Value) |= PduInfo->sdu[Data_Index++] << EIGHT_BITS;
                }
                else
                {
                    /*MISRA*/
                }
                REG_VAL(CAN0_BASE,Data_REG) = (uint16)Data_Value;
                Data_REG+=FOUR;
            }


            /*
             * Enable:
             *         1) Transmit Interrupts
             *         2) Use Mask Filter
             *         3) Set direction of Transmission
             */
            SET_BIT(ui16MsgCtrl,TXIE_BIT);
            SET_BIT(ui16MsgCtrl,UMASK_BIT);


            /*
             * -Write out the registers to program the message object.
             * -Using the structure used in the INIT for configuring and transmitting
             *   by pushing the value saved in the registers during the INIT into the interface registers
             */
            registers[Hth].ui16MsgCtrl = ui16MsgCtrl | registers[Hth].ui16MsgCtrl;
            REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET) = registers[Hth].ui16CmdMaskReg;
            REG_VAL(CAN0_BASE, CAN_IF1MSK1_OFFSET) = registers[Hth].ui16MaskReg0;
            REG_VAL(CAN0_BASE, CAN_IF1MSK2_OFFSET) = registers[Hth].ui16MaskReg1;
            REG_VAL(CAN0_BASE, CAN_IF1ARB1_OFFSET) = registers[Hth].ui16ArbReg0;
            REG_VAL(CAN0_BASE, CAN_IF1ARB2_OFFSET) = registers[Hth].ui16ArbReg1;
            REG_VAL(CAN0_BASE, CAN_IF1MCTL_OFFSET) = registers[Hth].ui16MsgCtrl;
            /*
             * Transfer the message object to the message object specified by Hoh ID
             */
            SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET),DIR_BIT);
            REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET) = ((Object_Check[Can_Controller_ID][Hth][ZERO].mailbox) & SIX_BIT_MASK);
            /* Wait for busy bit to clear */
            while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
            {
                /*Do Nothing*/
            }
            Object_Check[Can_Controller_ID][Hth][ZERO].Check = Unconfirmed;
            return E_OK;
        }
        /*Basic CAN*/
        else if (BASIC == Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanHandleType)
        {
            uint8 ObjectCount_Iter;
            for (ObjectCount_Iter = ZERO ; ObjectCount_Iter<=Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanHardwareObjectCount - ONE; ObjectCount_Iter++)
            {
                if( Confirmed == Object_Check[Can_Controller_ID][Hth][ObjectCount_Iter].Check)
                {
                    Object_Check[Can_Controller_ID][Hth][ObjectCount_Iter].Check = Unconfirmed;
                    /*
                     * Initialize the values to a known state before filling them in based on
                     * the type of message object that is being configured.
                     */
                    uint16 ui16MsgCtrl = ZERO;

                    /*
                     * Set the TXRQST bit and the reset the rest of the register.
                     */
                    SET_BIT(ui16MsgCtrl, TXRQST_BIT);
                    /*
                     * Set the data length since this is set for all transfers. This is also a
                     * single transfer and not a FIFO transfer so set EOB bit.
                     */
                    ui16MsgCtrl |= (PduInfo->length & FOUR_BIT_MASK);
                    /*
                     * Mark this as the last entry if this is not the last entry in a FIFO.
                     */
                    SET_BIT(ui16MsgCtrl,EOB_BIT);
                    /*
                     * Configure the Arbitration registers.
                     */
                    if(Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanIdType == ID_EXTENDED)
                    {
                        /*
                         * Set the 29 bit version of the Identifier for this message object.
                         */
                        registers[Hth].ui16ArbReg0 = (uint16)(PduInfo->id);
                        registers[Hth].ui16ArbReg1 = (((uint16)(PduInfo->id) >> SIXTEEN) & THIRTEEN_BIT_MASK);
                        /*
                         * Mark the message as valid and set the extended ID bit.
                         */
                        SET_BIT(registers[Hth].ui16ArbReg1,MSGVAL_BIT);
                        SET_BIT(registers[Hth].ui16ArbReg1,XTD_BIT);
                    }
                    else
                    {
                        /*
                         * Set the 11 bit version of the Identifier for this message object.
                         * The lower 18 bits are set to zero.
                         */
                        registers[Hth].ui16ArbReg0 = ZERO;
                        registers[Hth].ui16ArbReg1 = (((uint16)(PduInfo->id) << TWO) & THIRTEEN_BIT_MASK);
                        /*
                         * Mark the message as valid.
                         */
                        SET_BIT(registers[Hth].ui16ArbReg1,MSGVAL_BIT);
                    }
                    /*
                     * Write the data out to the CAN Data registers
                     */
                    uint32 Data_Index, Data_Value;
                    uint32 Data_REG;
                    Data_REG = (CAN_IF1DA1_OFFSET);
                    for(Data_Index = ZERO; Data_Index < PduInfo->length ;)
                    {
                        Data_Value =PduInfo->sdu[Data_Index++];
                        if(Data_Index < PduInfo->length)
                        {
                            (Data_Value) |= PduInfo->sdu[Data_Index++] << EIGHT_BITS;
                        }
                        else
                        {
                            /*MISRA*/
                        }
                        REG_VAL(CAN0_BASE,Data_REG) = (uint16)Data_Value;
                        Data_REG+=FOUR;
                    }
                    /*
                     * Enable:
                     *         1) Transmit Interrupts
                     *         2) Use Mask Filter
                     *         3) Set direction of Transmission
                     */
                    SET_BIT(ui16MsgCtrl,TXIE_BIT);
                    SET_BIT(ui16MsgCtrl,UMASK_BIT);


                    /*
                     * -Write out the registers to program the message object.
                     * -Using the structure used in the INIT for configuring and transmitting
                     *   by pushing the value saved in the registers during the INIT into the interface registers
                     */
                    registers[Hth].ui16MsgCtrl = ui16MsgCtrl | registers[Hth].ui16MsgCtrl;
                    REG_VAL(CAN0_BASE, CAN_IF1CMSK_OFFSET) = registers[Hth].ui16CmdMaskReg;
                    REG_VAL(CAN0_BASE, CAN_IF1MSK1_OFFSET) = registers[Hth].ui16MaskReg0;
                    REG_VAL(CAN0_BASE, CAN_IF1MSK2_OFFSET) = registers[Hth].ui16MaskReg1;
                    REG_VAL(CAN0_BASE, CAN_IF1ARB1_OFFSET) = registers[Hth].ui16ArbReg0;
                    REG_VAL(CAN0_BASE, CAN_IF1ARB2_OFFSET) = registers[Hth].ui16ArbReg1;
                    REG_VAL(CAN0_BASE, CAN_IF1MCTL_OFFSET) = registers[Hth].ui16MsgCtrl;
                    /*
                     * Transfer the message object to the message object specified by Hoh ID
                     */
                    SET_BIT(REG_VAL(CAN0_BASE,CAN_IF1ARB2_OFFSET),DIR_BIT);
                    REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET) = ((Object_Check[Can_Controller_ID][Hth][ObjectCount_Iter].mailbox) & SIX_BIT_MASK);
                    /* Wait for busy bit to clear */
                    while(BIT_IS_SET(REG_VAL(CAN0_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
                    {
                        /*Do Nothing*/
                    }
                    return E_OK;
                }
                else
                {
                    /*Do Nothing*/
                }
                /*No Free Mailbox*/
                if (ObjectCount_Iter == Can_Configuration.CanConfigSet.CanHardwareObject[Hth].CanHardwareObjectCount)
                {
                    return CAN_BUSY;
                }
                else
                {
                    /*Do Nothing*/
                }
            }
        }
        /*No Free Mailbox*/
        else
        {
            return CAN_BUSY;
        }

#elif (CanConf_CAN1_CONTROLLER_ACTIVATION == STD_ON)

        /*
         * Initialize the values to a known state before filling them in based on
         * the type of message object that is being configured.
         */
        uint16 ui16MsgCtrl = ZERO;
        /* Wait for busy bit to clear */
        while(BIT_IS_SET(REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET),BUSY_BIT))
        {
            /*Do Nothing*/
        }
        /*
         * Set the TXRQST bit and the reset the rest of the register.
         */
        SET_BIT(ui16MsgCtrl, TXRQST_BIT);
        /* Single transmission*/
        if (Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[Hth-ONE].CanHardwareObjectCount == ONE)
        {
            /*
             * Set the data length since this is set for all transfers. This is also a
             * single transfer and not a FIFO transfer so set EOB bit.
             */
            ui16MsgCtrl |= (PduInfo->length & FOUR_BIT_MASK);
            /*
             * Mark this as the last entry if this is not the last entry in a FIFO.
             */
            SET_BIT(ui16MsgCtrl,EOB_BIT);
            /*
             * Write the data out to the CAN Data registers
             */
            uint32 Data_Index, Data_Value;
            uint32 Data_REG;
            Data_REG = (CAN_IF1DA1_OFFSET);
            for(Data_Index = ZERO; Data_Index < PduInfo->length ;)
            {
                Data_Value =PduInfo->sdu[Data_Index++];
                if(Data_Index < PduInfo->length)
                {
                    (Data_Value) |= PduInfo->sdu[Data_Index++] << EIGHT_BITS;
                }
                else
                {
                    /*Misra*/
                }
                REG_VAL(CAN1_BASE,Data_REG) = (uint16)Data_Value;
                Data_REG+=4;
            }
        }

        /*
         * Enable:
         *         1) Transmit Interrupts
         *         2) Use Mask Filter
         *         3) Set direction of Transmission
         */
        SET_BIT(ui16MsgCtrl,TXIE_BIT);
        SET_BIT(ui16MsgCtrl,UMASK_BIT);


        /*
         * -Write out the registers to program the message object.
         * -Using the structure used in the INIT for configuring and transmitting
         *   by pushing the value saved in the registers during the INIT into the interface registers
         */
        registers[Hth-ONE].ui16MsgCtrl = ui16MsgCtrl | registers[Hth-ONE].ui16MsgCtrl;
        REG_VAL(CAN1_BASE, CAN_IF1CMSK_OFFSET) = registers[Hth-ONE].ui16CmdMaskReg;
        REG_VAL(CAN1_BASE, CAN_IF1MSK1_OFFSET) = registers[Hth-ONE].ui16MaskReg0;
        REG_VAL(CAN1_BASE, CAN_IF1MSK2_OFFSET) = registers[Hth-ONE].ui16MaskReg1;
        REG_VAL(CAN1_BASE, CAN_IF1ARB1_OFFSET) = registers[Hth-ONE].ui16ArbReg0;
        REG_VAL(CAN1_BASE, CAN_IF1ARB2_OFFSET) = registers[Hth-ONE].ui16ArbReg1;
        REG_VAL(CAN1_BASE, CAN_IF1MCTL_OFFSET) = registers[Hth-ONE].ui16MsgCtrl;
        /*
         * Transfer the message object to the message object specified by Hoh ID
         */
        SET_BIT(REG_VAL(CAN1_BASE,CAN_IF1ARB2_OFFSET),DIR_BIT);
        REG_VAL(CAN1_BASE, CAN_IF1CRQ_OFFSET) = ((Can_Configuration.Controller[CAN1_CONTROLLER_ID].HOH[Hth-ONE].ID) & SIX_BIT_MASK);

        Message_Confirmation[Can_Controller_ID][Hth] = Unconfirmed;
        return E_OK;
#endif /*CanConf_CAN1_CONTROLLER_ACTIVATION*/
    }
}



/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf.c
 *
 * Description: Source file for Can Interface Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/*Include the module header file*/
#include "CanIf.h"
#include "CanIf_Cbk.h"

/* CanIf_GetTxPDU function prototype */
STATIC CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID);

/*Status variable to check if the module is initialized or not*/
CanIf_State CanIfCurrent_State = CANIF_UNINIT ;

/*Status variable which holds the state of the CANIF */
Can_ControllerStateType CanIf_ControllerMode[CAN_CONTROLLERS_NUMBER];

/*Status variable which holds the state of the PDU channel */
CanIf_PduModeType CanIf_ChannelPduMode[CAN_CONTROLLERS_NUMBER];

/*An array to map the HRH to the HOH*/
uint8 HOH_HRH_MAP[HRH_NUMBER];


/************************************************************************************
 * Service name:CanIf_GetTxPDU
 * Syntax :CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID)
 * Parameters(in): PduIdType TxPDU_ID
 * Return value :Address of CanIfTxPduCfg
 * Description : Get the CanIfTxPduCfg from the TxPDU ID
 *************************************************************************************/
CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID)
{
    /*Check if the ID of the transmitted PDU exceeds the max number of configured IDs or not*/
    if(TxPDU_ID<CanIfMaxTxPduCfg)
    {
        return (CanIfTxPduCfg*)&CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TxPDU_ID];
    }
    else
    {
        return NULL_PTR;
    }
}

/************************************************************************************
 * Service Name: CanIf_Init
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ConfigPtr - Pointer to configuration parameter set.
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize internal and external interfaces of the
 *              CAN Interface for the further processing
 ************************************************************************************/
void CanIf_Init(const CanIf_ConfigType* ConfigPtr)
{

    /* check if the input configuration pointer is not a NULL_PTR */
    if (NULL_PTR == ConfigPtr)
    {
#if(CanIfDevErrorDetect == STD_ON)
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_INIT_SID, CANIF_E_PARAM_POINTER);
#endif
    }
    else
    {

        /* Variable used in for loop */
        uint8 count;

        /*
         * [SWS_CANIF_00085]The service CanIf_Init() shall initialize the global variables
         *  and data structures of the CanIf including flags and buffers.
         */

        /* check if the module is initialized or not */
        if (CANIF_UNINIT == CanIfCurrent_State)
        {

#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
            /* A loop to clear the RX Notification flags */
            for(count =ZERO; count < CanIfMaxRxPduCfg ; count++)
            {
                CanIf_RxNotificationFlag[count]= CANIF_NO_NOTIFICATION;

            }
#endif

#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
            /*A loop to clear the TX Notification flags */
            for(count =ZERO; count < CanIfMaxTxPduCfg ; count++)
            {
                CanIf_TxNotificationFlag[count]= CANIF_NO_NOTIFICATION;
            }
#endif
            /* [SWS_CANIF_00001] The CanIf expects that the CAN Controller remains in STOPPED mode like after power-on reset
             * after the initialization process has been completed.
             *  In this mode the CanIf and CanDrv are neither able to transmit nor receive CAN L-PDUs
             */

            /* [SWS_CANIF_00864] During initialization CanIf shall switch
             * every channel to CANIF_OFFLINE.
             */
            for(count=ZERO ; count < CAN_CONTROLLERS_NUMBER ; count++)
            {
                /*initialization CanIf_ControllerMode with CAN_CS_STOPPED*/
                CanIf_ControllerMode[count] = CAN_CS_STOPPED;
                /*initialization CanIf_ChannelPduMode with CANIF_OFFLINE*/
                CanIf_ChannelPduMode[count] = CANIF_OFFLINE;
            }
        }
        else
        {
            /*MISRA: Do Nothing*/
        }

        /*Mapping between HRH & HOH */
        uint8 HRH_INDEX=ZERO;
        for (count = ZERO ; count < CAN_HOH_NUMBER ; count++)
        {
            if (Can_Configuration.CanConfigSet.CanHardwareObject[count].CanObjectType == RECIEVE)
            {
                HOH_HRH_MAP[HRH_INDEX] = count;
                HRH_INDEX++;
            }
            else
            {
                /*MISRA: Do Nothing*/
            }
        }
        /* the CanIF module is initialized and ready */
        CanIfCurrent_State = CANIF_READY;
    }
}

/************************************************************************************
 * Service Name: CanIf_DeInit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to De-initialize the CanIf module.
 ************************************************************************************/
void CanIf_DeInit(void)
{
    /* Variable used in for loop */
    uint8 count ;
    /* De-initializing the Controllers and  setting the channel modes to CANIF_OFFLINE */
    for(count=ZERO ; count < CAN_CONTROLLERS_NUMBER ; count++)
    {
        /* set the CanIf controller state to CAN_CS_UNINIT state */
        CanIf_ControllerMode[count] = CAN_CS_UNINIT;
        /* set the CanIf channel PDU states to CANIF_OFFLINE state */
        CanIf_ChannelPduMode[count] = CANIF_OFFLINE;
    }
    /* set the CanIf state to UNINIT state */
    CanIfCurrent_State = CANIF_UNINIT ;
}

/************************************************************************************
 * Service Name: CanIf_Transmit
 * Service ID[hex]: 0x49
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 * Parameters (in): TxPduId - Identifier of the PDU to be transmitted
 *                  PduInfoPtr - Length of and pointer to the PDU data and pointer
 *                               to MetaData.
 * Parameters (in): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Transmit request has been accepted.
 *                                E_NOT_OK: Transmit request hasn't been accepted
 * Description: Function to Request transmission of a PDU.
 ************************************************************************************/
Std_ReturnType CanIf_Transmit(PduIdType TxPduId,const PduInfoType* PduInfoPtr)
{
    /* Variable used to get the CANID of the TxPDU */
    uint32 TxPDU_CanID ;
    /*Variable to store the return value of canif transmit function*/
    Std_ReturnType CanIf_Transmit_Return;
    /*Variable to store the return value of can write function*/
    Std_ReturnType Can_Write_Return;
    /*Variable to store info of PDU*/
    Can_PduType Can_PduData;
    /*Pointer to CanIfTxPduCfg container  */
    CanIfTxPduCfg* TxPDU =  NULL_PTR;
    /*Get the TxPDU from the TxPduId passed to the function*/
    TxPDU = CanIf_GetTxPDU(TxPduId);
    /*Get the ControllerId : CAN0 OR CAN1 */
    uint8 ControllerId = TxPDU->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthCanCtrlIdRef->CanIfCtrlCanCtrlRef->CanControllerId;
    /*Get the CanIfTxPduCanIdType:EXTENDED_CAN OR EXTENDED_FD_CAN OR STANDARD_CAN OR STANDARD_FD_CAN */
    CanIfTxPduCanIdType Pdu_CanId_Type = TxPDU->CanIfTxPduCanIdType;


    /* Check if the module is initialized or not*/
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID, CANIF_E_UNINIT);
        /*Make the return value of the function be E_NOT_OK*/
        CanIf_Transmit_Return = E_NOT_OK;
#endif
    }

    /* [SWS_CANIF_00319] If parameter TxPduId of CanIf_Transmit() has an invalid
     * value, CanIf shall report development error code CANIF_E_INVALID_TXPDUID to
     * the Det_ReportError service of the DET, when CanIf_Transmit() is called
     */
    else if (TxPduId > CanIfMaxTxPduCfg )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID,  CANIF_E_INVALID_TXPDUID );
        /*Make the return value of the function be E_NOT_OK*/
        CanIf_Transmit_Return = E_NOT_OK;
#endif
    }

    /* [SWS_CANIF_00320] d If parameter PduInfoPtr of CanIf_Transmit() has an
     * invalid value, CanIf shall report development error code CANIF_E_PARAM_POINTER
     * to the Det_ReportError service of the DET module, when CanIf_Transmit()
     * is called.
     */
    else if(   NULL_PTR== PduInfoPtr  )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID, CANIF_E_PARAM_POINTER);
        /*Make the return value of the function be E_NOT_OK*/
        CanIf_Transmit_Return = E_NOT_OK;
#endif
    }

    /* [SWS_CANIF_00893] d When CanIf_Transmit() is called with PduInfoPtr-
     * >SduLength exceeding the maximum length of the PDU referenced by TxPduId:
     *  SduLength > 8 if the Can_IdType indicates a classic CAN frame
     *  SduLength > 64 if the Can_IdType indicates a CAN FD frame
     * CanIf shall report runtime error code CANIF_E_DATA_LENGTH_MISMATCH to the
     * Det_ReportRuntimeError() service of the DET.
     */
    else if((Pdu_CanId_Type ==STANDARD_CAN )||(Pdu_CanId_Type ==EXTENDED_CAN ))
    {
        /*check if PduInfoPtr->SduLength exceeding the maximum length of the PDU referenced by TxPduId */
        if(PduInfoPtr->SduLength >CANNIF_STANDARD_MAX_SDU_Length)
        {
#if( CanIfDevErrorDetect == STD_ON  )
            Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID, CANIF_E_DATA_LENGTH_MISMATCH);
            /*Make the return value of the function be E_NOT_OK*/
            CanIf_Transmit_Return = E_NOT_OK;
#endif
        }
    }

    else if((Pdu_CanId_Type ==STANDARD_FD_CAN )||(Pdu_CanId_Type ==EXTENDED_FD_CAN ))
    {
        /*check if PduInfoPtr->SduLength exceeding the maximum length of the PDU referenced by TxPduId */
        if(PduInfoPtr->SduLength >CANNIF_FD_MAX_SDU_Length)
        {
#if( CanIfDevErrorDetect == STD_ON  )
            Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID, CANIF_E_DATA_LENGTH_MISMATCH);
            /*Make the return value of the function be E_NOT_OK*/
            CanIf_Transmit_Return = E_NOT_OK;
#endif
        }
    }

    /*
     * [SWS_CANIF_00900] When CanIf_Transmit() is called with PduInfoPtr->SduLength
     * exceeding the maximum length of the PDU referenced by TxPduId
     * and CanIfTxPduTruncation is disabled, CanIf shall report the runtime error
     * CANIF_E_TXPDU_LENGTH_EXCEEDED and return E_NOT_OK without further actions.
     */
    else if((PduInfoPtr->SduLength > CANIF_MAX_PDU_Length) && (TxPDU->CanIfTxPduTruncation == FALSE))   /* how to use the TX PDUID to get the max Pdu length  ???*/
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TRANSMIT_SID, CANIF_E_TXPDU_LENGTH_EXCEEDED);
        /*Make the return value of the function be E_NOT_OK*/
        CanIf_Transmit_Return = E_NOT_OK;
#endif
    }
    else
    {

        /* [SWS_CANIF_00317]  The service CanIf_Transmit() shall not accept a transmit request,
         *  if the controller mode referenced by ControllerId is different to
         *  CAN_CS_STARTED and the channel mode at least for the transmit path is not online
         *  or offline active.
         */
        if((CanIf_ControllerMode[ControllerId]!=CAN_CS_STARTED) && ((CanIf_ChannelPduMode[ControllerId] != CANIF_ONLINE) || (CanIf_ChannelPduMode[ControllerId] != CANIF_TX_OFFLINE_ACTIVE) ))
        {
            /*Make the return value of the function be E_NOT_OK*/
            CanIf_Transmit_Return = E_NOT_OK;
        }
        else
        {



            /*Assign the HTH that will be passed to Can_write from the TxPDU Paramter*/
            Can_HwHandleType Hth = TxPDU->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthIdSymRef->CanObjectId;

            /* [SWS_CANIF_00318] CanIf_Transmit() shall call Can_Write() with the hardware transmit handle corresponding
             *  to the provided TxPduId and a Can_PduType structure where:
             *  swPduHandle is set to the CanTxPduId used in the corresponding CanIf_TxConfirmation() call
             *  length is set to the value provided as PduInfoPtr->SduLength, possibly reduced according to [SWS_CANIF_00894]
             *  id is set to the CAN ID associated with the TxPduId
             *  sdu is set to the pointer provided as PduInfoPtr->SduDataPtr
             */

            /* [SWS_CANIF_00243]  CanIf shall set the two most significant bits (’IDentifier Extension flag’ and ’CAN FD flag’)
             *  of the CanId (PduInfoPtr->id) before CanIf passes the predefined CanId to CanDrv at call of Can_Write()
             * The CanId format type of each CAN L-PDU can be configured by CanIfTxPduCanIdType, refer to CanIfTxPduCanIdType
             */

            /*  TxPDU->CanIfTxPduCanId is used to get the CANID of the PDU */
            TxPDU_CanID = TxPDU->CanIfTxPduCanId;
            if(TxPDU->CanIfTxPduCanIdType == STANDARD_CAN)
            {
                TxPDU_CanID =   TxPDU_CanID | TWO_MSB_STANDARD_MASK ;
            }
            else if(TxPDU->CanIfTxPduCanIdType == EXTENDED_CAN)
            {
                TxPDU_CanID =   TxPDU_CanID | TWO_MSB_EXTENDED_MASK ;
            }
            else
            {
                /*MISRA: Do Nothing*/
            }
            /*Storing the ID of the TxPDU*/
            Can_PduData.id = TxPDU_CanID;

            /*
             * [SWS_CANIF_00894] When CanIf_Transmit() is called with PduInfoPtr->SduLength
             * exceeding the maximum length of the PDU referenced by TxPduId and
             * CanIfTxPduTruncation is enabled, CanIf shall transmit as much data as possible
             * and discard the rest.
             */
            if((PduInfoPtr->SduLength > CANIF_MAX_PDU_Length) && (TxPDU->CanIfTxPduTruncation == TRUE))
            {
                /*Storing the length of the TxPDU*/
                Can_PduData.length = CANIF_MAX_PDU_Length;
            }
            else
            {
                /*Storing the length of the TxPDU*/
                Can_PduData.length = PduInfoPtr->SduLength;
            }
            /*Make the SDU pointer point on the same address/data as SduDataPtr */
            Can_PduData.sdu = PduInfoPtr->SduDataPtr;
            /*store TxPDU ID in Can_PduData.swPduHandle variable */
            Can_PduData.swPduHandle = TxPduId;

            /*Assigning the variables passed by the function to the Can_PduType variable to pass it to the Can_Write */
            Can_Write_Return = Can_Write(Hth, &Can_PduData);
            if (Can_Write_Return == E_OK)
            {
                /*Make the return value of the function be E_OK*/
                CanIf_Transmit_Return = E_OK;
            }
            else
            {
                /*Make the return value of the function be E_NOT_OK*/
                CanIf_Transmit_Return = E_NOT_OK;
            }
        }
    }
    return CanIf_Transmit_Return;
}



/************************************************************************************
 * Service Name: CanIf_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant (Not for the same controller)
 * Parameters (in): ControllerId - Abstracted CanIf ControllerId which is assigned to a
 *                                 CAN controller, which is requested for mode transition.
 *                  ControllerMode - Requested mode transition
 * Parameters (in): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Controller mode request has been accepted
 *                                E_NOT_OK: Controller mode request hasn't been accepted
 * Description: Function to call the corresponding CAN Driver service for changing of
                the CAN controller mode.
 ************************************************************************************/
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{
    /*variable to store the state of the ControllerMode function*/
    Can_ControllerStateType Requested_Mode ;
    /*variable to store the return value of CanIf_SetControllerMode function */
    Std_ReturnType Can_SetControllerMode_return ;

    /* Check if the module is initialized or not*/
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_CONTROLLER_MODE_SID, CANIF_E_UNINIT);
        Can_SetControllerMode_return = E_NOT_OK;
#endif
    }
    /* Check if the Controller ID is greater than the number of configured controllers*/
    else if (ControllerId >= CAN_CONTROLLERS_NUMBER)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_CONTROLLER_MODE_SID,  CANIF_E_PARAM_CONTROLLERID );
        Can_SetControllerMode_return = E_NOT_OK;
#endif
    }
    /* Check If parameter ControllerMode has an invalid value*/
    else if (  (ControllerMode !=CAN_CS_STARTED) && (ControllerMode !=CAN_CS_STOPPED) && (ControllerMode !=CAN_CS_SLEEP) )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_CONTROLLER_MODE_SID,  CANIF_E_PARAM_CTRLMODE );
        Can_SetControllerMode_return = E_NOT_OK;
#endif
    }
    else
    {
        switch (ControllerMode)
        {
        case CAN_CS_STOPPED :

            /* [SWS_CANIF_00866] If CanIf_SetControllerMode(ControllerId,
             * CAN_CS_STOPPED) or CanIf_ControllerBusOff(ControllerId) is called,
             * CanIf shall set the PDU channel mode of the corresponding channel to
             * CANIF_TX_OFFLINE.
             */
            Requested_Mode =CAN_CS_STOPPED;
            CanIf_ChannelPduMode[ControllerId] = CANIF_TX_OFFLINE;
            Can_SetControllerMode_return = Can_SetControllerMode( ControllerId , Requested_Mode );
            if(Can_SetControllerMode_return == E_OK)
            {
                CanIf_ControllerMode[ControllerId] = CAN_CS_STOPPED;
            }
            else
            {
                /* MISRA:Do Nothing */
            }
            break;
        case CAN_CS_STARTED:
            /*Store the new required mode in the variable*/
            Requested_Mode =CAN_CS_STARTED;
            /*Call Can_SetControllerMode function with the required mode */
            Can_SetControllerMode_return = Can_SetControllerMode( ControllerId , Requested_Mode );
            /*Check if the return value of Can_SetControllerMode is OK or not */
            if(Can_SetControllerMode_return == E_OK)
            {
                /*If the condition is true , update the mode of CanIf_ControllerMode*/
                CanIf_ControllerMode[ControllerId] = CAN_CS_STARTED;
            }
            else
            {
                /*MISRA:Do Nothing */
            }
            break;
        }
    }
    return Can_SetControllerMode_return;
}

/************************************************************************************
 * Service Name: CanIf_ReadTxNotifStatus
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): CanIfTxSduId - L-SDU handle to be transmitted.
                                   This handle specifies the corresponding CAN LSDU ID and implicitly
                                   the CAN Driver instance as
                                   well as the corresponding CAN controller device.
 * Parameters (in): None
 * Parameters (out): None
 * Return value: CanIf_NotifStatusType - Current confirmation status of the corresponding
 *                                       CAN Tx L-PDU.
 *
 * Description: Function to  return the confirmation status (confirmation occurred or
                not) of a specific static or dynamic CAN Tx L-PDU, requested by the
                CanIfTxSduId.
 ************************************************************************************/
#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
CanIf_NotifStatusType CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId)
{
    /*Variable to store the return value of CAN L-PDU notification status */
    CanIf_NotifStatusType ReturnState = CANIF_NO_NOTIFICATION ;
    /* Check if the module is initialized or not*/
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_ReadTxNotifStatus_SID, CANIF_E_UNINIT);
#endif
    }
    /* [SWS_CANIF_00331] d If parameter CanIfTxSduId of
       CanIf_ReadTxNotifStatus() is out of range or if no status information was
       configured for this CAN Tx L-SDU, CanIf shall report development error code
       CANIF_E_INVALID_TXPDUID to the Det_ReportError service of the DET
       when CanIf_ReadTxNotifStatus() is called.
     */

    if (CanIfTxSduId > CanIfMaxTxPduCfg )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_ReadTxNotifStatus_SID,  CANIF_E_INVALID_TXPDUID );
#endif
    }
    else
    {
        /*Pointer to point on the configuration (parameters) of a transmit CAN L-PDU  */
        const CanIfTxPduCfg *TxPDU_ptr = NULL_PTR;
        /* store the init parameters of the CAN Interface in TxPDU_ptr */
        TxPDU_ptr = &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[CanIfTxSduId];

        /* [SWS_CANIF_00393] d If configuration parameters
       CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API (ECUC_CanIf_00609) and
       CANIF_TXPDU_READ_NOTIFYSTATUS (ECUC_CanIf_00589) for the transmitted
       L-SDU are set to TRUE, and if CanIf_ReadTxNotifStatus() is called, the CanIf
       shall reset the notification status for the transmitted L-SDU.
         */
        if(TxPDU_ptr->CanIfTxPduReadNotifyStatus == TRUE)
        {
            /*Check if The requested Tx CAN L-PDU was successfully transmitted .*/
            if(CANIF_TX_RX_NOTIFICATION == CanIf_TxNotificationFlag[CanIfTxSduId])
            {
                /*Make the return value of CAN L-PDU notification status equals CANIF_TX_RX_NOTIFICATION. */
                ReturnState = CANIF_TX_RX_NOTIFICATION ;
                /*Reset the notification status for the transmitted L-SDU*/
                CanIf_TxNotificationFlag[CanIfTxSduId]= CANIF_NO_NOTIFICATION;
            }
            else
            {
                /*No transmit event occurred for the requested L-PDU.*/
                ReturnState = CANIF_NO_NOTIFICATION ;
            }
        }
        else
        {
            /*No transmit event occurred for the requested L-PDU.*/
            ReturnState = CANIF_NO_NOTIFICATION ;
        }
    }
    return ReturnState;
}
#endif /*CanIfPublicReadTxPduNotifyStatusApi */

/************************************************************************************
 * Service Name: CanIf_SetPduMode
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): ControllerId - All PDUs of the own ECU connected to the corresponding
 *                                 CanIf ControllerId, which is assigned to a physical
 *                                 CAN controller are addressed.
 *                  PduModeRequest - Requested PDU mode change.
 * Parameters (in): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Request for mode transition has been accepted.
 *                                E_NOT_OK:  Request for mode transition hasn't been accepted
 * Description: Function to set the requested mode at the L-PDUs of a predefined logical
 *              PDU channel.
 ************************************************************************************/
Std_ReturnType CanIf_SetPduMode(uint8 ControllerId,CanIf_PduModeType PduModeRequest)
{
    /*variable to store the return value of CanIf_SetPduMode function */
    Std_ReturnType ReturnState;

    /*check if the module is initialized or not */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_PDU_MODE_SID, CANIF_E_UNINIT);
        /*Make the return value of the function be E_NOT_OK*/
        ReturnState = E_NOT_OK;
#endif
    }

    /* [SWS_CANIF_00341] d If CanIf_SetPduMode() is called with invalid ControllerId,
     *  CanIf shall report development error code CANIF_E_PARAM_CONTROLLERID
     *  to the Det_ReportError service of the DET module.
     */
    else if (ControllerId >= CAN_CONTROLLERS_NUMBER)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_PDU_MODE_SID,  CANIF_E_PARAM_CONTROLLERID );
        /*Make the return value of the function be E_NOT_OK*/
        ReturnState = E_NOT_OK;
#endif
    }

    /* [SWS_CANIF_00860] d If CanIf_SetPduMode() is called with invalid PduModeRequest,
     * CanIf shall report development error code CANIF_E_PARAM_PDU_MODE
     * to the Det_ReportError service of the DET module.
     */
    else if ((PduModeRequest != CANIF_OFFLINE) && (PduModeRequest != CANIF_TX_OFFLINE) && (PduModeRequest != CANIF_TX_OFFLINE_ACTIVE) && (PduModeRequest != CANIF_ONLINE))
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_PDU_MODE_SID,  CANIF_E_PARAM_PDU_MODE );
        /*Make the return value of the function be E_NOT_OK*/
        ReturnState = E_NOT_OK;
#endif
    }
    else
    {
        /* [SWS_CANIF_00874] d The service CanIf_SetPduMode() shall not accept any request and shall return E_NOT_OK,
         *  if the controller mode referenced by ControllerId is not in state CAN_CS_STARTED.
         */
        if(CanIf_ControllerMode[ControllerId] != CAN_CS_STARTED)
        {
            /* if the mode is not the started mode , make the return value of the function be E_NOT_OK*/
            ReturnState = E_NOT_OK;
        }
        else
        {
            /*Update CanIf_ChannelPduMode with the required mode */
            CanIf_ChannelPduMode[ControllerId] = PduModeRequest ;
            /*Make the return value of the function be E_OK*/
            ReturnState = E_OK;
        }
    }
    return ReturnState;
}

/************************************************************************************
 * Service Name: CanIf_ReadRxNotifStatus
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): CanIfRxSduId - Receive L-SDU handle specifying the correspondoing
 *                                 CAN L-SDU ID and implicitly the CAN Driver instance as well
 *                                 as the corresponding CAN controller device.
 * Parameters (in): None
 * Parameters (out): None
 * Return value: CanIf_NotifStatusType - Current indication status of the corresponding CAN
 *                                       Rx L-PDU.
 * Description: Function to return the indication status (indication occurred or not) of a
 *              specific CAN Rx L-PDU, requested by the CanIfRxSduId.
 ************************************************************************************/
#if(STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
CanIf_NotifStatusType CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId)
{
    /*Variable to store the return value of CAN L-PDU notification status */
    CanIf_NotifStatusType ReturnState = CANIF_NO_NOTIFICATION ;
    /*check if the module is initialized or not */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_ReadRxNotifStatus_SID, CANIF_E_UNINIT);
#endif
    }
    /*
     * [SWS_CANIF_00336] d If parameter CanIfRxSduId of
     * CanIf_ReadRxNotifStatus() is out of range or if status for CanRxPduId
     * was requested whereas CANIF_READRXPDU_DATA_API is disabled or if no status
     * information was configured for this CAN Rx L-SDU, CanIf shall report development
     * error code CANIF_E_INVALID_RXPDUID to the Det_ReportError service of
     * the DET, when CanIf_ReadRxNotifStatus() is called. c(SRS_BSW_00323)
     */

    else if (CanIfRxSduId > CanIfMaxRxPduCfg )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_ReadTxNotifStatus_SID,  CANIF_E_INVALID_RXPDUID );
#endif
    }
    else
    {

        /*Pointer to point on the configuration (parameters) of a received CAN L-PDU  */
        const CanIfRxPduCfg *RxPDU_ptr = NULL_PTR;
        /* store the init parameters of the CAN Interface in RxPDU_ptr */
        RxPDU_ptr = &CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[CanIfRxSduId];

        /*
         * [SWS_CANIF_00394] d If configuration parameters
         * CANIF_PUBLIC_READRXPDU_NOTIFY_STATUS_API (ECUC_CanIf_00608) and
         * CANIF_RXPDU_READ_NOTIFYSTATUS (ECUC_CanIf_00595) are set to TRUE, and
         * if CanIf_ReadRxNotifStatus() is called, then CanIf shall reset the notification
         * status for the received L-SDU.
         */
        if(RxPDU_ptr->CanIf_RxPduReadNotifyStatus == TRUE)
        {
            /*Check if The requested Rx CAN L-PDU was successfully received.*/
            if(CANIF_TX_RX_NOTIFICATION == CanIf_RxNotificationFlag[CanIfRxSduId])
            {
                /*Make the return value of CAN L-PDU notification status equals CANIF_TX_RX_NOTIFICATION. */
                ReturnState = CANIF_TX_RX_NOTIFICATION ;
                /*Reset the notification status for the transmitted L-SDU*/
                CanIf_RxNotificationFlag[CanIfRxSduId]= CANIF_NO_NOTIFICATION;
            }
            else
            {
                /*No  receive event occurred for the requested L-PDU.*/
                ReturnState = CANIF_NO_NOTIFICATION ;
            }
        }
        else
        {
            /*No receive event occurred for the requested L-PDU.*/
            ReturnState = CANIF_NO_NOTIFICATION ;
        }
    }
    return ReturnState;
}
#endif /*CanIfPublicReadRxPduNotifyStatusApi */

/************************************************************************************
 * Service Name: CanIf_ReadRxPduData
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): CanIfRxSduId - Receive L-SDU handle specifying the correspondoing
 *                                 CAN L-SDU ID and implicitly the CAN Driver instance as well
 *                                 as the corresponding CAN controller device.
 * Parameters (inout): None
 * Parameters (out): CanIfRxInfoPtr - Contains the length (SduLength) of the received
 *                                    PDU, a pointer to a buffer (SduDataPtr) containing
 *                                    the PDU, and the MetaData related to this PDU.
 * Return value: Std_ReturnType - E_OK: Request for L-SDU data has been accepted.
 *                                E_NOT_OK:  No valid data has been received
 * Description: Function to provide the Data Length and the received data of the
 *              requested CanIfRxSduId to the calling upper layer
 ************************************************************************************/
#if(STD_ON == CanIfPublicReadRxPduDataApi)
Std_ReturnType CanIf_ReadRxPduData(PduIdType CanIfRxSduId,PduInfoType* CanIfRxInfoPtr)
{
    /*variable to store the return value of CanIf_ReadRxPduData function */
    Std_ReturnType Return_Value;
    /*Variable to store the ID of the controller*/
    uint8 ControllerId = CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[CanIfRxSduId].CanIfRxPduHrhIdRef->CanIfHrhCanCtrlIdRef->CanIfCtrlId;
    /* check if the module is initialized or not */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READ_RX_PDU_DATA_SID, CANIF_E_UNINIT);
        /*Make the return value of the function be E_NOT_OK*/
        Return_Value = E_NOT_OK;
#endif
    }
    /*
     * [SWS_CANIF_00325] d If parameter CanIfRxSduId of CanIf_ReadRxPduData()
     * has an invalid value, e.g. not configured to be stored within CanIf via
     * CANIF_READRXPDU_DATA (ECUC_CanIf_00600), CanIf shall report development
     * error code CANIF_E_INVALID_RXPDUID to the Det_ReportError service of the
     * DET, when CanIf_ReadRxPduData() is called. c(SRS_BSW_00323)
     */
    else if (CanIfRxSduId > CanIfMaxRxPduCfg )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READ_RX_PDU_DATA_SID,  CANIF_E_INVALID_RXPDUID );
        /*Make the return value of the function be E_NOT_OK*/
        Return_Value = E_NOT_OK;
#endif
    }
    /*
     * [SWS_CANIF_00326] d If parameter CanIfRxInfoPtr of
     * CanIf_ReadRxPduData() has an invalid value, CanIf shall report development error code
     * CANIF_E_PARAM_POINTER to the Det_ReportError service of
     * the DET module, when CanIf_ReadRxPduData() is called. c(SRS_BSW_00323)
     */
    else  if (CanIfRxInfoPtr == NULL_PTR)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_READ_RX_PDU_DATA_SID,  CANIF_E_PARAM_POINTER);
        /*Make the return value of the function be E_NOT_OK*/
        Return_Value = E_NOT_OK;
#endif
    }
    else
    {
        /*
         * [SWS_CANIF_00324] The function CanIf_ReadRxPduData() shall not accept a
         * request and return E_NOT_OK, if the corresponding controller mode refrenced by ControllerId
         * is different to CAN_CS_STARTED and the channel mode is in the receive
         * path online.
         */
        if(CanIf_ControllerMode[ControllerId]!=CAN_CS_STARTED)
        {
            /*Make the return value of the function be E_NOT_OK*/
            Return_Value = E_NOT_OK;
        }
        else
        {
            /*MISRA:Do Nothing*/
        }
        /*
         * [SWS_CANIF_00329] d CanIf_ReadRxPduData() shall not be used for CanIfRxSduId,
         * which are defined to receive multiple CAN-Ids (range reception). c()
         */
        if (CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[CanIfRxSduId].CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType == BASIC)
        {
            /*Make the return value of the function be E_NOT_OK*/
            Return_Value = E_NOT_OK;
        }
        else

        {
            /*Read the data from CanIf Buffer*/
            if (CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[CanIfRxSduId].CanIf_RxPduReadData == TRUE)
            {
                /*Make the SduDataPtr pointer point on the same address/data as sdu */
                CanIfRxInfoPtr->SduDataPtr = CanIf_RxBuffer[CanIfRxSduId].sdu;
                /*Store the length of the received data from the buffer in CanIfRxInfoPtr->SduLength*/
                CanIfRxInfoPtr->SduLength = CanIf_RxBuffer[CanIfRxSduId].length;
                /*Make the return value of the function be E_OK*/
                Return_Value = E_OK;
            }
            else
            {
                /*MISRA:Do Nothing*/
            }
        }
    }
    return Return_Value;
}
#endif /*CanIfPublicReadRxPduDataApi*/

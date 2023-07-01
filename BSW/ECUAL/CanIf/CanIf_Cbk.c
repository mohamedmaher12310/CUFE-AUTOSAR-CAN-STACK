/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: CanIf_Cbk.c
 *
 * Description: Source file for CanIf Call Back.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
/* Include  CanIf Call Back Header file  */
#include "CanIf_Cbk.h"

/*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
CanIf_NotifStatusType CanIf_RxNotificationFlag[CanIfMaxRxPduCfg];
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/

/*Tx Notification Flags*/
#if (STD_ON == CanIfPublicReadTxPduNotifyStatusApi)
CanIf_NotifStatusType CanIf_TxNotificationFlag[CanIfMaxTxPduCfg];
#endif /*CanIfPublicReadTxPduNotifyStatusApi*/

/*CanIf Recieve Buffer (ReadAPI)*/
#if (STD_ON == CanIfPublicReadRxPduDataApi)
Can_PduType CanIf_RxBuffer[CanIfMaxRxPduCfg]={0};
Can_PduType Temp_Buffer;
#endif /*CanIfPublicReadRxPduDataApi*/

/************************************************************************************
 * Service Name: CanIf_RxIndication
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Mailbox - Identifies the HRH and its corresponding CAN Controller
 *                  PduInfoPtr - Pointer to the received L-PDU
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to indicate a successful reception of a received CAN Rx L-PDU
 *              to the CanIf after passing all filters and validation checks.
 ************************************************************************************/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType * PduInfoPtr)
{
    /*Pointer to  the received PDU*/
    CanIfRxPduCfg* RxPDU = NULL_PTR;
    /*Pointer to sub-container that define the range of PDUs that a specific HRH will support  */
    CanIfHrhRangeCfg* RxPDU_Range = NULL_PTR;
    /*Pointer to the HRH which RxPDU belongs to */
    const CanIfHrhCfg* HRH_Ptr = NULL_PTR;
    /*Index OR ID of received PDU*/
    uint8 RxPDU_index;
    /*Index of HOH*/
    uint8 HOH_index ;
    /*Index of HRH*/
    uint8 HRH_index ;


    /*
     * If CanIf was not initialized before calling CanIf_RxIndication(),
     * CanIf shall not execute Rx indication handling, when CanIf_RxIndication() is called.
     */
    /* Check if the module is initialized or not*/
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
 #if(STD_ON == CanIfDevErrorDetect)
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_UNINIT);

#endif
        }

    /*
     * If parameter Mailbox->Hoh of CanIf_RxIndication() has an invalid value,
     * CanIf shall report development error code
     */
    else if(Mailbox->Hoh > CAN_HOH_NUMBER)
    {
#if(STD_ON == CanIfDevErrorDetect)
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_HOH);
#endif
    }

    /*
     * If parameter Mailbox->CanId of CanIf_RxIndication() has an invalid value,
     * CanIf shall report development error code CANIF_E_PARAM_CANID to the Det_ReportError
     * service of the DET
     */
    else if ( (Mailbox->CanId > CANNIF_STANDARD_MAX) || (Mailbox->CanId >CANNIF_EXTENDED_MAX) )
    {
#if(STD_ON == CanIfDevErrorDetect)
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID);
#endif
        }
    /*
     * If parameter PduInfoPtr or Mailbox has an invalid value,
     * CanIf shall report development error code CANIF_E_PARAM_POINTER to
     * the Det_ReportError service of the DET module
     */
    else if( ( NULL_PTR == Mailbox) || ( NULL_PTR== PduInfoPtr)  )
    {
#if(STD_ON == CanIfDevErrorDetect)
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_POINTER);
#endif
    }
    else

    {
        /* Store the addresses to pointers*/
        /* CanIfRxPduCfg Container*/
        RxPDU = CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg;
        /*Index of Pdu*/
        uint8 RECEIVED_PDU_INDEX ;
        for( RECEIVED_PDU_INDEX=0; RECEIVED_PDU_INDEX< CanIfMaxRxPduCfg ;RECEIVED_PDU_INDEX++)
        {
            if (Mailbox->CanId == CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[RECEIVED_PDU_INDEX].CanIfRxPduCanId)
            {
                RxPDU_index = RECEIVED_PDU_INDEX;
                break;
            }
        }
        /* CanIfHrhCfg Container*/
        HRH_Ptr = CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[RxPDU_index].CanIfRxPduHrhIdRef;
        /*Index of Hoh*/
        HOH_index = (HRH_Ptr->CanIfHrhIdSymRef->CanObjectId);
        /*Index of Hrh*/
        uint8 iter;
        for (iter = ZERO; iter < HRH_NUMBER ; iter ++)
        {
            if (HOH_HRH_MAP[iter] == HOH_index)
            {
                HRH_index = iter;
                break;
            }
            else
            {
                /*MISRA :Do Nothing*/
            }
        }
        /*Use MACROS instead of variables*/
        /* CanIfHrhRangeCfg Container*/
        RxPDU_Range = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHrhCfg[HRH_index].CanIfHrhRangeCfg;
        /* BASIC CAN*/
        if(BASIC == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) )
        {
            /*Check for SW Filtering*/
            if(TRUE == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter))
            {
                /*
                 * A range of CanIds which shall pass the software receive filter shall either be defined by its upper limit (see CANIF_HRHRANGE_UPPER_CANID,
                 * ECUC_CanIf_00630) and lower limit (see CANIF_HRHRANGE_LOWER_CANID,
                 * ECUC_CanIf_00629) CanId, or by a base ID (see CANIF_HRHRANGE_BASEID) and
                 * a mask that defines the relevant bits of the base ID (see CANIF_HRHRANGE_MASK). c
                 * ()
                 */
                /* Check on Upper & Lower Range*/
                if((((Mailbox->CanId) &(RxPDU->CanIfRxPduCanIdMask))>=(RxPDU_Range->CanIfHrhRangeRxPduLowerCanId))&&(((Mailbox->CanId)&(RxPDU->CanIfRxPduCanIdMask))<=(RxPDU_Range->CanIfHrhRangeRxPduUpperCanId)))
                {
                    /*Passed the SW Filter Check, Check on Data Length*/
#if (CanIfPrivateDataLengthCheck == STD_ON)
                    /*
                     * If CanIf_RxIndication() is called with invalid PduInfoPtr->SduLength,
                     * runtime error CANIF_E_INVALID_DATA_LENGTH is reported (see[SWS_CANIF_00168]).
                     */
                    if((PduInfoPtr->SduLength) > (RxPDU->CanIfRxPduDataLength))
                    {
#if(STD_ON == CanIfDevErrorDetect)
                        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_INVALID_DATA_LENGTH);
#endif
                    }
                    /*Passed the Data Length Check*/
                    else
#endif /*CanIfPrivateDataLengthCheck*/
                    {
                        /* [SWS_CANIF_00198] d If the configuration parameter
                         * CANIF_PUBLIC_READRXPDU_DATA_API (ECUC_CanIf_00607) is set to TRUE,
                         * CanIf shall store each received L-SDU, at which CANIF_RXPDU_READDATA
                         * (ECUC_CanIf_00600) is enabled, into a receive L-SDU buffer. This means that if the
                         * configuration parameter CANIF_RXPDU_READDATA (ECUC_CanIf_00600) is set to
                         * TRUE, CanIf has to allocate a receive L-SDU buffer for this receive L-SDU.
                         */
#if (STD_ON == CanIfPublicReadRxPduDataApi)
                        if (RxPDU->CanIf_RxPduReadData == TRUE)
                        {
                            /* Store the message in the Rx Buffer*/
                            CanIf_RxBuffer[RxPDU_index]=Temp_Buffer;
                        }
                        else
                        {
                            /*MISRA :Do Nothing*/
                        }
#endif /*CanIfPublicReadRxPduDataApi*/
                        /*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
                        if(RxPDU->CanIf_RxPduReadNotifyStatus == TRUE)
                        {
                            CanIf_RxNotificationFlag[RxPDU_index]=CANIF_TX_RX_NOTIFICATION;
                        }
                        else
                        {
                            /*MISRA :Do Nothing*/
                        }
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/
                        /*  Call the User*/
                        switch(RxPDU->CanIfRxPduUserRxIndicationName)
                        {
                        case PDUR :
                        {
                            /*Variable to store the data of PDU*/
                            PduInfoType RxPduPDUR;
                            RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                            RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                            RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                            PduR_CanIfRxIndication(RxPDU_index,&RxPduPDUR);
                            break;
                        }
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    /*MISRA :Do Nothing*/
                }
            }
        }
        /*FULL CAN*/
        else
        {
            /*Check on CanId*/
            if( ( (Mailbox->CanId) & (RxPDU->CanIfRxPduCanIdMask) ) == (RxPDU->CanIfRxPduCanIdMask)&(RxPDU->CanIfRxPduCanId) )
            {
#if (CanIfPrivateDataLengthCheck == STD_ON)
                /*
                 * If CanIf_RxIndication() is called with invalid PduInfoPtr->SduLength,
                 * runtime error CANIF_E_INVALID_DATA_LENGTH is reported (see[SWS_CANIF_00168]).
                 */
                if((PduInfoPtr->SduLength) > (RxPDU->CanIfRxPduDataLength))
                {
                    Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_INVALID_DATA_LENGTH);
                }
                /*Passed the Data Length Check*/
                else
#endif /*CanIfPrivateDataLengthCheck*/
                {
                    /*
                     * [SWS_CANIF_00198] d If the configuration parameter
                     * CANIF_PUBLIC_READRXPDU_DATA_API (ECUC_CanIf_00607) is set to TRUE,
                     * CanIf shall store each received L-SDU, at which CANIF_RXPDU_READDATA
                     * (ECUC_CanIf_00600) is enabled, into a receive L-SDU buffer. This means that if the
                     * configuration parameter CANIF_RXPDU_READDATA (ECUC_CanIf_00600) is set to
                     * TRUE, CanIf has to allocate a receive L-SDU buffer for this receive L-SDU.
                     */
#if (STD_ON == CanIfPublicReadRxPduDataApi)
                    if (RxPDU->CanIf_RxPduReadData == TRUE)
                    {
                        /* Store the message in the Rx Buffer*/
                        CanIf_RxBuffer[RxPDU_index]=Temp_Buffer;
                    }
                    else
                    {
                        /*MISRA :Do Nothing*/
                    }
#endif /*CanIfPublicReadRxPduDataApi*/
                    /* Rx Notification Flags */
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
                    if(RxPDU->CanIf_RxPduReadNotifyStatus == TRUE)
                    {
                        CanIf_RxNotificationFlag[RxPDU_index]=CANIF_TX_RX_NOTIFICATION;
                    }
                    else
                    {
                        /*MISRA :Do Nothing*/
                    }
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/
                    /*  Call the User*/
                    switch(RxPDU->CanIfRxPduUserRxIndicationName)
                    {
                    case PDUR :
                    {
                        /*Variable to store the data of PDU*/
                        PduInfoType RxPduPDUR;
                        RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                        RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                        RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                        PduR_CanIfRxIndication(RxPDU_index,&RxPduPDUR);
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
}

/******************************************************************************
 *Service name: CanIf_TxConfirmation
 *Syntax: void CanIf_TxConfirmation(PduIdType CanTxPduId)
 *Service ID[hex]: 0x13
 *Sync/Async: Synchronous
 *Reentrancy: Reentrant
 *Parameters (in):  - CanTxPduId This ID specifies the corresponding CAN L-PDU ID and implicitly the CAN Driver instance as well as the corresponding CAN controller device.
 *Parameters (inout): None
 *Parameters (out): None
 *Return value: None
 *Description: This service confirms a previously successfully processed transmission of a CAN TxPDU.
 ******************************************************************************/
#if (PduRTxConfirmation)
void CanIf_TxConfirmation(PduIdType CanTxPduId)
{
    /* [SWS_CANIF_00412] If CanIf was not initialized before calling CanIf_TxConfirmation(), CanIf shall not call the service
     * <User_TxConfirmation>() and shall not set the Tx confirmation status, when
     * CanIf_TxConfirmation() is called.
     */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TX_CONFIRMATION_SID, CANIF_E_UNINIT);
#endif
    }

    /* [SWS_CANIF_00410] If parameter CanTxPduId of CanIf_TxConfirmation()
     * has an invalid value, CanIf shall report development error code
     * CANIF_E_PARAM_LPDU to the Det_ReportError service of the DET module,
     * when CanIf_TxConfirmation() is called.
     */
    else if (CanTxPduId > CanIfMaxTxPduCfg )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TX_CONFIRMATION_SID,  CANIF_E_PARAM_LPDU );
#endif
    }

    else{

     /*Pointer to the Transmitted PDU */
    CanIfTxPduCfg *TxPDU_ptr = NULL_PTR;
    TxPDU_ptr =  &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[CanTxPduId];

    /* [SWS_CANIF_00391]  If configuration parameters
     * CANIF_PUBLIC_READTXPDU_NOTIFY_STATUS_API (ECUC_CanIf_00609) and
     * CANIF_TXPDU_READ_NOTIFYSTATUS (ECUC_CanIf_00589) for the Transmitted
     *  L-PDU are set to TRUE, and if CanIf_TxConfirmation() is called, CanIf shall set
     * the notification status for the Transmitted L-PDU.
     */
#if(STD_ON == CanIfPublicReadTxPduNotifyStatusApi)

    if(TxPDU_ptr->CanIfTxPduReadNotifyStatus == TRUE)
    {
        CanIf_TxNotificationFlag[CanTxPduId]= CANIF_TX_RX_NOTIFICATION;
    }

#endif /*CanIfPublicReadTxPduNotifyStatusApi */
    if(TxPDU_ptr->CanIfTxPduUserTxConfirmationUL == PDUR)
    {
        PduR_CanIfTxConfirmation(CanTxPduId,E_OK);
    }
    else if(TxPDU_ptr->CanIfTxPduUserTxConfirmationUL == CAN_TP)
    {
        /* CAN_TP_TxConfirmation(E_OK); */
    }
    else
    {
        /*MISRA : Do Nothing*/
    }
}
}
#endif /*PduRTxConfirmation*/

/************************************************************************************
 * Service Name: CanIf_ControllerModeIndication
 * Service ID[hex]: 0x17
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ControllerId - Abstract CanIf ControllerId which is assigned to a
 *                                 CAN controller, which state has been transitioned.
 *                  ControllerMode - Mode to which the CAN controller transitioned
 * Parameters (in): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to indicate a controller state transition referring to the
 *              corresponding CAN controller with the abstract CanIf ControllerId.
 ************************************************************************************/
void CanIf_ControllerModeIndication(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{
    /* [SWS_CANIF_00702] If CanIf was not initialized before calling
     * CanIf_ControllerModeIndication(), CanIf shall not execute state transition notification,
     *  when CanIf_ControllerModeIndication() is called.
     */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLER_MODE_INDICATION_SID, CANIF_E_UNINIT);
#endif
    }

    /* [SWS_CANIF_00700] If parameter ControllerId of
     * CanIf_ControllerModeIndication() has an invalid value, CanIf
     * shall report development error code CANIF_E_PARAM_CONTROLLERID
     * to the Det_ReportError service of the DET module, when
     * CanIf_ControllerModeIndication() is called.
     */
    else if (ControllerId >= CAN_CONTROLLERS_NUMBER)
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLER_MODE_INDICATION_SID,  CANIF_E_PARAM_CONTROLLERID );
#endif
    }

    /* Check If parameter ControllerMode has an invalid value*/
    else if (  (ControllerMode !=CAN_CS_STARTED) && (ControllerMode !=CAN_CS_STOPPED) && (ControllerMode !=CAN_CS_SLEEP) )
    {
#if( CanIfDevErrorDetect == STD_ON  )
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_CONTROLLER_MODE_INDICATION_SID,  CANIF_E_PARAM_CTRLMODE );
#endif
    }
    else
       {
           /*MISRA : Do Nothing*/
       }


}

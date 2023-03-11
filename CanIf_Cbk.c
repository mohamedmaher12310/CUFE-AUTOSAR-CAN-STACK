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
Can_PduType CanIf_RxBuffer[CanIfMaxRxPduCfg];
#endif /*CanIfPublicReadRxPduDataApi*/

/************************************************************************************
 * Service Name: CanIf_RxIndication
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Mailbox - Identifies the HRH and its corresponding CAN Controller
 *                  PduInfoPtr - Pointer to the received L-PDU
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to indicate a successful reception of a received CAN Rx L-PDU
 *              to the CanIf after passing all filters and validation checks.
 ************************************************************************************/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType * PduInfoPtr)
{
    /*Variables to store the needed Data*/
    CanIfRxPduCfg* RxPDU = NULL_PTR;
    CanIfHrhRangeCfg* RxPDU_Range = NULL_PTR;
    CanIfHrhCfg* HRH_Ptr = NULL_PTR;
    uint8 RxPDU_index;
    uint8 HOH_index ;
    uint8 HRH_index ;
    /* NES2AL FL ENUM wel comparison ely fe page 41 [SWS_CANIF_00877] */
    /*
     * [SWS_CANIF_00877] d If CanIf receives a L-PDU (see CanIf_RxIndication()),
     * Basically, CanIf supports reception either of Standard CAN IDs or
     * Extended_ID CAN IDs on one Physical CAN Channel by the parameters CANIF_TXPDU_CANIDTYPE (see ECUC_CanIf_00590) and
     * CANIF_RXPDU_CANIDTYPE (see ECUC_CanIf_00596).
     */
    boolean Extended_ID=ZERO;
    Can_IdType Id_Type = ( (Mailbox->CanId && (TWO_MSB_MASK)) >> EXTENDED_ID_BITS_NUM ) ;
    if (Id_Type == STANDARD_CAN_Rx)
    {
        Extended_ID = ZERO;
    }
    else if (Id_Type == EXTENDED_CAN_Rx)
    {
        Extended_ID = ONE;
    }
#if(STD_ON == CanIfDevErrorDetect)
    /* If CanIf was not initialized before calling CanIf_RxIndication(),
     * CanIf shall not execute Rx indication handling, when CanIf_RxIndication() is called.
     */
    /* Check if the module is initialized or not*/
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_UNINIT);
    }
    else
    {
        /*Do Nothing*/
    }
    /*
     * If parameter Mailbox->Hoh of CanIf_RxIndication() has an invalid value,
     * CanIf shall report development error code
     */
    if(Mailbox->Hoh > CAN_HOH_NUMBER)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_HOH);
    }
    else
    {
        /* Do nothing*/
    }
    /*
     * If parameter Mailbox->CanId of CanIf_RxIndication() has an invalid value,
     * CanIf shall report development error code CANIF_E_PARAM_CANID to the Det_ReportError
     * service of the DET
     */
    if ( (Mailbox->CanId > CANNIF_STANDARD_MAX) || (Mailbox->CanId >CANNIF_EXTENDED_MAX) )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID);
    }
    else
    {
        /*MISRA : do nothing*/
    }
    /*
     * If parameter PduInfoPtr or Mailbox has an invalid value,
     * CanIf shall report development error code CANIF_E_PARAM_POINTER to
     * the Det_ReportError service of the DET module
     */
    if( ( NULL_PTR == Mailbox) || ( NULL_PTR== PduInfoPtr)  )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_POINTER);
    }
    else
#endif
    {
        /* Store the addresses to pointers*/
        /* CanIfRxPduCfg Container*/
        RxPDU=&CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg;
        /*Index of Pdu*/
        RxPDU_index = RxPDU->CanIfRxPduId;
        /* CanIfHrhCfg Container*/
        HRH_Ptr = &CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[RxPDU_index].CanIfRxPduHrhIdRef;
        /*Index of Hoh*/
        HOH_index = (HRH_Ptr->CanIfHrhIdSymRef->CanObjectId);
        /*Index of Hrh*/
        uint8 iter;
        for (iter = ZERO; iter < HRH_NUMBER ; iter ++)
        {
            if (HOH_HRH_MAP[iter] == HOH_index)
            {
                HRH_index = iter;
            }
            else
            {
                /*Do Nothing*/
            }
        }
        /* CanIfHrhRangeCfg Container*/
        RxPDU_Range = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[CAN_INSTANCE_ID].CanIfHrhCfg[HRH_index].CanIfHrhRangeCfg;
        /* BASIC CAN*/
        if(BASIC == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) )
        {
            /*Check for SW Filtering*/
            if(TRUE == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter))
            {
                /* A range of CanIds which shall pass the software receive filter shall either be defined by its upper limit (see CANIF_HRHRANGE_UPPER_CANID,
                 * ECUC_CanIf_00630) and lower limit (see CANIF_HRHRANGE_LOWER_CANID,
                 * ECUC_CanIf_00629) CanId, or by a base ID (see CANIF_HRHRANGE_BASEID) and
                 * a mask that defines the relevant bits of the base ID (see CANIF_HRHRANGE_MASK). c
                 * ()
                 */
                /* Check on Upper & Lower Range*/
                if( ( ((Mailbox->CanId) &(RxPDU->CanIfRxPduCanIdMask)) >= (RxPDU_Range->CanIfHrhRangeRxPduLowerCanId) ) && ( ((Mailbox->CanId)&(RxPDU->CanIfRxPduCanIdMask)) <= (RxPDU_Range->CanIfHrhRangeRxPduUpperCanId) )  )
                {
                    /*Passed the SW Filter Check, Check on Data Length*/
#if (CanIfPrivateDataLengthCheck == STD_ON)
                    /*If CanIf_RxIndication() is called with invalid PduInfoPtr->SduLength,
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
                            uint8 ControllerId = HRH_Ptr->CanIfHrhCanCtrlIdRef->CanIfCtrlId;
                            /* Store the message in the Rx Buffer*/
                            /* Modify function argument?! */
                            Can_MessageReceive(ControllerId, HOH_index, &CanIf_RxBuffer[RxPDU_index]);
                        }
                        else
                        {
                            /*Do Nothing*/
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
                            /*Do Nothing*/
                        }
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/
                        /*  Call the User*/
                        switch(RxPDU->CanIfRxPduUserRxIndicationName)
                        {
                        case PDUR :
                        {
                            PduInfoType RxPduPDUR;
                            RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                            RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                            RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                            /*PDUR_RxIndication(RxPDU_index,&RxPduPDUR);*/
                            break;
                        }
                        default:
                            break;
                        }
                    }
                }
                else
                {
                    /*Do Nothing*/
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
                /* If CanIf_RxIndication() is called with invalid PduInfoPtr->SduLength,
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
                        uint8 ControllerId = HRH_Ptr->CanIfHrhCanCtrlIdRef->CanIfCtrlId;
                        /* Store the message in the Rx Buffer*/
                        /* Modify function argument?! */
                        Can_MessageReceive(ControllerId, HOH_index, &CanIf_RxBuffer[RxPDU_index]);
                    }
                    else
                    {
                        /*Do Nothing*/
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
                        /*Do Nothing*/
                    }
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/
                    /*  Call the User*/
                    switch(RxPDU->CanIfRxPduUserRxIndicationName)
                    {
                    case PDUR :
                    {
                        PduInfoType RxPduPDUR;
                        RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                        RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                        RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                        /*PDUR_RxIndication(RxPDU_index,&RxPduPDUR);*/
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

void CanIf_TxConfirmation(PduIdType CanTxPduId)
{

#if( CanIfDevErrorDetect == STD_ON  )

    /* [SWS_CANIF_00412] If CanIf was not initialized before calling CanIf_TxConfirmation(), CanIf shall not call the service
     * <User_TxConfirmation>() and shall not set the Tx confirmation status, when
     * CanIf_TxConfirmation() is called.
     */
    if (CANIF_UNINIT == CanIfCurrent_State)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TX_CONFIRMATION_SID, CANIF_E_UNINIT);
    }

    /* [SWS_CANIF_00410] If parameter CanTxPduId of CanIf_TxConfirmation()
     * has an invalid value, CanIf shall report development error code
     * CANIF_E_PARAM_LPDU to the Det_ReportError service of the DET module,
     * when CanIf_TxConfirmation() is called.
     */
    if (CanTxPduId > CanIfMaxTxPduCfg )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_TX_CONFIRMATION_SID,  CANIF_E_PARAM_LPDU );
    }

#endif

    /* needed pointers */
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
        /* PDUR_TxConfirmation(E_OK); */
    }
    else if(TxPDU_ptr->CanIfTxPduUserTxConfirmationUL == CAN_TP)
    {
        /* CAN_TP_TxConfirmation(E_OK); */
    }
    else
    {

    }
}

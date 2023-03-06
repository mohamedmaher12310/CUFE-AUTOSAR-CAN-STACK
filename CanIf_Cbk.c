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

/*CanIf Recieve Buffer (ReadAPI)*/
#if (STD_ON == CanIfPublicReadRxPduDataApi)
uint64 CanIf_RxBuffer[CanIfMaxRxPduCfg]={ZERO};
#endif /*CanIfPublicReadRxPduDataApi*/

/*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
CanIf_NotifStatusType CanIf_RxNotificationFlag[CanIfMaxRxPduCfg]={ZERO};
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/

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
    /*needed pointers*/
    CanIfRxPduCfg* RxPDU = NULL_PTR;
    CanIfHrhRangeCfg* RxPDU_Range = NULL_PTR;
    CanIfHrhCfg* HRH_index_Ptr = NULL_PTR;
    /*needed variables*/
    uint8 RxPDU_index ;
    uint8 HRH_index ;
    uint8 PDU_PASS=ZERO;
    /* NES2AL FL ENUM wel comparison ely fe page 41 */
    boolean Extended=ZERO;
    Can_IdType Id_Type = ( (Mailbox->CanId && (0xC0000000)) >> 29 ) ;
    if (Id_Type == STANDARD_CAN_Rx)
    {
        Extended = ZERO;
    }
    else if (Id_Type == EXTENDED_CAN_Rx)
    {
        Extended = ONE;
    }
#if(STD_ON == CanIfDevErrorDetect)
    /* If parameter Mailbox->Hoh of CanIf_RxIndication() has an invalid value, CanIf shall report development error code*/
    if(Mailbox->Hoh > CAN_HOH_NUMBER)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_HOH);
    }
    else
    {
        /*MISRA : do nothing*/
    }
    /*If parameter Mailbox->CanId of CanIf_RxIndication() has an invalid value,
     *CanIf shall report development error code CANIF_E_PARAM_CANID to the Det_ReportError
     *service of the DET
     */
    if ( (Mailbox->CanId > CANNIF_STANDARD_MAX) || (Mailbox->CanId >CANNIF_EXTENDED_MAX) )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_CANID);
    }
    else
    {
        /*MISRA : do nothing*/
    }
    /*If parameter PduInfoPtr or Mailbox has an invalid value,
     *CanIf shall report development error code CANIF_E_PARAM_POINTER to
     *the Det_ReportError service of the DET module
     */
    if( ( NULL_PTR == Mailbox) || ( NULL_PTR== PduInfoPtr)  )
    {

        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_POINTER);
    }
    else
#endif
    {

        RxPDU=&(CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg);
        RxPDU_index = RxPDU->CanIfRxPduId;
        HRH_index_Ptr = &CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg[RxPDU_index].CanIfRxPduHrhIdRef;
        HRH_index= (HRH_index_Ptr->CanIfHrhIdSymRef->CanObjectId);
        RxPDU_Range = &CanIf_Configuration.CanIfInitCfg.CanIfInitHohCfg[Can_DRIVERS_NUMBER].CanIfHrhCfg[HRH_index].CanIfHrhRangeCfg;
        /* [SWS_CANIF_00877] ??*/
        /***************************************before all of this check the channel mode of the  PDU ************************/
        //        if( (CANIF_TX_OFFLINE == RxPDU->CanIf_PduModeType) || (CANIF_ONLINE == RxPDU->CanIf_PduModeType) )
        //        {

        /***************************************before all of this check the channel mode of the  PDU ************************/
        //        if( (CANIF_TX_OFFLINE == RxPDU->CanIf_PduModeType) || (CANIF_ONLINE == RxPDU->CanIf_PduModeType) )
        //        {
        if(BASIC == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) )
        {


            /*check of SW filter enable*/
            if(TRUE == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter))

            /*check of SW filter enable*/
            if(TRUE == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter))
            {
                if( ( ((Mailbox->CanId) &(RxPDU->CanIfRxPduCanIdMask)) >= (RxPDU_Range->CanIfHrhRangeRxPduLowerCanId) ) && ( ((Mailbox->CanId)&(RxPDU->CanIfRxPduCanIdMask)) <= (RxPDU_Range->CanIfHrhRangeRxPduUpperCanId) )  )
                {
                    PDU_PASS=1;
                }
                else
                {
                    PDU_PASS=0;
                }
            }
            else
            {

            }
            /*after passing sw filter test*/
            if( 1 == PDU_PASS ){
#if (CanIfPrivateDataLengthCheck == STD_ON)
                if((PduInfoPtr->SduLength) > (RxPDU->CanIfRxPduDataLength))
                {
                    Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_INVALID_DATA_LENGTH);

                }
#endif
                else/*length check is ok call the upper layer*/
                {
                    /*CanIf Recieve Buffer (ReadAPI)*/
#if (STD_ON == CanIfPublicReadRxPduDataApi)
                    //Nsta2bel el message we n5znha fl CanIf buffer CanIf_RxBuffer

#endif /*CanIfPublicReadRxPduDataApi*/

                    /*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
                    CanIf_RxNotificationFlag[RxPDU_index]=CANIF_TX_RX_NOTIFICATION;
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/

                    switch(RxPDU->CanIfRxPduUserRxIndicationName)
                    {
                    case PDUR :
                    {
                        PduInfoType RxPduPDUR;
                        RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                        RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                        RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                        PDUR_RxIndication(RxPDU_index,&RxPduPDUR);

                        break;
                    }
                    default:
                        break;


                    }

                }
            }
            else/*PDU_PASS=0*/
            {

            }

        }
        else if( ( (Mailbox->CanId) & (RxPDU->CanIfRxPduCanIdMask) ) == (RxPDU->CanIfRxPduCanIdMask)&(RxPDU->CanIfRxPduCanId) )
        {               /*FULL CAN*/
#if (CanIfPrivateDataLengthCheck == STD_ON)
            if((PduInfoPtr->SduLength) > (RxPDU->CanIfRxPduDataLength))
            {
                Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_INVALID_DATA_LENGTH);

            }
#endif
            else/*length check is ok call the upper layer*/
            {

                /*CanIf Recieve Buffer (ReadAPI)*/
#if (STD_ON == CanIfPublicReadRxPduDataApi)
                //Nsta2bel el message we n5znha fl CanIf buffer CanIf_RxBuffer

#endif /*CanIfPublicReadRxPduDataApi*/

                /*Rx Notification Flags*/
#if (STD_ON == CanIfPublicReadRxPduNotifyStatusApi)
                CanIf_RxNotificationFlag[RxPDU_index]=CANIF_TX_RX_NOTIFICATION;
#endif /*CanIfPublicReadRxPduNotifyStatusApi*/


                switch(RxPDU->CanIfRxPduUserRxIndicationName)
                {
                case PDUR :
                {
                    PduInfoType RxPduPDUR;
                    RxPduPDUR.SduLength = PduInfoPtr->SduLength;
                    RxPduPDUR.SduDataPtr = PduInfoPtr->SduDataPtr;
                    RxPduPDUR.MetaDataPtr = PduInfoPtr->MetaDataPtr;
                    //PDUR_RxIndication(RxPDU_index,&RxPduPDUR);

                    break;
                }
                default:
                    break;


                }

            }

        }
        //}
        else
        {

        }
    }
}

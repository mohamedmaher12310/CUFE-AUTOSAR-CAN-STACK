/******************************************************************************
 *
 * Module: CanIf
 *
 * File Name: Can.c
 *
 * Description: Source file for CanIf Module.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/*Include the module header file*/
#include "CanIf.h"





/******************************************************************************
 *Service name: CanIf_RxIndication
 *Syntax: void CanIf_RxIndication(const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr)
 *Service ID[hex]: 0x14
 *Sync/Async: Synchronous
 *Reentrancy: Reentrant
 *Parameters (in):  - Mailbox Identifies the HRH and its corresponding CAN Controller
                    -PduInfoPtr Pointer to the received L-PDU
 *Parameters (inout): None
 *Parameters (out): None
 *Return value: None
 *Description: This service indicates a successful reception of a received CAN Rx LPDU to the CanIf after passing all filters and validation checks
 ******************************************************************************/
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType * PduInfoPtr)
{

    /* If parameter Mailbox->Hoh of CanIf_RxIndication() has an invalid value, CanIf shall report development error code*/
#if(STD_ON == CanIfDevErrorDetect)

    if(Mailbox->Hoh != RECIEVE)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_HOH);
    }
    else
    {
        /*MISRA : do nothing*/
    }

    /* If parameter Mailbox->CanId of CanIf_RxIndication() has an invalid value, CanIf shall report development error code CANIF_E_PARAM_CANID to the Det_ReportError service of the DET */
    if ( (Mailbox->CanId > CANNIF_STANDARD_MAX) || (Mailbox->CanId >CANNIF_EXTENDED_MAX) )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_CANID);
    }
    else
    {
        /*MISRA : do nothing*/
    }


    /*If parameter PduInfoPtr or Mailbox has an invalid value, CanIf shall report development error code CANIF_E_PARAM_POINTER to the Det_ReportError service of the DET module*/
    if( ( NULL_PTR == Mailbox) || ( NULL_PTR== PduInfoPtr)  )
    {

        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CanIf_RxIndication_RXID_SID, CANIF_E_PARAM_POINTER);
    }
    else
    {
        /*MISRA : do nothing*/
    }


#endif
    const CanIfRxPduCfg* RxPDU = NULL_PTR;
    uint8 RxPDU_index ;
    RxPDU=&CanIf_Configuration.CanIfInitCfg.CanIfRxPduCfg;

    RxPDU_index = RxPDU->CanIfRxPduId;

    //    uint16 iter;
    uint8 PDU_PASS=8;
    if(BASIC == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) )
    {
        /*check of SW filter enable*/
        if(TRUE == (RxPDU->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter))
        {
            if( ( (Mailbox->CanId) & (RxPDU->CanIfRxPduCanIdMask) ) == (RxPDU->CanIfRxPduCanIdMask)&(RxPDU->CanIfRxPduCanId) )
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
    else{/*FULL CAN*/

    }
    //    for (iter = 0; iter < CanIf_ConfigPtr->InitConfig->CanIfMaxRxPduCfg ; iter++)
    //    {
    //        if(((&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) == BASIC)
    //        {
    //            /* Software filtering */
    //            if ( ((&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter) ==TRUE)
    //            {
    //
    //                if ((Mailbox->CanId & (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanIdMask ) == ( (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanId & (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanIdMask))
    //                {
    //                    /* We found a pdu. so, DLC Check & call higher layers  */
    //                    PDU_PASS=ONE;
    //                }
    //                else
    //                {
    //                    /* PDU does not pass sw filter */
    //                    PDU_PASS=ZERO;
    //
    //                }
    //
    //            }
    //        }
    //
    //        /*Data Length Check*/
    //        if( PDU_PASS== ONE)
    //        {
    //
    //            /* CanIf shall accept all received L-PDUs with a Data Length value equal or greater then the configured Data Length value*/
    //            if (PduInfoPtr->SduLength < (&Cfg_Arr_CanIfRxIndication[RxPduIndex])->CanIfRxPduDataLength)
    //            {
    //                /* Call Det_ReportRuntimeError() with error code CANIF_E_INVALID_DATA_LENGTH*/
    //
    //                Det_ReportRuntimeError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_INVALID_DATA_LENGTH);
    //
    //
    //            }
    //            // else         /*Call <User_RxIndication>() to upper layers */
    //
    //#endif
    //
    //            switch(Get_User_RxIndication_Name(RxPduIndex))
    //            {
    //            case CAN_NM:
    //            {
    //                break;
    //
    //            }
    //
    //            case PDUR:
    //            {
    //
    //                break;
    //            }
    //
    //
    //            }
    //
    //        }
    //
    //    }
}

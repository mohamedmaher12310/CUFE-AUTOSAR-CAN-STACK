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

<<<<<<< HEAD
=======

CanIf_ConfigType *CanIf_ConfigPtr;

Std_ReturnType CanIf_GetPduMode(uint8 ControllerId,CanIf_PduModeType* PduModePtr)

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
void CanIf_RxIndication(const Can_HwType* Mailbox, const PduInfoType *PduInfoPtr)
{

   /* If parameter Mailbox->Hoh of CanIf_RxIndication() has an invalid value, CanIf shall report development error code*/
#if(STD_ON == CAN_DEV_ERROR_DETECT)

   if(Mailbox->Hoh != RECIEVE)
   {    ///?????/instance id
       Det_ReportError(CANIF_MODULE_ID, CAN_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_HOH);
             return E_NOT_OK;
   }
   else
   {
       /*MISRA : do nothing*/
   }

  /* If parameter Mailbox->CanId of CanIf_RxIndication() has an invalid value, CanIf shall report development error code CANIF_E_PARAM_CANID to the Det_ReportError service of the DET */
   if ( (Mailbox->CanId > CANNIF_STANDARD_MAX) || (Mailbox->CanId >CANNIF_EXTENDED_MAX) )    //???????
     {    ///?????/instance id
         Det_ReportError(CANIF_MODULE_ID, CAN_INSTANCE_ID, CANIF_RX_INDICATION_SID, CANIF_E_PARAM_CANID);
               return E_NOT_OK;
     }
     else
     {
         /*MISRA : do nothing*/
     }


#endif

/*

Note: If CanIf_RxIndication() is called with invalid PduInfoPtr-
>SduLength, runtime error CANIF_E_INVALID_DATA_LENGTH is reported



If parameter PduInfoPtr or Mailbox of
CanIf_RxIndication() has an invalid value, CanIf shall report development
error code CANIF_E_PARAM_POINTER to the Det_ReportError service of the DET
module, when CanIf_RxIndication() is called.*/

    // if((CanIf_GetPduMode(channel_CanIf_RxIndication,&mode_CanIf_RxIndication))==E_OK)

    CanIfRxPduCfg* Cfg_Arr_CanIfRxIndication = CanIf_ConfigPtr->InitConfig->CanIfRxPduConfigPtr;

    uint16 iter;
    uint8 PDU_PASS;

    for (iter = 0; iter < CanIf_ConfigPtr->InitConfig->CanIfMaxRxPduCfg ; iter++)
    {
       // cont=(uint8)0;

        // if (CanIf_hrhConfigTypeInstance[iter].CanIfCanControllerHrhIdRef == Hrh)
        //{

        if(((&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduHrhIdRef->CanIfHrhIdSymRef->CanHandleType) == BASIC)
        {
            /* Software filtering */
            if ( ((&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduHrhIdRef->CanIfHrhSoftwareFilter) ==TRUE)
            {
                //if ((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfSoftwareFilterType == CANIF_SOFTFILTER_TYPE_MASK)
                //{
                if ((Mailbox->CanId & (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanIdMask ) == ( (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanId & (&Cfg_Arr_CanIfRxIndication[iter])->CanIfRxPduCanIdMask))
                {
                    /* We found a pdu. so, DLC Check & call higher layers  */
                    PDU_PASS=ONE;
                }
                else
                {
                    /* PDU does not pass sw filter */
                    //  ++entry_count;
                    // cont=(uint8)1;
                    /* continue; */
                    /* Go to next entry */
                }
                // }


            }
        }
        /*Data Length Check*/
        if( PDU_PASS== ONE)
        {

#if (CanIfPrivateDataLengthCheck == STD_ON)
       // if (CanDlc < (&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduDlc)
          /* CanIf shall accept all received L-PDUs with a Data Length value equal or greater then the configured Data Length value*/
            if (PduInfoPtr->SduLength < (&Cfg_Arr_CanIfRxIndication[RxPdu_Index])->CanIfRxPduDataLength)
        {
           // VALIDATE_NO_RV((uint8)FALSE, CANIF_RXINDICATION_ID, CANIF_E_PARAM_DLC);
            //check_t = (uint8) 1;
            //det error

            /* return; */
        }
           // else         /*Call <User_RxIndication>() to upper layers */

#endif

        /*Call <User_RxIndication>() to upper layers */
      //  if(check_t == (uint8) 0)
        //{
            // switch ((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfRxUserType)
        CanIfRxPduUserRxIndicationUL  UL_NAME = Get_User_RxIndication_Name(RxPdu_Index);
     // switch (CanIF_RxPDUCbkConfig_a[Cfg_Arr_CanIfRxIndication->CanIfRxPduCallBackInd].CanIfRxUserType)
       switch(Get_User_RxIndication_Name(RxPdu_Index))
        {
            case CANIF_USER_TYPE_CAN_SPECIAL:
            {
                ( (CanIf_FuncTypeCanSpecial)(CanIF_RxPDUCbkConfig_a[Cfg_Arr_CanIfRxIndication->CanIfRxPduCallBackInd].CanIfUserRxIndication) )(
                        (&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduHrhRef->CanIfCanControllerHrhIdRef,
                        (&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduId,
                        CanSduPtr,
                        CanDlc,
                        CanId);

                check_t = (uint8) 1;
                break;

                /*   return; */
            }

            case CANIF_USER_TYPE_CAN_NM:
#if defined(USE_CANNM)
                CanNm_RxIndication((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduId,CanSduPtr);
                check_t=1;
                break;
                /* return; */

#endif
                break;

            case CANIF_USER_TYPE_CAN_PDUR:
                /* Send Can frame to PDU router */
#if defined(USE_PDUR)
            {
                PduInfoType pduInfo;
                pduInfo.SduLength = CanDlc;
                pduInfo.SduDataPtr = (uint8 *)CanSduPtr;
                PduR_CanIfRxIndication((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduId,&pduInfo);
            }
            check_t = 1;
            break;
            /* return; */
#endif
            break;

            case CANIF_USER_TYPE_CAN_TP:
                /* Send Can frame to CAN TP */
#if defined(USE_CANTP)
            {
                PduInfoType CanTpRxPdu;
                CanTpRxPdu.SduLength = CanDlc;
                CanTpRxPdu.SduDataPtr = (uint8 *)CanSduPtr;
                CanTp_RxIndication((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduId, &CanTpRxPdu);
            }
            check_t = 1;
            break;
            /* return; */
#endif
            break;
            case CANIF_USER_TYPE_J1939TP:
                /* Send Can frame to CAN TP */
#if defined(USE_J1939TP)
            {
                PduInfoType J1939TpRxPdu;
                J1939TpRxPdu.SduLength = CanDlc;
                J1939TpRxPdu.SduDataPtr = (uint8 *)CanSduPtr;
                J1939Tp_RxIndication((&Cfg_Arr_CanIfRxIndication[entry_count])->CanIfCanRxPduId, &J1939TpRxPdu);
            }
            check_t = 1;
            break;
            /*  return; */
#endif
            break;
            default:
            {
                break;
            }
            }
     //   }
          }
    }
    if((check_t==(uint8)0)&&(cont == (uint8)0))
    {
        /*   Cfg_Arr_CanIfRxIndication++; */
        ++entry_count;
    }


    //    }

}

}
>>>>>>> a49b16a40b61da91ad60d5698dc351845b415c59

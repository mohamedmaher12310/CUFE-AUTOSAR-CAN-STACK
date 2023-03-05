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

STATIC CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID);

/*
 * Service name:CanIf_GetTxPDU
 * Syntax :CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID)
 * Parameters(in): PduIdType TxPDU_ID
 * Return value :Address of CanIfTxPduCfg
 * Description : Get the CanIfTxPduCfg from the TxPDU ID
 * */



CanIfTxPduCfg* CanIf_GetTxPDU(PduIdType TxPDU_ID)
{
    uint8 TxPDU_index;
    if(TxPDU_ID<CanIfMaxTxPduCfg)
    {
        for(TxPDU_index =0;TxPDU_index<CanIfMaxTxPduCfg;TxPDU_index++ )
        {
            if(TxPDU_ID == CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TxPDU_index].CanIfTxPduId)
            {
                return &CanIf_Configuration.CanIfInitCfg.CanIfTxPduCfg[TxPDU_index];
            }
            else
            {

            }
        }
    }
    else
    {
        return NULL_PTR;

    }

    return NULL_PTR;
}


/* *Service name: CanIf_Transmit
 *Syntax: Std_ReturnType CanIf_Transmit(PduIdType TxPduId,const PduInfoType* PduInfoPtr)
 *Service ID[hex]: 0x49
 *Sync/Async: Synchronous
 *Reentrancy: Reentrant for different PduIds. Non reentrant for the same PduId.
 *Parameters (in): TxPduId Identifier of the PDU to be transmitted
 *PduInfoPtr Length of and pointer to the PDU data and pointer
 *to MetaData.
 *Parameters (inout): None
 *Parameters (out): None
 *Return value: Std_ReturnType E_OK: Transmit request has been accepted.
 *E_NOT_OK: Transmit request has not been accepted.
 *Description: Requests transmission of a PDU.
 *
 * */
Std_ReturnType CanIf_Transmit(PduIdType TxPduId,const PduInfoType* PduInfoPtr)
{
    Std_ReturnType Can_Write_Return;
    Can_PduType Can_PduData;
    CanIfTxPduCfg* TxPDU =  NULL_PTR;

    /*Get the TxPDU from the TxPduId passed to the function*/
    TxPDU = CanIf_GetTxPDU(TxPduId);

    /*Assign the HTH that will be passed to Can_write from the TxPDU Paramter*/
    Can_HwHandleType Hth = TxPDU->CanIfTxPduBufferRef->CanIfBufferHthRef->CanIfHthIdSymRef->CanObjectId;

    /*Assigning the variables passed by the function to the Can_PduType variable to pass it
     * to the Can_Write */
    Can_PduData.id = TxPDU->CanIfTxPduCanId;
    Can_PduData.length = PduInfoPtr->SduLength;
    Can_PduData.sdu = PduInfoPtr->SduDataPtr;
    Can_PduData.swPduHandle = TxPduId;

    /*Can_Write(Hth,Can_PduType* PduInfo) */
    Can_Write_Return = Can_Write(Hth, &Can_PduData);
    if (Can_Write_Return == CAN_OK)
    {
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
}



/************************************************************************************
 * Service Name: CanIf_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Reentrant (Not for the same controller)
 * Parameters (in): ControllerId - Abstracted CanIf ControllerId which is assigned to a
 *                                 CAN controller, which is requested for mode transition.
 *                  ControllerMode - Requested mode transition
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Std_ReturnType - E_OK: Controller mode request has been accepted
 *                                E_NOT_OK: Controller mode request hasn't been accepted
 * Description: Function to call the corresponding CAN Driver service for changing of
                the CAN controller mode.
 ************************************************************************************/
Std_ReturnType CanIf_SetControllerMode(uint8 ControllerId,Can_ControllerStateType ControllerMode)
{

#if( CanIfDevErrorDetect == STD_ON  )

    /* Check if the Controller ID is greater than the number of configured controllers*/
    if (ControllerId >= CAN_CONTROLLERS_NUMBER)
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_CONTROLLER_MODE_SID,  CANIF_E_PARAM_CONTROLLERID );
        return E_NOT_OK;
    }

    /* Check If parameter ControllerMode has an invalid value*/
    if (  (ControllerMode !=CAN_CS_STARTED) || (ControllerMode !=CAN_CS_STOPPED) || (ControllerMode !=CAN_CS_SLEEP) )
    {
        Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_SET_CONTROLLER_MODE_SID,  CANIF_E_PARAM_CTRLMODE );
        return E_NOT_OK;
    }


#endif

    Can_ControllerStateType Requested_Mode ;
    Std_ReturnType Can_SetControllerMode_return ;

    switch (ControllerMode)
    {
    case CAN_CS_STOPPED :
        Requested_Mode =CAN_CS_STOPPED;
        Can_SetControllerMode_return = Can_SetControllerMode( ControllerId , Requested_Mode );
        break;

    case CAN_CS_STARTED:
        Requested_Mode =CAN_CS_STARTED;
        Can_SetControllerMode_return = Can_SetControllerMode( ControllerId , Requested_Mode );
        break;
    }

    return Can_SetControllerMode_return;

}

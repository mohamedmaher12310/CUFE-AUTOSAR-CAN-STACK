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

/************************************************************************************
 * Service Name: CanIf_RxIndication
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy:  Reentrant
 * Parameters (in):
 *          Mailbox: Identifies the HRH and its corresponding CAN Controller
 *          PduInfoPtr :Pointer to the received L-PDUParameters (inout): None
 * Parameters (out): None
 * Return value:     None
 * Description: This service indicates a successful reception of a received CAN Rx LPDU
 *              to the CanIf after passing all filters and validation checks.
 ************************************************************************************/
/*included functions*/


uint8 CanIf_GetHrhChannel(uint8 Hrh_index)
    {

    CanIfHrhCfg* CanIfHrhCfg_config;


        uint8 channel_num=0;

        CanIfHrhCfg_config = CanIf_ConfigType_Ptr ->InitConfig ->CanIfHohConfigPtr ->CanIfHrh_config ;


        return channel_num;
    }


void CanIf_RxIndication(const Can_HwType* Mailbox,const PduInfoType* PduInfoPtr)
{

    CanIf_PduModeType CanIf_RxIndication_Channel_Mode = CANIF_OFFLINE ;


    uint8 channel_index = CanIf_GetHrhChannel(Mailbox ->Hoh);




}

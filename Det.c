 /******************************************************************************
 *
 * Module: Det
 *
 * File Name: Det.c
 *
 * Description:  Det stores the development errors reported by other modules.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "Det.h"

Std_ReturnType Det_ReportError( uint16 ModuleId,
                      uint8 InstanceId,
                      uint8 ApiId,
                      uint8 ErrorId )
{
    while(1)
    {

    }
    return E_OK;
}

 Std_ReturnType Det_ReportRuntimeError( uint16 ModuleId,
                                     uint8 InstanceId,
                                     uint8 ApiId,
                                     uint8 ErrorId )

 {
    /* while(1)
     {

     }*/
     /*******may i use ISR???*/
     return E_OK;
 }


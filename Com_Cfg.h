/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Com Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_
#define CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_

/*
 * Module version
 */
#define COM_CFG_SW_MAJOR_VERSION            (1U)
#define COM_CFG_SW_MINOR_VERSION            (0U)
#define COM_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define COM_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define COM_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define COM_CFG_AR_RELEASE_PATCH_VERSION    (1U)

/************************ComGeneral Container************************/
/*Switches the development error detection and notification on or off.*/
#define ComDevErrorDetect                      (STD_ON)
/************************ComIPdu Container************************/
//#define ComIPduCallout


#endif /* CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_ */

/******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Os Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef OS_H_
#define OS_H_

/* Id for the company in the AUTOSAR
 * for example Omar Khedr's ID = 1000 :) */
#define OS_VENDOR_ID    (1000U)

/* OS Module Id */
#define OS_MODULE_ID    (80U)

/* OS Instance Id */
#define OS_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define OS_SW_MAJOR_VERSION           (1U)
#define OS_SW_MINOR_VERSION           (0U)
#define OS_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define OS_AR_RELEASE_MAJOR_VERSION   (4U)
#define OS_AR_RELEASE_MINOR_VERSION   (3U)
#define OS_AR_RELEASE_PATCH_VERSION   (1U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and OS Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != OS_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != OS_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != OS_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Include Common Macros header file -> SET_BIT,CLEAR_BIT*/
#include "Common_Macros.h"
/* Include Platform types header file-> uint*/
#include "Platform_Types.h"
/* Include Registers header file*/
#include "Os_Regs.h"

/* Initialize the SysTick timer with Preload value ~= 1ms*/
void SYSTICK_VOIDInit (void);
/* Function to return the value of the counter which counts every 1 ms*/
uint32 GetCounterValue(void);
uint32 CPUcpsid(void);
uint32 CPUcpsie(void);

#endif /* OS_H_ */


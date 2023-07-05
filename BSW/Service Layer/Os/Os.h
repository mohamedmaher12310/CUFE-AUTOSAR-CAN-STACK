 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.h
 *
 * Description: Header file for Os Scheduler.
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

#include "../../../Library/Std_Types.h"

/* AUTOSAR checking between Std Types and OS Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != OS_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != OS_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != OS_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

#include "../Com/Com.h"

#include "../../../Application/App.h"

#include "../../MCAL/Timer/gpt.h"
/* Timer counting time in ms */
#define OS_BASE_TIME 1000

/* Description:
 * Function responsible for:
 * 1. Enable Interrupts
 * 2. Start the Os timer
 * 3. Execute the Init Task
 * 4. Start the Scheduler to run the tasks
 */
void Os_start(void);

/* Description: The Engine of the Os Scheduler used for switch between different tasks */
void Os_Scheduler(void);

/* Description: Function called by the Timer Driver in the MCAL layer using the call back pointer */
void Os_NewTimerTick(void);

#endif /* OS_H_ */

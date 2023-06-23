 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example ID = 1000*/
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (3U)
#define PORT_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "../../../Library/Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Dio Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Registers Header File*/
#include "Port_Regs.h"
   
/* Non AUTOSAR files */
#include "../../../Library/Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
   
/* Service ID for PORT init */
#define PORT_INIT_SID                    (uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID       (uint8)0x01

/* Service ID for PORT refresh Port direction */
#define PORT_REFRESH_PORT_DIRECTION_SID  (uint8)0x02

/* Service ID for PORT get version info */
#define PORT_GET_VERSION_INFO_SID        (uint8)0x03

/* Service ID for PORT set Pin mode */
#define PORT_SET_PIN_MODE_SID            (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report invalid Port Pin ID is requested */
#define PORT_E_PARAM_PIN                 (uint8)0x0A

/* Det Code to report that Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE    (uint8)0x0B

/* DET code to report that Port_Init service is called with a wrong Pointer parameter */
#define PORT_E_PARAM_CONFIG              (uint8)0x0C

/* DET code to report that API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_PARAM_INVALID_MODE        (uint8)0x0D

/* DET code to report that API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE         (uint8)0x0E

/* DET code to report that an API service is called without module initialization */
#define PORT_E_UNINIT                    (uint8)0x0F

/* Det Code to report that APIs called with a NULL Pointer*/
#define PORT_E_PARAM_POINTER             (uint8)0x10
   
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Enumeration for Port_PinDirectionType used by the PORT APIs */
typedef enum 
{
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirectionType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Enumeration for internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_InternalResistorType;

/* Enumeration for internal resistor type for PIN */
typedef enum
{
    GPIO,UART,SSI,
    I2C,PWM,QEI,GPT,
    CAN = 8,USB,SYS_CTRL,
    ANALOG_COMP,CORE,
    ADC
}Port_PinMode;

/* Data Structure for PIN configuration*/
typedef struct
{
	uint8 Port_Number;
        Port_PinType Pin_Number;
        Port_PinDirectionType Pin_Direction;
        Port_PinModeType Pin_Mode;
        Port_InternalResistorType Pin_Resistor;
        uint8 Pin_Initial_Value;
        boolean Pin_Direction_Changeable;
        boolean Pin_Mode_Changeable;
} Port_ConfigPins;


/* Data Structure required for initializing the Port Driver */
typedef struct
{
	Port_ConfigPins Pins[PORT_CONFIGURED_PINS];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Port module:
*              - Setup the direction of the pin
*              - Setup the mode of the pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
extern void Port_Init
(
const Port_ConfigType* ConfigPtr
); 

/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number, Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the direction of the pin
************************************************************************************/
#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
extern void Port_SetPinDirection
(
  Port_PinType Pin, 
  Port_PinDirectionType Direction 
);
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refresh the direction of the pin and return it to the 
*              original configured value 
************************************************************************************/
extern void Port_RefreshPortDirection
( 
 void 
);

/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information 
*                   of this module.
* Return value: None
* Description: Function to Return the version information of this module.
************************************************************************************/
extern void Port_GetVersionInfo
(
 Std_VersionInfoType* versioninfo 
);

/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on
*                  port pin. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the mode of the pin
************************************************************************************/#if (STD_ON == PORT_SET_PIN_MODE_API)
extern void Port_SetPinMode
( 
 Port_PinType Pin, 
 Port_PinModeType Mode 
);
#endif

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/
/* PORTs names*/
#define PORTA                   (uint8)0
#define PORTB                   (uint8)1
#define PORTC                   (uint8)2
#define PORTD                   (uint8)3
#define PORTE                   (uint8)4
#define PORTF                   (uint8)5
/* Some Used Numbers*/
#define ZERO                    (uint8)0
#define ONE                     (uint8)1
#define FOUR                    (uint8)4
/* PINs numbers*/
#define PIN0                    (uint8)0
#define PIN1                    (uint8)1
#define PIN2                    (uint8)2
#define PIN3                    (uint8)3
#define PIN4                    (uint8)4
#define PIN5                    (uint8)5
#define PIN6                    (uint8)6
#define PIN7                    (uint8)7
/* Number defined by the TM4C123GH6PM MCU creators to unlock GPIO Commit Register */
#define UNLOCK_GPIOCR           (uint32)0x4C4F434B
/* Mask used in algorithm of choosing the mode in PMCx bits */
#define FIRST_BYTE_MASK         (uint32)0x0000000F
/* Changeabillity*/
#define DIRECTION_CHANGEABLE        (1U)
#define DIRECTION_NOT_CHANGEABLE    (0U)
#define MODE_CHANGEABLE             (1U)
#define MODE_NOT_CHANGEABLE         (0U)
/* Maximum number of Modes*/
#define MAX_MODE_NUM                (15U)

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;

#endif /* PORT_H */

/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Can Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/
#ifndef CAN_H_
#define CAN_H_

/* Id for the company in the AUTOSAR
 * for example Omar Khedr's ID = 1000 :) */
#define CAN_VENDOR_ID    (1000U)

/* Can Module Id */
#define CAN_MODULE_ID    (80U)

/* Can Instance Id */
#define CAN_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define CAN_SW_MAJOR_VERSION           (1U)
#define CAN_SW_MINOR_VERSION           (0U)
#define CAN_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define CAN_AR_RELEASE_MAJOR_VERSION   (4U)
#define CAN_AR_RELEASE_MINOR_VERSION   (3U)
#define CAN_AR_RELEASE_PATCH_VERSION   (1U)

/*
 * Macros for Can Status
 */
#define CAN_READY                (1U)
#define CAN_UNINIT               (0U)


/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Can Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Can Pre-Compile Configuration Header file */
#include "Can_Cfg.h"

/* AUTOSAR Version checking between Can_Cfg.h and Can.h files */
#if ((CAN_CFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (CAN_CFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (CAN_CFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of Can_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Can_Cfg.h and Can.h files */
#if ((CAN_CFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||  (CAN_CFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||  (CAN_CFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of Can_Cfg.h does not match the expected version"
#endif

/* Registers Header File*/
#include "Can_Regs.h"

/*Communication Stack General Types Header file*/
#include "CommStack_Types.h"

/*CAN General Types Header file*/
#include "Can_GeneralTypes.h"

/* Non AUTOSAR files */
#include "Common_Macros.h"


/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/

/* Service ID for Can_Init API */
#define CAN_INIT_SID                    (uint8)0x00

/* Service ID for Can De-Init API */
#define CAN_DE_INIT_SID                 (uint8)0x10

/* Service ID for Can Set Controller Mode API*/
#define CAN_SET_CONTROLLER_MODE_SID     (uint8)0x03

/* Service ID for Can Disable Controller Interrupts API*/
#define CAN_DISABLE_CONTROLLER_INTERRUPTS_SID    (uint8)0x04

/* Service ID for Can Enable Controller Interrupts API*/
#define CAN_ENABLE_CONTROLLER_INTERRUPTS_SID    (uint8)0x05

/* Service ID for Can Write API*/
#define CAN_WRITE_SID                           (uint8)0x06

/* Service ID for Can Main function Write API*/
#define CAN_MAINFUNCTION_WRITE_SID              (uint8)0x01

/* Service ID for Can Main function Read API*/
#define CAN_MAINFUNCTION_READ_SID               (uint8)0x08

/* Service ID for Can Main function Mode API*/
#define CAN_MAINFUCNTION_MODE_SID               (uint8)0x0c

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/

/* DET code to report that an API Service called with wrong parameter */
#define CAN_E_PARAM_POINTER                 (uint8)0x01
#define CAN_E_PARAM_HANDLE                  (uint8)0x02
#define CAN_E_PARAM_DATA_LENGTH             (uint8)0x03
#define CAN_E_PARAM_CONTROLLER              (uint8)0x04

/* DET Code to report that an API Service used without initialization */
#define CAN_E_UNINIT                        (uint8)0x05

/* DET code to report Invalid transition for the current mode */
#define CAN_E_TRANSITION                    (uint8)0x06

/* DET code to report that Parameter Baudrate has an invalid value */
#define CAN_E_PARAM_BAUDRATE                (uint8)0x07

/* DET Code to report Invalid configuration set selection*/
#define CAN_E_INIT_FAILED                   (uint8)0x09

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Enumeration to represent Return values of CAN driver API.*/
typedef enum Can_ReturnType
{
    CAN_OK, /*success*/
    CAN_NOT_OK, /*error occurred or wakeup event occurred during sleep transition*/
    CAN_BUSY /*transmit request could not be processed because no transmit object was available*/
}Can_ReturnType;

/*Enumeration to represent the the type of the CAN Handle*/
typedef enum
{
    BASIC,
    FULL
} CanHandleType;

/*Enumeration to represent the message ID type */
typedef enum
{
    ID_EXTENDED,
    ID_MIXED,
    ID_STANDARD
} CanIdType;

/*Enumeration to represent the CAN object type */
typedef enum
{
    RECIEVE,
    TRANSMIT
} CanObjectType;

/*BaudRate Configuration Structure*/
typedef struct Can_BaudRate
{
    uint16 BaudRate;
    uint8 PropSeg;
    uint8 PhaseSeg1;
    uint8 PhaseSeg2;
    uint8 SyncJumpWidth;
} CanControllerBaudrateConfig;

/*Hardware Filter Configuration Structure*/
typedef struct Can_HardwareFilterConfig
{
    uint32 CanHwFilterCode;
    uint32 CanHwFilterMask;
} CanHwFilter ;

/*Controller Configuration Structure*/
typedef struct CanController
{
    uint8 CanControllerId;
    CanControllerBaudrateConfig CanControllerBaudrateConfig;
} CanController;

/*Hardware Object Configuration Structure*/
typedef struct CanHardwareObject
{
    CanHandleType CanHandleType;
    uint32 CanHardwareObjectCount;
    CanIdType CanIdType;
    uint32 CanObjectId;
    CanObjectType CanObjectType;
    CanController* CanControllerRef;
    CanHwFilter CanHwFilter;
} CanHardwareObject;



/* Typedef for external data structure containing the overall initialization
data for the CAN driver and SFR settings affecting all controllers.*/
typedef struct CanConfigSet
{
    CanController CanController[CAN_CONTROLLERS_NUMBER];
    CanHardwareObject CanHardwareObject[CAN_HOH_NUMBER];
} CanConfigSet;

typedef struct CanMainFunctionRWPeriods
{
    float32 CanMainFunctionPeriod;
} CanMainFunctionRWPeriods;

typedef struct CanGeneral
{
    CanMainFunctionRWPeriods CanMainFunctionRWPeriods;
} CanGeneral;


typedef struct Can_ConfigType
{
    CanGeneral CanGeneral;
    CanConfigSet CanConfigSet;
}Can_ConfigType;

typedef enum
{
    Confirmed,
    Unconfirmed
}Confirmation_Check;

typedef struct
{
 Confirmation_Check Check;
 uint8 mailbox;
} Message_Confirmation;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
 * Service Name: Can_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Config - Pointer to driver configuration.
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to initialize the Can module:
 *              After power-up/reset, the Can module shall be in the state
 *              CAN_UNINIT,The function Can_Init shall change the module state to
 *              CAN_READY, after initializing all controllers inside the HW
 *              Unit.
 *              Each CAN controller must then be started separately by calling the function
 *              Can_SetControllerMode(CAN_CS_STARTED).
 *             -Enable Clock for CAN Peripheral.
 *             -Enable Interrupt or Polling defined by configuration.
 *             -Set the configured Baudrate.
 *             -Configure the whole 32 hardware message object for each controller (0-1)
 *              depending on the configuration.
 *             -Transfer the controller state from UNINIT State to STOPPED State.
 ************************************************************************************/
extern void Can_Init(
        const Can_ConfigType* Config
);


/************************************************************************************
 * Service Name: Can_DeInit
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to De-Initialize the module by resetting all register values
 *              to the reset value.
 ************************************************************************************/
extern void Can_DeInit(
        void
);

/************************************************************************************
 *Service name: Can_Write
 *Service ID[hex]: 0x06
 *Sync/Async: Synchronous
 *Reentrancy: Reentrant (thread-safe)
 *Parameters (in): Can_HwHandleType Hth - Information which HW-transmit handle shall
 *                                        be used for transmit.
 *                 const Can_PduType* PduInfo - Pointer to SDU user memory, Data Length
 *                                              and Identifier.
 *Parameters (inout):None
 *Parameters (out): None
 *Return value: Std_ReturnType -  E_OK: Write command has been accepted
 *                                E_NOT_OK: development error occurred
 *                                CAN_BUSY: No TX hardware buffer available or pre-emptive call
 *                                          of Can_Write that can't be implemented re-entrant
 *Description: This function is called by CanIf to pass a CAN message to CanDrv for
 *             transmission.
 ************************************************************************************/
extern Std_ReturnType Can_Write(Can_HwHandleType Hth,const Can_PduType* PduInfo);

/*********************************************************************************************
 * Service name: Can_MainFunction_Read
 * Syntax: void Can_MainFunction_Read(void)
 * Service ID[hex]: 0x08
 * Description: -This function performs the polling of RX indications when CAN_RX_PROCESSING is set to POLLING.
 *              -The Can module may implement the function Can_MainFunction_Read
 *                 as empty define in case no polling at all is used
 *
 ********************************************************************/
extern void Can_MainFunction_Read(void);



/***************************************************************************************************************
 * Service name: Can_MainFunction_Write
 * Syntax: void Can_MainFunction_Write(void)
 *  Service ID[hex]: 0x01
 *  Description: This function performs the polling of TX confirmation when
 *  CAN_TX_PROCESSING is set to POLLING.
 *
 *************************************************************************************************************/
extern void Can_MainFunction_Write(void);

/********************************************************************************************************/
/*Service name: Can_EnableControllerInterrupts
Syntax: void Can_EnableControllerInterrupts(uint8 Controller)
Service ID[hex]: 0x05
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): Controller CAN controller for which interrupts shall be re-enabled
Parameters
(inout):
None
Parameters (out): None
Return value: None
Description: This function enables all allowed interrupts.*/
/********************************************************************************************************/

void Can_EnableControllerInterrupts( uint8 Controller );

/*********************************************************************************************
 *Service name: Can_DisableControllerInterrupts
void Can_DisableControllerInterrupts( uint8 Controller )
Syntax:
Service ID[hex]: 0x04
Sync/Async: Synchronous
Reentrancy: Reentrant
Parameters (in): Controller CAN controller for which interrupts shall be disabled.
Parameters None
(inout):
Parameters (out): None
Return value: None
Description: This function disables all interrupts for this CAN controller.
 ********************************************************************************************/
extern void Can_DisableControllerInterrupts( uint8 Controller );

/************************************************************************************
 * Service name: Can_SetControllerMode
 * Service ID[hex]: 0x03
 * Sync/Async: Asynchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Controller - CAN controller for which the status shall be changed
 *                  Transition -Transition value to request new CAN controller state
 * Parameters (inout): None
 * Parameters (out):   None
 * Return value: Std_ReturnType E_OK - Request accepted
 *               Std_ReturnType E_NOT_OK - Request not accepted, a development error occurred
 * Description:  This function performs software triggered state transitions of
 *               the CAN controller State machine.
 ************************************************************************************/
extern Std_ReturnType Can_SetControllerMode(uint8 Controller , Can_ControllerStateType Transition);

/*Recieve message from message object*/
extern uint8 Can_MessageReceive(uint32 Controller_Base_Address,Can_HwHandleType MessageObj_Num, Can_PduType* Message);

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/

#define ZERO                (0U)
#define ONE                 (1U)
#define TWO                 (2U)
#define FOUR                (4U)
#define SIXTEEN             (16U)
#define TMILLI              (1000U)
#define THIRTEEN_BIT_MASK   (0x00001FFF)
#define SIX_BIT_MASK        (0x0000003F)
#define EIGHT_BITS          (8U)
#define TWELVE_BITS         (12U)
#define SIX_BITS            (6U)
#define FOUR_BIT_MASK       (0x0000000F)
#define CAN_NOT_INITIALIZED (0u)
#define TWENTY_NINE_INTD    (29u)
#define THIRTY_INTD         (30u)
#define THIRTY_ONE_INTD     (31u)
#define FIVE_INTA           (5u)
#define SIX_INTA            (6u)
#define SEVEN_INTA          (7u)


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/

/* Extern PB structures to be used by Can and other modules */
extern Can_ConfigType Can_Configuration;

extern Message_Confirmation Object_Check[CAN_CONTROLLERS_NUMBER][CAN_HOH_NUMBER][MAX_HWOBJECT_COUNT];

/* interrupt variables */
extern volatile boolean MSG_Object_INT_Flag ;
extern volatile uint8 MSG_Number_INT[32] ;
extern volatile boolean Error_Flag ;
extern volatile uint8 Error_Status ;
extern volatile uint32 Recieve_Count ;
extern volatile uint32 Transmit_Count ;


#endif /* CAN_H_ */




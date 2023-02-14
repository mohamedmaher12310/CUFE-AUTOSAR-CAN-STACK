/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Can Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/*
 * Module version
 */
#define CAN_CFG_SW_MAJOR_VERSION            (1U)
#define CAN_CFG_SW_MINOR_VERSION            (0U)
#define CAN_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define CAN_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define CAN_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define CAN_CFG_AR_RELEASE_PATCH_VERSION    (1U)

/* CAN Processing type*/
#define INTERRUPT     (0U)
#define MIXED         (1U)
#define POLLING       (2U)

/* CAN State */
#define CAN_INITIALIZED         (1U)
#define CAN_NOT_INITAILIZED    (0U)


/**********************************Can General Configurations***************************/
/*
  Switches the development error detection and notification on or off.
   true: detection and notification is enabled.
   false: detection and notification is disabled.

 */
#define CAN_DEV_ERROR_DETECT                (STD_ON)

/*
 * Specifies if multiplexed transmission shall be supported.ON or OFF
 */
#define CAN_MULTIPLEXED_TRANSMISSION        (STD_OFF)

/*
 * This parameter describes the period for cyclic call to
   Can_MainFunction_Busoff. Unit is seconds
 */
#define CAN_MAINFUNCITON_BUSOFF_PERIOD       (1U)

/*
 * This parameter describes the period for cyclic call to
   Can_MainFunction_Mode. Unit is seconds
 */
#define CAN_MAINFUNCITON_MODE_PERIOD        (float32)0.1

/*
 * This parameter describes the period for cyclic call to
   Can_MainFunction_Wakeup. Unit is seconds.
 */
#define CAN_MAINFUNCITON_WAKEUP_PERIOD       (1U)

/*
 * Selects support of Pretended Network features in Can driver.
    True: Enabled
    False: Disabled
 */
#define CAN_PUBLIC_ICOM_SUPPORT              (STD_OFF)

/*
 * The support of the Can_SetBaudrate API is optional.
If this parameter is set to true the Can_SetBaudrate API shall be
supported. Otherwise the API is not supported.
 *
 */
#define CAN_SET_BAUDRATE_API                 (STD_OFF)

/*
 * Specifies the maximum time for blocking function until a timeout is
detected. Unit is seconds.
 */

#define CanConf_CanTimeoutDuration           (float32)0.5

/*
 * Switches the Can_GetVersionInfo() API ON or OFF
 */
#define CAN_GET_VERSION_INFO                 (STD_ON)

/*
 * Specifies the maximum time for blocking function until a timeout is
 * detected. Unit is seconds.
 * For Example = 50ms
 */
#define CAN_TIMEOUT_DURATION                  (float32)0.05

/**********************************Can Controller Configurations***************************/

/* Defines the number of CAN Controllers in TM4C123GH6PM MCU*/
#define CAN_CONTROLLERS_NUMBER                     (uint8)2

/*
 * Enables / disables API Can_MainFunction_BusOff() for handling busoff events in
polling mode.
 */
#define CanConf_CAN0_MAINFUNCTION_BUSOFF           INTERRUPT
#define CanConf_CAN1_MAINFUNCTION_BUSOFF           INTERRUPT

/*
 * Defines if a CAN controller is used in the configuration.
 */
#define CanConf_CAN0_CONTROLLER_ACTIVATION          (STD_ON)
#define CanConf_CAN1_CONTROLLER_ACTIVATION          (STD_OFF)

/*Specifies the CAN controller base address.*/
#define CAN0_BASE                                   CAN0_BASE_ADDRESS
#define CAN1_BASE                                   CAN1_BASE_ADDRESS
/*
 * This parameter provides the controller ID which is unique in a given CAN
Driver. The value for this parameter starts with 0 and continue without any
gaps
 */
#define CAN0_CONTROLLER_ID          (0U)
#define CAN1_CONTROLLER_ID          (1U)

/*
 * Enables / disables API Can_MainFunction_Read() for handling PDU reception events in polling mode
 */
#define CanConf_CAN0_RX_PROCESSING         INTERRUPT
#define CanConf_CAN1_RX_PROCESSING         INTERRUPT

/*
 * Enables / disables API Can_MainFunction_Write() for handling PDU transmission
events in polling mode.
 */
#define CanConf_CAN0_TX_PROCESSING           POLLING
#define CanConf_CAN1_TX_PROCESSING           INTERRUPT

/*
 * Adds / removes the service Can_CheckWakeup() from the code.
True: Can_CheckWakeup can be used.
False: Can_CheckWakeup cannot be used.
 *
 */
#define CanConf_CAN0_WAKEUP_FUCNTION_API        (STD_OFF)
#define CanConf_CAN1_WAKEUP_FUCNTION_API        (STD_OFF)

/*
 * Enables / disables API Can_MainFunction_Wakeup() for handling wakeup events
in polling mode
 */
#define CanConf_CAN0_MAINFUNCTION_WAKEUP        (STD_OFF)
#define CanConf_CAN1_MAINFUNCTION_WAKEUP        (STD_OFF)

/*
 * Description CAN driver support for wakeup over CAN Bus.
 */
#define CanConf_CAN0_WAKEUP_SUPPORT             (STD_OFF)
#define CanConf_CAN1_WAKEUP_SUPPORT             (STD_OFF)

/**********************************Baudrate Configurations***************************/

/*
 * Specifies the baudrate of the controller in kbps.
 */
#define CanConf_CAN0_CONTROLLER_BAUDRATE        (uint16)500
#define CanConf_CAN1_CONTROLLER_BAUDRATE        (uint16)500

/*
 * Specifies propagation delay in time quantas.
 */
#define CanConf_CAN0_CONTROLLER_PROPSEG          (uint8)1
#define CanConf_CAN1_CONTROLLER_PROPSEG          (uint8)1

/*
 * Specifies phase segment 1 in time quantas.
 *
 */
#define CanConf_CAN0_CONTROLLER_SEG1             (uint8)7
#define CanConf_CAN1_CONTROLLER_SEG1             (uint8)7

/*
 * Specifies phase segment 2 in time quantas.
 *
 */
#define CanConf_CAN0_CONTROLLER_SEG2             (uint8)7
#define CanConf_CAN1_CONTROLLER_SEG2             (uint8)7

/*
 * Specifies the synchronization jump width for the controller in time quantas.
 */
#define CanConf_CAN0_CONTROLLER_SYNC_JUMP_WIDTH  (uint8)4
#define CanConf_CAN1_CONTROLLER_SYNC_JUMP_WIDTH  (uint8)4

/**********************************Can Hardware Object Configurations***************************/

/* Defines the number of CAN Controllers in TM4C123GH6PM MCU*/
#define CAN_HARDWARE_OBJECTS_NUMBER                     (uint8)32

/*
 *Name :CanHandleType
  Parent Container: CanHardwareObject
  Description :Specifies the type (Full-CAN or Basic-CAN) of a hardware object.
 */

#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_0              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_1              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_2              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_3              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_4              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_5              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_6              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_7              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_8              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_9              (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_10             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_11             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_12             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_13             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_14             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_15             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_16             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_17             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_18             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_19             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_20             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_21             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_22             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_23             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_24             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_25             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_26             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_27             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_28             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_29             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_30             (CanHandleType)BASIC
#define CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_31             (CanHandleType)BASIC

#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_0              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_1              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_2              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_3              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_4              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_5              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_6              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_7              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_8              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_9              (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_10             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_11             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_12             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_13             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_14             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_15             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_16             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_17             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_18             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_19             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_20             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_21             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_22             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_23             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_24             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_25             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_26             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_27             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_28             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_29             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_30             (CanHandleType)BASIC
#define CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_31             (CanHandleType)BASIC

/*
 * Name:CanHardwareObjectUsesPolling
   Parent Container:CanHardwareObject
   Description:Enables polling of this hardware object
 */

#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)

#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_0             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_1             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_2             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_3             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_4             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_5             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_6             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_7             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_8             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_9             (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_10            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_11            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_12            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_13            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_14            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_15            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_16            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_17            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_18            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_19            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_20            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_21            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_22            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_23            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_24            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_25            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_26            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_27            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_28            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_29            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_30            (STD_OFF)
#define CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_31            (STD_OFF)

#endif


#if  (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)

#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_0             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_1             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_2             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_3             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_4             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_5             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_6             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_7             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_8             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_9             (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_10            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_11            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_12            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_13            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_14            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_15            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_16            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_17            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_18            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_19            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_20            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_21            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_22            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_23            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_24            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_25            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_26            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_27            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_28            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_29            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_30            (STD_OFF)
#define CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_31            (STD_OFF)

#endif

/*
Name: CanHwObjectCount
Parent Container: CanHardwareObject
Description: Number of hardware objects used to implement one HOH. In case of a
             HRH this parameter defines the number of elements in the hardware FIFO
             or the number of shadow buffers, in case of a HTH it defines the number of
             hardware objects used for multiplexed transmission or for a hardware FIFO
             used by a FullCAN HTH.
 */
#define MAX_HWOBJECT_COUNT                            (uint8)10


#define CAN0_CONTROLLER_HW_OBJECT_COUNT_0             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_1             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_2             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_3             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_4             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_5             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_6             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_7             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_8             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_9             (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_10            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_11            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_12            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_13            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_14            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_15            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_16            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_17            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_18            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_19            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_20            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_21            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_22            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_23            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_24            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_25            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_26            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_27            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_28            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_29            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_30            (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_COUNT_31            (uint32)1

#define CAN1_CONTROLLER_HW_OBJECT_COUNT_0             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_1             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_2             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_3             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_4             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_5             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_6             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_7             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_8             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_9             (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_10            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_11            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_12            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_13            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_14            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_15            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_16            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_17            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_18            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_19            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_20            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_21            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_22            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_23            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_24            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_25            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_26            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_27            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_28            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_29            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_30            (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_COUNT_31            (uint32)1

/*
Name: CanIdType
Parent Container: CanHardwareObject
Description: Specifies whether the IdValue is of type
- standard identifier
- extended identifier
- mixed mode
ImplementationType: Can_IdType
 */
#define CAN0_CONTROLLER_ID_TYPE_0                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_1                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_2                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_3                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_4                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_5                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_6                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_7                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_8                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_9                           (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_10                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_11                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_12                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_13                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_14                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_15                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_16                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_17                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_18                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_19                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_20                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_21                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_22                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_23                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_24                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_25                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_26                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_27                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_28                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_29                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_30                          (CanIdType)ID_STANDARD
#define CAN0_CONTROLLER_ID_TYPE_31                          (CanIdType)ID_STANDARD

#define CAN1_CONTROLLER_ID_TYPE_0                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_1                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_2                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_3                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_4                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_5                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_6                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_7                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_8                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_9                           (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_10                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_11                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_12                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_13                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_14                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_15                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_16                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_17                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_18                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_19                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_20                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_21                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_22                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_23                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_24                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_25                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_26                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_27                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_28                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_29                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_30                          (CanIdType)ID_STANDARD
#define CAN1_CONTROLLER_ID_TYPE_31                          (CanIdType)ID_STANDARD

/*
Name: CanObjectId
Parent Container: CanHardwareObject
Description: Holds the handle ID of HRH or HTH. The value of this parameter is unique
             in a given CAN Driver, and it should start with 0 and continue without any
             gaps.
The HRH and HTH Ids share a common ID range.
Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3
 */
#define CAN0_CONTROLLER_HW_OBJECT_ID_0                           (uint32)1
#define CAN0_CONTROLLER_HW_OBJECT_ID_1                           (uint32)2
#define CAN0_CONTROLLER_HW_OBJECT_ID_2                           (uint32)3
#define CAN0_CONTROLLER_HW_OBJECT_ID_3                           (uint32)4
#define CAN0_CONTROLLER_HW_OBJECT_ID_4                           (uint32)5
#define CAN0_CONTROLLER_HW_OBJECT_ID_5                           (uint32)6
#define CAN0_CONTROLLER_HW_OBJECT_ID_6                           (uint32)7
#define CAN0_CONTROLLER_HW_OBJECT_ID_7                           (uint32)8
#define CAN0_CONTROLLER_HW_OBJECT_ID_8                           (uint32)9
#define CAN0_CONTROLLER_HW_OBJECT_ID_9                           (uint32)10
#define CAN0_CONTROLLER_HW_OBJECT_ID_10                          (uint32)11
#define CAN0_CONTROLLER_HW_OBJECT_ID_11                          (uint32)12
#define CAN0_CONTROLLER_HW_OBJECT_ID_12                          (uint32)13
#define CAN0_CONTROLLER_HW_OBJECT_ID_13                          (uint32)14
#define CAN0_CONTROLLER_HW_OBJECT_ID_14                          (uint32)15
#define CAN0_CONTROLLER_HW_OBJECT_ID_15                          (uint32)16
#define CAN0_CONTROLLER_HW_OBJECT_ID_16                          (uint32)17
#define CAN0_CONTROLLER_HW_OBJECT_ID_17                          (uint32)18
#define CAN0_CONTROLLER_HW_OBJECT_ID_18                          (uint32)19
#define CAN0_CONTROLLER_HW_OBJECT_ID_19                          (uint32)20
#define CAN0_CONTROLLER_HW_OBJECT_ID_20                          (uint32)21
#define CAN0_CONTROLLER_HW_OBJECT_ID_21                          (uint32)22
#define CAN0_CONTROLLER_HW_OBJECT_ID_22                          (uint32)23
#define CAN0_CONTROLLER_HW_OBJECT_ID_23                          (uint32)24
#define CAN0_CONTROLLER_HW_OBJECT_ID_24                          (uint32)25
#define CAN0_CONTROLLER_HW_OBJECT_ID_25                          (uint32)26
#define CAN0_CONTROLLER_HW_OBJECT_ID_26                          (uint32)27
#define CAN0_CONTROLLER_HW_OBJECT_ID_27                          (uint32)28
#define CAN0_CONTROLLER_HW_OBJECT_ID_28                          (uint32)29
#define CAN0_CONTROLLER_HW_OBJECT_ID_29                          (uint32)30
#define CAN0_CONTROLLER_HW_OBJECT_ID_30                          (uint32)31
#define CAN0_CONTROLLER_HW_OBJECT_ID_31                          (uint32)32

#define CAN1_CONTROLLER_HW_OBJECT_ID_0                           (uint32)1
#define CAN1_CONTROLLER_HW_OBJECT_ID_1                           (uint32)2
#define CAN1_CONTROLLER_HW_OBJECT_ID_2                           (uint32)3
#define CAN1_CONTROLLER_HW_OBJECT_ID_3                           (uint32)4
#define CAN1_CONTROLLER_HW_OBJECT_ID_4                           (uint32)5
#define CAN1_CONTROLLER_HW_OBJECT_ID_5                           (uint32)6
#define CAN1_CONTROLLER_HW_OBJECT_ID_6                           (uint32)7
#define CAN1_CONTROLLER_HW_OBJECT_ID_7                           (uint32)8
#define CAN1_CONTROLLER_HW_OBJECT_ID_8                           (uint32)9
#define CAN1_CONTROLLER_HW_OBJECT_ID_9                           (uint32)10
#define CAN1_CONTROLLER_HW_OBJECT_ID_10                          (uint32)11
#define CAN1_CONTROLLER_HW_OBJECT_ID_11                          (uint32)12
#define CAN1_CONTROLLER_HW_OBJECT_ID_12                          (uint32)13
#define CAN1_CONTROLLER_HW_OBJECT_ID_13                          (uint32)14
#define CAN1_CONTROLLER_HW_OBJECT_ID_14                          (uint32)15
#define CAN1_CONTROLLER_HW_OBJECT_ID_15                          (uint32)16
#define CAN1_CONTROLLER_HW_OBJECT_ID_16                          (uint32)17
#define CAN1_CONTROLLER_HW_OBJECT_ID_17                          (uint32)18
#define CAN1_CONTROLLER_HW_OBJECT_ID_18                          (uint32)19
#define CAN1_CONTROLLER_HW_OBJECT_ID_19                          (uint32)20
#define CAN1_CONTROLLER_HW_OBJECT_ID_20                          (uint32)21
#define CAN1_CONTROLLER_HW_OBJECT_ID_21                          (uint32)22
#define CAN1_CONTROLLER_HW_OBJECT_ID_22                          (uint32)23
#define CAN1_CONTROLLER_HW_OBJECT_ID_23                          (uint32)24
#define CAN1_CONTROLLER_HW_OBJECT_ID_24                          (uint32)25
#define CAN1_CONTROLLER_HW_OBJECT_ID_25                          (uint32)26
#define CAN1_CONTROLLER_HW_OBJECT_ID_26                          (uint32)27
#define CAN1_CONTROLLER_HW_OBJECT_ID_27                          (uint32)28
#define CAN1_CONTROLLER_HW_OBJECT_ID_28                          (uint32)29
#define CAN1_CONTROLLER_HW_OBJECT_ID_29                          (uint32)30
#define CAN1_CONTROLLER_HW_OBJECT_ID_30                          (uint32)31
#define CAN1_CONTROLLER_HW_OBJECT_ID_31                          (uint32)32

/*
Name: CanObjectType
Parent Container: CanHardwareObject
Description: Specifies if the HardwareObject is used as Transmit or as Receive object
 */
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_0                           (CanObjectType)RECIEVE
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_1                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_2                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_3                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_4                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_5                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_6                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_7                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_8                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_9                           (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_10                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_11                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_12                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_13                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_14                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_15                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_16                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_17                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_18                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_19                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_20                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_21                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_22                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_23                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_24                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_25                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_26                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_27                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_28                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_29                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_30                          (CanObjectType)TRANSMIT
#define CAN0_CONTROLLER_HW_OBJECT_TYPE_31                          (CanObjectType)TRANSMIT

#define CAN1_CONTROLLER_HW_OBJECT_TYPE_0                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_1                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_2                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_3                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_4                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_5                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_6                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_7                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_8                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_9                           (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_10                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_11                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_12                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_13                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_14                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_15                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_16                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_17                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_18                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_19                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_20                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_21                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_22                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_23                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_24                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_25                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_26                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_27                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_28                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_29                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_30                          (CanObjectType)TRANSMIT
#define CAN1_CONTROLLER_HW_OBJECT_TYPE_31                          (CanObjectType)TRANSMIT

/*
Name: CanControllerRef
Parent Container: CanHardwareObject
Description: Reference to CAN Controller to which the HOH is associated to.
 */
#define CAN0_CONTROLLER_HW_OBJECT_REF_0                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_1                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_2                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_3                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_4                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_5                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_6                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_7                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_8                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_9                           CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_10                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_11                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_12                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_13                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_14                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_15                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_16                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_17                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_18                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_19                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_20                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_21                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_22                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_23                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_24                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_25                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_26                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_27                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_28                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_29                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_30                          CAN0_CONTROLLER_ID
#define CAN0_CONTROLLER_HW_OBJECT_REF_31                          CAN0_CONTROLLER_ID

#define CAN1_CONTROLLER_HW_OBJECT_REF_0                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_1                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_2                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_3                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_4                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_5                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_6                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_7                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_8                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_9                           CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_10                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_11                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_12                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_13                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_14                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_15                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_16                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_17                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_18                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_19                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_20                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_21                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_22                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_23                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_24                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_25                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_26                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_27                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_28                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_29                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_30                          CAN1_CONTROLLER_ID
#define CAN1_CONTROLLER_HW_OBJECT_REF_31                          CAN1_CONTROLLER_ID

/**********************************Can Hardware Filter Configurations***************************/
/*
Name: CanHwFilterCode
Parent Container: CanHwFilter
Description: Specifies (together with the filter mask) the identifiers range that passes
             the hardware filter.
 */
#define CAN0_CONTROLLER_HW_FILTER_CODE_0                           0b00000000010
#define CAN0_CONTROLLER_HW_FILTER_CODE_1                           0b00000000010
#define CAN0_CONTROLLER_HW_FILTER_CODE_2                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_3                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_4                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_5                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_6                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_7                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_8                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_9                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_10                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_11                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_12                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_13                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_14                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_15                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_16                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_17                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_18                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_19                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_20                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_21                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_22                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_23                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_24                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_25                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_26                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_27                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_28                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_29                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_30                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_CODE_31                          0b00000000000

#define CAN1_CONTROLLER_HW_FILTER_CODE_0                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_1                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_2                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_3                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_4                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_5                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_6                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_7                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_8                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_9                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_10                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_11                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_12                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_13                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_14                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_15                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_16                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_17                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_18                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_19                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_20                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_21                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_22                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_23                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_24                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_25                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_26                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_27                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_28                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_29                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_30                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_CODE_31                          0b00000000000

/*
Name: CanHwFilterMask
Parent Container: CanHwFilter
Description: Describes a mask for hardware-based filtering of CAN identifiers. The CAN
             identifiers of incoming messages are masked with the appropriate
             CanFilterMaskValue. Bits holding a 0 mean don't care, i.e. do not compare
             the message's identifier in the respective bit position.
             The mask shall be build by filling with leading 0. In case of CanIdType
             EXTENDED or MIXED a 29 bit mask shall be build. In case of CanIdType
 */
#define CAN0_CONTROLLER_HW_FILTER_MASK_0                           0b11111111111
#define CAN0_CONTROLLER_HW_FILTER_MASK_1                           0b11111111111
#define CAN0_CONTROLLER_HW_FILTER_MASK_2                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_3                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_4                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_5                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_6                           0b11111111111
#define CAN0_CONTROLLER_HW_FILTER_MASK_7                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_8                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_9                           0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_10                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_11                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_12                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_13                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_14                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_15                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_16                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_17                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_18                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_19                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_20                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_21                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_22                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_23                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_24                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_25                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_26                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_27                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_28                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_29                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_30                          0b00000000000
#define CAN0_CONTROLLER_HW_FILTER_MASK_31                          0b00000000000

#define CAN1_CONTROLLER_HW_FILTER_MASK_0                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_1                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_2                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_3                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_4                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_5                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_6                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_7                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_8                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_9                           0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_10                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_11                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_12                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_13                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_14                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_15                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_16                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_17                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_18                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_19                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_20                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_21                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_22                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_23                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_24                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_25                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_26                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_27                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_28                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_29                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_30                          0b00000000000
#define CAN1_CONTROLLER_HW_FILTER_MASK_31                          0b00000000000

/**********************************Can Main Function RW Periods Configurations***************************/

/*
Name: CanMainFunctionPeriod
Parent Container: CanMainFunctionRWPeriods
Description: This parameter describes the period for cyclic call to
             Can_MainFunction_Read or Can_MainFunction_Write depending on the
             referring item. Unit is seconds. Different poll-cycles will be configurable if
             more than one CanMainFunctionPeriod is configured. In this case multiple
             Can_MainFunction_Read() or Can_MainFunction_Write() will be provided
             by the CAN Driver module.
 */

#define CAN_MAIN_FUNCTION_PERIOD            (float32)100

#endif /* CAN_CFG_H_ */


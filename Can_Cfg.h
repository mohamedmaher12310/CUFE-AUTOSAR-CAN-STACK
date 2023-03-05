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
#define CanConf_CAN0_RX_PROCESSING         POLLING
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
#define CAN_HOH_NUMBER                     (uint8)5

/*
 *Name :CanHandleType
  Parent Container: CanHardwareObject
  Description :Specifies the type (Full-CAN or Basic-CAN) of a hardware object.
 */

#define CAN_HOH_HANDLETYPE_0              (CanHandleType)BASIC
#define CAN_HOH_HANDLETYPE_1              (CanHandleType)BASIC
#define CAN_HOH_HANDLETYPE_2              (CanHandleType)BASIC
#define CAN_HOH_HANDLETYPE_3              (CanHandleType)BASIC
#define CAN_HOH_HANDLETYPE_4              (CanHandleType)BASIC

/*
 * Name:CanHardwareObjectUsesPolling
   Parent Container:CanHardwareObject
   Description:Enables polling of this hardware object
 */

#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)

#define CAN_HOH_USE_POLLING_0             (STD_OFF)
#define CAN_HOH_USE_POLLING_1             (STD_OFF)
#define CAN_HOH_USE_POLLING_2             (STD_OFF)
#define CAN_HOH_USE_POLLING_3             (STD_OFF)
#define CAN_HOH_USE_POLLING_4             (STD_OFF)
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
#define MAX_HWOBJECT_COUNT                            (uint8)3


#define CAN_HOH_COUNT_0             (uint32)3
#define CAN_HOH_COUNT_1             (uint32)1
#define CAN_HOH_COUNT_2             (uint32)1
#define CAN_HOH_COUNT_3             (uint32)1
#define CAN_HOH_COUNT_4             (uint32)1


/*
Name: CanIdType
Parent Container: CanHardwareObject
Description: Specifies whether the IdValue is of type
- standard identifier
- extended identifier
- mixed mode
ImplementationType: Can_IdType
 */
#define CAN_HOH_ID_TYPE_0                           (CanIdType)ID_STANDARD
#define CAN_HOH_ID_TYPE_1                           (CanIdType)ID_STANDARD
#define CAN_HOH_ID_TYPE_2                           (CanIdType)ID_STANDARD
#define CAN_HOH_ID_TYPE_3                           (CanIdType)ID_STANDARD
#define CAN_HOH_ID_TYPE_4                           (CanIdType)ID_STANDARD


/*
Name: CanObjectId
Parent Container: CanHardwareObject
Description: Holds the handle ID of HRH or HTH. The value of this parameter is unique
             in a given CAN Driver, and it should start with 0 and continue without any
             gaps.
The HRH and HTH Ids share a common ID range.
Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3
 */
#define CAN_HOH_ID_0                           (uint32)0
#define CAN_HOH_ID_1                           (uint32)1
#define CAN_HOH_ID_2                           (uint32)2
#define CAN_HOH_ID_3                           (uint32)3
#define CAN_HOH_ID_4                           (uint32)4

/*
Name: CanObjectType
Parent Container: CanHardwareObject
Description: Specifies if the HardwareObject is used as Transmit or as Receive object
 */
#define CAN_HOH_TYPE_0                           (CanObjectType)RECIEVE
#define CAN_HOH_TYPE_1                           (CanObjectType)TRANSMIT
#define CAN_HOH_TYPE_2                           (CanObjectType)RECIEVE
#define CAN_HOH_TYPE_3                           (CanObjectType)TRANSMIT
#define CAN_HOH_TYPE_4                           (CanObjectType)TRANSMIT


/*
Name: CanControllerRef
Parent Container: CanHardwareObject
Description: Reference to CAN Controller to which the HOH is associated to.
 */
#define CAN_HOH_REF_0                           CAN0_CONTROLLER_ID
#define CAN_HOH_REF_1                           CAN0_CONTROLLER_ID
#define CAN_HOH_REF_2                           CAN0_CONTROLLER_ID
#define CAN_HOH_REF_3                           CAN1_CONTROLLER_ID
#define CAN_HOH_REF_4                           CAN1_CONTROLLER_ID


/**********************************Can Hardware Filter Configurations***************************/
/*
Name: CanHwFilterCode
Parent Container: CanHwFilter
Description: Specifies (together with the filter mask) the identifiers range that passes
             the hardware filter.
 */
#define CAN_HW_FILTER_CODE_0                           0b00000000010
#define CAN_HW_FILTER_CODE_1                           0b00000000010
#define CAN_HW_FILTER_CODE_2                           0b00000000000
#define CAN_HW_FILTER_CODE_3                           0b00000000000
#define CAN_HW_FILTER_CODE_4                           0b00000000000

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
#define CAN_HW_FILTER_MASK_0                           0b11111111111
#define CAN_HW_FILTER_MASK_1                           0b11111111111
#define CAN_HW_FILTER_MASK_2                           0b11111111111
#define CAN_HW_FILTER_MASK_3                           0b00000000000
#define CAN_HW_FILTER_MASK_4                           0b00000000000


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


#define CanIfTxPduTriggerTransmit             STD_ON


#endif /* CAN_CFG_H_ */


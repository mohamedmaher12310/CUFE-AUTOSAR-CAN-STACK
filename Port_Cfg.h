 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: Omar Khedr
 ******************************************************************************/

#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (3U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (1U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for presence of Port_SetPinDirection API */
#define PORT_SET_PIN_DIRECTION_API           (STD_ON)

/* Pre-compile option for presence of Port_SetPinMode API */
#define PORT_SET_PIN_MODE_API                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_ON)

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_PINS                    (39U)

/* Pin Index in the array of structures in Port_PBcfg.c */
#define PortConf_PA0_PIN_ID_INDEX        (uint8)0x00
#define PortConf_PA1_PIN_ID_INDEX        (uint8)0x01
#define PortConf_PA2_PIN_ID_INDEX        (uint8)0x02
#define PortConf_PA3_PIN_ID_INDEX        (uint8)0x03
#define PortConf_PA4_PIN_ID_INDEX        (uint8)0x04
#define PortConf_PA5_PIN_ID_INDEX        (uint8)0x05
#define PortConf_PA6_PIN_ID_INDEX        (uint8)0x06
#define PortConf_PA7_PIN_ID_INDEX        (uint8)0x07
#define PortConf_PB0_PIN_ID_INDEX        (uint8)0x08
#define PortConf_PB1_PIN_ID_INDEX        (uint8)0x09
#define PortConf_PB2_PIN_ID_INDEX        (uint8)0x0A
#define PortConf_PB3_PIN_ID_INDEX        (uint8)0x0B
#define PortConf_PB4_PIN_ID_INDEX        (uint8)0x0C
#define PortConf_PB5_PIN_ID_INDEX        (uint8)0x0D
#define PortConf_PB6_PIN_ID_INDEX        (uint8)0x0E
#define PortConf_PB7_PIN_ID_INDEX        (uint8)0x0F
#define PortConf_PC4_PIN_ID_INDEX        (uint8)0x10
#define PortConf_PC5_PIN_ID_INDEX        (uint8)0x11
#define PortConf_PC6_PIN_ID_INDEX        (uint8)0x12
#define PortConf_PC7_PIN_ID_INDEX        (uint8)0x13
#define PortConf_PD0_PIN_ID_INDEX        (uint8)0x14
#define PortConf_PD1_PIN_ID_INDEX        (uint8)0x15
#define PortConf_PD2_PIN_ID_INDEX        (uint8)0x16
#define PortConf_PD3_PIN_ID_INDEX        (uint8)0x17
#define PortConf_PD4_PIN_ID_INDEX        (uint8)0x18
#define PortConf_PD5_PIN_ID_INDEX        (uint8)0x19
#define PortConf_PD6_PIN_ID_INDEX        (uint8)0x1A
#define PortConf_PD7_PIN_ID_INDEX        (uint8)0x1B
#define PortConf_PE0_PIN_ID_INDEX        (uint8)0x1C
#define PortConf_PE1_PIN_ID_INDEX        (uint8)0x1D
#define PortConf_PE2_PIN_ID_INDEX        (uint8)0x1E
#define PortConf_PE3_PIN_ID_INDEX        (uint8)0x1F
#define PortConf_PE4_PIN_ID_INDEX        (uint8)0x20
#define PortConf_PE5_PIN_ID_INDEX        (uint8)0x21
#define PortConf_PF0_PIN_ID_INDEX        (uint8)0x22
#define PortConf_PF1_PIN_ID_INDEX        (uint8)0x23
#define PortConf_PF2_PIN_ID_INDEX        (uint8)0x24
#define PortConf_PF3_PIN_ID_INDEX        (uint8)0x25
#define PortConf_PF4_PIN_ID_INDEX        (uint8)0x26

/* PORT Configured Port Numbers  */
#define PortConf_PA0_PORT_NUM        (uint8)0
#define PortConf_PA1_PORT_NUM        (uint8)0
#define PortConf_PA2_PORT_NUM        (uint8)0
#define PortConf_PA3_PORT_NUM        (uint8)0
#define PortConf_PA4_PORT_NUM        (uint8)0
#define PortConf_PA5_PORT_NUM        (uint8)0
#define PortConf_PA6_PORT_NUM        (uint8)0
#define PortConf_PA7_PORT_NUM        (uint8)0
#define PortConf_PB0_PORT_NUM        (uint8)1
#define PortConf_PB1_PORT_NUM        (uint8)1
#define PortConf_PB2_PORT_NUM        (uint8)1
#define PortConf_PB3_PORT_NUM        (uint8)1
#define PortConf_PB4_PORT_NUM        (uint8)1
#define PortConf_PB5_PORT_NUM        (uint8)1
#define PortConf_PB6_PORT_NUM        (uint8)1
#define PortConf_PB7_PORT_NUM        (uint8)1
#define PortConf_PC4_PORT_NUM        (uint8)2
#define PortConf_PC5_PORT_NUM        (uint8)2
#define PortConf_PC6_PORT_NUM        (uint8)2
#define PortConf_PC7_PORT_NUM        (uint8)2
#define PortConf_PD0_PORT_NUM        (uint8)3
#define PortConf_PD1_PORT_NUM        (uint8)3
#define PortConf_PD2_PORT_NUM        (uint8)3
#define PortConf_PD3_PORT_NUM        (uint8)3
#define PortConf_PD4_PORT_NUM        (uint8)3
#define PortConf_PD5_PORT_NUM        (uint8)3
#define PortConf_PD6_PORT_NUM        (uint8)3
#define PortConf_PD7_PORT_NUM        (uint8)3
#define PortConf_PE0_PORT_NUM        (uint8)4
#define PortConf_PE1_PORT_NUM        (uint8)4
#define PortConf_PE2_PORT_NUM        (uint8)4
#define PortConf_PE3_PORT_NUM        (uint8)4
#define PortConf_PE4_PORT_NUM        (uint8)4
#define PortConf_PE5_PORT_NUM        (uint8)4
#define PortConf_PF0_PORT_NUM        (uint8)5
#define PortConf_PF1_PORT_NUM        (uint8)5
#define PortConf_PF2_PORT_NUM        (uint8)5
#define PortConf_PF3_PORT_NUM        (uint8)5
#define PortConf_PF4_PORT_NUM        (uint8)5   

/* PORT Configured Pin Numbers */
#define PortConf_PA0_PIN_NUM        (Port_PinType)0
#define PortConf_PA1_PIN_NUM        (Port_PinType)1
#define PortConf_PA2_PIN_NUM        (Port_PinType)2
#define PortConf_PA3_PIN_NUM        (Port_PinType)3
#define PortConf_PA4_PIN_NUM        (Port_PinType)4
#define PortConf_PA5_PIN_NUM        (Port_PinType)5
#define PortConf_PA6_PIN_NUM        (Port_PinType)6
#define PortConf_PA7_PIN_NUM        (Port_PinType)7
#define PortConf_PB0_PIN_NUM        (Port_PinType)0
#define PortConf_PB1_PIN_NUM        (Port_PinType)1
#define PortConf_PB2_PIN_NUM        (Port_PinType)2
#define PortConf_PB3_PIN_NUM        (Port_PinType)3
#define PortConf_PB4_PIN_NUM        (Port_PinType)4
#define PortConf_PB5_PIN_NUM        (Port_PinType)5
#define PortConf_PB6_PIN_NUM        (Port_PinType)6
#define PortConf_PB7_PIN_NUM        (Port_PinType)7
#define PortConf_PC4_PIN_NUM        (Port_PinType)4
#define PortConf_PC5_PIN_NUM        (Port_PinType)5
#define PortConf_PC6_PIN_NUM        (Port_PinType)6
#define PortConf_PC7_PIN_NUM        (Port_PinType)7
#define PortConf_PD0_PIN_NUM        (Port_PinType)0
#define PortConf_PD1_PIN_NUM        (Port_PinType)1
#define PortConf_PD2_PIN_NUM        (Port_PinType)2
#define PortConf_PD3_PIN_NUM        (Port_PinType)3
#define PortConf_PD4_PIN_NUM        (Port_PinType)4
#define PortConf_PD5_PIN_NUM        (Port_PinType)5
#define PortConf_PD6_PIN_NUM        (Port_PinType)6
#define PortConf_PD7_PIN_NUM        (Port_PinType)7
#define PortConf_PE0_PIN_NUM        (Port_PinType)0
#define PortConf_PE1_PIN_NUM        (Port_PinType)1
#define PortConf_PE2_PIN_NUM        (Port_PinType)2
#define PortConf_PE3_PIN_NUM        (Port_PinType)3
#define PortConf_PE4_PIN_NUM        (Port_PinType)4
#define PortConf_PE5_PIN_NUM        (Port_PinType)5
#define PortConf_PF0_PIN_NUM        (Port_PinType)0
#define PortConf_PF1_PIN_NUM        (Port_PinType)1
#define PortConf_PF2_PIN_NUM        (Port_PinType)2
#define PortConf_PF3_PIN_NUM        (Port_PinType)3
#define PortConf_PF4_PIN_NUM        (Port_PinType)4   
   
/* 
 * PORT Configured Pin Directions 
 * by default all pins are configured as GPIO Input, except for LEDs connected at PF1,PF2,PF3
 */
#define PortConf_PA0_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA1_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA2_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA3_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA5_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA6_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PA7_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB0_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB1_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB2_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB3_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB5_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PB6_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PB7_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PC4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PC5_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PC6_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PC7_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD0_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD1_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD2_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD3_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD5_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD6_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PD7_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE0_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE1_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE2_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE3_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PE5_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PF0_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN
#define PortConf_PF1_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PF2_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PF3_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_OUT
#define PortConf_PF4_PIN_DIRECTION         (Port_PinDirectionType)PORT_PIN_IN

/* 
 * PORT Configured Pin Modes 
 * by default all pins are configured as GPIO 
 */
#define PortConf_PA0_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA1_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA2_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA3_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA4_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA5_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA6_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PA7_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB0_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB1_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB2_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB3_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB4_PIN_MODE         (Port_PinMode)CAN
#define PortConf_PB5_PIN_MODE         (Port_PinMode)CAN
#define PortConf_PB6_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PB7_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PC4_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PC5_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PC6_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PC7_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD0_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD1_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD2_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD3_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD4_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD5_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD6_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PD7_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE0_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE1_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE2_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE3_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE4_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PE5_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PF0_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PF1_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PF2_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PF3_PIN_MODE         (Port_PinMode)GPIO
#define PortConf_PF4_PIN_MODE         (Port_PinMode)GPIO

/* 
 * PORT Configured Pin Internal Resistor 
 * by default all pins are configured as inputs in pull-up configuration,
 * except for LEDs at PF1,PF2,PF3 is output  
 */
#define PortConf_PA0_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA1_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA2_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA3_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA5_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA6_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PA7_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB0_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB1_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB2_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB3_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB5_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)OFF
#define PortConf_PB6_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PB7_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PC4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PC5_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PC6_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PC7_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD0_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD1_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD2_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD3_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD5_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD6_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PD7_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE0_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE1_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE2_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE3_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PE5_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PF0_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP
#define PortConf_PF1_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)OFF
#define PortConf_PF2_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)OFF
#define PortConf_PF3_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)OFF
#define PortConf_PF4_PIN_INTERNAL_RESISTOR         (Port_InternalResistorType)PULL_UP

/* 
 * PORT Configured Pin Initial Value 
 * by default all pins are configured as inputs so the have no initial value,
 * except for LED at PF1 is output with initial value = STD_LOW  
 */
#define PortConf_PA0_PIN_INITIAL_VALUE         STD_LOW 
#define PortConf_PA1_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PA2_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PA3_PIN_INITIAL_VALUE         STD_LOW 
#define PortConf_PA4_PIN_INITIAL_VALUE         STD_LOW 
#define PortConf_PA5_PIN_INITIAL_VALUE         STD_LOW 
#define PortConf_PA6_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PA7_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB0_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB1_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB2_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB3_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB4_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB5_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB6_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PB7_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PC4_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PC5_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PC6_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PC7_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD0_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD1_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD2_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD3_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD4_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD5_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD6_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PD7_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE0_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE1_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE2_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE3_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE4_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PE5_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PF0_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PF1_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PF2_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PF3_PIN_INITIAL_VALUE         STD_LOW
#define PortConf_PF4_PIN_INITIAL_VALUE         STD_LOW

/* 
 * PORT Configured Pin Direction changeability
 * by default all pins are changeable  
 */
#define PortConf_PA0_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA1_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA2_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA3_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA4_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA5_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA6_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PA7_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB0_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB1_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB2_PIN_DIRECTION_CHANGE         STD_ON 
#define PortConf_PB3_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB4_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB5_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB6_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PB7_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PC4_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PC5_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PC6_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PC7_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD0_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD1_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD2_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD3_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD4_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD5_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD6_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PD7_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE0_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE1_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE2_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE3_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE4_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PE5_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PF0_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PF1_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PF2_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PF3_PIN_DIRECTION_CHANGE         STD_ON
#define PortConf_PF4_PIN_DIRECTION_CHANGE         STD_ON
   
/* 
 * PORT Configured Pin Mode changeability
 * by default all pins are changeable  
 */
#define PortConf_PA0_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA1_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA2_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA3_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA4_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA5_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA6_PIN_MODE_CHANGE         STD_ON
#define PortConf_PA7_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB0_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB1_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB2_PIN_MODE_CHANGE         STD_ON 
#define PortConf_PB3_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB4_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB5_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB6_PIN_MODE_CHANGE         STD_ON
#define PortConf_PB7_PIN_MODE_CHANGE         STD_ON
#define PortConf_PC4_PIN_MODE_CHANGE         STD_ON
#define PortConf_PC5_PIN_MODE_CHANGE         STD_ON
#define PortConf_PC6_PIN_MODE_CHANGE         STD_ON
#define PortConf_PC7_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD0_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD1_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD2_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD3_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD4_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD5_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD6_PIN_MODE_CHANGE         STD_ON
#define PortConf_PD7_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE0_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE1_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE2_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE3_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE4_PIN_MODE_CHANGE         STD_ON
#define PortConf_PE5_PIN_MODE_CHANGE         STD_ON
#define PortConf_PF0_PIN_MODE_CHANGE         STD_ON
#define PortConf_PF1_PIN_MODE_CHANGE         STD_ON
#define PortConf_PF2_PIN_MODE_CHANGE         STD_ON
#define PortConf_PF3_PIN_MODE_CHANGE         STD_ON
#define PortConf_PF4_PIN_MODE_CHANGE         STD_ON


   
#endif /* PORT_CFG_H */

 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "Port.h"

/*
 * Module Version 1.0.0
 */
#define PORT_PBCFG_SW_MAJOR_VERSION              (1U)
#define PORT_PBCFG_SW_MINOR_VERSION              (0U)
#define PORT_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define PORT_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

/* AUTOSAR Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Dio_PBcfg.c and Dio.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
                                             PortConf_PA0_PORT_NUM,PortConf_PA0_PIN_NUM,PortConf_PA0_PIN_DIRECTION,PortConf_PA0_PIN_MODE,PortConf_PA0_PIN_INTERNAL_RESISTOR,PortConf_PA0_PIN_INITIAL_VALUE,PortConf_PA0_PIN_DIRECTION_CHANGE,PortConf_PA0_PIN_MODE_CHANGE,
                                             PortConf_PA1_PORT_NUM,PortConf_PA1_PIN_NUM,PortConf_PA1_PIN_DIRECTION,PortConf_PA1_PIN_MODE,PortConf_PA1_PIN_INTERNAL_RESISTOR,PortConf_PA1_PIN_INITIAL_VALUE,PortConf_PA1_PIN_DIRECTION_CHANGE,PortConf_PA1_PIN_MODE_CHANGE,
                                             PortConf_PA2_PORT_NUM,PortConf_PA2_PIN_NUM,PortConf_PA2_PIN_DIRECTION,PortConf_PA2_PIN_MODE,PortConf_PA2_PIN_INTERNAL_RESISTOR,PortConf_PA2_PIN_INITIAL_VALUE,PortConf_PA2_PIN_DIRECTION_CHANGE,PortConf_PA2_PIN_MODE_CHANGE,
                                             PortConf_PA3_PORT_NUM,PortConf_PA3_PIN_NUM,PortConf_PA3_PIN_DIRECTION,PortConf_PA3_PIN_MODE,PortConf_PA3_PIN_INTERNAL_RESISTOR,PortConf_PA3_PIN_INITIAL_VALUE,PortConf_PA3_PIN_DIRECTION_CHANGE,PortConf_PA3_PIN_MODE_CHANGE,
                                             PortConf_PA4_PORT_NUM,PortConf_PA4_PIN_NUM,PortConf_PA4_PIN_DIRECTION,PortConf_PA4_PIN_MODE,PortConf_PA4_PIN_INTERNAL_RESISTOR,PortConf_PA4_PIN_INITIAL_VALUE,PortConf_PA4_PIN_DIRECTION_CHANGE,PortConf_PA4_PIN_MODE_CHANGE,
                                             PortConf_PA5_PORT_NUM,PortConf_PA5_PIN_NUM,PortConf_PA5_PIN_DIRECTION,PortConf_PA5_PIN_MODE,PortConf_PA5_PIN_INTERNAL_RESISTOR,PortConf_PA5_PIN_INITIAL_VALUE,PortConf_PA5_PIN_DIRECTION_CHANGE,PortConf_PA5_PIN_MODE_CHANGE,
                                             PortConf_PA6_PORT_NUM,PortConf_PA6_PIN_NUM,PortConf_PA6_PIN_DIRECTION,PortConf_PA6_PIN_MODE,PortConf_PA6_PIN_INTERNAL_RESISTOR,PortConf_PA6_PIN_INITIAL_VALUE,PortConf_PA6_PIN_DIRECTION_CHANGE,PortConf_PA6_PIN_MODE_CHANGE,
                                             PortConf_PA7_PORT_NUM,PortConf_PA7_PIN_NUM,PortConf_PA7_PIN_DIRECTION,PortConf_PA7_PIN_MODE,PortConf_PA7_PIN_INTERNAL_RESISTOR,PortConf_PA7_PIN_INITIAL_VALUE,PortConf_PA7_PIN_DIRECTION_CHANGE,PortConf_PA7_PIN_MODE_CHANGE,
                                             PortConf_PB0_PORT_NUM,PortConf_PB0_PIN_NUM,PortConf_PB0_PIN_DIRECTION,PortConf_PB0_PIN_MODE,PortConf_PB0_PIN_INTERNAL_RESISTOR,PortConf_PB0_PIN_INITIAL_VALUE,PortConf_PB0_PIN_DIRECTION_CHANGE,PortConf_PB0_PIN_MODE_CHANGE,
                                             PortConf_PB1_PORT_NUM,PortConf_PB1_PIN_NUM,PortConf_PB1_PIN_DIRECTION,PortConf_PB1_PIN_MODE,PortConf_PB1_PIN_INTERNAL_RESISTOR,PortConf_PB1_PIN_INITIAL_VALUE,PortConf_PB1_PIN_DIRECTION_CHANGE,PortConf_PB1_PIN_MODE_CHANGE,
                                             PortConf_PB2_PORT_NUM,PortConf_PB2_PIN_NUM,PortConf_PB2_PIN_DIRECTION,PortConf_PB2_PIN_MODE,PortConf_PB2_PIN_INTERNAL_RESISTOR,PortConf_PB2_PIN_INITIAL_VALUE,PortConf_PB2_PIN_DIRECTION_CHANGE,PortConf_PB2_PIN_MODE_CHANGE,
                                             PortConf_PB3_PORT_NUM,PortConf_PB3_PIN_NUM,PortConf_PB3_PIN_DIRECTION,PortConf_PB3_PIN_MODE,PortConf_PB3_PIN_INTERNAL_RESISTOR,PortConf_PB3_PIN_INITIAL_VALUE,PortConf_PB3_PIN_DIRECTION_CHANGE,PortConf_PB3_PIN_MODE_CHANGE,
                                             PortConf_PB4_PORT_NUM,PortConf_PB4_PIN_NUM,PortConf_PB4_PIN_DIRECTION,PortConf_PB4_PIN_MODE,PortConf_PB4_PIN_INTERNAL_RESISTOR,PortConf_PB4_PIN_INITIAL_VALUE,PortConf_PB4_PIN_DIRECTION_CHANGE,PortConf_PB4_PIN_MODE_CHANGE,
                                             PortConf_PB5_PORT_NUM,PortConf_PB5_PIN_NUM,PortConf_PB5_PIN_DIRECTION,PortConf_PB5_PIN_MODE,PortConf_PB5_PIN_INTERNAL_RESISTOR,PortConf_PB5_PIN_INITIAL_VALUE,PortConf_PB5_PIN_DIRECTION_CHANGE,PortConf_PB5_PIN_MODE_CHANGE,
                                             PortConf_PB6_PORT_NUM,PortConf_PB6_PIN_NUM,PortConf_PB6_PIN_DIRECTION,PortConf_PB6_PIN_MODE,PortConf_PB6_PIN_INTERNAL_RESISTOR,PortConf_PB6_PIN_INITIAL_VALUE,PortConf_PB6_PIN_DIRECTION_CHANGE,PortConf_PB6_PIN_MODE_CHANGE,
                                             PortConf_PB7_PORT_NUM,PortConf_PB7_PIN_NUM,PortConf_PB7_PIN_DIRECTION,PortConf_PB7_PIN_MODE,PortConf_PB7_PIN_INTERNAL_RESISTOR,PortConf_PB7_PIN_INITIAL_VALUE,PortConf_PB7_PIN_DIRECTION_CHANGE,PortConf_PB7_PIN_MODE_CHANGE,
                                             PortConf_PC4_PORT_NUM,PortConf_PC4_PIN_NUM,PortConf_PC4_PIN_DIRECTION,PortConf_PC4_PIN_MODE,PortConf_PC4_PIN_INTERNAL_RESISTOR,PortConf_PC4_PIN_INITIAL_VALUE,PortConf_PC4_PIN_DIRECTION_CHANGE,PortConf_PC4_PIN_MODE_CHANGE,
                                             PortConf_PC5_PORT_NUM,PortConf_PC5_PIN_NUM,PortConf_PC5_PIN_DIRECTION,PortConf_PC5_PIN_MODE,PortConf_PC5_PIN_INTERNAL_RESISTOR,PortConf_PC5_PIN_INITIAL_VALUE,PortConf_PC5_PIN_DIRECTION_CHANGE,PortConf_PC5_PIN_MODE_CHANGE,
                                             PortConf_PC6_PORT_NUM,PortConf_PC6_PIN_NUM,PortConf_PC6_PIN_DIRECTION,PortConf_PC6_PIN_MODE,PortConf_PC6_PIN_INTERNAL_RESISTOR,PortConf_PC6_PIN_INITIAL_VALUE,PortConf_PC6_PIN_DIRECTION_CHANGE,PortConf_PC6_PIN_MODE_CHANGE,
                                             PortConf_PC7_PORT_NUM,PortConf_PC7_PIN_NUM,PortConf_PC7_PIN_DIRECTION,PortConf_PC7_PIN_MODE,PortConf_PC7_PIN_INTERNAL_RESISTOR,PortConf_PC7_PIN_INITIAL_VALUE,PortConf_PC7_PIN_DIRECTION_CHANGE,PortConf_PC7_PIN_MODE_CHANGE,
                                             PortConf_PD0_PORT_NUM,PortConf_PD0_PIN_NUM,PortConf_PD0_PIN_DIRECTION,PortConf_PD0_PIN_MODE,PortConf_PD0_PIN_INTERNAL_RESISTOR,PortConf_PD0_PIN_INITIAL_VALUE,PortConf_PD0_PIN_DIRECTION_CHANGE,PortConf_PD0_PIN_MODE_CHANGE,
                                             PortConf_PD1_PORT_NUM,PortConf_PD1_PIN_NUM,PortConf_PD1_PIN_DIRECTION,PortConf_PD1_PIN_MODE,PortConf_PD1_PIN_INTERNAL_RESISTOR,PortConf_PD1_PIN_INITIAL_VALUE,PortConf_PD1_PIN_DIRECTION_CHANGE,PortConf_PD1_PIN_MODE_CHANGE,
                                             PortConf_PD2_PORT_NUM,PortConf_PD2_PIN_NUM,PortConf_PD2_PIN_DIRECTION,PortConf_PD2_PIN_MODE,PortConf_PD2_PIN_INTERNAL_RESISTOR,PortConf_PD2_PIN_INITIAL_VALUE,PortConf_PD2_PIN_DIRECTION_CHANGE,PortConf_PD2_PIN_MODE_CHANGE,
                                             PortConf_PD3_PORT_NUM,PortConf_PD3_PIN_NUM,PortConf_PD3_PIN_DIRECTION,PortConf_PD3_PIN_MODE,PortConf_PD3_PIN_INTERNAL_RESISTOR,PortConf_PD3_PIN_INITIAL_VALUE,PortConf_PD3_PIN_DIRECTION_CHANGE,PortConf_PD3_PIN_MODE_CHANGE,
                                             PortConf_PD4_PORT_NUM,PortConf_PD4_PIN_NUM,PortConf_PD4_PIN_DIRECTION,PortConf_PD4_PIN_MODE,PortConf_PD4_PIN_INTERNAL_RESISTOR,PortConf_PD4_PIN_INITIAL_VALUE,PortConf_PD4_PIN_DIRECTION_CHANGE,PortConf_PD4_PIN_MODE_CHANGE,
                                             PortConf_PD5_PORT_NUM,PortConf_PD5_PIN_NUM,PortConf_PD5_PIN_DIRECTION,PortConf_PD5_PIN_MODE,PortConf_PD5_PIN_INTERNAL_RESISTOR,PortConf_PD5_PIN_INITIAL_VALUE,PortConf_PD5_PIN_DIRECTION_CHANGE,PortConf_PD5_PIN_MODE_CHANGE,
                                             PortConf_PD6_PORT_NUM,PortConf_PD6_PIN_NUM,PortConf_PD6_PIN_DIRECTION,PortConf_PD6_PIN_MODE,PortConf_PD6_PIN_INTERNAL_RESISTOR,PortConf_PD6_PIN_INITIAL_VALUE,PortConf_PD6_PIN_DIRECTION_CHANGE,PortConf_PD6_PIN_MODE_CHANGE,
                                             PortConf_PD7_PORT_NUM,PortConf_PD7_PIN_NUM,PortConf_PD7_PIN_DIRECTION,PortConf_PD7_PIN_MODE,PortConf_PD7_PIN_INTERNAL_RESISTOR,PortConf_PD7_PIN_INITIAL_VALUE,PortConf_PD7_PIN_DIRECTION_CHANGE,PortConf_PD7_PIN_MODE_CHANGE,
                                             PortConf_PE0_PORT_NUM,PortConf_PE0_PIN_NUM,PortConf_PE0_PIN_DIRECTION,PortConf_PE0_PIN_MODE,PortConf_PE0_PIN_INTERNAL_RESISTOR,PortConf_PE0_PIN_INITIAL_VALUE,PortConf_PE0_PIN_DIRECTION_CHANGE,PortConf_PE0_PIN_MODE_CHANGE,
                                             PortConf_PE1_PORT_NUM,PortConf_PE1_PIN_NUM,PortConf_PE1_PIN_DIRECTION,PortConf_PE1_PIN_MODE,PortConf_PE1_PIN_INTERNAL_RESISTOR,PortConf_PE1_PIN_INITIAL_VALUE,PortConf_PE1_PIN_DIRECTION_CHANGE,PortConf_PE1_PIN_MODE_CHANGE,
                                             PortConf_PE2_PORT_NUM,PortConf_PE2_PIN_NUM,PortConf_PE2_PIN_DIRECTION,PortConf_PE2_PIN_MODE,PortConf_PE2_PIN_INTERNAL_RESISTOR,PortConf_PE2_PIN_INITIAL_VALUE,PortConf_PE2_PIN_DIRECTION_CHANGE,PortConf_PE2_PIN_MODE_CHANGE,
                                             PortConf_PE3_PORT_NUM,PortConf_PE3_PIN_NUM,PortConf_PE3_PIN_DIRECTION,PortConf_PE3_PIN_MODE,PortConf_PE3_PIN_INTERNAL_RESISTOR,PortConf_PE3_PIN_INITIAL_VALUE,PortConf_PE3_PIN_DIRECTION_CHANGE,PortConf_PE3_PIN_MODE_CHANGE,
                                             PortConf_PE4_PORT_NUM,PortConf_PE4_PIN_NUM,PortConf_PE4_PIN_DIRECTION,PortConf_PE4_PIN_MODE,PortConf_PE4_PIN_INTERNAL_RESISTOR,PortConf_PE4_PIN_INITIAL_VALUE,PortConf_PE4_PIN_DIRECTION_CHANGE,PortConf_PE4_PIN_MODE_CHANGE,
                                             PortConf_PE5_PORT_NUM,PortConf_PE5_PIN_NUM,PortConf_PE5_PIN_DIRECTION,PortConf_PE5_PIN_MODE,PortConf_PE5_PIN_INTERNAL_RESISTOR,PortConf_PE5_PIN_INITIAL_VALUE,PortConf_PE5_PIN_DIRECTION_CHANGE,PortConf_PE5_PIN_MODE_CHANGE,
                                             PortConf_PF0_PORT_NUM,PortConf_PF0_PIN_NUM,PortConf_PF0_PIN_DIRECTION,PortConf_PF0_PIN_MODE,PortConf_PF0_PIN_INTERNAL_RESISTOR,PortConf_PF0_PIN_INITIAL_VALUE,PortConf_PF0_PIN_DIRECTION_CHANGE,PortConf_PF0_PIN_MODE_CHANGE,
                                             PortConf_PF1_PORT_NUM,PortConf_PF1_PIN_NUM,PortConf_PF1_PIN_DIRECTION,PortConf_PF1_PIN_MODE,PortConf_PF1_PIN_INTERNAL_RESISTOR,PortConf_PF1_PIN_INITIAL_VALUE,PortConf_PF1_PIN_DIRECTION_CHANGE,PortConf_PF1_PIN_MODE_CHANGE,
                                             PortConf_PF2_PORT_NUM,PortConf_PF2_PIN_NUM,PortConf_PF2_PIN_DIRECTION,PortConf_PF2_PIN_MODE,PortConf_PF2_PIN_INTERNAL_RESISTOR,PortConf_PF2_PIN_INITIAL_VALUE,PortConf_PF2_PIN_DIRECTION_CHANGE,PortConf_PF2_PIN_MODE_CHANGE,
                                             PortConf_PF3_PORT_NUM,PortConf_PF3_PIN_NUM,PortConf_PF3_PIN_DIRECTION,PortConf_PF3_PIN_MODE,PortConf_PF3_PIN_INTERNAL_RESISTOR,PortConf_PF3_PIN_INITIAL_VALUE,PortConf_PF3_PIN_DIRECTION_CHANGE,PortConf_PF3_PIN_MODE_CHANGE,
                                             PortConf_PF4_PORT_NUM,PortConf_PF4_PIN_NUM,PortConf_PF4_PIN_DIRECTION,PortConf_PF4_PIN_MODE,PortConf_PF4_PIN_INTERNAL_RESISTOR,PortConf_PF4_PIN_INITIAL_VALUE,PortConf_PF4_PIN_DIRECTION_CHANGE,PortConf_PF4_PIN_MODE_CHANGE                                                      
				         };

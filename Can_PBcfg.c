/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Can Driver
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "Can.h"

/*
 * Module Version 1.0.0
 */
#define CAN_PBCFG_SW_MAJOR_VERSION              (1U)
#define CAN_PBCFG_SW_MINOR_VERSION              (0U)
#define CAN_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define CAN_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define CAN_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define CAN_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

/* AUTOSAR Version checking between Can_PBcfg.c and Can.h files */
#if ((CAN_PBCFG_AR_RELEASE_MAJOR_VERSION != CAN_AR_RELEASE_MAJOR_VERSION)\
        ||  (CAN_PBCFG_AR_RELEASE_MINOR_VERSION != CAN_AR_RELEASE_MINOR_VERSION)\
        ||  (CAN_PBCFG_AR_RELEASE_PATCH_VERSION != CAN_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Can_PBcfg.c and Can.h files */
#if ((CAN_PBCFG_SW_MAJOR_VERSION != CAN_SW_MAJOR_VERSION)\
        ||  (CAN_PBCFG_SW_MINOR_VERSION != CAN_SW_MINOR_VERSION)\
        ||  (CAN_PBCFG_SW_PATCH_VERSION != CAN_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Can_Init API */
const Can_ConfigType Can_Configuration = {
                                          /*Controller 0*/

                                           /*BaudRate*/

                                            CanConf_CAN0_CONTROLLER_BAUDRATE,
                                            CanConf_CAN0_CONTROLLER_PROPSEG,
                                            CanConf_CAN0_CONTROLLER_SEG1,
                                            CanConf_CAN0_CONTROLLER_SEG2,
                                            CanConf_CAN0_CONTROLLER_SYNC_JUMP_WIDTH,


                                            /*HOH 0*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_0,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_0,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_0,
                                            CAN0_CONTROLLER_ID_TYPE_0,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_0,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_0,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_0,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_0,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_0,

                                            /*HOH 1*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_1,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_1,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_1,
                                            CAN0_CONTROLLER_ID_TYPE_1,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_1,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_1,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_1,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_1,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_1,

                                            /*HOH 2*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_2,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_2,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_2,
                                            CAN0_CONTROLLER_ID_TYPE_2,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_2,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_2,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_2,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_2,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_2,

                                            /*HOH 3*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_3,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_3,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_3,
                                            CAN0_CONTROLLER_ID_TYPE_3,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_3,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_3,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_3,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_3,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_3,

                                            /*HOH 4*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_4,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_4,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_4,
                                            CAN0_CONTROLLER_ID_TYPE_4,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_4,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_4,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_4,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_4,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_4,

                                            /*HOH 5*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_5,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_5,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_5,
                                            CAN0_CONTROLLER_ID_TYPE_5,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_5,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_5,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_5,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_5,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_5,

                                            /*HOH 6*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_6,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_6,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_6,
                                            CAN0_CONTROLLER_ID_TYPE_6,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_6,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_6,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_6,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_6,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_6,

                                            /*HOH 7*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_7,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_7,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_7,
                                            CAN0_CONTROLLER_ID_TYPE_7,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_7,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_7,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_7,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_7,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_7,

                                            /*HOH 8*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_8,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_8,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_8,
                                            CAN0_CONTROLLER_ID_TYPE_8,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_8,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_8,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_8,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_8,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_8,

                                            /*HOH 9*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_9,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_9,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_9,
                                            CAN0_CONTROLLER_ID_TYPE_9,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_9,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_9,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_9,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_9,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_9,

                                            /*HOH 10*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_10,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_10,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_10,
                                            CAN0_CONTROLLER_ID_TYPE_10,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_10,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_10,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_10,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_10,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_10,

                                            /*HOH 11*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_11,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_11,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_11,
                                            CAN0_CONTROLLER_ID_TYPE_11,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_11,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_11,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_11,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_11,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_11,

                                            /*HOH 12*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_12,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_12,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_12,
                                            CAN0_CONTROLLER_ID_TYPE_12,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_12,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_12,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_12,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_12,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_12,

                                            /*HOH 13*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_13,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_13,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_13,
                                            CAN0_CONTROLLER_ID_TYPE_13,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_13,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_13,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_13,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_13,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_13,
                                            /*HOH 14*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_14,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_14,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_14,
                                            CAN0_CONTROLLER_ID_TYPE_14,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_14,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_14,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_14,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_14,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_14,

                                            /*HOH 15*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_15,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_15,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_15,
                                            CAN0_CONTROLLER_ID_TYPE_15,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_15,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_15,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_15,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_15,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_15,

                                            /*HOH 16*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_16,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_16,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_16,
                                            CAN0_CONTROLLER_ID_TYPE_16,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_16,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_16,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_16,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_16,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_16,

                                            /*HOH 17*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_17,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_17,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_17,
                                            CAN0_CONTROLLER_ID_TYPE_17,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_17,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_17,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_17,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_17,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_17,

                                            /*HOH 18*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_18,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_18,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_18,
                                            CAN0_CONTROLLER_ID_TYPE_18,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_18,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_18,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_18,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_18,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_18,

                                            /*HOH 19*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_19,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_19,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_19,
                                            CAN0_CONTROLLER_ID_TYPE_19,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_19,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_19,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_19,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_19,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_19,

                                            /*HOH 20*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_20,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_20,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_20,
                                            CAN0_CONTROLLER_ID_TYPE_20,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_20,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_20,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_20,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_20,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_20,

                                            /*HOH 21*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_21,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_21,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_21,
                                            CAN0_CONTROLLER_ID_TYPE_21,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_21,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_21,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_21,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_21,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_21,

                                            /*HOH 22*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_22,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_22,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_22,
                                            CAN0_CONTROLLER_ID_TYPE_22,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_22,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_22,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_22,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_22,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_22,

                                            /*HOH 23*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_23,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_23,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_23,
                                            CAN0_CONTROLLER_ID_TYPE_23,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_23,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_23,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_23,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_23,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_23,

                                            /*HOH 24*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_24,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_24,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_24,
                                            CAN0_CONTROLLER_ID_TYPE_24,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_24,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_24,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_24,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_24,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_24,

                                            /*HOH 25*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_25,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_25,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_25,
                                            CAN0_CONTROLLER_ID_TYPE_25,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_25,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_25,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_25,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_25,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_25,

                                            /*HOH 26*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_26,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_26,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_26,
                                            CAN0_CONTROLLER_ID_TYPE_26,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_26,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_26,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_26,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_26,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_26,

                                            /*HOH 27*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_27,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_27,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_27,
                                            CAN0_CONTROLLER_ID_TYPE_27,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_27,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_27,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_27,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_27,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_27,

                                            /*HOH 28*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_28,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_28,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_28,
                                            CAN0_CONTROLLER_ID_TYPE_28,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_28,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_28,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_28,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_28,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_28,

                                            /*HOH 29*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_29,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_29,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_29,
                                            CAN0_CONTROLLER_ID_TYPE_29,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_29,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_29,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_29,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_29,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_29,

                                            /*HOH 30*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_30,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_30,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_30,
                                            CAN0_CONTROLLER_ID_TYPE_30,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_30,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_30,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_30,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_30,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_30,

                                            /*HOH 31*/
                                            CAN0_CONTROLLER_HW_OBJECT_HANDLETYPE_31,
#if (MIXED == CanConf_CAN0_RX_PROCESSING) || (MIXED == CanConf_CAN0_TX_PROCESSING)
                                            CAN0_CONTROLLER_HW_OBJECT_USE_POLLING_31,
#endif
                                            CAN0_CONTROLLER_HW_OBJECT_COUNT_31,
                                            CAN0_CONTROLLER_ID_TYPE_31,
                                            CAN0_CONTROLLER_HW_OBJECT_ID_31,
                                            CAN0_CONTROLLER_HW_OBJECT_TYPE_31,
                                            CAN0_CONTROLLER_HW_OBJECT_REF_31,
                                            /*Filter Config*/

                                             CAN0_CONTROLLER_HW_FILTER_CODE_31,
                                             CAN0_CONTROLLER_HW_FILTER_MASK_31,



                                          /*Controller 1*/

                                           /*BaudRate*/

                                            CanConf_CAN1_CONTROLLER_BAUDRATE,
                                            CanConf_CAN1_CONTROLLER_PROPSEG,
                                            CanConf_CAN1_CONTROLLER_SEG1,
                                            CanConf_CAN1_CONTROLLER_SEG2,
                                            CanConf_CAN1_CONTROLLER_SYNC_JUMP_WIDTH,


                                            /*HOH 0*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_0,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_0,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_0,
                                            CAN1_CONTROLLER_ID_TYPE_0,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_0,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_0,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_0,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_0,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_0,

                                            /*HOH 1*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_1,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_1,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_1,
                                            CAN1_CONTROLLER_ID_TYPE_1,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_1,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_1,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_1,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_1,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_1,

                                            /*HOH 2*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_2,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_2,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_2,
                                            CAN1_CONTROLLER_ID_TYPE_2,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_2,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_2,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_2,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_2,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_2,

                                            /*HOH 3*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_3,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_3,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_3,
                                            CAN1_CONTROLLER_ID_TYPE_3,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_3,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_3,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_3,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_3,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_3,

                                            /*HOH 4*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_4,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_4,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_4,
                                            CAN1_CONTROLLER_ID_TYPE_4,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_4,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_4,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_4,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_4,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_4,

                                            /*HOH 5*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_5,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_5,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_5,
                                            CAN1_CONTROLLER_ID_TYPE_5,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_5,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_5,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_5,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_5,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_5,

                                            /*HOH 6*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_6,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_6,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_6,
                                            CAN1_CONTROLLER_ID_TYPE_6,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_6,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_6,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_6,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_6,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_6,

                                            /*HOH 7*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_7,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_7,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_7,
                                            CAN1_CONTROLLER_ID_TYPE_7,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_7,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_7,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_7,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_7,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_7,

                                            /*HOH 8*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_8,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_8,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_8,
                                            CAN1_CONTROLLER_ID_TYPE_8,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_8,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_8,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_8,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_8,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_8,

                                            /*HOH 9*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_9,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_9,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_9,
                                            CAN1_CONTROLLER_ID_TYPE_9,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_9,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_9,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_9,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_9,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_9,

                                            /*HOH 10*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_10,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_10,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_10,
                                            CAN1_CONTROLLER_ID_TYPE_10,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_10,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_10,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_10,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_10,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_10,

                                            /*HOH 11*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_11,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_11,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_11,
                                            CAN1_CONTROLLER_ID_TYPE_11,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_11,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_11,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_11,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_11,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_11,

                                            /*HOH 12*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_12,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_12,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_12,
                                            CAN1_CONTROLLER_ID_TYPE_12,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_12,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_12,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_12,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_12,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_12,

                                            /*HOH 13*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_13,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_13,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_13,
                                            CAN1_CONTROLLER_ID_TYPE_13,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_13,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_13,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_13,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_13,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_13,

                                            /*HOH 14*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_14,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_14,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_14,
                                            CAN1_CONTROLLER_ID_TYPE_14,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_14,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_14,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_14,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_14,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_14,

                                            /*HOH 15*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_15,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_15,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_15,
                                            CAN1_CONTROLLER_ID_TYPE_15,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_15,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_15,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_15,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_15,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_15,

                                            /*HOH 16*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_16,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_16,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_16,
                                            CAN1_CONTROLLER_ID_TYPE_16,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_16,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_16,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_16,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_16,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_16,

                                            /*HOH 17*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_17,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_17,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_17,
                                            CAN1_CONTROLLER_ID_TYPE_17,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_17,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_17,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_17,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_17,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_17,

                                            /*HOH 18*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_18,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_18,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_18,
                                            CAN1_CONTROLLER_ID_TYPE_18,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_18,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_18,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_18,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_18,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_18,

                                            /*HOH 19*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_19,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_19,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_19,
                                            CAN1_CONTROLLER_ID_TYPE_19,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_19,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_19,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_19,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_19,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_19,

                                            /*HOH 20*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_20,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_20,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_20,
                                            CAN1_CONTROLLER_ID_TYPE_20,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_20,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_20,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_20,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_20,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_20,

                                            /*HOH 21*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_21,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_21,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_21,
                                            CAN1_CONTROLLER_ID_TYPE_21,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_21,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_21,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_21,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_21,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_21,

                                            /*HOH 22*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_22,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_22,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_22,
                                            CAN1_CONTROLLER_ID_TYPE_22,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_22,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_22,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_22,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_22,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_22,

                                            /*HOH 23*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_23,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_23,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_23,
                                            CAN1_CONTROLLER_ID_TYPE_23,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_23,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_23,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_23,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_23,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_23,

                                            /*HOH 24*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_24,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_24,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_24,
                                            CAN1_CONTROLLER_ID_TYPE_24,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_24,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_24,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_24,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_24,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_24,

                                            /*HOH 25*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_25,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_25,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_25,
                                            CAN1_CONTROLLER_ID_TYPE_25,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_25,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_25,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_25,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_25,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_25,

                                            /*HOH 26*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_26,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_26,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_26,
                                            CAN1_CONTROLLER_ID_TYPE_26,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_26,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_26,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_26,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_26,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_26,

                                            /*HOH 27*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_27,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_27,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_27,
                                            CAN1_CONTROLLER_ID_TYPE_27,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_27,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_27,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_27,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_27,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_27,

                                            /*HOH 28*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_28,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_28,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_28,
                                            CAN1_CONTROLLER_ID_TYPE_28,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_28,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_28,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_28,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_28,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_28,

                                            /*HOH 29*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_29,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_29,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_29,
                                            CAN1_CONTROLLER_ID_TYPE_29,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_29,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_29,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_29,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_29,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_29,

                                            /*HOH 30*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_30,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_30,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_30,
                                            CAN1_CONTROLLER_ID_TYPE_30,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_30,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_30,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_30,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_30,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_30,

                                            /*HOH 31*/
                                            CAN1_CONTROLLER_HW_OBJECT_HANDLETYPE_31,
#if (MIXED == CanConf_CAN1_RX_PROCESSING) || (MIXED == CanConf_CAN1_TX_PROCESSING)
                                            CAN1_CONTROLLER_HW_OBJECT_USE_POLLING_31,
#endif
                                            CAN1_CONTROLLER_HW_OBJECT_COUNT_31,
                                            CAN1_CONTROLLER_ID_TYPE_31,
                                            CAN1_CONTROLLER_HW_OBJECT_ID_31,
                                            CAN1_CONTROLLER_HW_OBJECT_TYPE_31,
                                            CAN1_CONTROLLER_HW_OBJECT_REF_31,
                                            /*Filter Config*/

                                             CAN1_CONTROLLER_HW_FILTER_CODE_31,
                                             CAN1_CONTROLLER_HW_FILTER_MASK_31



};

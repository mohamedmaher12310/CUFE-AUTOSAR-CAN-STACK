/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com_Cfg.c
 *
 * Description: Source file for Com Configurations.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include of Com Header Filer*/
#include "Com.h"

/*
 * Module Version 1.0.0
 */
#define COM_PBCFG_SW_MAJOR_VERSION              (1U)
#define COM_PBCFG_SW_MINOR_VERSION              (0U)
#define COM_PBCFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.3.1
 */
#define COM_PBCFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define COM_PBCFG_AR_RELEASE_MINOR_VERSION     (3U)
#define COM_PBCFG_AR_RELEASE_PATCH_VERSION     (1U)

/* AUTOSAR Version checking between COM_Cfg.c and Com.h files */
#if ((COM_PBCFG_AR_RELEASE_MAJOR_VERSION != COM_AR_RELEASE_MAJOR_VERSION)\
        ||  (COM_PBCFG_AR_RELEASE_MINOR_VERSION != COM_AR_RELEASE_MINOR_VERSION)\
        ||  (COM_PBCFG_AR_RELEASE_PATCH_VERSION != COM_AR_RELEASE_PATCH_VERSION))
#error "The AR version of PBcfg.c does not match the expected version"
#endif

/* Software Version checking between Com_Cfg.c and Com.h files */
#if ((COM_PBCFG_SW_MAJOR_VERSION != COM_SW_MAJOR_VERSION)\
        ||  (COM_PBCFG_SW_MINOR_VERSION != COM_SW_MINOR_VERSION)\
        ||  (COM_PBCFG_SW_PATCH_VERSION != COM_SW_PATCH_VERSION))
#error "The SW version of PBcfg.c does not match the expected version"
#endif

/* PB structure used with Can_Init API */
const Com_ConfigType Com = {
                            .ComIPdu[ZERO] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = SEND,
                                           .ComIPduHandleId = ZERO,
                                           .ComIPduSignalProcessing = IMMEDIATE,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[ZERO] = (ComSignal*)&Com.ComSignal[ZERO],
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = ComMinimumDelayTime_Value,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = ComTxIPduUnusedAreasDefault_Value,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = ComTxModeTimePeriod_Value_0

                                                         }

                                           }
                            },
                            .ComIPdu[ONE] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = RECEIVE,
                                           .ComIPduHandleId = ONE,
                                           .ComIPduSignalProcessing = IMMEDIATE,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[ONE] = (ComSignal*)&Com.ComSignal[EIGHT],
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = ComMinimumDelayTime_Value,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = ComTxIPduUnusedAreasDefault_Value,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = ComTxModeTimePeriod_Value_1

                                                         }

                                           }
                            },
                            .ComIPdu[TWO] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = RECEIVE,
                                           .ComIPduHandleId = TWO,
                                           .ComIPduSignalProcessing = DEFERRED,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[TWO] = (ComSignal*)&Com.ComSignal[SIXTEEN],
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = ComMinimumDelayTime_Value,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = ComTxIPduUnusedAreasDefault_Value,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = ComTxModeTimePeriod_Value_2

                                                         }

                                           }
                            },
                            .ComSignal[ZERO] ={
                                            .ComBitPosition = ZERO,
                                            .ComHandleId = ZERO,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_0,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[ONE] ={
                                            .ComBitPosition = EIGHT,
                                            .ComHandleId = ONE,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_1,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWO] ={
                                            .ComBitPosition = SIXTEEN,
                                            .ComHandleId = TWO,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_2,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[THREE] ={
                                            .ComBitPosition = TWENTY_FOUR,
                                            .ComHandleId = THREE,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_3,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[FOUR] ={
                                            .ComBitPosition = THIRTY_TWO,
                                            .ComHandleId = FOUR,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_4,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[FIVE] ={
                                            .ComBitPosition = FOURTY,
                                            .ComHandleId = FIVE,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_5,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[SIX] ={
                                            .ComBitPosition = FOURTY_EIGHT,
                                            .ComHandleId = SIX,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_6,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[SEVEN] ={
                                            .ComBitPosition = FIFTY_SIX,
                                            .ComHandleId = SEVEN,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_7,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[EIGHT] ={
                                            .ComBitPosition = ZERO,
                                            .ComHandleId = EIGHT,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_8,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[NINE] ={
                                            .ComBitPosition = EIGHT,
                                            .ComHandleId = NINE,
                                            .ComInitialValueOnly=TRUE,
                                            .ComNotification=Com_CbkRxAck_9,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            .ComSignalLength=ONE,

                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = ZERO,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TEN] ={
                                             .ComBitPosition = SIXTEEN,
                                             .ComHandleId = TEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_10,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[ELEVEN] ={
                                             .ComBitPosition = TWENTY_FOUR,
                                             .ComHandleId = ELEVEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_11,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWELVE] ={
                                             .ComBitPosition = THIRTY_TWO,
                                             .ComHandleId = TWELVE,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_12,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[THIRTEEN] ={
                                             .ComBitPosition = FOURTY,
                                             .ComHandleId = THIRTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_13,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[FOURTEEN] ={
                                             .ComBitPosition = FOURTY_EIGHT,
                                             .ComHandleId = FOURTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_14,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[FIFTEEN] ={
                                             .ComBitPosition = FIFTY_SIX,
                                             .ComHandleId = FIFTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_15,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[SIXTEEN] ={
                                             .ComBitPosition = ZERO,
                                             .ComHandleId = SIXTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_16,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[SEVENTEEN] ={
                                             .ComBitPosition = EIGHT,
                                             .ComHandleId = SEVENTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_17,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[EIGHTEEN] ={
                                             .ComBitPosition = SIXTEEN,
                                             .ComHandleId = EIGHTEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_18,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[NINETEEN] ={
                                             .ComBitPosition = TWENTY_FOUR,
                                             .ComHandleId = NINETEEN,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_19,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWENTY] ={
                                             .ComBitPosition = THIRTY_TWO,
                                             .ComHandleId = TWENTY,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_20,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWENTY_ONE] ={
                                             .ComBitPosition = FOURTY,
                                             .ComHandleId = TWENTY_ONE,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_21,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWENTY_TWO] ={
                                             .ComBitPosition = FOURTY_EIGHT,
                                             .ComHandleId = TWENTY_TWO,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_22,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            },
                            .ComSignal[TWENTY_THREE] ={
                                             .ComBitPosition = FIFTY_SIX,
                                             .ComHandleId = TWENTY_THREE,
                                             .ComInitialValueOnly=TRUE,
                                             .ComNotification=Com_CbkRxAck_23,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             .ComSignalLength=ONE,

                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = ZERO,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = ComTimeout_Value, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = ZERO

                            }
};

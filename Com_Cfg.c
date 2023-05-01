/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com_Cfg.c
 *
 * Description: Source file for CanIf Pre-Compile Configurations.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

/* Include of Com Header Filer*/
#include "Com.h"

const Com_ConfigType Com = {
                            .ComIPdu[0] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = RECEIVE,
                                           .ComIPduHandleId = 0,
                                           .ComIPduSignalProcessing = DEFERRED,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[0] = &Com.ComSignal[0],
                                           .ComPduIdRef = 13,
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = 0.005,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = 0xFF,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = 0.125

                                                         }

                                           }
                            },
                            .ComIPdu[1] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = RECEIVE,
                                           .ComIPduHandleId = 1,
                                           .ComIPduSignalProcessing = DEFERRED,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[0] = &Com.ComSignal[8],
                                           .ComPduIdRef = 54,
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = 0.005,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = 0xFF,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = 0.125

                                                         }

                                           }
                            },
                            .ComIPdu[2] = {
                                           //                                        .ComIPduCallout = &,
                                           .ComIPduDirection = RECEIVE,
                                           .ComIPduHandleId = 2,
                                           .ComIPduSignalProcessing = DEFERRED,
                                           //                                        .ComIPduTriggerTransmitCallout,
                                           .ComIPduType = NORMAL,
                                           .ComIPduSignalRef[0] = &Com.ComSignal[16],
                                           .ComPduIdRef = 66,
                                           .ComTxIPdu = {
                                                         .ComMinimumDelayTime = 0.005,
                                                         .ComTxIPduClearUpdateBit = Confirmation,
                                                         .ComTxIPduUnusedAreasDefault = 0xFF,
                                                         .ComTxMode = {
                                                                       .ComTxModeMode = PERIODIC_Tx,
                                                                       .ComTxModeTimePeriod = 0.125

                                                         }

                                           }
                            },
                            .ComSignal[0] ={
                                            .ComBitPosition = 0,
                                            .ComHandleId = 0,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[1] ={
                                            .ComBitPosition = 8,
                                            .ComHandleId = 1,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[2] ={
                                            .ComBitPosition = 16,
                                            .ComHandleId = 2,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[3] ={
                                            .ComBitPosition = 24,
                                            .ComHandleId = 3,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[4] ={
                                            .ComBitPosition = 32,
                                            .ComHandleId = 4,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[5] ={
                                            .ComBitPosition = 40,
                                            .ComHandleId = 5,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[6] ={
                                            .ComBitPosition = 48,
                                            .ComHandleId = 6,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[7] ={
                                            .ComBitPosition = 56,
                                            .ComHandleId = 7,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=0

                            },
                            .ComSignal[8] ={
                                            .ComBitPosition = 0,
                                            .ComHandleId = 8,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[9] ={
                                            .ComBitPosition = 8,
                                            .ComHandleId = 9,
                                            .ComInitialValueOnly=TRUE,
                                            //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
                                            //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
                                            .ComTransferProperty = TRIGGERED,
                                            .ComUpdateBitPosition = 0,
                                            .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[10] ={
                                             .ComBitPosition = 16,
                                             .ComHandleId = 10,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[11] ={
                                             .ComBitPosition = 24,
                                             .ComHandleId = 11,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[12] ={
                                             .ComBitPosition = 32,
                                             .ComHandleId = 12,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[13] ={
                                             .ComBitPosition = 40,
                                             .ComHandleId = 13,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[14] ={
                                             .ComBitPosition = 48,
                                             .ComHandleId = 14,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[15] ={
                                             .ComBitPosition = 56,
                                             .ComHandleId = 15,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=1

                            },
                            .ComSignal[16] ={
                                             .ComBitPosition = 0,
                                             .ComHandleId = 16,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[17] ={
                                             .ComBitPosition = 8,
                                             .ComHandleId = 17,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[18] ={
                                             .ComBitPosition = 16,
                                             .ComHandleId = 18,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[19] ={
                                             .ComBitPosition = 24,
                                             .ComHandleId = 19,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[20] ={
                                             .ComBitPosition = 32,
                                             .ComHandleId = 20,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[21] ={
                                             .ComBitPosition = 40,
                                             .ComHandleId = 21,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[22] ={
                                             .ComBitPosition = 48,
                                             .ComHandleId = 22,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            },
                            .ComSignal[23] ={
                                             .ComBitPosition = 56,
                                             .ComHandleId = 23,
                                             .ComInitialValueOnly=TRUE,
                                             //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
                                             //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
                                             .ComTransferProperty = TRIGGERED,
                                             .ComUpdateBitPosition = 0,
                                             .ComSystemTemplateSystemSignalRef=2

                            }
};

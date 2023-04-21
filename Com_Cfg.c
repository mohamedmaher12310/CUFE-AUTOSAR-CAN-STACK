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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[1] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[2] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[3] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[4] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[5] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[6] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[7] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[8] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[9] ={
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
                                            //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[10] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[11] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[12] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[13] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[14] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[15] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[16] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[17] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[18] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[19] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[20] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[21] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[22] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            },
                            .ComSignal[23] ={
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
                                             //                                        .???   uint8* ComSystemTemplateSystemSignalRef;

                            }
};

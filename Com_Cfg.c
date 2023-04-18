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
//                                        .ComIPduCancellationSupport,
                                          .ComIPduDirection = RECEIVE,
                                          .ComIPduHandleId = 0,
                                          .ComIPduSignalProcessing = DEFERRED,
//                                        .ComIPduTriggerTransmitCallout,
                                          .ComIPduType = NORMAL,
//                                        .ComIPduGroupRef,
//                                        .ComIPduSignalGroupRef,
                                          .ComIPduSignalRef[0] = &Com.ComSignal[0],
                                          .ComPduIdRef = 13,
//                                        .ComIPduCounter ,
//                                        .ComIPduReplication,
                                          .ComTxIPdu = {
                                                        .ComMinimumDelayTime = 0.005,
                                                        .ComTxIPduClearUpdateBit = Confirmation,
                                                        .ComTxIPduUnusedAreasDefault = 0xFF,
                                                        .ComTxModeFalse={
                                                        .ComTxMode=
                                                        {
                                                         .ComTxModeMode = NONE_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0

                                                        }
                                                        },
                                                        .ComTxModeTrue={
                                                        .ComTxMode =
                                                        {
                                                         .ComTxModeMode = PERIODIC_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0
                                                        }
                                                        }
                                                     }
                           },
                           .ComIPdu[1] = {
//                                        .ComIPduCallout = &,
//                                        .ComIPduCancellationSupport,
                                          .ComIPduDirection = RECEIVE,
                                          .ComIPduHandleId = 1,
                                          .ComIPduSignalProcessing = DEFERRED,
//                                        .ComIPduTriggerTransmitCallout,
                                          .ComIPduType = NORMAL,
//                                        .ComIPduGroupRef,
//                                        .ComIPduSignalGroupRef,
                                          .ComIPduSignalRef[1] = &Com.ComSignal[8],
                                          .ComPduIdRef = 7,
//                                        .ComIPduCounter ,
//                                        .ComIPduReplication,
                                          .ComTxIPdu = {
                                                        .ComMinimumDelayTime = 0.005,
                                                        .ComTxIPduClearUpdateBit = Confirmation,
                                                        .ComTxIPduUnusedAreasDefault = 0xFF,
                                                        .ComTxModeFalse={
                                                        .ComTxMode=
                                                        {
                                                         .ComTxModeMode = NONE_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0

                                                        }
                                                        },
                                                        .ComTxModeTrue={
                                                        .ComTxMode =
                                                        {
                                                         .ComTxModeMode = PERIODIC_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0
                                                        }
                                                        }
                                          }
                           },
                           .ComIPdu[2] = {
//                                        .ComIPduCallout = &,
//                                        .ComIPduCancellationSupport,
                                          .ComIPduDirection = RECEIVE,
                                          .ComIPduHandleId = 2,
                                          .ComIPduSignalProcessing = DEFERRED,
//                                        .ComIPduTriggerTransmitCallout,
                                          .ComIPduType = NORMAL,
//                                        .ComIPduGroupRef,
//                                        .ComIPduSignalGroupRef,
                                          .ComIPduSignalRef[2] = &Com.ComSignal[16],
                                          .ComPduIdRef = 65,
//                                        .ComIPduCounter ,
//                                        .ComIPduReplication,
                                          .ComTxIPdu = {
                                                        .ComMinimumDelayTime = 0.005,
                                                        .ComTxIPduClearUpdateBit = Confirmation,
                                                        .ComTxIPduUnusedAreasDefault = 0xFF,
                                                        .ComTxModeFalse={
                                                        .ComTxMode=
                                                        {
                                                         .ComTxModeMode = NONE_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0

                                                        }
                                                        },
                                                        .ComTxModeTrue={
                                                        .ComTxMode =
                                                        {
                                                         .ComTxModeMode = PERIODIC_Tx,
                                                         .ComTxModeNumberOfRepetitions = 0,
                                                         .ComTxModeRepetitionPeriod = 0,
                                                         .ComTxModeTimeOffset = 0,
                                                         .ComTxModeTimePeriod = 0
                                                        }
                                                        }
                                          }
                           },
                           .ComSignal[0] ={
                                           .ComBitPosition = 0,
                                           .ComBitSize = 8,
                                           .ComDataInvalidAction = NOTIFY,
//                                         .ComErrorNotification,
//                                         .ComFirstTimeout,
                                           .ComHandleId = 0,
//                                         .ComInitialValueOnly,
//                                         .ComInvalidNotification,
//                                         .ComNotification,
                                           .ComRxDataTimeoutAction = NONE_Rx,
//                                         .ComSignalDataInvalidValue,?????
                                           .ComSignalEndianness = LITTLE_ENDIAN,
                                           .ComSignalInitValue = 0,
                                           .ComSignalLength = 1,
                                           .ComSignalType = UINT8,
                                           .ComTimeout = 0.125, /*DLM in sec*/
//                                         .ComTimeoutNotification,
//                                         .ComTimeoutSubstitutionValue,?????
                                           .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                           .ComUpdateBitPosition = 0,
//                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                           .ComFilter = {   /* filter configurations */
                                                            .ComFilterAlgorithm = ALWAYS,
                                           }
                           },
                           .ComSignal[1] = {
                                            .ComBitPosition = 1,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 1,
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 1,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }
                           },
                           .ComSignal[2] ={
                                           .ComBitPosition = 2,
                                           .ComBitSize = 8,
                                           .ComDataInvalidAction = NOTIFY,
//                                         .ComErrorNotification,
//                                         .ComFirstTimeout,
                                           .ComHandleId = 2,
//                                         .ComInitialValueOnly,
//                                         .ComInvalidNotification,
//                                         .ComNotification,
                                           .ComRxDataTimeoutAction = NONE_Rx,
//                                         .ComSignalDataInvalidValue,?????
                                           .ComSignalEndianness = LITTLE_ENDIAN,
                                           .ComSignalInitValue = 0,
                                           .ComSignalLength = 1,
                                           .ComSignalType = UINT8,
                                           .ComTimeout = 0.125, /*DLM in sec*/
//                                         .ComTimeoutNotification,
//                                         .ComTimeoutSubstitutionValue,?????
                                           .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                           .ComUpdateBitPosition = 2,
//                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                           .ComFilter = {   /* filter configurations */
                                                            .ComFilterAlgorithm = ALWAYS,
                                           }
                           },
                           .ComSignal[3] = {
                                            .ComBitPosition = 3,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification(address of Com_CbkTxErr),
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 3,
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
//                                            .ComNotification = (address of Com_CbkTxAck or Com_CbkRxAck),
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 3,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }
                           },
                           .ComSignal[4] ={
                                           .ComBitPosition = 4,
                                           .ComBitSize = 8,
                                           .ComDataInvalidAction = NOTIFY,
//                                         .ComErrorNotification,
//                                         .ComFirstTimeout,
                                           .ComHandleId = 4,/* index inside signal buffer */
//                                         .ComInitialValueOnly,
//                                         .ComInvalidNotification,
//                                         .ComNotification,
                                           .ComRxDataTimeoutAction = NONE_Rx,
//                                         .ComSignalDataInvalidValue,?????
                                           .ComSignalEndianness = LITTLE_ENDIAN,
                                           .ComSignalInitValue = 0,
                                           .ComSignalLength = 1,
                                           .ComSignalType = UINT8,
                                           .ComTimeout = 0.125, /*DLM in sec*/
//                                         .ComTimeoutNotification,
//                                         .ComTimeoutSubstitutionValue,?????
                                           .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                           .ComUpdateBitPosition = 4,
//                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                           .ComFilter = {   /* filter configurations */
                                                            .ComFilterAlgorithm = ALWAYS,
                                           }
                           },
                           .ComSignal[5] = {
                                            .ComBitPosition = 5,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 5,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 5,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }
                           },
                           .ComSignal[6] ={
                                           .ComBitPosition = 6,
                                           .ComBitSize = 8,
                                           .ComDataInvalidAction = NOTIFY,
//                                         .ComErrorNotification,
//                                         .ComFirstTimeout,
                                           .ComHandleId = 6,/* index inside signal buffer */
//                                         .ComInitialValueOnly,
//                                         .ComInvalidNotification,
//                                         .ComNotification,
                                           .ComRxDataTimeoutAction = NONE_Rx,
//                                         .ComSignalDataInvalidValue,?????
                                           .ComSignalEndianness = LITTLE_ENDIAN,
                                           .ComSignalInitValue = 0,
                                           .ComSignalLength = 1,
                                           .ComSignalType = UINT8,
                                           .ComTimeout = 0.125, /*DLM in sec*/
//                                         .ComTimeoutNotification,
//                                         .ComTimeoutSubstitutionValue,?????
                                           .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                           .ComUpdateBitPosition = 6,
//                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                           .ComFilter = {   /* filter configurations */
                                                            .ComFilterAlgorithm = ALWAYS,
                                           }
                           },
                           .ComSignal[7] = {
                                            .ComBitPosition = 7,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 7,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 7,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[8] ={
                                           .ComBitPosition = 0,
                                           .ComBitSize = 8,
                                           .ComDataInvalidAction = NOTIFY,
//                                         .ComErrorNotification,
//                                         .ComFirstTimeout,
                                           .ComHandleId = 8,/* index inside signal buffer */
//                                         .ComInitialValueOnly,
//                                         .ComInvalidNotification,
//                                         .ComNotification,
                                           .ComRxDataTimeoutAction = NONE_Rx,
//                                         .ComSignalDataInvalidValue,?????
                                           .ComSignalEndianness = LITTLE_ENDIAN,
                                           .ComSignalInitValue = 0,
                                           .ComSignalLength = 1,
                                           .ComSignalType = UINT8,
                                           .ComTimeout = 0.125, /*DLM in sec*/
//                                         .ComTimeoutNotification,
//                                         .ComTimeoutSubstitutionValue,?????
                                           .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                           .ComUpdateBitPosition = 0,
//                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                           .ComFilter = {   /* filter configurations */
                                                            .ComFilterAlgorithm = ALWAYS,
                                           }
                           },
                           .ComSignal[9] = {
                                            .ComBitPosition = 1,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 9,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 1,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[10] ={
                                            .ComBitPosition = 2,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 10,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 2,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[11] = {
                                             .ComBitPosition = 3,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 11,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 3,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[12] ={
                                            .ComBitPosition = 4,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 12,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 4,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[13] = {
                                             .ComBitPosition = 5,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 13,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 5,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[14] ={
                                            .ComBitPosition = 6,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 14,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 6,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[15] = {
                                             .ComBitPosition = 7,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 15,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 7,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[16] ={
                                            .ComBitPosition = 0,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 16,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 0,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[17] = {
                                             .ComBitPosition = 1,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 17,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 1,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[18] ={
                                            .ComBitPosition = 2,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 18,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 2,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[19] = {
                                             .ComBitPosition = 3,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 19,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 3,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[20] ={
                                            .ComBitPosition = 4,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 20,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 4,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[21] = {
                                             .ComBitPosition = 5,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 21,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 5,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           },
                           .ComSignal[22] ={
                                            .ComBitPosition = 6,
                                            .ComBitSize = 8,
                                            .ComDataInvalidAction = NOTIFY,
 //                                         .ComErrorNotification,
 //                                         .ComFirstTimeout,
                                            .ComHandleId = 22,/* index inside signal buffer */
 //                                         .ComInitialValueOnly,
 //                                         .ComInvalidNotification,
 //                                         .ComNotification,
                                            .ComRxDataTimeoutAction = NONE_Rx,
 //                                         .ComSignalDataInvalidValue,?????
                                            .ComSignalEndianness = LITTLE_ENDIAN,
                                            .ComSignalInitValue = 0,
                                            .ComSignalLength = 1,
                                            .ComSignalType = UINT8,
                                            .ComTimeout = 0.125, /*DLM in sec*/
 //                                         .ComTimeoutNotification,
 //                                         .ComTimeoutSubstitutionValue,?????
                                            .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                            .ComUpdateBitPosition = 6,
 //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                            .ComFilter = {   /* filter configurations */
                                                             .ComFilterAlgorithm = ALWAYS,
                                            }

                           },
                           .ComSignal[23] = {
                                             .ComBitPosition = 7,
                                             .ComBitSize = 8,
                                             .ComDataInvalidAction = NOTIFY,
  //                                         .ComErrorNotification,
  //                                         .ComFirstTimeout,
                                             .ComHandleId = 23,/* index inside signal buffer */
  //                                         .ComInitialValueOnly,
  //                                         .ComInvalidNotification,
  //                                         .ComNotification,
                                             .ComRxDataTimeoutAction = NONE_Rx,
  //                                         .ComSignalDataInvalidValue,?????
                                             .ComSignalEndianness = LITTLE_ENDIAN,
                                             .ComSignalInitValue = 0,
                                             .ComSignalLength = 1,
                                             .ComSignalType = UINT8,
                                             .ComTimeout = 0.125, /*DLM in sec*/
  //                                         .ComTimeoutNotification,
  //                                         .ComTimeoutSubstitutionValue,?????
                                             .ComTransferProperty = TRIGGERED_WITHOUT_REPETITION,
                                             .ComUpdateBitPosition = 7,
  //                                        .???   uint8* ComSystemTemplateSystemSignalRef;
                                             .ComFilter = {   /* filter configurations */
                                                              .ComFilterAlgorithm = ALWAYS,
                                             }

                           }
};

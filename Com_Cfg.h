/******************************************************************************
 *
 * Module: Com
 *
 * File Name: Com_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Com Module
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#ifndef CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_
#define CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_

/*
 * Module version
 */
#define COM_CFG_SW_MAJOR_VERSION            (1U)
#define COM_CFG_SW_MINOR_VERSION            (0U)
#define COM_CFG_SW_PATCH_VERSION            (0U)

/*
 * AUTOSAR Version
 */

#define COM_CFG_AR_RELEASE_MAJOR_VERSION    (4U)
#define COM_CFG_AR_RELEASE_MINOR_VERSION    (3U)
#define COM_CFG_AR_RELEASE_PATCH_VERSION    (1U)


/************************ComGeneral Container************************/

/* This parameter enables/disables the cancellation feature */
#define ComCancellationSupport                  (STD_OFF)

/*The error hook shall contain code to call the Det.
 *If this parameter is configured COM_DEV_ERROR_DETECT shall be set
 *to ON as output of the configuration tool. (as input for the source code).
 */
#define ComConfigurationUseDet                  (STD_ON)

#if (STD_ON == ComConfigurationUseDet)

#define COM_DEV_ERROR_DETECT                    (STD_ON)

#endif

/*Enables globally for the whole Com module the minimum delay
 *time monitoring for cyclic and repeated transmissions
 *(ComTxModeMode=PERIODIC or ComTxModeMode=MIXED for the cyclic
 *transmissions,ComTxModeNumberOfRepetitions > 0 for repeated transmissions).
 */
#define ComEnableMDTForCyclicTransmission       (STD_ON)

/* Activate/Deactivate the signal group array access APIs */
#define ComEnableSignalGroupArrayApi            (STD_OFF)

/* If this Parameter is set to true, retry of failed transmission requests is
 * enabled. If this Parameter is not present, the default value is assumed.
 */
#define ComRetryFailedTransmitRequests          (STD_OFF)

/* Defines the maximum number of supported I-PDU groups. */
#define ComSupportedIPduGroups                  (uint16)5

/*Defines the header files for callback functions which
 * shall be included by the COM module.
 */
//i think we will stop it as we wont implement RTE
#define ComUserCbkHeaderFile                    &(Rte.h)

/* Activate/Deactivate the version information API (Com_GetVersionInfo). */
#define ComVersionInfoApi                       (STD_OFF)

/************************ComConfig Container************************/

/* Maximum number of IPdus. */
#define ComMaxIPduCnt                           (uint64)3

/************************ComTimeBase Container************************/

/* The period between successive calls to Com_MainFunctionRouteSignals
 * in seconds. This parameter may be used by the COM generator to transform the values
 * of the signal gateway related timing configuration parameters of the COM module
 * to internal implementation specific counter or tick
 * values. The COM module's internal timing handling is implementation
 * specific.
 */
#define ComGwTimeBase                           (float64)2

/* The period between successive calls to Com_MainFunctionRx in seconds.
 * This parameter may be used by the COM generator to transform the values of the reception
 * related timing configuration parameters of the COM
 * module to internal implementation specific counter or tick values. The
 * COM module's internal timing handling is implementation specific.
 */
#define ComRxTimeBase                           (float64)2

/* The period between successive calls to Com_MainFunctionTx in seconds.
 * This parameter may be used by the COM generator to transform the values of the transmission
 * related timing configuration parameters of the COM
 * module to internal implementation specific counter or tick values. The
 * COM module's internal timing handling is implementation specific.
 */
#define ComTxTimeBase                           (float64)2

/*******************************************************************************
 *                      Definitions used in Module                             *
 *******************************************************************************/

#define SIG_LEN_IN_BTYES                (uint8)1
#define MAX_NUM_OF_SIGNAL       ((uint16)(ComMaxIPduCnt*(8/SIG_LEN_IN_BTYES)))
#define PDU_LEN_IN_BYTES                (uint8)8
#endif /* CUFE_AUTOSAR_CAN_STACK_COM_CFG_H_ */

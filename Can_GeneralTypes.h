/******************************************************************************
 *
 * Module: Can
 *
 * File Name: Can_GeneralTypes.h
 *
 * Description: General Can type definitions
 *
 * Author: CUFE 2023 Team
 *
 *******************************************************************************/

#ifndef CAN_GENERALTYPES_H_
#define CAN_GENERALTYPES_H_

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/*Enumeration to represent States that are used by the several ControllerMode functions.b*/
typedef enum Can_ControllerStateType
{
    CAN_CS_UNINIT, /*CAN controller state UNINIT.*/
    CAN_CS_STARTED, /*CAN controller state STARTED.*/
    CAN_CS_STOPPED, /*CAN controller state STOPPED.*/
    CAN_CS_SLEEP /*CAN controller state SLEEP.*/
}Can_ControllerStateType;

/*Enumeration to represent Error states of a CAN controller.*/
typedef enum Can_ErrorStateType
{
    CAN_ERRORSTATE_ACTIVE, /*The CAN controller takes fully part in communication.*/
    CAN_ERRORSTATE_PASSIVE, /*The CAN controller takes part in communication, but does not send active error frames.*/
    CAN_ERRORSTATE_BUSOFF /*The CAN controller does not take part in communication.*/
}Can_ErrorStateType;

/*Represents the hardware object handles of a CAN hardware unit.*/
typedef uint8 Can_HwHandleType;

/*Represents the Identifier of an L-PDU. The two most significant bits specify the
frame type*/
typedef uint32 Can_IdType;

/*This type defines a data structure which clearly provides an Hardware Object
Handle including its corresponding CAN Controller and therefore CanDrv as well
as the specific CanId.*/
typedef struct Can_HwType
{
    Can_IdType CanId; /*Standard/Extended CAN ID of CAN L-PDU*/
    Can_HwHandleType Hoh; /*ID of the corresponding Hardware Object Range*/
    uint8 ControllerId; /*ControllerId provided by CanIf clearly identify the corresponding controller*/
}Can_HwType;

/*Typedef to unite PduId (swPduHandle), SduLength (length), SduData (sdu), and
CanId (id) for any CAN L-SDU.*/
typedef struct Can_PduType
{
    PduIdType swPduHandle;
    uint8 length;
    Can_IdType id;
    uint8* sdu;
}Can_PduType;


#endif /* CAN_GENERALTYPES_H_ */

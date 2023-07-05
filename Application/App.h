/*
 * App.h
 *
 *  Created on: Jul 5, 2023
 *      Author: Mally
 */

#ifndef APPLICATION_APP_H_
#define APPLICATION_APP_H_

#include "../BSW/Service Layer/Com/Com.h"
#include "../BSW/MCAL/Port/Port.h"
#include "../BSW/MCAL/Uart/UART.h"


void Init_Task(void);

extern uint8 Array_RTE_Send[3][8];
extern uint8 Array_RTE_Receive[24];

#endif /* APPLICATION_APP_H_ */

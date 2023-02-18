#ifndef UART_H_
#define UART_H_

#include "Common_Macros.h"
#include "Std_Types.h"

void UART_INIT(void);
void UARTCharPut(uint32 ui32Base, unsigned char ucData);
uint32 UARTCharGet(uint32 ui32Base);
void UART1_SendString(unsigned char * SentString);
unsigned char * UART1_RecieveString(void);





#endif /* UART_H_ */

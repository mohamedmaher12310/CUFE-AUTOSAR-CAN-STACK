#include "UART.h"

void UART_INIT(void)
{
 volatile uint8 delay;
 /* Enabling the UART 1 module clock */
 REG_VAL(0x400FE000,0x618)= 0x00000002;
 delay=REG_VAL(0x400FE000,0x618);
 /* disabling module for configuring brd */
 REG_VAL( 0x4000D000,0x030)= 0x00000300;
 /* setting brd to 9600 */ 
  REG_VAL( 0x4000D000,0x024)= 0x00000068;  /* integer */
  REG_VAL( 0x4000D000,0x028)= 0x0000000B;  /* fraction */ 
  
  /* set the stop bits and parity */
  REG_VAL( 0x4000D000,0x02C)= 0x00000060;  /* fraction */ 
  
  /* configuring clock */
    REG_VAL( 0x4000D000,0xFC8)= 0x00000000;
  /* Enabling the periphral */
    REG_VAL( 0x4000D000,0x030)= 0x00000301;
}

void UARTCharPut(uint32 ui32Base, unsigned char ucData)
{
    //
    // Wait until space is available.
    //
    while(REG_VAL(ui32Base, 0x018) & 0x00000020)
    {
    }

    //
    // Send the char.
    //
    REG_VAL(ui32Base, 0x000) = ucData;
}

uint32 UARTCharGet(uint32 ui32Base)
{
    //
    // Wait until a char is available.
    //
    while(REG_VAL(ui32Base, 0x018) & 0x00000010)
    {
    }

    //
    // Now get the char.
    //
    return(REG_VAL(ui32Base, 0x000));
}



void UART1_SendString(unsigned char * SentString)
{
    unsigned char i;
    for ( i=0 ; SentString[i] ; i++)
    {
        UARTCharPut(0x4000D000, SentString[i]);
    }
}

unsigned char * UART1_RecieveString(void)
{
    uint8 LOC_RXChar ;
    STATIC uint8 LOC_RXString[32];
    uint8 LOC_u8Counter =0;
    /* Waiting till receiving flag is set*/
    while (REG_VAL(0x4000D000, 0x018) & 0x00000010);
    {
        /* Receive characters until ENTER is pressed (ASCII OF ENTER IS 13) */
        while ((LOC_RXChar=UARTCharGet(0x4000D000))!='\r')
        {
            UARTCharPut(0x4000D000,LOC_RXChar);
            LOC_RXString[LOC_u8Counter++]=LOC_RXChar;
        }
        LOC_RXString[LOC_u8Counter]='\0';
        return LOC_RXString;
    }
}

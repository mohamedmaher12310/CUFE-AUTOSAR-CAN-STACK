 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 * Author: CUFE 2023 Team
 ******************************************************************************/

#include "Port.h"
#include "Port_Regs.h"
/*Including Det module for developmnet error reporting*/
#if (STD_ON == DIO_DEV_ERROR_DETECT)

#include "Det.h"
/* AUTOSAR Version checking between Det and port Modules */
#if ((PORT_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (PORT_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (PORT_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

/*A pointer to the configuration structure*/
STATIC const Port_ConfigPins * Port_Pins = NULL_PTR;
/*Status variable to check if the module is initialized or not*/
STATIC uint8 Port_Status = PORT_NOT_INITIALIZED;

/************************************************************************************
* Service Name: Port_Init
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to initialize the Port module:
*              - Setup the direction of the pin
*              - Setup the mode of the pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr )
{
  #if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_POINTER);
	}
        else
        {
        /* Do Nothing*/
        }
        const Port_ConfigType * Check_Ptr=&Port_Configuration;
        if(Check_Ptr != ConfigPtr)
        {
          Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
        }
	else
  #endif
        {
    Port_Pins=ConfigPtr->Pins;      
    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = ZERO; /*a variable to create the delay required for the clock to start*/
    uint8 ID=ZERO;
    for ( ID=ZERO ; ID< PORT_CONFIGURED_PINS ; ID ++ )
    {
    /*Setting Port_Ptr to hold configuration structure address*/
    switch(Port_Pins[ID].Port_Number)
    {
        case  PORTA: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORTB: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORTC: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORTD: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORTE: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORTF: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
        default:
                 break;
    }
    
    /* Enable clock for PORT and allow time for clock to start*/
    SYSCTL_REGCGC2_REG |= (ONE<<Port_Pins[ID].Port_Number);
    delay = SYSCTL_REGCGC2_REG;
    
    /*Special pins the TM4C123GH6PM MCU that needs to be unlocked before being used*/
    if( ((PORTD == Port_Pins[ID].Port_Number) && (PIN7 == Port_Pins[ID].Pin_Number)) || ((PORTF ==Port_Pins[ID].Port_Number ) && (PIN0 == Port_Pins[ID].Pin_Number)) ) /* PD7 or PF0 */
    {
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = UNLOCK_GPIOCR;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Port_Pins[ID].Pin_Number);  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
    }
    else if( (PORTC == Port_Pins[ID].Port_Number) && (Port_Pins[ID].Pin_Number <= PIN3) ) /* PC0 to PC3 */
    {
        /* Do Nothing ...  this is the JTAG pins */
    }
    else
    {
        /* Do Nothing ... No need to unlock the commit register for this pin */
    }
    
    /*
     *Setting the direction of pin (output/input)
     *if output set the initial value configured by the user,
     *if input set the internal resistor configuration (pull-up/pull-down/off)
     */
    if(PORT_PIN_OUT == Port_Pins[ID].Pin_Direction)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[ID].Pin_Number);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(STD_HIGH == Port_Pins[ID].Pin_Initial_Value)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[ID].Pin_Number);          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET) , Port_Pins[ID].Pin_Number);        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
    }
    else if(PORT_PIN_IN == Port_Pins[ID].Pin_Direction)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Pins[ID].Pin_Number);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(PULL_UP == Port_Pins[ID].Pin_Resistor)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[ID].Pin_Number);       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if(PULL_DOWN == Port_Pins[ID].Pin_Resistor)
        {
            SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[ID].Pin_Number);     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET) , Port_Pins[ID].Pin_Number);     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
            CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET) , Port_Pins[ID].Pin_Number);   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
    }
    else
    {
        /* Do Nothing */
    }
    /* Setting mode for the pin*/
      /* For the GPIO */
      if(GPIO == Port_Pins[ID].Pin_Mode)
      {  
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[ID].Pin_Number);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[ID].Pin_Number);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
      *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(FIRST_BYTE_MASK << (Port_Pins[ID].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */      
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[ID].Pin_Number);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
      }
      /* For the ADC */
      else if (ADC == Port_Pins[ID].Pin_Mode)
      {
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[ID].Pin_Number);      /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[ID].Pin_Number);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
     *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(FIRST_BYTE_MASK << (Port_Pins[ID].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[ID].Pin_Number);        /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
      }
    /* For any other mode*/
    else 
    {
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Pins[ID].Pin_Number);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Pins[ID].Pin_Number);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
     *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)Port_Pins[ID].Pin_Mode << (Port_Pins[ID].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Pins[ID].Pin_Number);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
    Port_Status=PORT_INITIALIZED; /*Port initialized*/
    } 
    }
    
}

#if (STD_ON == PORT_SET_PIN_DIRECTION_API)
/************************************************************************************
* Service Name: Port_SetPinDirection
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number, Direction - Port Pin Direction
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the direction of the pin
************************************************************************************/
void Port_SetPinDirection ( Port_PinType Pin , Port_PinDirectionType Direction )
{
  #if (STD_ON == PORT_DEV_ERROR_DETECT)
    /* check if the input Pin parametre is a valid parametre */
	if (Pin > PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_PARAM_PIN);
	}
	else
        {
        /*Do nothing*/
        }
        /*checks if the module is initialized*/
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_UNINIT);
        }
        else
        {
        /*Do nothing*/        
        }
        /*checks if the direction is changeable*/
        if (DIRECTION_NOT_CHANGEABLE == Port_Configuration.Pins[Pin].Pin_Direction_Changeable)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID,
		     PORT_E_DIRECTION_UNCHANGEABLE);
        }
        else 
          
  #endif
        {
    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = ZERO; /*a variable to create the delay required for the clock to start*/
 
    /*Setting Port_Ptr to hold configuration structure address*/
    switch(Port_Configuration.Pins[Pin].Port_Number)
    {
        case  PORTA: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORTB: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORTC: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORTD: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORTE: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORTF: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
        default:
                 break;
    }
        
    if(PORT_PIN_OUT == Direction)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
    }
    else if(PORT_PIN_IN == Direction)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
    }
        }
}
#endif

/************************************************************************************
* Service Name: Port_RefreshPortDirection
* Service ID[hex]: 0x02
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Refresh the direction of the pin and return it to the 
*              original configured value 
************************************************************************************/
void Port_RefreshPortDirection( void )
{
  #if (STD_ON == PORT_DEV_ERROR_DETECT)
        /*checks if the module is initialized*/
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID,
		     PORT_E_UNINIT);
        }
        else
  #endif
        {
            uint8 ID=ZERO;
    for(ID=ZERO; ID<PORT_CONFIGURED_PINS; ID++)
    {
    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = ZERO; /*a variable to create the delay required for the clock to start*/
 
    /*Setting Port_Ptr to hold configuration structure address*/
    switch(Port_Configuration.Pins[ID].Port_Number)
    {
        case  PORTA: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORTB: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORTC: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORTD: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORTE: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORTF: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
        default:
                 break;
    }
    /*Check if the pin direction is changeable then exclude it */
    if (DIRECTION_CHANGEABLE == Port_Configuration.Pins[ID].Pin_Direction_Changeable)
    {
    /*Do Nothing*/
    }    
    else 
    {
    if(PORT_PIN_OUT == Port_Configuration.Pins[ID].Pin_Direction)
    {
	SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pins[ID].Pin_Number);                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
    }
    else if(PORT_PIN_IN == Port_Configuration.Pins[ID].Pin_Direction)
    {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_Configuration.Pins[ID].Pin_Number);             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
    }
    }
    }
        }
}

#if (STD_ON == PORT_VERSION_INFO_API)
/************************************************************************************
* Service Name: Port_GetVersionInfo
* Service ID[hex]: 0x03
* Sync/Async: Synchronous
* Reentrancy: Non Reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): versioninfo - Pointer to where to store the version information 
*                   of this module.
* Return value: None
* Description: Function to Return the version information of this module.
************************************************************************************/
void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  #if (STD_ON == PORT_DEV_ERROR_DETECT)
        /*checks if the module is initialized*/
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID,
		     PORT_E_UNINIT);
        }
        else
        {
        /*Do nothing*/        
        }
        /* check if the input pointer is not a NULL_PTR */
	if (NULL_PTR == versioninfo)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID,
		     PORT_E_PARAM_POINTER);
	}
        else 
          
  #endif
        {
                /* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
        }
}
#endif

#if (STD_ON == PORT_SET_PIN_MODE_API)
/************************************************************************************
* Service Name: Port_SetPinMode
* Service ID[hex]: 0x04
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pin - Port Pin ID number, Mode - New Port Pin mode to be set on
*                  port pin. 
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Set the mode of the pin
************************************************************************************/
void Port_SetPinMode(  Port_PinType Pin,  Port_PinModeType Mode )
{
  #if (STD_ON == PORT_DEV_ERROR_DETECT)
        /* check if the input Pin parametre is a valid parametre */
	if (Pin > PORT_CONFIGURED_PINS)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_PARAM_PIN);
	}
	else
        {
        /* Do nothing*/
        }
        /* checks if the mode is an invalid mode*/
        if (Mode >= MAX_MODE_NUM)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_PARAM_INVALID_MODE);
	}
	else
        {
        /* Do nothing*/
        }
        /* checks if the module is initialized*/
        if (PORT_NOT_INITIALIZED == Port_Status)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_UNINIT);
        }
        else
        {
        /* Do nothing*/        
        }
        /* checks if the mode is changeable*/
        if (MODE_NOT_CHANGEABLE == Port_Configuration.Pins[Pin].Pin_Mode_Changeable)
        {
                Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID,
		     PORT_E_MODE_UNCHANGEABLE);
        }
        else 
          
  #endif
        {
    volatile uint32 * Port_Ptr = NULL_PTR; /* point to the required Port Registers base address */
    volatile uint32 delay = ZERO; /*a variable to create the delay required for the clock to start*/
 
    /*Setting Port_Ptr to hold configuration structure address*/
    switch(Port_Configuration.Pins[Pin].Port_Number)
    {
        case  PORTA: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
		 break;
	case  PORTB: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
		 break;
	case  PORTC: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
		 break;
	case  PORTD: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
		 break;
        case  PORTE: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
		 break;
        case  PORTF: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
		 break;
        default:
                 break;
    }
     /* Setting mode for the pin*/
      /* For the GPIO */
    if(GPIO == Port_Configuration.Pins[Pin].Pin_Mode)
    {
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
      CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
      *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(FIRST_BYTE_MASK << (Port_Configuration.Pins[Pin].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */
      SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
    /* For the ADC */
    else if(ADC == Port_Configuration.Pins[Pin].Pin_Mode)
    {
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);      /* Set the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
     *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(FIRST_BYTE_MASK << (Port_Configuration.Pins[Pin].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);        /* Clear the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
    /* For any other mode*/
    else 
    {
     CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);             /* Enable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
     *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= ((uint32)Mode << (Port_Configuration.Pins[Pin].Pin_Number * FOUR));     /* Clear the PMCx bits for this pin */
     SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_Configuration.Pins[Pin].Pin_Number);        /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
    }
        }
}
#endif




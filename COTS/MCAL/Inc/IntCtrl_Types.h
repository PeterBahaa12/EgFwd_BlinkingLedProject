/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *  Author: Peter Bahaa
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define APINT_KEY_GAURD 0x05FA     /* OxFA05 is the Gaurding Key to be able to write on the APINT Register */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    RESET_Exception = 1,
    NMI_Exception,
    Hard_Fault_Exception,
    Memory_Management_Fault_Exception,
    BUS_Fault_Exception,
    Usage_Fault_Exception,
    SV_CALL_Exception = 11,
    Debug_Monitor_Exception,

}IntCtrl_ProcessorExceptions;


typedef enum
{
    DIO_PORTA_INT,
    DIO_PORTB_INT,
    DIO_PORTC_INT,
    DIO_PORTD_INT,
    DIO_PORTE_INT,
    UART0_INT,
    UART1_INT,
	SSI0_INT,
	I2C0_INT,
	PWM0_FAULT_INT,
	PWM0_Generator0_INT,
	PWM0_Generator1_INT,
	PWM0_Generator2_INT,
	QEI0_INT,
	ADC0_Sequence0_INT,
	ADC0_Sequence1_INT,
	ADC0_Sequence2_INT,
    ADC0_Sequence3_INT,
    WATCHDOG_TIMERS0_1_INT,
    TIMER0A_16_32_INT,
    TIMER0B_16_32_INT,
    TIMER1A_16_32_INT,
    TIMER1B_16_32_INT,
    TIMER2A_16_32_INT,
	TIMER2B_16_32_INT,
	ANALOG_COMPARATOR0_INT,
	ANALOG_COMPARATOR1_INT,
	SYSTEM_CONTROL_INT=28,
	FLASH_MEMORY_EEPROM_CONTROL_INT,
	GPIOF_INT,
	UART2_INT=33,
	SSI1_INT,
	TIMER3A_16_32_INT,
	TIMER3B_16_32_INT,
	I2CI_INT,
	QEI1_INT,
	CAN0_INT,
	CAN1_INT,
	HIBERNATION_MODULE_INT=43,
	USB_INT,
	PWM_GENERATOR3_INT,
	DMA_SOFTWARE_INT,
	DMA_ERROR_INT
}IntCtrl_InterruptNumTyp;

 
typedef enum
{
	Priority_0,
	Priority_1,
	Priority_2,
	Priority_3,
	Priority_4,
	Priority_5,
	Priority_6,
	Priority_7,
}INTCtrl_PriorityTyp;

typedef enum
{
	bxxx = 0x04,
	bxxy = 0x05,
	bxyy = 0x06,
	byyy = 0x07,
}INTCtrl_PriorityGroupTyp;

typedef struct 
{
	IntCtrl_InterruptNumTyp         IntNumber;
	INTCtrl_PriorityGroupTyp 	    PriorityGroup;
	INTCtrl_PriorityTyp		 	    Priority;
	INTCtrl_PriorityTyp		   		SubGroupPriority;
}INTCtrl_ConfigTyp;




#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

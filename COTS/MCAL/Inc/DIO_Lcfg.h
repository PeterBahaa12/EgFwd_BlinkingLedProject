/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio_Lcfg.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - DIO Driver  
 *
 * Author: Peter Bahaa
 *
 *******************************************************************************/
#ifndef DIO_LCFG_H_
#define DIO_LCFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/* Constants */
#define PORT_PINS_NUM        		(uint8)(2U)


/* Pin Levels Values */
/* This is another way to define the PortType
#define PORT_PIN_HIGH						(Port_PinLevel)(LOGIC_HIGH)
#define PORT_PIN_LOW 						(Port_PinLevel)(LOGIC_LOW)
#define PORT_PIN_LEVEL_INVALID  (Port_PinLevel)(2)*/

/* Pin Directions Values */
/*
#define PORT_PIN_INPUT					(Port_PinDirectionType)(0)
#define PORT_PIN_OUTPUT					(Port_PinDirectionType)(1)
#define PORT_PIN_DIR_INVALID		(Port_PinDirectionType)(2)*/

/* Pin Internal Attach Values */
#define PORT_PIN_PUR						(Port_pinInternalAttachType)(0)
#define PORT_PIN_PDR						(Port_pinInternalAttachType)(1)
#define PORT_PIN_ODR						(Port_pinInternalAttachType)(2)
#define PORT_PIN_RES_INVALID		(Port_pinInternalAttachType)(3)
/* Pin Output Current Values */
#define PORT_PIN_CUR_2MA    		(Port_PinOutputCurrentType)(0)
#define PORT_PIN_CUR_4MA				(Port_PinOutputCurrentType)(1)
#define PORT_PIN_CUR_8MA				(Port_PinOutputCurrentType)(2)


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 



#endif  /* DIO_LCFG_H_*/
/**********************************************************************************************************************
 *  END OF FILE: Dio_Lcfg.h
 *********************************************************************************************************************/

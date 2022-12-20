/******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - DIO Driver  
 *
 * Author: Peter Bahaa
 *
 *******************************************************************************/
#ifndef DIO_H_
#define DIO_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "DIO_Lcfg.h"
#include "Common_Macros.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*
 * Macros for Dio Status
 */
#define DIO_INITIALIZED                (1U)
#define DIO_NOT_INITIALIZED            (0U)
#define LOCK_KEY_MASK                  (0x4C4F434B)
#define CTRL_REG_CLEAR_MASK 					 (0xFFFFFFF0)
#define PORT_A_ID 0
#define PORT_B_ID 1
#define PORT_C_ID 2
#define PORT_D_ID 3
#define PORT_E_ID 4
#define PORT_F_ID 5


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8  Port_pinInternalAttachType;
typedef uint8  Port_PinOutputCurrentType;
typedef uint32 Port_LevelType;

/* Pin Mode */
typedef enum
{
	PORT_PIN_DIGITAL,PORT_PIN_ANALOG  /*Can be Adjusted using DEN & GPIO AMSEL*/
}Port_PinModeType;

/* Pin Levels Values */
typedef enum
{
	PORT_PIN_LOW=LOGIC_LOW,PORT_PIN_HIGH=LOGIC_HIGH,PORT_PIN_LEVEL_INVALID=2
}Port_PinLevel;


typedef enum
{
	PORT_PIN_INPUT=0,PORT_PIN_OUTPUT,PORT_PIN_DIR_INVALID
}DIO_PinDirectionType;

typedef enum
{
	DIO_PORT_A=1,DIO_PORT_B,DIO_PORT_C,DIO_PORT_D,DIO_PORT_E,DIO_PORT_F
}Port_Num;

typedef enum
{
	PORT_PIN0=0,PORT_PIN1,PORT_PIN2,PORT_PIN3,PORT_PIN4,PORT_PIN5,PORT_PIN6,PORT_PIN7
}Port_PinNum;

typedef struct
{
	Port_Num 									PortNum;
	Port_PinNum                  				PortPinNum;
	Port_PinModeType 							PortPinMode;
	DIO_PinDirectionType 				  		PortPinDirection;
	Port_PinLevel 								PortPinLevelValue;
	Port_pinInternalAttachType					PortPinInternalAttach;
	Port_PinOutputCurrentType					PortPinOutputCurrent;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 /************************************************************************************
* Function Name: DIO_Init
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the DIO module
************************************************************************************/
 void DIO_Init(Port_ConfigType* DIO_Config_Ptr);


/************************************************************************************
* Function Name: DIO_ReadPort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port_Num
* Parameters (inout): None
* Parameters (out): None
* Return value: PORT_LEVEL
* Description: Function to read a port value.
************************************************************************************/
Port_LevelType DIO_ReadPort(Port_Num PORT_ID);

	/************************************************************************************
* Function Name: DIO_WritePort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port_Num, Port Value
* Parameters (inout): None
* Parameters (out): None
* Return value: void
* Description: Function to read a port value.
************************************************************************************/
void DIO_WritePort(Port_Num PORT_ID, Port_LevelType Port_Value);

/************************************************************************************
* Function Name: DIO_WriteChannel
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port_NUM ,Pin ID, Pin Level
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void DIO_WriteChannel(Port_Num PORT_ID,Port_PinNum Pin_Num,Port_PinLevel Pin_Value);

/************************************************************************************
* Function Name: DIO_ReadChannel
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port_Num 
									 Channel_ID 
* Parameters (inout): None
* Parameters (out): None
* Return value: Port_PinLevel
* Description: Function to set a level of a channel.
************************************************************************************/
Port_PinLevel DIO_ReadChannel(Port_Num PORT_ID,Port_PinNum Pin_Num);

/************************************************************************************
* Function Name: DIO_FlipChannel
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Port_Num 
									 Channel_ID 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to set a level of a channel.
************************************************************************************/
void DIO_FlipChannel(Port_Num PORT_ID,Port_PinNum Pin_Num);

#endif  /* DIO_H_ */
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/

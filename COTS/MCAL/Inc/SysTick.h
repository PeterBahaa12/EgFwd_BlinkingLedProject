/******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Systick Driver  
 *              Page 128 in Data Sheet
 * Author: Peter Bahaa
 *
 *******************************************************************************/
#ifndef Systick_H_
#define Systick_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu_Hw.h"
#include "Common_Macros.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  Local DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
static void (*CallBack_Ptr) (void) = NULL_PTR;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
 /************************************************************************************
* Function Name: Systick_Init
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Systick_Load_value 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to Init the Systick Timer.
************************************************************************************/
 void Systick_Init(uint32 Systick_value);
 
  /************************************************************************************
* Function Name: Systick_Enable
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to Enable the Systick Timer.
************************************************************************************/
 void Systick_Enable(void);
 
 /************************************************************************************
* Function Name: Systick_Disable
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): None 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to Disable the Systick Timer.
************************************************************************************/
void Systick_Disable(void);


 /************************************************************************************
* Function Name: Systick_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Pointer to function 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to set the call back function of the Systick Timer
************************************************************************************/
void Systick_SetCallBack(void (*Ptr_f)(void));
 /************************************************************************************
* Function Name: SysTick_Handler
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): NONE 
* Parameters (inout): None
* Parameters (out): None
* Return value: NONE
* Description: Function to call the callback function of the Systick ISR
************************************************************************************/
void SysTick_Handler(void);


#endif  /* Systick_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Systick.h
 *********************************************************************************************************************/

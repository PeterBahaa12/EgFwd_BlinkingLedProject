 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: Systick.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Systtick Driver
 *              Page 138 IN Datasheet.
 * Author: Peter Bahaa
 ******************************************************************************/
 
 
  /**********************************************************************************************************************
 * INCLUDES
 ***********************************************************************************************************************/
#include "SysTick.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/




 /**********************************************************************************************************************
 *  GLOBAL FUNCTION Definitons
 **********************************************************************************************************************/
 
 
 
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
 void Systick_Init(uint32 Systick_Load_value)
 {
	 ST_RELOAD_REG  = Systick_Load_value; /* Load the timer with the required value */
	 ST_CURRENT_REG = 0; /* Initially clearing the timer */
	 ST_CTRL_REG   |= 0x00000006; /* enable its interrupt and select clock to be System clock */ 
 }
 
 
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
 void Systick_Enable(void)
 {
		 ST_CTRL_REG   |= 0x00000007; /* Enable Systick & enable its interrupt and select clock to be System clock */ 
 }
 
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
 void Systick_Disable(void)
 {
		 ST_CTRL_REG   |= 0x00000006; /* Disable Systick & enable its interrupt and select clock to be System clock */ 
 }
 
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
void Systick_SetCallBack(void (*Ptr_f)(void))
{
				CallBack_Ptr = Ptr_f ; 
}
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
void SysTick_Handler(void)
{
	if(CallBack_Ptr != NULL_PTR)
	{
		CallBack_Ptr();
	}
}
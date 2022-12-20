/******************************************************************************
 *
 * Module: IntCrtl
 *
 * File Name: IntCrtl.h
 *
 * Description: Header file for IntCrtl Module    
 *
 * Author: Peter Bahaa
 *
 *******************************************************************************/
#ifndef IntCrtl_H
#define IntCrtl_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define APINT_KEY_GAURD 0x05FA

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 
/******************************************************************************
* \Syntax          : void IntCrtl_Init(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);                                      
* \Description     : initialize NVIC\SCB Module by parsing the Configuration 
*                    into NVIC\SCB registers                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);


/******************************************************************************
* \Syntax          : void IntCrtl_EnableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);                                    
* \Description     : Function to Enable an Interrupt                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_EnableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);


/******************************************************************************
* \Syntax          : void IntCrtl_DisableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);                                   
* \Description     : Function to Disable an Interrupt                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_DisableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);





#endif  /* IntCrtl_H */
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.h
 *********************************************************************************************************************/

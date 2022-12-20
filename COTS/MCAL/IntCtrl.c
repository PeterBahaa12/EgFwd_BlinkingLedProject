/******************************************************************************
 *
 * Module: Nested Vector Interrupt Controller Driver
 *
 * File Name: IntCrtl.c
 *
 * Created on: December 12, 2022
 *
 * Description: Source file of The Driver that Configures All MCU interrupts Priority into gorups and subgroups
 *              Enable NVIC Interrupt Gate for Peripherals
 * Author: Peter Bahaa
 *
 *******************************************************************************/


/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "Mcu_Hw.h"
#include "IntCtrl.h"
#include "common_macros.h"



/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/*Function to Calculate which PRI Register we should use*/
static uint32* getPRIRegister(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static uint32* getPRIRegister(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr)
{

    if((IntCtrl_ConfigPtr->IntNumber==0)||(IntCtrl_ConfigPtr->IntNumber==1)||(IntCtrl_ConfigPtr->IntNumber==2)||(IntCtrl_ConfigPtr->IntNumber==3))
    {
        return PRI0;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==4)||(IntCtrl_ConfigPtr->IntNumber==5)||(IntCtrl_ConfigPtr->IntNumber==6)||(IntCtrl_ConfigPtr->IntNumber==7))
    {
        return PRI1;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==8)||(IntCtrl_ConfigPtr->IntNumber==9)||(IntCtrl_ConfigPtr->IntNumber==10)||(IntCtrl_ConfigPtr->IntNumber==11))
    {
        return PRI2;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==12)||(IntCtrl_ConfigPtr->IntNumber==13)||(IntCtrl_ConfigPtr->IntNumber==14)||(IntCtrl_ConfigPtr->IntNumber==15))
    {
        return PRI3;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==16)||(IntCtrl_ConfigPtr->IntNumber==17)||(IntCtrl_ConfigPtr->IntNumber==18)||(IntCtrl_ConfigPtr->IntNumber==19))
    {
        return PRI4;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==20)||(IntCtrl_ConfigPtr->IntNumber==21)||(IntCtrl_ConfigPtr->IntNumber==22)||(IntCtrl_ConfigPtr->IntNumber==23))
    {
        return PRI5;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==24)||(IntCtrl_ConfigPtr->IntNumber==25)||(IntCtrl_ConfigPtr->IntNumber==26)||(IntCtrl_ConfigPtr->IntNumber==27))
    {
        return PRI6;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==28)||(IntCtrl_ConfigPtr->IntNumber==29)||(IntCtrl_ConfigPtr->IntNumber==30)||(IntCtrl_ConfigPtr->IntNumber==31))
    {
        return PRI7;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==32)||(IntCtrl_ConfigPtr->IntNumber==33)||(IntCtrl_ConfigPtr->IntNumber==34)||(IntCtrl_ConfigPtr->IntNumber==35))
    {
        return PRI8;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==36)||(IntCtrl_ConfigPtr->IntNumber==37)||(IntCtrl_ConfigPtr->IntNumber==38)||(IntCtrl_ConfigPtr->IntNumber==39))
    {
        return PRI9;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==40)||(IntCtrl_ConfigPtr->IntNumber==41)||(IntCtrl_ConfigPtr->IntNumber==42)||(IntCtrl_ConfigPtr->IntNumber==43))
    {
        return PRI10;
    }
    else if((IntCtrl_ConfigPtr->IntNumber==44)||(IntCtrl_ConfigPtr->IntNumber==45)||(IntCtrl_ConfigPtr->IntNumber==46)||(IntCtrl_ConfigPtr->IntNumber==47))
    {
        return PRI11;
    }

}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize NVIC\SCB Module by parsing the Configuration 
*                    into NVIC\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_Init(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr)
{
    uint8 PRI_Offset;
    uint8 PRI_Offsets[3]={5,13,21,29};
    uint8 Final_Priority; /*This Variable will hold the value of the priority of both group and Sub Group*/
	volatile uint32 *PRI_Register_Used;
    /*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = (APINT_KEY_GAURD)|((IntCtrl_ConfigPtr->PriorityGroup)<<8); 


    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/
    
    /* Calculate offset of interrupt needed to write PRI Register */
    PRI_Offset = PRI_Offsets[(IntCtrl_ConfigPtr->IntNumber)%4];

    /*Decide which PRI Register To Use*/
    PRI_Register_Used = getPRIRegister(IntCtrl_ConfigPtr->IntNumber);
    
    if(IntCtrl_ConfigPtr->PriorityGroup == bxxx) /*No Sub Groups*/
    {
        Final_Priority = IntCtrl_ConfigPtr->Priority;
    }
    else if(IntCtrl_ConfigPtr->PriorityGroup == bxxy) /*Only 1 Sub Group*/
    {
        Final_Priority = ( (IntCtrl_ConfigPtr->Priority<<1) | (IntCtrl_ConfigPtr->SubGroupPriority) ); 
    }
    else if(IntCtrl_ConfigPtr->PriorityGroup == bxyy) /*2 Sub Groups*/
    {
        Final_Priority = ( (IntCtrl_ConfigPtr->Priority<<2) | (IntCtrl_ConfigPtr->SubGroupPriority) ); 
    }
    else if(IntCtrl_ConfigPtr->PriorityGroup == byyy) /*only Sub Groups => No Interrupt Preemptions */
    {
        Final_Priority = IntCtrl_ConfigPtr->SubGroupPriority ; 
    }

    /*Assign Priority */
    *PRI_Register_Used |= (Final_Priority<<PRI_Offset); 

	
}
/******************************************************************************
* \Syntax          : void IntCrtl_EnableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);                                    
* \Description     : Function to Enable an Interrupt                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_EnableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr)
{   
    uint8 EN_REG_BIT_NUM;
    volatile uint32 *EN_Reg_Used;
    EN_REG_BIT_NUM = ((IntCtrl_ConfigPtr->IntNumber)%32);
    if(((IntCtrl_ConfigPtr->IntNumber)>=0) && ((IntCtrl_ConfigPtr->IntNumber)<=31) )
    {
        EN_Reg_Used = EN0;
    }
    else if(((IntCtrl_ConfigPtr->IntNumber)>=32) && ((IntCtrl_ConfigPtr->IntNumber)<=63) )
    {
        EN_Reg_Used = EN1;
    }
    else if(((IntCtrl_ConfigPtr->IntNumber)>=64) && ((IntCtrl_ConfigPtr->IntNumber)<=95) )
    {
        EN_Reg_Used = EN2;
    }
        else if(((IntCtrl_ConfigPtr->IntNumber)>=96) && ((IntCtrl_ConfigPtr->IntNumber)<=127) )
    {
        EN_Reg_Used = EN3;
    }
        else if(((IntCtrl_ConfigPtr->IntNumber)>=128) && ((IntCtrl_ConfigPtr->IntNumber)<=138) )
    {
        EN_Reg_Used = EN4;
    }
    SET_BIT(*EN_Reg_Used,EN_REG_BIT_NUM);
}

/******************************************************************************
* \Syntax          : void IntCrtl_DisableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr);                                   
* \Description     : Function to Disable an Interrupt                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void IntCrtl_DisableINT(const INTCtrl_ConfigTyp *IntCtrl_ConfigPtr)
{
    uint8 DIS_REG_BIT_NUM;
    volatile uint32 *DIS_Reg_Used;
    DIS_REG_BIT_NUM  = ((IntCtrl_ConfigPtr->IntNumber)%32);
    if(((IntCtrl_ConfigPtr->IntNumber)>=0) && ((IntCtrl_ConfigPtr->IntNumber)<=31) )
    {
        DIS_Reg_Used = DIS0;
    }
    else if(((IntCtrl_ConfigPtr->IntNumber)>=32) && ((IntCtrl_ConfigPtr->IntNumber)<=63) )
    {
        DIS_Reg_Used = DIS1;
    }
    else if(((IntCtrl_ConfigPtr->IntNumber)>=64) && ((IntCtrl_ConfigPtr->IntNumber)<=95) )
    {
        DIS_Reg_Used = DIS2;
    }
        else if(((IntCtrl_ConfigPtr->IntNumber)>=96) && ((IntCtrl_ConfigPtr->IntNumber)<=127) )
    {
        DIS_Reg_Used = DIS3;
    }
        else if(((IntCtrl_ConfigPtr->IntNumber)>=128) && ((IntCtrl_ConfigPtr->IntNumber)<=138) )
    {
        DIS_Reg_Used = DIS4;
    }
    SET_BIT(*DIS_Reg_Used,DIS_REG_BIT_NUM);
}
/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/

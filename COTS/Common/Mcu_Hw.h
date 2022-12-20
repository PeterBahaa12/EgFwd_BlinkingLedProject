/******************************************************************************
 *
 * Module: MCU_Hardware Configuration
 * File Name: Mcu_Hw.h
 *
 * Created on: December 12, 2022
 *
 * Description: Header File for Registers Defintion.
 * Author: Peter Bahaa
 *
 *******************************************************************************/

#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/



/*****************************************************************************
* NVIC and SYS SCB Types
******************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/* This Can be used by :  
INTCTRL.B.VECPEND = 0x50; 
OR
INTCTRL.R = 0x00001223;
*/

/*****************************************************************************
* System control and clock types
******************************************************************************/
typedef struct 
{
    uint32 MOSCDIS    :1;
    uint32            :3;
    uint32 OSCSRC     :2;
    uint32 XTAL       :5;
    uint32 BYPASS     :1;
    uint32            :1;
    uint32 PWRDN      :1;
    uint32            :3;
    uint32 PWMDIV     :3;
    uint32 USEPWMDIV  :1;
    uint32            :1;
    uint32 USESYSDIV  :1;
    uint32 SYSDIV     :4;
    uint32 ACG        :1; 
    uint32            :4;
}RCC_BF;
typedef union 
{
    uint32 R;
    RCC_BF B;
}RCC_Tag;

typedef struct 
{
    uint32            :4;
    uint32 OSCSRC2    :3;
    uint32            :4;
    uint32 BYPASS2    :1;
    uint32            :1;
    uint32 PWRDN2     :1;
    uint32 USBPWRDN   :1;
    uint32            :7;
    uint32 SYSDIV2LSB :1;
    uint32 SYSDIV2    :6;
    uint32            :1;
    uint32 DIV400     :1;
    uint32 USERCC2    :1; 

}RCC2_BF;
typedef union 
{
    uint32 R;
    RCC2_BF B;
}RCC2_Tag;


/* This Can be used by :  
RCC.B.XTAL = 0x50; 
OR
RCC.R = 0x00001223;
*/





/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000

/*****************************************************************************
* NVIC and SCB Registers
******************************************************************************/

#define APINT            (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C)))
#define INTCTRL          (*((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)))

/* 
Interrupt Priority Registers Each Register has 4 Interrupts Inside with Programmable Priority of 
0 to 7 
*/
#define PRI0             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x400))
#define PRI1             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x404))
#define PRI2             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x408))
#define PRI3             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x40C))
#define PRI4             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x410))
#define PRI5             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x414))
#define PRI6             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x418))
#define PRI7             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x41C))
#define PRI8             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x420))
#define PRI9             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x424))
#define PRI10            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x428))
#define PRI11            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x42C))
#define PRI12            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x430))
#define PRI13            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x434))
#define PRI14            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x438))
#define PRI15            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x43C))
#define PRI16            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x440))
#define PRI17            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x444))
#define PRI18            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x448))
#define PRI19            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x44C))
#define PRI20            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x450))
#define PRI21            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x454))
#define PRI22            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x458))
#define PRI23            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x45C))
#define PRI24            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x460))
#define PRI25            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x464))
#define PRI26            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x468))
#define PRI27            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x46C))
#define PRI28            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x470))
#define PRI29            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x474))
#define PRI30            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x478))
#define PRI31            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x47C))
#define PRI32            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x480))
#define PRI33            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x484))
#define PRI34            ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x488))

/* 
Interrupt Enable Registers Each Register has 32 Interrupts, each bit corresponds to an interrupt BIT0=> Interrupt 0 GPIO PORT A Interrupt 
*/
#define EN0              ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100))
#define EN1              ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x104))
#define EN2              ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x108))
#define EN3              ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x10C))
#define EN4              ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x110))

/* 
Interrupt Disable Registers Each Register has 32 Interrupts, each bit corresponds to an interrupt BIT0=> Interrupt 0 GPIO PORT A Interrupt 
*/
#define DIS0             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x180))
#define DIS1             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x184))
#define DIS2             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x188))
#define DIS3             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x18C))
#define DIS4             ((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x190))

/* 
Interrupt Pend Registers Each Register has 32 Interrupts and they force interrupts into pending state
, each bit corresponds to an interrupt BIT0=> Interrupt 0 GPIO PORT A Interrupt 
*/
#define PEND0             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200)))
#define PEND1             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204)))
#define PEND2             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208)))
#define PEND3             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C)))
#define PEND4             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210)))

/* 
Interrupt unPend Registers Each Register has 32 Interrupts and clear pending state of interrupts
, each bit corresponds to an interrupt BIT0=> Interrupt 0 GPIO PORT A Interrupt 
*/
#define UNPEND0             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200)))
#define UNPEND1             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x204)))
#define UNPEND2             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x208)))
#define UNPEND3             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x20C)))
#define UNPEND4             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x210)))

/* 
Interrupt ACTIVE Registers Each Register has 32 Interrupts and used to check the status of the Register *READ ONLY*
, each bit corresponds to an interrupt BIT0=> Interrupt 0 GPIO PORT A Interrupt 
*/
#define ACTIVE0             (*((const volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x200)))
#define ACTIVE1             (*((const volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x304)))
#define ACTIVE2             (*((const volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x308)))
#define ACTIVE3             (*((const volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x30C)))
#define ACTIVE4             (*((const volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x310)))


/*****************************************************************************
* System and clock control
******************************************************************************/
#define RCC            (*((volatile RCC_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x060)))
#define RCC2           (*((volatile RCC2_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0x070)))
#define MOSCCTL        (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x07C)))  /*Main Oscillator Control*/
#define RIS_REG        (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x050))) 


/*****************************************************************************
GPIO registers (PORTA)
*****************************************************************************/
#define GPIO_PORTA_APB_BASE_ADDRESS   0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS   0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS   0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS   0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS   0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS   0x40025000


#define GPIO_PORTA_DATA_REG       		(*((volatile uint32 *)0x400043FC)) /*Data Register that will be used to Write Values on any PIN*/
#define GPIO_PORTA_DIR_REG        		(*((volatile uint32 *)0x40004400)) /*Direction Register I/P Pin => 0 O/P Pin => 1 */
#define GPIO_PORTA_AFSEL_REG      		(*((volatile uint32 *)0x40004420))
#define GPIO_PORTA_PUR_REG        		(*((volatile uint32 *)0x40004510))
#define GPIO_PORTA_PDR_REG        		(*((volatile uint32 *)0x40004514))
#define GPIO_PORTA_DEN_REG        		(*((volatile uint32 *)0x4000451C))
#define GPIO_PORTA_LOCK_REG       		(*((volatile uint32 *)0x40004520))
#define GPIO_PORTA_CR_REG         		(*((volatile uint32 *)0x40004524))
#define GPIO_PORTA_AMSEL_REG      		(*((volatile uint32 *)0x40004528))
#define GPIO_PORTA_PCTL_REG       		(*((volatile uint32 *)0x4000452C))
#define GPIO_PORTA_GPIODR2R						(*((volatile uint32 *)0x40004500))
#define GPIO_PORTA_GPIODR4R						(*((volatile uint32 *)0x40004504))
#define GPIO_PORTA_GPIODR8R						(*((volatile uint32 *)0x40004508))

/* PORTA External Interrupts Registers */
#define GPIO_PORTA_IS_REG         		(*((volatile uint32 *)0x40004404))
#define GPIO_PORTA_IBE_REG        		(*((volatile uint32 *)0x40004408))
#define GPIO_PORTA_IEV_REG        		(*((volatile uint32 *)0x4000440C))
#define GPIO_PORTA_IM_REG         		(*((volatile uint32 *)0x40004410))
#define GPIO_PORTA_RIS_REG        		(*((volatile uint32 *)0x40004414))
#define GPIO_PORTA_ICR_REG        		(*((volatile uint32 *)0x4000441C))

/*****************************************************************************
GPIO registers (PORTB)
*****************************************************************************/
#define GPIO_PORTB_DATA_REG       		(*((volatile uint32 *)0x400053FC))
#define GPIO_PORTB_DIR_REG        		(*((volatile uint32 *)0x40005400))
#define GPIO_PORTB_AFSEL_REG      		(*((volatile uint32 *)0x40005420))
#define GPIO_PORTB_PUR_REG        		(*((volatile uint32 *)0x40005510))
#define GPIO_PORTB_PDR_REG        		(*((volatile uint32 *)0x40005514))
#define GPIO_PORTB_DEN_REG        		(*((volatile uint32 *)0x4000551C))
#define GPIO_PORTB_LOCK_REG       		(*((volatile uint32 *)0x40005520))
#define GPIO_PORTB_CR_REG         		(*((volatile uint32 *)0x40005524))
#define GPIO_PORTB_AMSEL_REG      		(*((volatile uint32 *)0x40005528))
#define GPIO_PORTB_PCTL_REG       		(*((volatile uint32 *)0x4000552C))
#define GPIO_PORTB_GPIODR2R						(*((volatile uint32 *)0x40005500))
#define GPIO_PORTB_GPIODR4R						(*((volatile uint32 *)0x40005504))
#define GPIO_PORTB_GPIODR8R						(*((volatile uint32 *)0x40005508))

/* PORTB External Interrupts Registers */
#define GPIO_PORTB_IS_REG         		(*((volatile uint32 *)0x40005404))
#define GPIO_PORTB_IBE_REG        		(*((volatile uint32 *)0x40005408))
#define GPIO_PORTB_IEV_REG        		(*((volatile uint32 *)0x4000540C))
#define GPIO_PORTB_IM_REG         		(*((volatile uint32 *)0x40005410))
#define GPIO_PORTB_RIS_REG        		(*((volatile uint32 *)0x40005414))
#define GPIO_PORTB_ICR_REG        		(*((volatile uint32 *)0x4000541C))
		
/*****************************************************************************
GPIO registers (PORTC)
*****************************************************************************/
#define GPIO_PORTC_DATA_REG      			(*((volatile uint32 *)0x400063FC))
#define GPIO_PORTC_DIR_REG       			(*((volatile uint32 *)0x40006400))
#define GPIO_PORTC_AFSEL_REG     			(*((volatile uint32 *)0x40006420))
#define GPIO_PORTC_PUR_REG       			(*((volatile uint32 *)0x40006510))
#define GPIO_PORTC_PDR_REG       			(*((volatile uint32 *)0x40006514))
#define GPIO_PORTC_DEN_REG       			(*((volatile uint32 *)0x4000651C))
#define GPIO_PORTC_LOCK_REG      			(*((volatile uint32 *)0x40006520))
#define GPIO_PORTC_CR_REG        			(*((volatile uint32 *)0x40006524))
#define GPIO_PORTC_AMSEL_REG     			(*((volatile uint32 *)0x40006528))
#define GPIO_PORTC_PCTL_REG      			(*((volatile uint32 *)0x4000652C))
#define GPIO_PORTC_GPIODR2R						(*((volatile uint32 *)0x40006500))
#define GPIO_PORTC_GPIODR4R						(*((volatile uint32 *)0x40006504))
#define GPIO_PORTC_GPIODR8R						(*((volatile uint32 *)0x40006508))

/* PORTC External Interrupts Registers */
#define GPIO_PORTC_IS_REG         		(*((volatile uint32 *)0x40006404))
#define GPIO_PORTC_IBE_REG        		(*((volatile uint32 *)0x40006408))
#define GPIO_PORTC_IEV_REG        		(*((volatile uint32 *)0x4000640C))
#define GPIO_PORTC_IM_REG         		(*((volatile uint32 *)0x40006410))
#define GPIO_PORTC_RIS_REG        		(*((volatile uint32 *)0x40006414))
#define GPIO_PORTC_ICR_REG        		(*((volatile uint32 *)0x4000641C))
		
/*****************************************************************************
GPIO registers (PORTD)
*****************************************************************************/
#define GPIO_PORTD_DATA_REG      		 (*((volatile uint32 *)0x400073FC))
#define GPIO_PORTD_DIR_REG       		 (*((volatile uint32 *)0x40007400))
#define GPIO_PORTD_AFSEL_REG     		 (*((volatile uint32 *)0x40007420))
#define GPIO_PORTD_PUR_REG       		 (*((volatile uint32 *)0x40007510))
#define GPIO_PORTD_PDR_REG       		 (*((volatile uint32 *)0x40007514))
#define GPIO_PORTD_DEN_REG       		 (*((volatile uint32 *)0x4000751C))
#define GPIO_PORTD_LOCK_REG      		 (*((volatile uint32 *)0x40007520))
#define GPIO_PORTD_CR_REG        		 (*((volatile uint32 *)0x40007524))
#define GPIO_PORTD_AMSEL_REG     		 (*((volatile uint32 *)0x40007528))
#define GPIO_PORTD_PCTL_REG      		 (*((volatile uint32 *)0x4000752C))
#define GPIO_PORTD_GPIODR2R					 (*((volatile uint32 *)0x40007500))
#define GPIO_PORTD_GPIODR4R					 (*((volatile uint32 *)0x40007504))
#define GPIO_PORTD_GPIODR8R					 (*((volatile uint32 *)0x40007508))

/* PORTD External Interrupts Registers */
#define GPIO_PORTD_IS_REG         	(*((volatile uint32 *)0x40007404))
#define GPIO_PORTD_IBE_REG        	(*((volatile uint32 *)0x40007408))
#define GPIO_PORTD_IEV_REG        	(*((volatile uint32 *)0x4000740C))
#define GPIO_PORTD_IM_REG         	(*((volatile uint32 *)0x40007410))
#define GPIO_PORTD_RIS_REG        	(*((volatile uint32 *)0x40007414))
#define GPIO_PORTD_ICR_REG        	(*((volatile uint32 *)0x4000741C))

/*****************************************************************************
GPIO registers (PORTE)
*****************************************************************************/
#define GPIO_PORTE_DATA_REG      		 (*((volatile uint32 *)0x400243FC))
#define GPIO_PORTE_DIR_REG       		 (*((volatile uint32 *)0x40024400))
#define GPIO_PORTE_AFSEL_REG     		 (*((volatile uint32 *)0x40024420))
#define GPIO_PORTE_PUR_REG       		 (*((volatile uint32 *)0x40024510))
#define GPIO_PORTE_PDR_REG       		 (*((volatile uint32 *)0x40024514))
#define GPIO_PORTE_DEN_REG       		 (*((volatile uint32 *)0x4002451C))
#define GPIO_PORTE_LOCK_REG      		 (*((volatile uint32 *)0x40024520))
#define GPIO_PORTE_CR_REG        		 (*((volatile uint32 *)0x40024524))
#define GPIO_PORTE_AMSEL_REG     		 (*((volatile uint32 *)0x40024528))
#define GPIO_PORTE_PCTL_REG      		 (*((volatile uint32 *)0x4002452C))
#define GPIO_PORTE_GPIODR2R					 (*((volatile uint32 *)0x40024500))
#define GPIO_PORTE_GPIODR4R					 (*((volatile uint32 *)0x40024504))
#define GPIO_PORTE_GPIODR8R					 (*((volatile uint32 *)0x40024508))

/* PORTE External Interrupts Registers */
#define GPIO_PORTE_IS_REG         		(*((volatile uint32 *)0x40024404))
#define GPIO_PORTE_IBE_REG        		(*((volatile uint32 *)0x40024408))
#define GPIO_PORTE_IEV_REG        		(*((volatile uint32 *)0x4002440C))
#define GPIO_PORTE_IM_REG         		(*((volatile uint32 *)0x40024410))
#define GPIO_PORTE_RIS_REG        		(*((volatile uint32 *)0x40024414))
#define GPIO_PORTE_ICR_REG        		(*((volatile uint32 *)0x4002441C))

/*****************************************************************************
GPIO registers (PORTF)
*****************************************************************************/
#define GPIO_PORTF_DATA_REG       		(*((volatile uint32 *)0x400253FC))
#define GPIO_PORTF_DIR_REG        		(*((volatile uint32 *)0x40025400))
#define GPIO_PORTF_AFSEL_REG      		(*((volatile uint32 *)0x40025420))
#define GPIO_PORTF_PUR_REG        		(*((volatile uint32 *)0x40025510))
#define GPIO_PORTF_PDR_REG        		(*((volatile uint32 *)0x40025514))
#define GPIO_PORTF_DEN_REG        		(*((volatile uint32 *)0x4002551C))
#define GPIO_PORTF_LOCK_REG       		(*((volatile uint32 *)0x40025520))
#define GPIO_PORTF_CR_REG         		(*((volatile uint32 *)0x40025524))
#define GPIO_PORTF_AMSEL_REG      		(*((volatile uint32 *)0x40025528))
#define GPIO_PORTF_PCTL_REG       		(*((volatile uint32 *)0x4002552C))
#define GPIO_PORTF_GPIODR2R						(*((volatile uint32 *)0x40025000))
#define GPIO_PORTF_GPIODR4R						(*((volatile uint32 *)0x40025004))
#define GPIO_PORTF_GPIODR8R						(*((volatile uint32 *)0x40025008))


/* PORTF External Interrupts Registers */
#define GPIO_PORTF_IS_REG        		 (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_REG       		 (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_REG       		 (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_REG        		 (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_REG       		 (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_ICR_REG       		 (*((volatile uint32 *)0x4002541C))


/* General-Purpose Input/Output Run Mode Clock Gating Control */
#define SYS_CTRL_RCGCGPIO_REG    (*((volatile uint32*)0x400FE108))
#define SYS_CTRL_RCGC2GPIO_REG   (*((volatile uint32*)(0x400FE000+0x108))) 
	

/*****************************************************************************
* Systick Timer Registers
******************************************************************************/
#define ST_CURRENT_REG     (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)))
#define ST_RELOAD_REG      (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)))
#define ST_CTRL_REG 			 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)))

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/

 /******************************************************************************
 *
 * Module: DIO
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - DIO Driver
 *              Page 656 IN Datasheet.
 * Author: Peter Bahaa
 ******************************************************************************/
 
 
 
 
 
  /**********************************************************************************************************************
 * INCLUDES
 ***********************************************************************************************************************/
 
#include "DIO.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
 #define NUM_OF_PINS_PER_PORT 8
 #define NUM_OF_PORTS 6
 
 /**********************************************************************************************************************
 *  GLOBAL FUNCTION Definitons
 **********************************************************************************************************************/
 
/************************************************************************************
* Function Name: DIO_Init
* Sync/Async: Synchronous
* Reentrancy: Non-reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Initializes the DIO module
	NOTE : Driver Doesn't support analog INT or interrupts yet. 
************************************************************************************/
 
  void DIO_Init(Port_ConfigType* DIO_Config_Ptr)
 { 
	 volatile uint32 PCTL_REG_CLEAR_MASK = CTRL_REG_CLEAR_MASK ;
		switch (DIO_Config_Ptr->PortNum)
			
	{
			case DIO_PORT_A:
						/* Activate Clock */
						SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_A_ID);
						/*Wait for Clock to Init*/
						while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_A_ID));
						
						
						/*PIN Direction & Attach Type */
						if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
						{
							/* Init direction and clear everything on the PIN */
							SET_BIT(GPIO_PORTA_DIR_REG,(DIO_Config_Ptr->PortPinNum));
							CLEAR_BIT(GPIO_PORTA_DATA_REG,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
						{
							/* Configure PIN As Input */
							CLEAR_BIT(GPIO_PORTA_DIR_REG,(DIO_Config_Ptr->PortPinNum));
							/* Configure Attach Type */
							if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
							{
								SET_BIT(GPIO_PORTA_PUR_REG,(DIO_Config_Ptr->PortPinNum));
							}
						else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
							{
								SET_BIT(GPIO_PORTA_PDR_REG,(DIO_Config_Ptr->PortPinNum));
							}
						
						else
						{
							/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
							CLEAR_BIT(GPIO_PORTA_PDR_REG,(DIO_Config_Ptr->PortPinNum));
							CLEAR_BIT(GPIO_PORTA_PUR_REG,(DIO_Config_Ptr->PortPinNum));
						}
					}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTA_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTA_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTA_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTA_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTA_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTA_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTA_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTA_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTA_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTA_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTA_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
						break;
		
			case DIO_PORT_B:
					/* Activate Clock */
					SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_B_ID);
					/*Wait for Clock to Init*/
					while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_B_ID));
					
					/*PIN Direction & Attach Type */
					if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
					{
						/* Init direction and clear everything on the PIN */
						SET_BIT(GPIO_PORTB_DIR_REG,(DIO_Config_Ptr->PortPinNum));
						CLEAR_BIT(GPIO_PORTB_DATA_REG,(DIO_Config_Ptr->PortPinNum));
					}
					else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
					{
						/* Configure PIN As Input */
						CLEAR_BIT(GPIO_PORTB_DIR_REG,(DIO_Config_Ptr->PortPinNum));
								/* Configure Attach Type */
								if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
								{
									SET_BIT(GPIO_PORTB_PUR_REG,(DIO_Config_Ptr->PortPinNum));
								}
								else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
								{
									SET_BIT(GPIO_PORTB_PDR_REG,(DIO_Config_Ptr->PortPinNum));
								}
								else
								{
								/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
								CLEAR_BIT(GPIO_PORTB_PDR_REG,(DIO_Config_Ptr->PortPinNum));
								CLEAR_BIT(GPIO_PORTB_PUR_REG,(DIO_Config_Ptr->PortPinNum));
								}
					}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTB_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTB_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTB_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTB_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTB_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTB_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTB_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTB_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTB_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTB_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTB_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
					break;
		
			case DIO_PORT_C:
			/* Activate Clock */
			SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_C_ID);
			/*Wait for Clock to Init*/
			while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_C_ID));
			
			/*PIN Direction & Attach Type */
			if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
			{
				/* Init direction and clear everything on the PIN */
				SET_BIT(GPIO_PORTC_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTC_DATA_REG,(DIO_Config_Ptr->PortPinNum));
			}
						else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
			{
				/* Configure PIN As Input */
				CLEAR_BIT(GPIO_PORTC_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				/* Configure Attach Type */
				if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
				{
					SET_BIT(GPIO_PORTC_PUR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
				{
					SET_BIT(GPIO_PORTC_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else
			{
				/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
				CLEAR_BIT(GPIO_PORTC_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTC_PUR_REG,(DIO_Config_Ptr->PortPinNum));
			}
			}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTC_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTC_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTC_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTC_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTC_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTC_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTC_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTC_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTC_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTC_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTC_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
			break;
		
			case DIO_PORT_D:
			/* Activate Clock */
			SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_D_ID);
			/*Wait for Clock to Init*/
			while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_D_ID));
			/*unlocking the pin in the GPIOLOCK register and uncommitting it, PD[7]*/
			if(DIO_Config_Ptr->PortPinNum == PORT_PIN7) /* PD7 */
			GPIO_PORTD_LOCK_REG = LOCK_KEY_MASK ;
			SET_BIT(GPIO_PORTD_CR_REG,PORT_PIN7);	
						/*PIN Direction & Attach Type */
			if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
			{
				/* Init direction and clear everything on the PIN */
				SET_BIT(GPIO_PORTD_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTD_DATA_REG,(DIO_Config_Ptr->PortPinNum));
				
			}
						else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
			{
				/* Configure PIN As Input */
				CLEAR_BIT(GPIO_PORTD_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				/* Configure Attach Type */
				if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
				{
					SET_BIT(GPIO_PORTD_PUR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
				{
					SET_BIT(GPIO_PORTD_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else
			{
				/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
				CLEAR_BIT(GPIO_PORTD_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTD_PUR_REG,(DIO_Config_Ptr->PortPinNum));
			}
		}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTD_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTD_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTD_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTD_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTD_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTD_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTD_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTD_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTD_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTD_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTD_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
			
			break;
		
			case DIO_PORT_E:
			/* Activate Clock */
			SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_E_ID); 
			/*Wait for Clock to Init*/
			while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_E_ID));
						/*PIN Direction & Attach Type */
			if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
			{
				/* Init direction and clear everything on the PIN */
				SET_BIT(GPIO_PORTE_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTE_DATA_REG,(DIO_Config_Ptr->PortPinNum));
			}
			else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
			{
				/* Configure PIN As Input */
				CLEAR_BIT(GPIO_PORTE_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				/* Configure Attach Type */
				if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
				{
					SET_BIT(GPIO_PORTE_PUR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
				{
					SET_BIT(GPIO_PORTE_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else
			{
				/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
				CLEAR_BIT(GPIO_PORTE_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTE_PUR_REG,(DIO_Config_Ptr->PortPinNum));
			}
		}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTE_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTE_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTE_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTE_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTE_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTE_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTE_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTE_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTE_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTE_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTE_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
			break;
		
			case DIO_PORT_F:
			/* Activate Clock */
			SET_BIT(SYS_CTRL_RCGCGPIO_REG,PORT_F_ID);
			/*Wait for Clock to Init*/
			while(!BIT_IS_SET(SYS_CTRL_RCGC2GPIO_REG,PORT_F_ID));
			/*unlocking the pin in the GPIOLOCK register and uncommitting it, PF[0]*/
			if(DIO_Config_Ptr->PortPinNum == PORT_PIN0) /* PF0 */
			GPIO_PORTF_LOCK_REG = LOCK_KEY_MASK ;
			SET_BIT(GPIO_PORTF_CR_REG,PORT_PIN0);
			
				/*PIN Direction & Attach Type */
			if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_OUTPUT)
			{
				/* Init direction and clear everything on the PIN */
				SET_BIT(GPIO_PORTF_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTF_DATA_REG,(DIO_Config_Ptr->PortPinNum));
				
			}
						else if(DIO_Config_Ptr->PortPinDirection == PORT_PIN_INPUT)
			{
				/* Configure PIN As Input */
				CLEAR_BIT(GPIO_PORTF_DIR_REG,(DIO_Config_Ptr->PortPinNum));
				/* Configure Attach Type */
				if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PUR) /* Pull Up Resistor! */
				{
					SET_BIT(GPIO_PORTF_PUR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else if(DIO_Config_Ptr -> PortPinInternalAttach == PORT_PIN_PDR) /* Pull down Resistor! */
				{
					SET_BIT(GPIO_PORTF_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				}
			else
			{
				/*Clear Both Pull Up and pulldown registers ie. external pull up or pull down*/
				CLEAR_BIT(GPIO_PORTF_PDR_REG,(DIO_Config_Ptr->PortPinNum));
				CLEAR_BIT(GPIO_PORTF_PUR_REG,(DIO_Config_Ptr->PortPinNum));
			}
		}
						/* Configure PIN Mode */
						if(DIO_Config_Ptr->PortPinMode == PORT_PIN_DIGITAL)
						{
							/* Disable Analog on PIN */
							CLEAR_BIT(GPIO_PORTF_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTF_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTF_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							SET_BIT(GPIO_PORTF_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
					else if(DIO_Config_Ptr->PortPinMode == PORT_PIN_ANALOG)
						{
							/* Enable Analog on PIN */
							SET_BIT(GPIO_PORTF_AMSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/*Disable alternative function*/
							CLEAR_BIT(GPIO_PORTF_AFSEL_REG,(DIO_Config_Ptr->PortPinNum));
							/* Clear PMCx bits for PIN to use it as GPIO pin */
							ROL(PCTL_REG_CLEAR_MASK,((DIO_Config_Ptr->PortPinNum)*4))  ;
							GPIO_PORTF_PCTL_REG = PCTL_REG_CLEAR_MASK;
							/* Set digital enable bit for current pin*/
							CLEAR_BIT(GPIO_PORTF_DEN_REG,(DIO_Config_Ptr->PortPinNum));
						}
						
						
						/* Configure Pin Current */
						if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_2MA)
						{
							SET_BIT(GPIO_PORTF_GPIODR2R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_4MA)
						{
							SET_BIT(GPIO_PORTF_GPIODR4R,(DIO_Config_Ptr->PortPinNum));
						}
						else if(DIO_Config_Ptr->PortPinOutputCurrent == PORT_PIN_CUR_8MA)
						{
							SET_BIT(GPIO_PORTF_GPIODR8R,(DIO_Config_Ptr->PortPinNum));
						}
			break;
		}
	}
 
	
	
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
Port_LevelType DIO_ReadPort(Port_Num PORT_ID)
	
{
uint32 Port_Value ;
	switch(PORT_ID)
	{
		case DIO_PORT_A:
			 Port_Value = GPIO_PORTA_DATA_REG;
			break;
		case DIO_PORT_B:
			 Port_Value = GPIO_PORTB_DATA_REG;
			break;
		case DIO_PORT_C:
			 Port_Value = GPIO_PORTC_DATA_REG;
			break;
		case DIO_PORT_D:
			 Port_Value = GPIO_PORTD_DATA_REG;
			break;
		case DIO_PORT_E:
			 Port_Value = GPIO_PORTE_DATA_REG;
			break;
		case DIO_PORT_F:
			 Port_Value = GPIO_PORTF_DATA_REG;
			break;
	}
	return Port_Value;
}


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
void DIO_WritePort(Port_Num PORT_ID, Port_LevelType Port_Value)
{
		switch(PORT_ID)
	{
		case DIO_PORT_A:
			 GPIO_PORTA_DATA_REG = Port_Value ;
			break;
		case DIO_PORT_B:
			 GPIO_PORTB_DATA_REG = Port_Value ;
			break;
		case DIO_PORT_C:
			 GPIO_PORTC_DATA_REG = Port_Value ;
			break;
		case DIO_PORT_D:
			 GPIO_PORTD_DATA_REG = Port_Value ;
			break;
		case DIO_PORT_E:
		   GPIO_PORTE_DATA_REG = Port_Value ;
			break;
		case DIO_PORT_F:
			  GPIO_PORTF_DATA_REG = Port_Value;
			break;
	}
}
/************************************************************************************
* Function Name: DIO_WriteChannel
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Channel_ID - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void DIO_WriteChannel(Port_Num PORT_ID,Port_PinNum Pin_Num,Port_PinLevel Pin_Value)
{
		switch(PORT_ID)
	{
		case DIO_PORT_A:
			if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTA_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTA_DATA_REG,Pin_Num);
			}
			break;
		case DIO_PORT_B:
			 if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			}
			break;
		case DIO_PORT_C:
			 if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTC_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTC_DATA_REG,Pin_Num);
			}
			break;
		case DIO_PORT_D:
			 if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTD_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTD_DATA_REG,Pin_Num);
			}
			break;
		case DIO_PORT_E:
		   if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTE_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTE_DATA_REG,Pin_Num);
			}
			break;
		case DIO_PORT_F:
			  if(Pin_Value == PORT_PIN_HIGH)
			{
				SET_BIT(GPIO_PORTF_DATA_REG,Pin_Num);
			}
			else if(Pin_Value == PORT_PIN_LOW)
			{
				CLEAR_BIT(GPIO_PORTF_DATA_REG,Pin_Num);
			}
			break;
	}	
}

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
Port_PinLevel DIO_ReadChannel(Port_Num PORT_ID,Port_PinNum Pin_Num)
{
	uint8 pin_value;
		switch(PORT_ID)
	{
		case DIO_PORT_A:
			if(BIT_IS_SET(GPIO_PORTA_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
			
		case DIO_PORT_B:
			if(BIT_IS_SET(GPIO_PORTB_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
		case DIO_PORT_C:
			if(BIT_IS_SET(GPIO_PORTC_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
		case DIO_PORT_D:
			if(BIT_IS_SET(GPIO_PORTD_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
		case DIO_PORT_E:
		  if(BIT_IS_SET(GPIO_PORTE_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
		case DIO_PORT_F:
			 if(BIT_IS_SET(GPIO_PORTF_DATA_REG,Pin_Num))
			{
				pin_value = PORT_PIN_HIGH;
			}
			else 
			{
			  pin_value = PORT_PIN_LOW;
			}
			break;
	}
	return pin_value;	
}

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
void DIO_FlipChannel(Port_Num PORT_ID,Port_PinNum Pin_Num)
{
			switch(PORT_ID)
	{
		case DIO_PORT_A:
			 TOGGLE_BIT(GPIO_PORTA_DATA_REG,Pin_Num);
			break;
		case DIO_PORT_B:
			 TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			break;
		case DIO_PORT_C:
			 TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			break;
		case DIO_PORT_D:
			 TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			break;
		case DIO_PORT_E:
			 TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			break;
		case DIO_PORT_F:
			 TOGGLE_BIT(GPIO_PORTB_DATA_REG,Pin_Num);
			break;
	}
}
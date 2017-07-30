/**
  ******************************************************************************
  * Ten Tep		:		    main.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			  MinhHaGroup
  *	Website 	:			  MinhHaGroup.com
  * Phien Ban	:			  V1.0.0
  * Ngay		  :    		31-07-2012
  * Tom Tat   :       Dinh nghia ham main.           			
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
#include "main.h"
#include "var.h" 
/*********************************EXTERN VARIABLE***********************************/ 
int main(void)
{
/***********************************BIEN CUC BO*************************************/
char str[20];
uint8_t Key;
/***********************************SYSTEM******************************************/
SystemInit();

/************************************NVIC*******************************************/
//NVIC_Configuration();
						
/************************************GPIO*******************************************/
GPIO_Configuration();

/************************************TIMER*******************************************/
//+++++++++++++++++++++++++++++++++++TIMER1+++++++++++++++++++++++++++++++++++++++++++
//TIMER1_Configuration();

//+++++++++++++++++++++++++++++++++++TIMER2+++++++++++++++++++++++++++++++++++++++++++
//TIMER2_Configuration();

//+++++++++++++++++++++++++++++++++++TIMER3+++++++++++++++++++++++++++++++++++++++++++
//TIMER3_Configuration();	

/************************************DMA********************************************/
//+++++++++++++++++++++++++++++++++++DMA1+++++++++++++++++++++++++++++++++++++++++++
//DMA1_Configuration();

//+++++++++++++++++++++++++++++++++++DMA2+++++++++++++++++++++++++++++++++++++++++++
//DMA1_Configuration();

/************************************ADC********************************************/
//++++++++++++++++++++++++++++++++++ADC1+++++++++++++++++++++++++++++++++++++++++++
//ADC1_Configuration();

//+++++++++++++++++++++++++++++++++ADC2+++++++++++++++++++++++++++++++++++++++++++
//ADC2_Configuration();	

//+++++++++++++++++++++++++++++++++ADC3++++++++++++++++++++++++++++++++++++++++++
//ADC3_Configuration();

/************************************USART********************************************/
//+++++++++++++++++++++++++++++++++USART1++++++++++++++++++++++++++++++++++++++++++
// USART1_Configuration();
	
//+++++++++++++++++++++++++++++++++USART2++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++USART3++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++USART4++++++++++++++++++++++++++++++++++++++++++
/****************************** USER FUNCITION *************************************/	
  delay_init(72);
	LCD_Init();
	EEP_24CXX_Init();
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
								 EXCUTION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/****************************************************************************
****************************************************************************/
LCD_Puts((uint8_t*)"MinhHaGroup");
LCD_Gotoxy(0,1);
LCD_Puts((uint8_t*)"BanLinhKien.Vn");
delay_ms(1000);
LCD_Clear();
EEP_24CXX_WriteS(0x01,(uint8_t*)"Nguyen Quy Nhat");
EEPROM_24CXX_ReadS(0x01,15,(uint8_t *)str);
LCD_Gotoxy(0,1);
LCD_Puts((uint8_t *)str);
while(1)
 {	
		;
 }
}
/******************* (C) COPYRIGHT 2012 Nguyen Quy Nhat *****END OF FILE****/

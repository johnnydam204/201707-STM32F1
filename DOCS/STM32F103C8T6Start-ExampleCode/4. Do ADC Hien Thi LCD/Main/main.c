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
	uint16_t ValueADC;
	uint8_t Str[20];
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
ADC1_Configuration();

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
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
								 EXCUTION
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/****************************************************************************
****************************************************************************/
LCD_Puts("MinhHaGroup");
LCD_Gotoxy(0,1);
LCD_Puts("BanLinhKien.Vn");
delay_ms(1000);
LCD_Clear();
while(1)
 {
			ValueADC=read_adc(ADC1,0);
	    sprintf(Str,"ADC = %4u",ValueADC);
	    LCD_Gotoxy(0,0);
	    LCD_Puts(Str);
 }
}
/******************* (C) COPYRIGHT 2012 Nguyen Quy Nhat *****END OF FILE****/

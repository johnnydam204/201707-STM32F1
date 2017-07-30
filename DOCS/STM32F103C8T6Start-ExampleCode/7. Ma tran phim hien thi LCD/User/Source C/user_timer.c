/**
  ******************************************************************************
  * Ten Tep		:		    user_timer.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:       	Dinh nghia cac ham cau hinh cho Timer.           			
  *           
  *
  ******************************************************************************
  * Chu Y		:			Disable cac ham khong su dung den.
  *							Cac timer co cac chuc nang ho tro va cau hinh khac nhau,
  *							xem chi tiet tai stm32f10x_tim.c va stm32f10x_tim.h
  *							TIM_CounterMode:
								- TIM_CounterMode_Up				--> 
								- TIM_CounterMode_Down				-->
								- TIM_CounterMode_CenterAligned1	-->
								- TIM_CounterMode_CenterAligned2	-->
								- TIM_CounterMode_CenterAligned3	-->
							TIM_ClockDivision
								- TIM_CKD_DIV1						-->
								- TIM_CKD_DIV2						-->
								- TIM_CKD_DIV4						-->
  *							
  *
  *
  * 
  ******************************************************************************
  */
#include "user_timer.h"
unsigned int CCR2_Val=60000; 
void  TIMER1_Configuration(void)
{
	TIM_TimeBaseInitTypeDef  TIM1_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM1_OCInitStructure;
//	TIM_BDTRInitTypeDef TIM3_BDTRInitStructure;
/*-------------------------------------------------------------------*/
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
  //Chon gia tri chia tan so 0x0001 - 0x000ff	
  TIM3_TimeBaseStructure.TIM_Prescaler = 6000;						
  //Chon che do dem
  TIM3_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	
  // Chon chu ky 
  TIM3_TimeBaseStructure.TIM_Period =6000;
  //Chon gia tri chia clock
  TIM3_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  
   TIM3_TimeBaseStructure.TIM_RepetitionCounter = 0x0;
 // Cau hinh
  TIM_TimeBaseInit(TIM3,&TIM3_TimeBaseStructure);				
 //++++++++++++++++++++Cau Hinh Output Compare++++++++++++++++++++++++++++ 
 
 // che do output_compare
  TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle ;	
// TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
 //Enable Output
  TIM3_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
 //Do rong xung
  TIM3_OCInitStructure.TIM_Pulse =2000;						 
 // Chon muc do uu tien 																	
  TIM3_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;			
//Cau hinh OC2
  TIM_OC2Init(TIM3, &TIM3_OCInitStructure);
//Disable Preload 
  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);
 //  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++Cau Hinh InputCapture+++++++++++++++++++++++++++++

//Enable Timer3
   TIM_Cmd(TIM3,ENABLE);
//Enable Ngat CC2
  // TIM_ITConfig(TIM3,TIM_IT_CC2,ENABLE); //
  //+++++++++++++++++++++++++TIMER 4++++++++++++++++++++++++++++++++++
   	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);	
  TIM4_TimeBaseStructure.TIM_Prescaler = 600;						//Prescaler = 63
  //Chon che do cho bo dem
  TIM4_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;//TIM_CounterMode_Down;	
  // Chon chu ky 
  TIM4_TimeBaseStructure.TIM_Period =0xffff;
  //Chon toc do chia
  TIM4_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;//TIM_CKD_DIV2;TIM_CKD_DIV4					
 // Cau hinh
  TIM_TimeBaseInit(TIM4,&TIM4_TimeBaseStructure);
  //++++++++++++++++++++Cau Hinh Output Compare++++++++++++++++++++++++++++ 
 
 // che do output_compare
  TIM4_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle ;	
 //Enable Output
  TIM4_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
 //Do rong xung
  TIM4_OCInitStructure.TIM_Pulse =CCR2_Val;						 
 // Chon muc do uu tien 																	
  TIM4_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;			
//Cau hinh OC2
  TIM_OC1Init(TIM4, &TIM4_OCInitStructure);
//Disable Preload 
  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Disable);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   TIM_Cmd(TIM4,ENABLE);
//Enable Ngat CC2
   TIM_ITConfig(TIM4,TIM_IT_CC1,ENABLE); //
}

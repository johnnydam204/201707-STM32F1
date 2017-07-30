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
	//TIM_OCInitTypeDef  TIM1_OCInitStructure;
	TIM_ICInitTypeDef  TIM1_ICInitStructure;
//	TIM_BDTRInitTypeDef TIM3_BDTRInitStructure;
/*-------------------------------------------------------------------*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);
  //Chon gia tri chia tan so 0x0001 - 0xffff	
  TIM1_TimeBaseStructure.TIM_Prescaler = 72;						
  //Chon che do dem
  TIM1_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;	
  // Chon chu ky 
  TIM1_TimeBaseStructure.TIM_Period =0xffff;
  //Chon gia tri chia clock
  TIM1_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  // So lan tran Timer
   TIM1_TimeBaseStructure.TIM_RepetitionCounter = 0x0;
 // Cau hinh
  TIM_TimeBaseInit(TIM1,&TIM1_TimeBaseStructure);				
 //++++++++++++++++++++Cau Hinh Output Compare++++++++++++++++++++++++++++ 
 
// // che do output_compare
//  //TIM1_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle ;	
// TIM3_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM2;
// //Enable Output
// // TIM1_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
// //Do rong xung
// // TIM1_OCInitStructure.TIM_Pulse =2000;						 
// // Chon muc do uu tien 																	
// // TIM1_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;			
//Cau hinh OC2
// // TIM_OC2Init(TIM3, &TIM1_OCInitStructure);
//Disable Preload 
//  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Disable);
// //  TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++Cau Hinh InputCapture+++++++++++++++++++++++++++++
   TIM1_ICInitStructure.TIM_Channel      =    TIM_Channel_1;    
	 TIM1_ICInitStructure.TIM_ICFilter     =    0x05;
	 TIM1_ICInitStructure.TIM_ICPolarity   =    TIM_ICPolarity_Rising;
	 TIM1_ICInitStructure.TIM_ICPrescaler  =    TIM_ICPSC_DIV1;
	 TIM1_ICInitStructure.TIM_ICSelection  =    TIM_ICSelection_DirectTI;
	 TIM_ICInit(TIM1,&TIM1_ICInitStructure);
	 TIM_Cmd(TIM1,ENABLE);
	 TIM_ITConfig(TIM1,TIM_IT_CC1,ENABLE);
	 TIM_ITConfig(TIM1,TIM_IT_Update,ENABLE);
}

/**
  ******************************************************************************
  * Ten Tep		:		    user_delay.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  * Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat   	:       	Dinh nghia cac ham su dung de tao tre.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y			:				
  *
  *
  * 
  ******************************************************************************
  */
#include "user_delay.h"
 
static u8  fac_us=0;
static u16 fac_ms=0;
void delay_init(u8 SYSCLK)
{
	SysTick->CTRL&=0xfffffffb;
	fac_us=SYSCLK/8;		    
	fac_ms=(u16)fac_us*1000;
}								    
void delay_ms(u16 nms)
{	 		  	  
	u32 temp;		   
	SysTick->LOAD=(u32)nms*fac_ms;
	SysTick->VAL =0x00;           
	SysTick->CTRL=0x01 ;         
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16))); 
	SysTick->CTRL=0x00;       
	SysTick->VAL =0X00;       	    
}   	    								   
void delay_us(u32 nus)
{		
	u32 temp;	    	 
	SysTick->LOAD=nus*fac_us;   		 
	SysTick->VAL=0x00;        
	SysTick->CTRL=0x01 ;      	 
	do
	{
		temp=SysTick->CTRL;
	}
	while(temp&0x01&&!(temp&(1<<16)));   
	SysTick->CTRL=0x00;       
	SysTick->VAL =0X00;        
}





































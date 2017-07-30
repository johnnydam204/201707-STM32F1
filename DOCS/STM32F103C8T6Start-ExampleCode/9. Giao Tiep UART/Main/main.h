/**
  ******************************************************************************
  * Ten Tep		:		    Main.h
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			  MinhHaGroup
  *	Website 	:			  MinhHaGroup.com
  * Phien Ban	:			  V1.0.0
  * Ngay		  :    		31-07-2012
  * Tom Tat   :       	Khai bao cac thu vien su dung.
  *							Dinh nghia mot so chuc nang.
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */		
#ifndef __MAIN_H
#define	__MAIN_H
//#define USE_STDPERIPH_DRIVER
//#define STM32F10X_HD
/************************INCLUDE FILE********************************/
/*++++++++++++STANDAR C++++++++++++++*/
#include  <stdarg.h>
#include  <string.h>
#include  <ctype.h>
#include  <stdlib.h>
#include  <stdio.h>
/*++++++++++++DRIVER++++++++++++++++*/
#include "DEF_STM32.h"
#include "stm32f10x.h"	   
//#include "stm32f10x_adc.h"
//#include "stm32f10x_dma.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_usart.h"
#include "stm32f10x_tim.h"
#include "misc.h"	
/*+++++++++++++USER+++++++++++++++++*/
#include "user_delay.h"
#include "user_gpio.h"
//#include "user_dma.h"
//#include "user_adc.h"
#include "user_timer.h"
#include "user_interrupt.h"
#include "user_usart.h"
#include "user_nvic.h"
/************DEVICE******************/
#include "lcd16x2.h"
/**************************DEFINE********************************/ 
//+++++++++++++++++++++++++DEFINE PORTA+++++++++++++++++++++++++++
#define   LED7_DATA_PORT    PORTA
#define   LCD_D4       PORTA_4
#define   LCD_D5       PORTA_5
#define   LCD_D6       PORTA_6
#define   LCD_D7       PORTA_7

#define   BUTTON1      PINA_11
#define   BUTTON2      PINA_12
#define   ROLE         PORTA_13
#define   BUTTON3      PINA_14
#define   BUTTON4      PINA_15
#define   NE555        PINA_8
//+++++++++++++++++++++++++DEFINE PORTB+++++++++++++++++++++++++++
#define   LED7_ADDR_PORT   PORTB
#define   PORT_LED         PORTB
#define   LED1             PORTB_0
#define   COI              PORTB_8
#define   LCD_RS           PORTB_12
#define   LCD_RW           PORTB_13
#define   LCD_EN           PORTB_14
#define   LED7_D1          PORTB_12
#define   LED7_D2          PORTB_13
#define   LED7_D3          PORTB_14
#define   LED7_D4          PORTB_15


//+++++++++++++++++++++++++DEFINE PORTC+++++++++++++++++++++++++++
//+++++++++++++++++++++++++DEFINE PORTD+++++++++++++++++++++++++++
//+++++++++++++++++++++++++DEFINE PORTE+++++++++++++++++++++++++++
//+++++++++++++++++++++++++DEFINE PORTF+++++++++++++++++++++++++++
//+++++++++++++++++++++++++DEFINE PORTG+++++++++++++++++++++++++++
#endif

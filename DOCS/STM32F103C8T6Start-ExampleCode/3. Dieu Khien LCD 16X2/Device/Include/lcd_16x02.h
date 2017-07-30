/**
  ******************************************************************************
  * Ten Tep		:		    lcd_16x02.h
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat		:       	Khai bao cac ham dieu khien LCD.
  *             			
  *           
  *
  ******************************************************************************
  * Chu Y			:			Can phai dinh nghia cac chan dieu khien LCD o file main.h
  *									Cau hinh cac chan do la ngo ra.	
	*								Vi du: 		#define LCD_RS	PORTB(5)
  *
  *
  * 
  ******************************************************************************
  */
#ifndef __DEVICE_LCD_16x02_
#define __DEVICE_LCD_16x02_

#include "main.h"
#define LINE_1 0x80
#define LINE_2 0xC0
#define CLEAR_LCD 0x01
 void LCD_PulseEnable(void);
/* ==================HAM GUI 4 BIT DATA RA LCD===================== */
 void LCD_SendFourBit( unsigned char cX );
/* ==================HAM GUI CAU LENH RA LCD======================= */
 void LCD_SendCommand (unsigned char cX );
/* ====================HAM KHOI TAO LCD============================ */
 void LCD_Init ( void );
/* ============HAM THIET LAP VI TRI CON TRO======================= */
void LCD_Gotoxy(unsigned char x, unsigned char y);
/* ====================HAM XOA MAN HINH LCD======================= */
void LCD_Clear(void);
/* ==================HAM GUI 1 KI TU LEN LCD====================== */
 void LCD_PutChar ( unsigned int cX );
/* =================HAM GUI 1 CHUOI KI TU RA LCD================== */
void LCD_PutString(char *s);
#endif



/**
  ******************************************************************************
  * Ten Tep		:		    TFT_240x320.h
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat		:       	Khai bao cac ham dieu khien LCD TFT 240x320.
  *             			Dinh nghia bang FONT 12x06 cho LCD.
  *           				Dinh ngia mau LCD
  *
  ******************************************************************************
  * Chu Y			:				
  *
  *
  * 
  ******************************************************************************
  */
#ifndef __DEVICE_TFT_240X320_H
#define __DEVICE_TFT_240x320_H
#include "main.h"
#define Bank1_LCD_D    ((uint32_t)0x60020000)    //disp Data ADDR
#define Bank1_LCD_C    ((uint32_t)0x60000000)	 //disp Reg ADDR
#define BLACK 			0x0000
#define BLUE  			0X001F 
#define DARKBLUE      	0X01CF
#define GREEN 			0X07E0
#define GBLUE 			0X07FF
#define LBBLUE          0X2B12 
#define GRAYBLUE       	0X5458
#define LIGHTBLUE      	0X7D7C
#define CYAN          	0x7FFF
#define LIGHTGREEN     	0X841F	
#define GRAY  			0X8430
#define LGRAYBLUE       0XA651
#define BROWN 			0XBC40
#define LGRAY 			0XC618 
#define LIGHTGRAY       0XEF5B    	
#define RED	  			0XF800 
#define MAGENTA       	0xF81F
#define BRRED 			0XFC07
#define GRED  			0XFFE0
#define WHITE         	0xFFFF
#define MAX_CHAR_POSX 232
#define MAX_CHAR_POSY 304 
#define SIZE_1206	0x01
#define SIZE_1608	0x02                             
void TFT_Init(void);
void LCD_WR_REG(unsigned int index);
void LCD_WR_CMD(unsigned int index,unsigned int val);
void LCD_WR_Data(unsigned int val);
unsigned short LCD_RD_data(void);
void TFT_CLEAR(u8 x,u16 y,u8 len,u16 wid); 
void TFT_DrawPoint(u8 x,u16 y,u16 COLOR);
void TFT_ShowChar(u8 x,u16 y,u8 num,u8 size,u16 COLOR);
void TFT_ShowNum(u8 x,u16 y,u32 num,u8 size, u16 COLOR);
void TFT_ShowString(u8 x,u16 y,const u8 *p,u8 size,u16 COLOR);
void TFT_ShowBmp(u8 x,u16 y,u8 lenth,u16 wide,const u8 *p);
#define LCD_RST 		PORTE(1)
#define LCD_CS			PORTD(7)
#define LCD_RS			PORTD(11)
#define LCD_OE			PORTD(4)
#define LCD_WE			PORTD(5)
#define LCD_D0			PORTD(14)
#define LCD_D1			PORTD(15)
#define LCD_D2			PORTD(0)
#define LCD_D3			PORTD(1)
#define LCD_D4			PORTE(7)
#define LCD_D5			PORTE(8)
#define LCD_D6			PORTE(9)
#define LCD_D7			PORTE(10)
#define LCD_D8			PORTE(11)
#define LCD_D9			PORTE(12)
#define LCD_D10			PORTE(13)
#define LCD_D11			PORTE(14)
#define LCD_D12			PORTE(15)
#define LCD_D13			PORTD(8)
#define LCD_D14			PORTD(9)	
#define LCD_D15			PORTD(10)
#endif

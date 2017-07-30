/**
  ******************************************************************************
  * Ten Tep		:		    lcd_16x02.c
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
#include "lcd_16x02.h"
#include "user_delay.h"
 void LCD_PulseEnable(void)
{
	LCD_EN=1;	
	delay_us(30);	 	
	LCD_EN=0;
	delay_us(500); 	
}

/* ==================HAM GUI 4 BIT DATA RA LCD===================== */
 void LCD_SendFourBit( unsigned char cX )
{
 LCD_D4 = cX & 0x01; 
 LCD_D5 = (cX>>1)&1;
 LCD_D6 = (cX>>2)&1;
 LCD_D7 = (cX>>3)&1;
}

/* ==================HAM GUI CAU LENH RA LCD======================= */
 void LCD_SendCommand (unsigned char cX )
{
LCD_SendFourBit  ( cX >>4 );      /* send 4 bit high  */
LCD_PulseEnable() ;
LCD_SendFourBit ( cX  );		 /* send 4 bit low  */
LCD_PulseEnable() ;
}

/* ====================HAM KHOI TAO LCD============================ */
 void LCD_Init ( void )
{
LCD_SendFourBit ( 0x00 );
delay_ms(200);
LCD_RS=0;	
LCD_RW=0;
LCD_EN=0;
LCD_SendFourBit ( 0x03 );         
LCD_PulseEnable() ;
LCD_PulseEnable () ;
LCD_PulseEnable () ;
LCD_SendFourBit ( 0x02 );     	
LCD_PulseEnable() ;
LCD_SendCommand( 0x2C );     // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
LCD_SendCommand( 0x80);
LCD_SendCommand( 0x0C); 			// cho phep hien thi man hinh
LCD_SendCommand( 0x06 );     // tang ID, khong dich khung hinh
LCD_SendCommand( CLEAR_LCD );// xoa toan bo khung hinh
}

/* ============HAM THIET LAP VI TRI CON TRO======================= */
void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(!y)
  address = (LINE_1+x);
  else
  address = (LINE_2+x);
  delay_us(100);
  LCD_SendCommand(address);
  delay_us(500);
}

/* ====================HAM XOA MAN HINH LCD======================= */
void LCD_Clear(void)
{
	LCD_SendCommand( CLEAR_LCD );  
}

/* ==================HAM GUI 1 KI TU LEN LCD====================== */
 void LCD_PutChar ( unsigned int cX )
{
	LCD_RS=1;	
	LCD_SendCommand( cX );
  LCD_RS=0;
}

/* =================HAM GUI 1 CHUOI KI TU RA LCD================== */
void LCD_PutString(char *s)
{
   while (*s)
   {
			LCD_PutChar(*s);
      s++;
   }
}

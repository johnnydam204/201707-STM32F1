/**
  ******************************************************************************
  * Ten Tep      :        lcd16x2.c
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Dinh nghia cac ham dieu khien LCD 16x2.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho LCD vao file main.h
  *					 Vi Du:
#define     LCD_RS     PORTD_0          
#define     LCD_RW     PORTD_1          
#define     LCD_EN     PORTD_2         
#define     LCD_D4     PORTD_4          
#define     LCD_D5     PORTD_5          
#define     LCD_D6     PORTD_6         
#define     LCD_D7     PORTD_7                            
  ******************************************************************************
**/
/*********************************** VI DU ************************************
    uint8_t str[16],humi;
	LCD_Init();
	sprintf(str,"BanLinhKien.Vn");
	LCD_Puts(str);
	......
	sprintf(str,"Do Am: %u",humi);
	LCD_Gotoxy(0,1);
	LCD_Puts(str);
	LCD_PutChar('%');
*******************************************************************************/
#include "lcd16x2.h"

 /*******************************************************************************
Noi Dung    :   Gui tin hieu Enable den LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/

 void LCD_Enable(void)
{
 LCD_EN=1;
 delay_us(3);
 LCD_EN=0;
 delay_us(50); 
}

 /*******************************************************************************
Noi Dung    :   Gui 4 bit du lieu den LCD.
Tham Bien   :   Data: 4 bit thap cua Data chua 4 bit du lieu can gui.
Tra Ve      :   Khong.
********************************************************************************/

 void LCD_Send4Bit( uint8_t  Data )
{
 LCD_D4=(Data>>0)&0x01;
 LCD_D5=(Data>>1)&0x01;
 LCD_D6=(Data>>2)&0x01;
 LCD_D7=(Data>>3)&0x01;
}
 /*******************************************************************************
Noi Dung    :   Gui 1 byte du lieu den LCD.
Tham Bien   :   command: byte du lieu can gui.
Tra Ve      :   Khong.
********************************************************************************/

 void LCD_SendCommand (uint8_t  command )
{
LCD_Send4Bit  ( command >>4 );   /* Gui 4 bit cao */
LCD_Enable () ;
LCD_Send4Bit  ( command  );      /* Gui 4 bit thap*/
LCD_Enable () ;
}
 /*******************************************************************************
Noi Dung    :   Khoi tao LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_Init ( void )
{
LCD_Send4Bit(0x00);
delay_ms(20);
LCD_RS=0;
LCD_RW=0;
LCD_Send4Bit(0x03);
LCD_Enable();
delay_ms(5);
LCD_Enable();
delay_us(100);
LCD_Enable();
LCD_Send4Bit(0x02);
LCD_Enable();
LCD_SendCommand( 0x28 );         // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
LCD_SendCommand( 0x0c);          // cho phep hien thi man hinh
LCD_SendCommand( 0x06 );         // tang ID, khong dich khung hinh
LCD_Clear();                     // xoa toan bo khung hinh
}
 /*******************************************************************************
Noi Dung    :   Thiet lap vi tri con tro LCD.
Tham Bien   :   x: vi tri cot cua con tro. x = 0 - 15.
                y: vi tri hang cua con tro. y= 0,1.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Gotoxy(uint8_t  x, uint8_t  y)
{
  uint8_t  address;
  if(!y)
  address = (0x80+x);
  else
  address = (0xC0+x);
  delay_ms(1);
  LCD_SendCommand(address);
  delay_ms(5);
}
 /*******************************************************************************
Noi Dung    :   Xoa noi dung hien thi tren LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Clear(void)
{
  LCD_SendCommand(0x01);  
  delay_ms(5);
}
 /*******************************************************************************
Noi Dung    :   Viet 1 ki tu len LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
 void LCD_PutChar ( uint8_t  Data )
{
 LCD_RS=1;
 LCD_SendCommand( Data );
 LCD_RS=0;
}
 /*******************************************************************************
Noi Dung    :   Viet 1 chuoi ki tu len LCD.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void LCD_Puts (uint8_t *s)
{
   while (*s)
   {
      LCD_PutChar(*s);
      s++;
   }
}
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/





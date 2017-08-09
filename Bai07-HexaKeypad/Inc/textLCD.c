#include "main.h"
#include "stm32f1xx_hal.h"
#include "textLCD.h"

// Xay dung ham
// Thiet lap chan cho LCD la OUTPUT
void lcd_pinout(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	// Thiet lap chan LCD_RS -> OUTPUT
	GPIO_InitStruct.Pin = LCD_RS;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_RS_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_RW -> OUTPUT
	GPIO_InitStruct.Pin = LCD_RW;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_RW_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_EN -> OUTPUT
	GPIO_InitStruct.Pin = LCD_EN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_EN_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_D4 -> OUTPUT
	GPIO_InitStruct.Pin = LCD_D4;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_D4_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_D5 -> OUTPUT
	GPIO_InitStruct.Pin = LCD_D5;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_D5_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_D6 -> OUTPUT
	GPIO_InitStruct.Pin = LCD_D6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_D6_PORT, &GPIO_InitStruct);
	
	// Thiet lap chan LCD_D7 -> OUTPUT
	GPIO_InitStruct.Pin = LCD_D7;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(LCD_D7_PORT, &GPIO_InitStruct);
}

// Ham truyen nua byte(4bit)
void lcd_nible(char nib)
{
	LCD_RW_OFF; // Chi ghi du lieu vao LCD, khong doc ra;
	
	//Cach 1
	LCD_D4_OFF;
	if((nib >> 4) & 0x01)	LCD_D4_ON;
	
	LCD_D5_OFF;
	if((nib >> 5) & 0x01)	LCD_D5_ON;
	
	LCD_D6_OFF;
	if((nib >> 6) & 0x01)	LCD_D6_ON;
	
	LCD_D7_OFF;
	if((nib >> 7) & 0x01)	LCD_D7_ON;
	
	// Cach 2
	/*
	LCD_D4_OFF;
	if(nib & 0x10)	LCD_D4_ON;
	
	LCD_D5_OFF;
	if(nib & 0x20)	LCD_D5_ON;
	
	LCD_D6_OFF;
	if(nib & 0x40)	LCD_D6_ON;
	
	LCD_D7_OFF;
	if(nib & 0x80)	LCD_D7_ON;
	*/
	
	// Dua du lieu vao LCD
	LCD_EN_ON;
	HAL_Delay(1);
	LCD_EN_OFF;
}

// Ham truyen di ca byte => ham truyen du lieu
void lcd_byte(char byte)
{
	lcd_nible(byte); 				// Truyen len 4 bit cao cua bien byte
	lcd_nible(byte << 4);		// Dich 4 bit thap cua bien byte len cao va truyen
	HAL_Delay(1);
}

// Ham truyen lenh
void lcd_cmd(char cmd)
{
	LCD_RS_OFF;				// Truy cap vao thanh ghi lenh
	lcd_byte(cmd);
}

// Ham truyen du lieu => ham truyen ky tu
void lcd_putc(char chr)
{
	LCD_RS_ON;				// Truy cap vao thanh ghi du lieu
	lcd_byte(chr);
}

// Ham truyen chuoi ky tu
void lcd_puts(char *str)
{
	while(*str)  // Khi bien con tro str van con du lieu, chua bi tran
	{
		lcd_putc(*str);	// du lieu ky tu o bien con tro str
		str++; 					// Tang chi so dia chi cua bien con tro
	}
}

// Ham thiet lap vi tri con tro hien thi
void lcd_gotoxy(char x, char y)
{
	// Tra cuu theo tu khoa LCD Addressing
	if(y == 1) lcd_cmd(0x80 + x -1);
	if(y == 2) lcd_cmd(0xC0 + x -1); 
}

// Ham khoi tao hoat dong cu LCD
void lcd_init(void)
{
	lcd_pinout(); // Cau hinh chan LCD -> OUT
	LCD_RS_OFF;
	LCD_RW_OFF;
	LCD_EN_OFF;
	
	LCD_D4_OFF;
	LCD_D5_OFF;
	LCD_D6_OFF;
	LCD_D7_OFF;
	
	HAL_Delay(15);
	lcd_nible(0x30); //   LCD 8 bit
	HAL_Delay(5);
	lcd_nible(0x30);
	
	HAL_Delay(1);
	lcd_nible(0x30);
	
	
	HAL_Delay(1);
	lcd_nible(0x20);
	HAL_Delay(100);
	
	lcd_cmd(0x28);
	lcd_cmd(0x0C); //   Bat hien thi, tat con tro
	lcd_cmd(0x06); //   Dich con tro sang phai 1 kt
	lcd_cmd(0x01); //   Xoa man hinh
	lcd_cmd(0x02); //   Dua con tro ve dau dong
	
	
	HAL_Delay(100);

}

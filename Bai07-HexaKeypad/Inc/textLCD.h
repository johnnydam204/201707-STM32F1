#ifndef __TEXT_LCD_H
#define __TEXT_LCD_H

#include "main.h"
#include "stm32f1xx_hal.h"

// Dinh danh phan cung
#define LCD_RS	GPIO_PIN_12
#define LCD_RW	GPIO_PIN_13
#define LCD_EN	GPIO_PIN_14

#define LCD_D4	GPIO_PIN_4
#define LCD_D5	GPIO_PIN_5
#define LCD_D6	GPIO_PIN_6
#define LCD_D7	GPIO_PIN_7

#define LCD_RS_PORT		GPIOB
#define LCD_RW_PORT		GPIOB
#define LCD_EN_PORT		GPIOB

#define LCD_D4_PORT		GPIOA
#define LCD_D5_PORT		GPIOA
#define LCD_D6_PORT		GPIOA
#define LCD_D7_PORT		GPIOA

// Dinh nghia thiet lap muc logic 1
#define LCD_RS_ON			HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS, GPIO_PIN_SET)
#define LCD_RW_ON			HAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW, GPIO_PIN_SET) 
#define LCD_EN_ON			HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN, GPIO_PIN_SET) 
#define LCD_D4_ON			HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4, GPIO_PIN_SET) 
#define LCD_D5_ON			HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5, GPIO_PIN_SET) 
#define LCD_D6_ON			HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6, GPIO_PIN_SET) 
#define LCD_D7_ON			HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7, GPIO_PIN_SET) 

// Dinh nghia xoa muc logic ve 0
#define LCD_RS_OFF		HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS, GPIO_PIN_RESET)
#define LCD_RW_OFF		HAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW, GPIO_PIN_RESET) 
#define LCD_EN_OFF		HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN, GPIO_PIN_RESET) 
#define LCD_D4_OFF		HAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4, GPIO_PIN_RESET) 
#define LCD_D5_OFF		HAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5, GPIO_PIN_RESET) 
#define LCD_D6_OFF		HAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6, GPIO_PIN_RESET) 
#define LCD_D7_OFF		HAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7, GPIO_PIN_RESET) 

// Khai bao ham nguyen mau
void lcd_pinout(void);						// Thiet lap chan cho LCD la OUTPUT
void lcd_nible(char nib);					// Ham truyen nua byte(4bit)
void lcd_byte(char byte);					// Ham truyen di ca byte => ham truyen du lieu
void lcd_cmd(char cmd);						// Ham truyen lenh
void lcd_putc(char chr);					// Ham truyen du lieu => ham truyen ky tu
void lcd_puts(char *str);					// Ham truyen chuoi ky tu
void lcd_gotoxy(char x, char y);	// Ham thiet lap vi tri con tro hien thi	
void lcd_init(void);							// Ham khoi tao hoat dong cu LCD

#endif

#ifndef __HEXA_KEYPAD_H
#define __HEXA_KEYPAD_H

#include "main.h"
#include "stm32f1xx_hal.h"

// Dinh danh phan cung

#define KEYPAD_ROW1				GPIO_PIN_0
#define KEYPAD_ROW2				GPIO_PIN_1
#define KEYPAD_ROW3				GPIO_PIN_2
#define KEYPAD_ROW4				GPIO_PIN_3

#define KEYPAD_COL1				GPIO_PIN_4
#define KEYPAD_COL2				GPIO_PIN_5
#define KEYPAD_COL3				GPIO_PIN_6
#define KEYPAD_COL4				GPIO_PIN_7

#define KEYPAD_ROW1_PORT	GPIOB
#define KEYPAD_ROW2_PORT	GPIOB
#define KEYPAD_ROW3_PORT	GPIOB
#define KEYPAD_ROW4_PORT	GPIOB

#define KEYPAD_COL1_PORT	GPIOB
#define KEYPAD_COL2_PORT	GPIOB
#define KEYPAD_COL3_PORT	GPIOB
#define KEYPAD_COL4_PORT	GPIOB

// Dinh nghia Xuat du lieu
#define KEYPAD_ROW1_ON		HAL_GPIO_WritePin(KEYPAD_ROW1_PORT, KEYPAD_ROW1, GPIO_PIN_SET)
#define KEYPAD_ROW2_ON		HAL_GPIO_WritePin(KEYPAD_ROW2_PORT, KEYPAD_ROW2, GPIO_PIN_SET)
#define KEYPAD_ROW3_ON		HAL_GPIO_WritePin(KEYPAD_ROW3_PORT, KEYPAD_ROW3, GPIO_PIN_SET)
#define KEYPAD_ROW4_ON		HAL_GPIO_WritePin(KEYPAD_ROW4_PORT, KEYPAD_ROW4, GPIO_PIN_SET)

#define KEYPAD_ROW1_OFF		HAL_GPIO_WritePin(KEYPAD_ROW1_PORT, KEYPAD_ROW1, GPIO_PIN_RESET)
#define KEYPAD_ROW2_OFF		HAL_GPIO_WritePin(KEYPAD_ROW2_PORT, KEYPAD_ROW2, GPIO_PIN_RESET)
#define KEYPAD_ROW3_OFF		HAL_GPIO_WritePin(KEYPAD_ROW3_PORT, KEYPAD_ROW3, GPIO_PIN_RESET)
#define KEYPAD_ROW4_OFF		HAL_GPIO_WritePin(KEYPAD_ROW4_PORT, KEYPAD_ROW4, GPIO_PIN_RESET)

// Dinh nghia nhan du lieu
#define KEYPAD_COL1_RD		HAL_GPIO_ReadPin(KEYPAD_COL1_PORT, KEYPAD_COL1)
#define KEYPAD_COL2_RD		HAL_GPIO_ReadPin(KEYPAD_COL2_PORT, KEYPAD_COL2)
#define KEYPAD_COL3_RD		HAL_GPIO_ReadPin(KEYPAD_COL3_PORT, KEYPAD_COL3)
#define KEYPAD_COL4_RD		HAL_GPIO_ReadPin(KEYPAD_COL4_PORT, KEYPAD_COL4)

// Khai  bao ham nguyen mau
void keypad_gpio_config(void);
void keypad_init(void);
unsigned char keypad_readkey(void);



#endif /* __HEXA_KEYPAD_H */

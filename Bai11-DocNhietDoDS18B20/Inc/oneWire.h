#ifndef __ONE_WIRE_H
#define __ONE_WIRE_H

#include "main.h"
#include "stm32f1xx_hal.h"
#include "delay.h"

// Dinh nghia co thiet bi ket noi vao bus hay khong
#define PRESENT			0
#define NOPRESENT		1

// Dinh nghia chan ONE-WIRE
#define DQ					GPIO_PIN_9
#define DQ_PORT			GPIOB

// Xuat du lieu tai chan DQ
#define DQ_HIGH			HAL_GPIO_WritePin(DQ_PORT, DQ, GPIO_PIN_SET);
#define DQ_LOW			HAL_GPIO_WritePin(DQ_PORT, DQ, GPIO_PIN_RESET);

// Nhan du lieu tai chan DQ
#define DQ_READ			HAL_GPIO_ReadPin(DQ_PORT, DQ);

// Thiet lap IO
void oneWire_setOutput(void);
void oneWire_setInput(void);

// Ghi du lieu
void oneWire_writeBit0(void);
void oneWire_writeBit1(void);
void oneWire_writeByte(unsigned char data);

// Nhan du lieu
unsigned char oneWire_readBit(void);
unsigned char oneWire_readByte(void);

void oneWire_reset(void);

#endif

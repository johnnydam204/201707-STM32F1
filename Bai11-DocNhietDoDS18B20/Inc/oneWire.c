#include "oneWire.h"

unsigned char devicePresent = NOPRESENT; // Bien kiem tra xem co thiet bi gan vao bus chua

// Thiet lap IO
void oneWire_setOutput(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.Pin = DQ;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(DQ_PORT, &GPIO_InitStruct);
}

void oneWire_setInput(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
	
	GPIO_InitStruct.Pin = DQ;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DQ_PORT, &GPIO_InitStruct);
}

void oneWire_reset(void)
{
	oneWire_setOutput();
	DQ_LOW;
	delay_us(500);
	
	oneWire_setInput();
//	delay_us(70);
//	devicePresent = DQ_READ;
//	if(devicePresent == PRESENT)
//	{
//		// Lam viec gi do o day
//	}
//	else
//	{
//		// Lam viec gi do o day
//	}
	delay_us(500);
	oneWire_setInput();
}

// Ghi du lieu
void oneWire_writeBit0(void)
{
	oneWire_setOutput();
	DQ_LOW;
	delay_us(60);
		
	oneWire_setInput();
	delay_us(10);
}

void oneWire_writeBit1(void)
{
	oneWire_setOutput();
	DQ_LOW;
	delay_us(6);
	
	oneWire_setInput();
	delay_us(64);
}

void oneWire_writeByte(unsigned char data)
{
	unsigned temp, i;
	for(i = 0; i< 8; i++)
	{
		temp = data;
		data = data >> 1;
		if(temp & 0x01) oneWire_writeBit1();
		else oneWire_writeBit0();
	}
}

// Nhan du lieu
unsigned char oneWire_readBit(void)
{
	unsigned char data;
	
	oneWire_setOutput();
	DQ_LOW;
	delay_us(6);
	
	oneWire_setInput();
	delay_us(9);
	
	data = DQ_READ;
	delay_us(55);
	
	return data;	
}

unsigned char oneWire_readByte(void)
{
	unsigned char data, temp, i;
	for(i = 0; i< 8; i++)
	{
		temp = oneWire_readBit();
		if(temp) data = data | (1<<i);
	}
	return data;
}


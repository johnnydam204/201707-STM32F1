#include "at24cxx.h"
/*******************************************************************************
Noi Dung    :   Khoi tao giao tiep chip EEPROM.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_Init()
{
	I2C_Init();
}
/*******************************************************************************
Noi Dung    :   Doc du lieu tu EEPROM.
Tham Bien   :   address:   Dia chi can doc du lieu.
Tra Ve      :   Gia tri du lieu doc duoc.
********************************************************************************/
uint8_t EEP_24CXX_Read(uint8_t address)
{
  	uint8_t Data;
  	I2C_Start();
  	I2C_Write(0xa0);
  	I2C_Write(address);
  	I2C_Start();
  	I2C_Write(0xa1);
  	Data=I2C_Read(0);
  	I2C_Stop();
  	return Data;
}
/*******************************************************************************
Noi Dung    :   Viet du lieu vao EEPROM.
Tham Bien   :   address:   Dia chi can ghi du lieu.
                Data   :   Gia tri du lieu can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_Write(uint8_t address,uint8_t Data)
{
  	I2C_Start();
  	I2C_Write(0xa0);
  	I2C_Write(address);                   
  	I2C_Write(Data);                 
  	I2C_Stop();
	delay_ms(10);
}
/*******************************************************************************
Noi Dung    :   Viet mot chuoi du lieu vao EEPROM.
Tham Bien   :   address:   Dia chi bat dau ghi du lieu.
                *s     :   Chuoi du lieu can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_WriteS(uint8_t address,uint8_t*s)
{
	while(*s)
	{
		EEP_24CXX_Write(address++,*s);
		s++;
	}
}
/*******************************************************************************
Noi Dung    :   Doc mot chuoi du lieu tu EEPROM.
Tham Bien   :   address:   Dia chi bat dau ghi du lieu.
                *s     :   Chuoi du lieu can doc.
                lenght :   Do dai du lieu can doc.
Tra Ve      :   Khong.
********************************************************************************/
void EEPROM_24CXX_ReadS(uint8_t address, uint8_t lenght, uint8_t *s)
{
	uint8_t i=0;
	while(lenght)
	{
		s[i++]=EEP_24CXX_Read(address++);
		lenght--;
		delay_ms(2);
	}
	s[i]=0;
}

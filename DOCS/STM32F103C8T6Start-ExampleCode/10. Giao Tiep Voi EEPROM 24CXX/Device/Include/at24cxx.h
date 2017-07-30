#ifndef __24CXX_H
#define __24CXX_H
#include "main.h"
/*******************************************************************************
Noi Dung    :   Khoi tao giao tiep chip EEPROM.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_Init(void);
/*******************************************************************************
Noi Dung    :   Doc du lieu tu EEPROM.
Tham Bien   :   address:   Dia chi can doc du lieu.
Tra Ve      :   Gia tri du lieu doc duoc.
********************************************************************************/
uint8_t EEP_24CXX_Read(uint8_t address);
/*******************************************************************************
Noi Dung    :   Viet du lieu vao EEPROM.
Tham Bien   :   address:   Dia chi can ghi du lieu.
                Data   :   Gia tri du lieu can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_Write(uint8_t address,uint8_t Data);
/*******************************************************************************
Noi Dung    :   Viet mot chuoi du lieu vao EEPROM.
Tham Bien   :   address:   Dia chi bat dau ghi du lieu.
                *s     :   Chuoi du lieu can ghi.
Tra Ve      :   Khong.
********************************************************************************/
void EEP_24CXX_WriteS(uint8_t address,uint8_t*s);
/*******************************************************************************
Noi Dung    :   Doc mot chuoi du lieu tu EEPROM.
Tham Bien   :   address:   Dia chi bat dau ghi du lieu.
                *s     :   Chuoi du lieu can doc.
                lenght :   Do dai du lieu can doc.
Tra Ve      :   Khong.
********************************************************************************/
void EEPROM_24CXX_ReadS(uint8_t address, uint8_t lenght, uint8_t *s);
#endif

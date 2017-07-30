#ifndef __USER_SPI_H
#define __USER_SPI_H
void SPI1_Configuration(void) 
{ 
  SPI_InitTypeDef   SPI_InitStructure; 

  /* Enable Clock*/
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);  
   /* Cai dat cac thong so cau hinh SPI1 */ 
  SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex; 
  // Chon master - slaver  
  SPI_InitStructure.SPI_Mode = SPI_Mode_Master;						   
  SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;					   
  SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;						   
  SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;						   
  SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
  //Chon so chia tan so  
  SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_64; 
  //Chon kieu truyen du lieu  
  SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;				   
  SPI_InitStructure.SPI_CRCPolynomial = 7;							   
  SPI_Init(SPI1, &SPI_InitStructure);
  
  /* SPI1 Enable*/  
  SPI_Cmd(SPI1,ENABLE);
}
unsigned char SPI_WriteByte(SPI_TypeDef* SPIx,unsigned char data) 
{ 
 unsigned char Data = 0; 
  while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_TXE)==RESET); 
  SPI_I2S_SendData(SPIx,data); 
  while(SPI_I2S_GetFlagStatus(SPIx,SPI_I2S_FLAG_RXNE)==RESET); 
  Data = SPI_I2S_ReceiveData(SPIx); 
  return Data; 
}   
#endif

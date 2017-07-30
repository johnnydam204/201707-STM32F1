#include "i2c.h"
/*******************************************************************************
Noi Dung    :   Khoi tao giao thuc I2C
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void I2C_Init(void)
{
	GPIO_SetState(GPIOB,GPIO_Pin_11,GPIO_Mode_Out_OD);
	GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_Out_OD);
	SCL=1;
	delay_us(5);
	SDA_OUT=1;
	delay_us(5);
}
/*******************************************************************************
Noi Dung    :   Gui lenh Start I2C.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void I2C_Start(void)
{
	  GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_Out_OD);
	  SDA_OUT=1; 
  	SCL=1; 
  	delay_us(5);
  	SDA_OUT=0; 
  	delay_us(5);
  	SCL=0;
		delay_us(5);
}
/*******************************************************************************
Noi Dung    :   Gui lenh Stop I2C.
Tham Bien   :   Khong.
Tra Ve      :   Khong.
********************************************************************************/
void I2C_Stop(void)
{
	  GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_Out_OD);
		SDA_OUT=0;
  	SCL=1;
  	delay_us(5);
  	SDA_OUT=1;
  	delay_us(5);
  	SCL=0;
		delay_us(5);
}
/*******************************************************************************
Noi Dung    :   Viet du lieu len kenh I2C.
Tham Bien   :   Data   :   Gia tri du lieu.
Tra Ve      :   Khong.
********************************************************************************/
uint8_t I2C_Write(uint8_t Data)
{
    uint8_t i;
	  GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_Out_OD);
  	for(i=0;i<8;i++)
    {
			if(Data&0x80)
				SDA_OUT=1;
			else
				SDA_OUT=0;
      Data<<=1;	
			delay_us(5);
		  SCL=1;
		  delay_us(5);
		  SCL=0;
			delay_us(5); 
	  }
		GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_IN_FLOATING);
  	SCL=1;
  	delay_us(5);
  	i=SDA_IN;
  	delay_us(5);
  	SCL=0;
		delay_us(5);
  	return i;
}
/*******************************************************************************
Noi Dung    :   Lay du lieu tren kenh I2C.
Tham Bien   :   Khong. 
Tra Ve      :   Gia tri du lieu.
********************************************************************************/
uint8_t I2C_Read(uint8_t Ack)
{
  	uint8_t I2C_data=0,i;
		GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_IN_FLOATING);
  	for(i=0;i<8;i++)
    {   
				
      	SCL=1; 
				delay_us(10);			
			  I2C_data<<=1;
			  if(SDA_IN)
      	I2C_data|=1;
      	delay_us(10);
      	SCL=0;
    }
		GPIO_SetState(GPIOB,GPIO_Pin_10,GPIO_Mode_Out_OD);
		SCL=1;
  	delay_us(5);
		SDA_OUT=Ack;
		delay_us(5);
  	SCL=0;
    return I2C_data;
}

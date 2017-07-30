#include "onewire.h"
void OneWire_Reset()
{
 GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_Out_OD);//Thiet lap dau ra
 ONE_WIRE_OUT=0;
 delay_us(500);
 GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_IN_FLOATING);//Thiet lap dau vao
 delay_us(500); 
 GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_IN_FLOATING);//Thiet lap dau vao
}
void OneWire_Write(uint8_t data)
{
 uint8_t count;
 for (count=0; count<8; ++count)
 {
  GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_Out_OD);//Thiet lap dau ra
  ONE_WIRE_OUT=0;
  delay_us( 2 ); 
  if(data&0x01)ONE_WIRE_OUT=1;
  else ONE_WIRE_OUT=0;
  data>>=1;
  delay_us( 60 ); 
  GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_IN_FLOATING);//Thiet lap dau vao
  delay_us(2);
 }
}
uint8_t OneWire_Read(void)
{
 uint8_t count, data=0;
 for (count=0; count<8; ++count)
 {
  GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_Out_OD);//Thiet lap dau ra
  ONE_WIRE_OUT=0;
  delay_us( 2 );                      
  GPIO_SetState(GPIOB,GPIO_Pin_9,GPIO_Mode_IN_FLOATING);//Thiet lap dau vao         
  delay_us( 8 );                
  if(ONE_WIRE_IN)
  data|=0x01<<count;
  delay_us( 120 ); 
 }
 return( data );
}

/**
  ******************************************************************************
  * Ten Tep      :        hc595.c
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Dinh nghia cac ham dieu khien IC 74HC595.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho HC595 vao ham main.h
  *					Vi du:            
#define         HC595_LATCH_BIT     PORTB_0       
#define         HC595_LATCH_FRAME   PORTB_1       
#define         HC595_DATA          PORTB_2       
#define         HC595_OE            PORTB_3       
#define         HC595_RS            PORTB_4                   
  ******************************************************************************
**/
/*****************************************************************
uint8_t HC595_Buffer[8];
....
HC595_InArray(HC595_Buffer,8);
HC595_LatchFrame();
*****************************************************************/
#include "hc595.h"
void HC595_Byte(uint8_t Data)
{
   uint8_t b=0x80;
   while(b)
   {
        HC595_DATA=Data&b;
        HC595_LatchBit();
		b>>=1;
   }
}
void HC595_Array(uint8_t *Array, uint8_t Length)
{
   while(Length--)
   {
       HC595_Byte(*(Array+Length));
   }
}
/******************KET THUC FILE********************
__________________NGUYEN QUY NHAT__________________*/         
   
      
   
   
   
   

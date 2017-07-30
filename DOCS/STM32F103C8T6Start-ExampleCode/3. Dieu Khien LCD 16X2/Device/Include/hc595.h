/**
  ******************************************************************************
  * Ten Tep      :        hc595.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Khai bao cac ham dieu khien IC 74HC595.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho HC595 vao ham main.h
  *					Vi du:        
#define      HC595_LATCH_BIT      PORTB_0    
#define      HC595_LATCH_FRAME    PORTB_1    
#define      HC595_DATA           PORTB_2    
#define      HC595_OE             PORTB_3    
#define      HC595_RS             PORTB_4                       
  ******************************************************************************
**/
#ifndef __HC595_H
#define __HC595_H
#include "main.h"
#ifdef	HC595_OE
	#define HC595_OutPutEnable(State){\
		HC595_OE=State;}
#define HC595_ENABLE_OUT	0
#endif
#ifdef HC595_RS
	#define HC595_Reset(State){\
	    HC595_RS=State;}
#define HC595_RESET		    0
#endif
#define HC595_LatchBit(){\
	HC595_LATCH_BIT=0;\
	HC595_LATCH_BIT=1;\
	}
#define HC595_LatchFrame(){\
    HC595_LATCH_FRAME=0;\
	HC595_LATCH_FRAME=1;\
	}
void HC595_Byte(uint8_t  Data);
void HC595_Array(uint8_t  *Array, uint8_t  Length);
#endif
/******************KET THUC FILE********************
__________________NGUYEN QUY NHAT__________________*/

         
   
      
   
   
   
   


/**
  ******************************************************************************
  * Ten Tep      :        KEY4X4.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Khai bao cac ham dieu khien ma tran phim 4x4.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho ma tran phim 4x4 vao file main.h
  *                  Vi du:
#define         KEY4X4_COL1          PINB_0    
#define         KEY4X4_COL2          PINB_1    
#define         KEY4X4_COL3          PINB_2    
#define         KEY4X4_COL4          PINB_3    
#define         KEY4X4_ROW1         PORTB_4   
#define         KEY4X4_ROW2         PORTB_5   
#define         KEY4X4_ROW3         PORTB_6   
#define         KEY4X4_ROW4         PORTB_7   
  ******************************************************************************
**/

#ifndef	__KEY_4X4_H
#define __KEY_4X4_H
#include "main.h"
 /*******************************************************************************
Noi Dung    :   Kiem tra co nut duoc an hay khong..
Tham Bien   :   Khong.
Tra Ve      :   1:   Neu co nut duoc an.
                0:   Neu khong co nut duoc an.
********************************************************************************/

uint8_t  KEY4X4_IsPush(void);

 /*******************************************************************************
Noi Dung    :   Keo hang thu i xuong muc logic 0, de kiem tra co nut duoc an tai 
                hang thu i hay khong.
Tham Bien   :   i: vi tri hang can kiem tra.
Tra Ve      :   Khong.
********************************************************************************/

void KEY4X4_CheckRow(uint8_t  i);

 /*******************************************************************************
Noi Dung    :   Lay gia tri nut nhan duoc an.
Tham Bien   :   Khong.
Tra Ve      :   0:     Neu khong co nut duoc an.
				khac 0: Gia tri cua nut an.
********************************************************************************/

uint8_t  KEY4X4_GetKey(void);

#endif
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/

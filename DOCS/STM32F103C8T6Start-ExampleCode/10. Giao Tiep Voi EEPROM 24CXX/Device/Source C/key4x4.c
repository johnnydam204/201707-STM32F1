/**
  ******************************************************************************
  * Ten Tep      :        key4x4.c
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Dinh nghia cac ham dieu khien ma tran phim 4x4.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho ma tran phim 4x4 vao file main.h
  *                  Vi du:
#define         KEY4X4_COL1     PINB_0         
#define         KEY4X4_COL2     PINB_1         
#define         KEY4X4_COL3     PINB_2        
#define         KEY4X4_COL4     PINB_3        
#define         KEY4X4_ROW1     PORTB_4       
#define         KEY4X4_ROW2     PORTB_5       
#define         KEY4X4_ROW3     PORTB_6       
#define         KEY4X4_ROW4     PORTB_7       
  ******************************************************************************
**/

/*********************************** VI DU ************************************
    uint8_t key;
    key = KEY4X4_GetKey();
*******************************************************************************/
#include "key4x4.h"

const uint8_t  KEY_4X4[4][4]={'7','8','9','/',
								 '4','5','6','*',
								 '1','2','3','-',
								 '#','0','=','+'};							 							 
 /*******************************************************************************
Noi Dung    :   Kiem tra co nut duoc an hay khong..
Tham Bien   :   Khong.
Tra Ve      :   1:   Neu co nut duoc an.
                0:   Neu khong co nut duoc an.
********************************************************************************/
uint8_t  KEY4X4_IsPush(void)
{
    if((KEY4X4_COL1==0)|(KEY4X4_COL2==0)|(KEY4X4_COL3==0)|(KEY4X4_COL4==0))
       return 1;
    else 
       return 0;
}
 /*******************************************************************************
Noi Dung    :   Keo hang thu i xuong muc logic 0, de kiem tra co nut duoc an tai 
                hang thu i hay khong.
Tham Bien   :   i: vi tri hang can kiem tra.
Tra Ve      :   Khong.
********************************************************************************/
void KEY4X4_CheckRow(uint8_t i)
{
KEY4X4_ROW1=KEY4X4_ROW2=KEY4X4_ROW3=KEY4X4_ROW4=1;
     if(i==0)
       KEY4X4_ROW1=0;
     else if(i==1)
       KEY4X4_ROW2=0;
     else if(i==2)
       KEY4X4_ROW3=0;
     else
       KEY4X4_ROW4=0;
}
 /*******************************************************************************
Noi Dung    :   Lay gia tri nut nhan duoc an.
Tham Bien   :   Khong.
Tra Ve      :   0:     Neu khong co nut duoc an.
				khac 0: Gia tri cua nut an.
********************************************************************************/
uint8_t  KEY4X4_GetKey(void)
{
	uint8_t  i;
	KEY4X4_ROW1=KEY4X4_ROW2=KEY4X4_ROW3=KEY4X4_ROW4=0;
	if(KEY4X4_IsPush())
	{
		delay_ms(5);
		if(KEY4X4_IsPush())
		{			
			for(i=0;i<4;i++)
			{				
				KEY4X4_CheckRow(i);
				if(!KEY4X4_COL1) return KEY_4X4[i][0];
				if(!KEY4X4_COL2) return KEY_4X4[i][1];
				if(!KEY4X4_COL3) return KEY_4X4[i][2];
				if(!KEY4X4_COL4) return KEY_4X4[i][3];
			}		
		}
	}
	return 0;
}
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/

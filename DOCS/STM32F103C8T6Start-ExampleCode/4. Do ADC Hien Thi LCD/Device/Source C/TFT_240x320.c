/**
  ******************************************************************************
  * Ten Tep		:		    TFT_240x320.c
  * Tac Gia		:	  		Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay		:    		31-07-2012
  * Tom Tat		:       	Dinh nghia cac ham dieu khien LCD TFT 240x320.
  *             			
  *           				
  *
  ******************************************************************************
  * Chu Y			:				
  *
  *
  * 
  ******************************************************************************
  */
/****************************************************************************
Viet 1 lenh len thanh ghi LCD
****************************************************************************/ 
#include "TFT_240x320.h"
void LCD_WR_REG(unsigned int index)
{
	*(__IO uint16_t *) (Bank1_LCD_C)= index; 
}			 
/****************************************************************************
****************************************************************************/ 
void LCD_WR_CMD(unsigned int index,unsigned int val)
{	
	*(__IO uint16_t *) (Bank1_LCD_C)= index;	
	*(__IO uint16_t *) (Bank1_LCD_D)= val;
}
/****************************************************************************
****************************************************************************/ 
unsigned short LCD_RD_data(void){
	unsigned int a=0;
	a=*(__IO uint16_t *) (Bank1_LCD_D);   //
	a=*(__IO uint16_t *) (Bank1_LCD_D);   //
	return(a); 
}
/****************************************************************************
****************************************************************************/ 
void LCD_WR_Data(unsigned int val)
{   
	*(__IO uint16_t *) (Bank1_LCD_D)= val;
	LCD_WR_DATA(val);
}
void LCD_WR_Data_8(unsigned int val)
{
	*(__IO uint16_t *) (Bank1_LCD_D)= val;
}
/****************************************************************************
 ****************************************************************************/ 
/****************************************************************************
****************************************************************************/ 
void TFT_Init(void)
{	unsigned int i;	 
    LCD_RST=0;
	delay_us(1);				   
    LCD_RST=1;		 
	delay_us(1);	
	LCD_WR_CMD(0x00E3, 0x3008); // Set internal timing
	LCD_WR_CMD(0x00E7, 0x0012); // Set internal timing
	LCD_WR_CMD(0x00EF, 0x1231); // Set internal timing
	LCD_WR_CMD(0x0000, 0x0001); // Start Oscillation
	LCD_WR_CMD(0x0001, 0x0100); // set SS and SM bit
	LCD_WR_CMD(0x0002, 0x0700); // set 1 line inversion

	LCD_WR_CMD(0x0003, 0x1030); // set GRAM write direction and BGR=0,262K colors,1 transfers/pixel.
	LCD_WR_CMD(0x0004, 0x0000); // Resize register
	LCD_WR_CMD(0x0008, 0x0202); // set the back porch and front porch
	LCD_WR_CMD(0x0009, 0x0000); // set non-display area refresh cycle ISC[3:0]
	LCD_WR_CMD(0x000A, 0x0000); // FMARK function
	LCD_WR_CMD(0x000C, 0x0000); // RGB interface setting
	LCD_WR_CMD(0x000D, 0x0000); // Frame marker Position
	LCD_WR_CMD(0x000F, 0x0000); // RGB interface polarity
//Power On sequence 
	LCD_WR_CMD(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_CMD(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
	LCD_WR_CMD(0x0012, 0x0000); // VREG1OUT voltage
	LCD_WR_CMD(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude
	delay_us(1);// Dis-charge capacitor power voltage
	LCD_WR_CMD(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB
	LCD_WR_CMD(0x0011, 0x0227); // R11h=0x0221 at VCI=3.3V, DC1[2:0], DC0[2:0], VC[2:0]
	delay_us(1);
	LCD_WR_CMD(0x0012, 0x001C); // External reference voltage= Vci;
	delay_us(1);
	LCD_WR_CMD(0x0013, 0x1800); // R13=1200 when R12=009D;VDV[4:0] for VCOM amplitude
	LCD_WR_CMD(0x0029, 0x001C); // R29=000C when R12=009D;VCM[5:0] for VCOMH
	LCD_WR_CMD(0x002B, 0x000D); // Frame Rate = 91Hz
	delay_us(1);
	LCD_WR_CMD(0x0020, 0x0000); // GRAM horizontal Address
	LCD_WR_CMD(0x0021, 0x0000); // GRAM Vertical Address
// ----------- Adjust the Gamma Curve ----------//
	LCD_WR_CMD(0x0030, 0x0007);
	LCD_WR_CMD(0x0031, 0x0302);
	LCD_WR_CMD(0x0032, 0x0105);
	LCD_WR_CMD(0x0035, 0x0206);
	LCD_WR_CMD(0x0036, 0x0808);
	LCD_WR_CMD(0x0037, 0x0206);
	LCD_WR_CMD(0x0038, 0x0504);
	LCD_WR_CMD(0x0039, 0x0007);
	LCD_WR_CMD(0x003C, 0x0105);
	LCD_WR_CMD(0x003D, 0x0808);
//------------------ Set GRAM area ---------------//
	LCD_WR_CMD(0x0050, 0x0000); // Horizontal GRAM Start Address
	LCD_WR_CMD(0x0051, 0x00EF); // Horizontal GRAM End Address
	LCD_WR_CMD(0x0052, 0x0000); // Vertical GRAM Start Address
	LCD_WR_CMD(0x0053, 0x013F); // Vertical GRAM Start Address
	LCD_WR_CMD(0x0060, 0xA700); // Gate Scan Line
	LCD_WR_CMD(0x0061, 0x0001); // NDL,VLE, REV
	LCD_WR_CMD(0x006A, 0x0000); // set scrolling line
//-------------- Partial Display Control ---------//
	LCD_WR_CMD(0x0080, 0x0000);
	LCD_WR_CMD(0x0081, 0x0000);
	LCD_WR_CMD(0x0082, 0x0000);
	LCD_WR_CMD(0x0083, 0x0000);
	LCD_WR_CMD(0x0084, 0x0000);
	LCD_WR_CMD(0x0085, 0x0000);
//-------------- Panel Control -------------------//
	LCD_WR_CMD(0x0090, 0x0010);
	LCD_WR_CMD(0x0092, 0x0000);
	LCD_WR_CMD(0x0093, 0x0003);
	LCD_WR_CMD(0x0095, 0x0110);
	LCD_WR_CMD(0x0097, 0x0000);
	LCD_WR_CMD(0x0098, 0x0000);
	LCD_WR_CMD(0x0007, 0x0133); // 262K color and display ON

    LCD_WR_CMD(32, 0);
    LCD_WR_CMD(33, 0);
	*(__IO uint16_t *) (Bank1_LCD_C)= 34;	 //
	for(i=0;i<76800;i++)
	{
	  LCD_WR_Data(0xffff);					 //
	}  
}

/****************************************************************************
xoa mot khung hinh bat dau toa do (x,y) do dai len, do rong wid
****************************************************************************/ 
void TFT_CLEAR(u8 x,u16 y,u8 len,u16 wid)
{                    
    u32 n,temp;	
	LCD_WR_CMD(0x0050, x); 				//
	LCD_WR_CMD(0x0051, x+len-1); 		//
	LCD_WR_CMD(0x0052, y);              //
	LCD_WR_CMD(0x0053, y+wid-1); 		//
	LCD_WR_CMD(32, 0);					//
    LCD_WR_CMD(33, 30);					//
	LCD_WR_REG(34);
	temp=(u32)len*wid;    
	for(n=0;n<temp;n++)LCD_WR_Data(0xffff); //
}   

/****************************************************************************
Ve diem co toa do (x,y)
****************************************************************************/ 
void TFT_DrawPoint(u8 x,u16 y,u16 COLOR)
{
    LCD_WR_CMD(0x0050, x); 				//
	LCD_WR_CMD(0x0051, x); 		//
	LCD_WR_CMD(0x0052, y);              //
	LCD_WR_CMD(0x0053, y); 		//
	LCD_WR_CMD(32, x);					//
    LCD_WR_CMD(33, y);					//
	LCD_WR_REG(34);				   
	LCD_WR_Data(COLOR); 	   	
} 
/****************************************************************************
hien thi ki tu len man hinh o toa do (x,y)
****************************************************************************/ 
void TFT_ShowChar(u8 x,u16 y,u8 num,u16 COLOR)
{       
    u8 temp;
    u8 pos,t;      
    if(x>MAX_CHAR_POSX||y>MAX_CHAR_POSY)return;
    //
	LCD_WR_CMD(0x0050, x); 				//
	LCD_WR_CMD(0x0051, x+5); 			//
	LCD_WR_CMD(0x0052, y);              //
	LCD_WR_CMD(0x0053, y+11); 			// 
	LCD_WR_CMD(32, x);
    LCD_WR_CMD(33, y);
	LCD_WR_REG(34);					   
	num=num-' ';						//
	for(pos=0;pos<12;pos++)	{
	    temp=asc2_1206[num][pos];		//
	    for(t=0;t<6;t++)
	    {                 
	        if(temp&0x01)LCD_WR_Data(COLOR);	  //
	        else LCD_WR_Data(0xffff);                 //   
	        temp>>=1; 
	    }
	}
}  	 

/****************************************************************************
Hien thi 1 so len man hinh bat dau tu toa do (x,y)
****************************************************************************/ 
void TFT_ShowNum(u8 x,u16 y,u32 num,u16 COLOR)
{      
	u32 res;   	   
	u8 t=0,t1=0;   
	res=num;
	if(!num)TFT_ShowChar(x,y,'0',COLOR);		//
	while(res)  						//
	{
		res/=10;
		t++;
	}
	t1=t;
	while(t)							//
	{
		res=mn(10,t-1); 	 
	    TFT_ShowChar(x+(t1-t)*6,y,(num/res)%10+'0',COLOR);	 //
		t--;
	}
	if(t1==3) TFT_ShowChar(x+18,y,' ',COLOR);	                 //			     
} 
/****************************************************************************
hien thi mot chuoi ki tu tu toa do (x,y)
****************************************************************************/ 
void TFT_ShowString(u8 x,u16 y,const u8 *p,u16 COLOR)
{         
    while(*p!='\0')
    {       
        if(x>MAX_CHAR_POSX){x=0;y+=12;}
        if(y>MAX_CHAR_POSY){y=x=0;TFT_CLEAR(0,0,240,320);}
        TFT_ShowChar(x,y,*p,COLOR);
        x+=6;
        p++;
    }  
}
/****************************************************************************
hien thi mot anh bitmap len man hinh
****************************************************************************/ 
void TFT_ShowBmp(u8 x,u16 y,u8 lenth,u16 wide,const u8 *p)
{      
    u32 size,temp; 
	LCD_WR_CMD(0x0050, x); 				//
	LCD_WR_CMD(0x0051, (u16)x+lenth-1); //
	LCD_WR_CMD(0x0052, y);              //
	LCD_WR_CMD(0x0053, y+wide-1); 		//
	LCD_WR_CMD(32, x);
    LCD_WR_CMD(33, y);
	LCD_WR_REG(34);					   

	temp=(u32)lenth*wide*2;
	for(size=0;size<temp;size++)LCD_WR_Data_8(p[size]); 
}         
void TFT_FillColor(u8 x,u16 y, u8 x1, u16 y1, u16 COLOR)
{	u16 a,b; 
	for(a=0; a<(y1-y); a++){
	  for(b=0; b<(x1-x); b++){
	   TFT_DrawPoint(x+b,y+a,COLOR);
	  }
	}	  	
}
u16 LCD_ReadX(void)
{ 
   u16 x=0;
   LCD_CS=0;		//PORTB(7)=0;
   delay_us(1);						
   SPI_WriteByte(SPI1,0x90);		
   delay_us(1);			
   x=SPI_WriteByte(SPI1,0x00);			
   x<<=8;
   x+=SPI_WriteByte(SPI1,0x00);
   delay_us(1);
   LCD_CS=1;	//PORTB(7)=1;					    								  
   x = x>>3;						
   return (x);
}
u16 LCD_ReadY(void)
{
   u16 y=0;
   LCD_CS=0;		//PORTB(7)=0;
   delay_us(1);						
   SPI_WriteByte(SPI1,0xD0);				
   delay_us(1);
   y=SPI_WriteByte(0x00);			 
   y<<=8;
   y+=SPI_WriteByte(0x00);
   delay_us(1);						
   LCD_CS=1;	//PORTB(7)=1;					    								  
   y = y>>3;	
   return (y);
}
void LCD_Read_XPT2046(void)
{	
	float X1,Y1;    
	u8 t,t1,count=0;		
	u16 databuffer[2][30];    				         
	u16 temp=0;	 
    do{					                             	
		X=TPReadX();		   
		Y=TPReadY();
		if(X>100&&X<4000&&Y>100&&Y<4000)             
		{	  
			databuffer[0][count]=X;
			databuffer[1][count]=Y;
			count++;  
		} 		
	}while((PEN==0)&&count<30); 			  		 
	if(count==30)                                    
	{  
	    do                                           
		{	
			t1=0;		  
			for(t=0;t<count-1;t++)
			{
				if(databuffer[0][t]>databuffer[0][t+1])
				{
					temp=databuffer[0][t+1];
					databuffer[0][t+1]=databuffer[0][t];
					databuffer[0][t]=temp;
					t1=1; 
				}  
			}
		}while(t1); 	  
		do                                             
		{	
			t1=0;		 
			for(t=0;t<count-1;t++)
			{
				if(databuffer[1][t]>databuffer[1][t+1])
				{
					temp=databuffer[1][t+1];
					databuffer[1][t+1]=databuffer[1][t];
					databuffer[1][t]=temp;
					t1=1;	 
				}  
			}
		}while(t1);
	}			
	X1=0; Y1=0;
	for(count=10;count<20; count++){
		X1=X1+databuffer[0][count];
		Y1=Y1+databuffer[1][count];
	}	
	X1=X1/10;  Y1=Y1/10;
	TFT_ShowNum(190,2,X1);						 
	TFT_ShowNum(190,17,Y1);						 
	if(X1<=4096&&Y1<=4096)                       
	{	
		X=X1;
		Y=Y1;															 
		if(dw==1){			 					 
			if(X1>=Xs)X1=0;						 
			else X1=Xs-X1;						
			if(Y1<=Ys)Y1=Ys-Y1;					 
			else Y1=0; 							
			X=X1/X2; 							
			Y=Y1/Y2;							
			drawbigpoint(X,Y); 				
			}
	}
}
/******************* (C) COPYRIGHT 2011 ·Ü¶·STM32 *****END OF FILE****/

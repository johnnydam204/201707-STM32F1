#include "ds18b20.h"

float ds18b20_read(void)
{
	uint8_t busy=0, temp1, temp2;
	uint16_t temp3, timeOut=0;	
	float result;
	
	oneWire_reset();
	
	oneWire_writeByte(SKIP_ROM);
	oneWire_writeByte(START_CONVERT);
	
//	while ((busy==0)&&timeOut<2000)
//	{
//		busy = oneWire_readByte();
//		timeOut++;
//	}
//	
//	if(timeOut>=2000)
//	return -1;
	
	oneWire_reset();
	
	oneWire_writeByte(SKIP_ROM);
	oneWire_writeByte(READ_SCRATCHPAD);
	
	temp1 = oneWire_readByte();
	temp2 = oneWire_readByte();
	
	temp3 = (temp2 << 8) | temp1; 
	
	result = (float) temp3 / 16.0;
	
	HAL_Delay(200);
	return result;
}

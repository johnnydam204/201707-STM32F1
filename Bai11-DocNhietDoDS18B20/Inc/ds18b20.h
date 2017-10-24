#ifndef __DS18B20_H
#define __DS18B20_H

#include "main.h"
#include "stm32f1xx_hal.h"
#include "oneWire.h"

#define SKIP_ROM						0xCC
#define READ_ROM						0x33
#define MATCH_ROM						0x55
#define SEARCH_ROM					0xF0
#define ALARM_SEARCH_ROM		0xEC

#define START_CONVERT				0x44
#define READ_SCRATCHPAD 		0xBE


float ds18b20_read(void);

#endif

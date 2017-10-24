#ifndef __DELAY_H
#define __DELAY_H

#include "main.h"
#include "stm32f1xx_hal.h"

void timerInit(void);
void delay_us(__IO uint16_t us);
void delay_ms(__IO uint16_t ms);

#endif

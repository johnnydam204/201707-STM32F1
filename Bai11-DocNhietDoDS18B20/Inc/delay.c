#include "main.h"
#include "stm32f1xx_hal.h"
#include "delay.h"

TIM_HandleTypeDef htim4; // <-- Thay timer o day

// Khai bao bien dem thoi gian
__IO uint16_t counterInit;
__IO uint16_t counter;

// Ham cau hinh timer
void timerInit(void)
{
	TIM_ClockConfigTypeDef sClockSourceConfig;
  TIM_MasterConfigTypeDef sMasterConfig;

  htim4.Instance = TIM4;
	
  htim4.Init.Prescaler = 8-1;  //<--- Cai dat he so tan so o day
	
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
	
  htim4.Init.Period = 50000-1; //<--- Cai dat so dem MAX o day
	
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
}

// Ham tao tre theo micro giay
void delay_us(__IO uint16_t us)
{
	HAL_TIM_Base_Start(&htim4);  // Chay timer
	counterInit = (uint16_t) __HAL_TIM_GET_COUNTER(&htim4);  // Lay gia tri dau bo dem
	do
	{
		counter = (uint16_t) __HAL_TIM_GET_COUNTER(&htim4); // Lay gia tri bo dem		
	}
	while(counter - counterInit < us);
	
	__HAL_TIM_SET_COUNTER(&htim4,0); // Xoa gia tri bo dem
	HAL_TIM_Base_Stop(&htim4);  // Dung timer	
}

// Ham tao tre theo mili giay
void delay_ms(__IO uint16_t ms)
{
	while(ms--)
		delay_us(1000);
}

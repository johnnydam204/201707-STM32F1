#include "HexaKeypad.h"

void keypad_gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Thiet lap ROW1 la dau ra */
  GPIO_InitStruct.Pin = KEYPAD_ROW1;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(KEYPAD_ROW1_PORT, &GPIO_InitStruct);
	
	/* Thiet lap ROW2 la dau ra */
  GPIO_InitStruct.Pin = KEYPAD_ROW2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(KEYPAD_ROW2_PORT, &GPIO_InitStruct);
	
	/* Thiet lap ROW3 la dau ra */
  GPIO_InitStruct.Pin = KEYPAD_ROW3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(KEYPAD_ROW3_PORT, &GPIO_InitStruct);
	
	/* Thiet lap ROW4 la dau ra */
  GPIO_InitStruct.Pin = KEYPAD_ROW4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(KEYPAD_ROW4_PORT, &GPIO_InitStruct);
	
  /* Thiet lap COL1 la dau vao */
  GPIO_InitStruct.Pin = KEYPAD_COL1;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COL1_PORT, &GPIO_InitStruct);
	
  /* Thiet lap COL2 la dau vao */
  GPIO_InitStruct.Pin = KEYPAD_COL2;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COL2_PORT, &GPIO_InitStruct);
	
  /* Thiet lap COL3 la dau vao */
  GPIO_InitStruct.Pin = KEYPAD_COL3;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COL3_PORT, &GPIO_InitStruct);
	
  /* Thiet lap COL4 la dau vao */
  GPIO_InitStruct.Pin = KEYPAD_COL4;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COL4_PORT, &GPIO_InitStruct);
}

void keypad_init(void)
{
	keypad_gpio_config();
	KEYPAD_ROW1_ON;
	KEYPAD_ROW2_ON;
	KEYPAD_ROW3_ON;
	KEYPAD_ROW4_ON;
}

unsigned char keypad_readkey(void)
{
	unsigned char keyPressed = 255; // Phim duoc nhan
	
	// Quet dong dau -------------------------------------
	KEYPAD_ROW1_OFF; KEYPAD_ROW2_ON; KEYPAD_ROW3_ON; KEYPAD_ROW4_ON;
	if(KEYPAD_COL1_RD == 0) 			
	{
		while(KEYPAD_COL1_RD == 0);
		keyPressed = 1;
	}
	else if (KEYPAD_COL2_RD == 0)
	{
		while(KEYPAD_COL2_RD == 0);
		keyPressed = 2;
	}
	else if (KEYPAD_COL3_RD == 0)	
	{
		while(KEYPAD_COL3_RD == 0);
		keyPressed = 3;
	}
	else if (KEYPAD_COL4_RD == 0)
	{
		while(KEYPAD_COL4_RD == 0);
		keyPressed = 'A';
	}
	//----------------------------------------------------
	// Quet dong hai -------------------------------------
	KEYPAD_ROW1_ON; KEYPAD_ROW2_OFF; KEYPAD_ROW3_ON; KEYPAD_ROW4_ON;
	if(KEYPAD_COL1_RD == 0) 			
	{
		while(KEYPAD_COL1_RD == 0);
		keyPressed = 4;
	}
	else if (KEYPAD_COL2_RD == 0)
	{
		while(KEYPAD_COL2_RD == 0);
		keyPressed = 5;
	}
	else if (KEYPAD_COL3_RD == 0)	
	{
		while(KEYPAD_COL3_RD == 0);
		keyPressed = 6;
	}
	else if (KEYPAD_COL4_RD == 0)
	{
		while(KEYPAD_COL4_RD == 0);
		keyPressed = 'B';
	}
	//----------------------------------------------------	
	// Quet dong ba -------------------------------------
	KEYPAD_ROW1_ON; KEYPAD_ROW2_ON; KEYPAD_ROW3_OFF; KEYPAD_ROW4_ON;
	if(KEYPAD_COL1_RD == 0) 			
	{
		while(KEYPAD_COL1_RD == 0);
		keyPressed = 7;
	}
	else if (KEYPAD_COL2_RD == 0)
	{
		while(KEYPAD_COL2_RD == 0);
		keyPressed = 8;
	}
	else if (KEYPAD_COL3_RD == 0)	
	{
		while(KEYPAD_COL3_RD == 0);
		keyPressed = 9;
	}
	else if (KEYPAD_COL4_RD == 0)
	{
		while(KEYPAD_COL4_RD == 0);
		keyPressed = 'C';
	}
	//----------------------------------------------------	
	// Quet dong bon -------------------------------------
	KEYPAD_ROW1_ON; KEYPAD_ROW2_ON; KEYPAD_ROW3_ON; KEYPAD_ROW4_OFF;
	if(KEYPAD_COL1_RD == 0) 			
	{
		while(KEYPAD_COL1_RD == 0);
		keyPressed = '*';
	}
	else if (KEYPAD_COL2_RD == 0)
	{
		while(KEYPAD_COL2_RD == 0);
		keyPressed = 0;
	}
	else if (KEYPAD_COL3_RD == 0)	
	{
		while(KEYPAD_COL3_RD == 0);
		keyPressed = '#';
	}
	else if (KEYPAD_COL4_RD == 0)
	{
		while(KEYPAD_COL4_RD == 0);
		keyPressed = 'D';
	}
	//----------------------------------------------------	
	
	return keyPressed;
}

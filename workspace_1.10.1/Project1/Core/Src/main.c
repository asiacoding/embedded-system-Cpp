
#include "main.h"

void SystemClock_Config(void);

static void MX_GPIO_Init(void);

int RunSw(int Button);

void stopSw();

void SmallLightSwitch();

__weak void Delay(uint32_t Delay);

int Index = 0;

int LoopingFun = 0;

int main(void)
{

  HAL_Init();

  SystemClock_Config();

  MX_GPIO_Init();



  while (1)
  {


	  if(LoopingFun == 1)
	  {
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == GPIO_PIN_RESET)
		  {
			  RunSw(3);
		  }

		  RunSw(2);
	  }
	  else
	  {
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_3) == GPIO_PIN_RESET)
		  {
			  stopSw();
			  Delay(1000);
		  }
		  if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_4) == GPIO_PIN_RESET)
		  {
			  RunSw(2);

			  Delay(1000);
		  }
	  }
  }
}


void stopSw()
{

	/*
	 A1 Led Red ->Output
	 A2 Led Green ->Output
A3 Led Blue ->Output
C15 Y Led1  ->Output
C14 Y Led2  ->Output
C13 Y Led3  ->Output
	 * */
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,0);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,0);

	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,0);

//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0);

}


int RunSw(int Button)
{
	//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);
//	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);




	if(Button==1)
	{
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_9);
		return 1;
	}

	if(Button==2)
	{
		SmallLightSwitch();

		return 1;
	}

	if(Button == 3 )
	{
		if(LoopingFun == 0)
		{
			LoopingFun = 1;
		}
		else{
			LoopingFun = 0;
		}

		return 1;
	}


	return 0;
}


__weak void Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
  if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }

  while ((HAL_GetTick() - tickstart) < wait)
  {
  }
}



void SmallLightSwitch(){
	//GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15

	if(Index==0) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);
	else if (Index==1) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);
	else if (Index==2) HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);
	else if (Index==3) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1);
	else if (Index==4) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1);
	else if (Index==5) HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,1);

	if(Index >= 5){
		stopSw();
		Index=0;
	}else Index += 1;

}








void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA3 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

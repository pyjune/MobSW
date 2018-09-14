
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
const uint8_t WREN = 0x06; // 0000 X110 Set Write Enable Latch
const uint8_t WRDI = 0x04; // 0000 X100 Reset Write Enable Latch
const uint8_t WRSR = 0x01; // 0000 X001 Write Status Register
const uint8_t RDSR = 0x05; // 0000 X101 Read Status Register
const uint8_t READ = 0x03; // 0000 X011 Read Data from Memory Array
const uint8_t WRITE = 0x02; // 0000 X010 Write Data to Memory Array
uint8_t txBuf[35];
uint8_t rxBuf[35];
uint8_t cmdWRSR[] = { 0x01, 0x80};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_SPI1_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  // Read RDSR
  uint8_t rdStatus;
  uint8_t preStatus;

  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
  HAL_Delay(1);
  HAL_SPI_Transmit(&hspi1, &RDSR, 1, 100);
  HAL_SPI_Receive(&hspi1, &rdStatus, 1, 100);
  HAL_Delay(1);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
  preStatus = rdStatus;

  if((rdStatus&(1<<1)) != 0)
  {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
	  	HAL_Delay(1);
	  	HAL_SPI_Transmit(&hspi1, &WRDI, 1, 100);
	  	HAL_Delay(1);
	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
  }
  else
  {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
	  	  	HAL_Delay(1);
	  	  	HAL_SPI_Transmit(&hspi1, &WREN, 1, 100);
	  	  	HAL_Delay(1);
	  	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
  }

  // Read RDSR
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
	  HAL_Delay(1);
	  HAL_SPI_Transmit(&hspi1, &RDSR, 1, 100);
	  HAL_SPI_Receive(&hspi1, &rdStatus, 1, 100);
	  HAL_Delay(1);
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
   if(preStatus != rdStatus)
   {
	   // 전체가 쓰기 금지인지 확인
	   if(((rdStatus&1<<2)!=0) && ((rdStatus&1<<2)!= 1))
	   {
		   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
		   	  HAL_Delay(1);

		   	HAL_SPI_Transmit(&hspi1, cmdWRSR, 2, 100);
		   	HAL_Delay(1);
		    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
		    HAL_Delay(1);
	   }
	   // Write Enable
	   	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
		HAL_Delay(1);
		HAL_SPI_Transmit(&hspi1, &WREN, 1, 100);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
	   // Data write
		txBuf[0] = WRITE;
		txBuf[1] = 0x00; // EEPROM 상위 주소
		txBuf[2] = 0x00; // EEPROM 하위 주소
		for(int i=0; i<32; i++)
			txBuf[3+i] = i+1;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
		HAL_Delay(1);
		HAL_SPI_Transmit(&hspi1, txBuf, 35, 100);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
		// Data read
		txBuf[0] = READ;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET); // EEP_CS low
		HAL_Delay(1);
		HAL_SPI_TransmitReceive  ( &hspi1, txBuf, rxBuf , 35, 100);
		HAL_Delay(1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET); // CS High
	   //
	   HAL_Delay(100);
   }
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_64;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);

  /*Configure GPIO pin : PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
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
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

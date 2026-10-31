/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern TIM_HandleTypeDef htim1;
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Serialstudio_TX_Pin GPIO_PIN_2
#define Serialstudio_TX_GPIO_Port GPIOA
#define PB13_SPI_CLK_Pin GPIO_PIN_13
#define PB13_SPI_CLK_GPIO_Port GPIOB
#define RCLK_Pin GPIO_PIN_14
#define RCLK_GPIO_Port GPIOB
#define PB15_SPI_DAT_Pin GPIO_PIN_15
#define PB15_SPI_DAT_GPIO_Port GPIOB
#define PC6_START_SW_PIN_Pin GPIO_PIN_6
#define PC6_START_SW_PIN_GPIO_Port GPIOC
#define PC7_LED1_Pin GPIO_PIN_7
#define PC7_LED1_GPIO_Port GPIOC
#define PC8_LED2_Pin GPIO_PIN_8
#define PC8_LED2_GPIO_Port GPIOC
#define PA8_TEMP_DAT_Pin GPIO_PIN_8
#define PA8_TEMP_DAT_GPIO_Port GPIOA
#define PC10_SET_UP_Pin GPIO_PIN_10
#define PC10_SET_UP_GPIO_Port GPIOC
#define PC10_SET_UP_EXTI_IRQn EXTI15_10_IRQn
#define PC11_SET_DOWN_Pin GPIO_PIN_11
#define PC11_SET_DOWN_GPIO_Port GPIOC
#define PC11_SET_DOWN_EXTI_IRQn EXTI15_10_IRQn
#define PC12_SET_TARGET_Pin GPIO_PIN_12
#define PC12_SET_TARGET_GPIO_Port GPIOC
#define PC12_SET_TARGET_EXTI_IRQn EXTI15_10_IRQn
#define PB5_RELAY_Pin GPIO_PIN_5
#define PB5_RELAY_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

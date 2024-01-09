/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SW0_Pin GPIO_PIN_2
#define SW0_GPIO_Port GPIOE
#define SW1_Pin GPIO_PIN_3
#define SW1_GPIO_Port GPIOE
#define SW2_Pin GPIO_PIN_4
#define SW2_GPIO_Port GPIOE
#define SW3_Pin GPIO_PIN_5
#define SW3_GPIO_Port GPIOE
#define Pot0_Pin GPIO_PIN_0
#define Pot0_GPIO_Port GPIOA
#define Pot1_Pin GPIO_PIN_1
#define Pot1_GPIO_Port GPIOA
#define Pot2_Pin GPIO_PIN_2
#define Pot2_GPIO_Port GPIOA
#define Pot3_Pin GPIO_PIN_3
#define Pot3_GPIO_Port GPIOA
#define LED0_Pin GPIO_PIN_0
#define LED0_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOB
#define Toggle0_Pin GPIO_PIN_7
#define Toggle0_GPIO_Port GPIOE
#define Toggle1_Pin GPIO_PIN_8
#define Toggle1_GPIO_Port GPIOE
#define Toggle2_Pin GPIO_PIN_9
#define Toggle2_GPIO_Port GPIOE
#define Toggle3_Pin GPIO_PIN_10
#define Toggle3_GPIO_Port GPIOE
#define NEOPIXELS_Pin GPIO_PIN_10
#define NEOPIXELS_GPIO_Port GPIOB
#define Stepper_0_Pin GPIO_PIN_12
#define Stepper_0_GPIO_Port GPIOD
#define Stepper_2_Pin GPIO_PIN_13
#define Stepper_2_GPIO_Port GPIOD
#define Stepper_1_Pin GPIO_PIN_14
#define Stepper_1_GPIO_Port GPIOD
#define Stepper_3_Pin GPIO_PIN_15
#define Stepper_3_GPIO_Port GPIOD
#define DISP_GRID0_Pin GPIO_PIN_2
#define DISP_GRID0_GPIO_Port GPIOG
#define DISP_GRID1_Pin GPIO_PIN_3
#define DISP_GRID1_GPIO_Port GPIOG
#define DISP_A_Pin GPIO_PIN_4
#define DISP_A_GPIO_Port GPIOG
#define DISP_F_Pin GPIO_PIN_5
#define DISP_F_GPIO_Port GPIOG
#define DISP_B_Pin GPIO_PIN_6
#define DISP_B_GPIO_Port GPIOG
#define DISP_GRID2_Pin GPIO_PIN_7
#define DISP_GRID2_GPIO_Port GPIOG
#define DISP_G_Pin GPIO_PIN_8
#define DISP_G_GPIO_Port GPIOG
#define Relay1_Pin GPIO_PIN_2
#define Relay1_GPIO_Port GPIOD
#define Relay2_Pin GPIO_PIN_3
#define Relay2_GPIO_Port GPIOD
#define DISP_C_Pin GPIO_PIN_9
#define DISP_C_GPIO_Port GPIOG
#define DISP_DP_Pin GPIO_PIN_10
#define DISP_DP_GPIO_Port GPIOG
#define DISP_D_Pin GPIO_PIN_11
#define DISP_D_GPIO_Port GPIOG
#define DISP_E_Pin GPIO_PIN_12
#define DISP_E_GPIO_Port GPIOG
#define LED3_Pin GPIO_PIN_3
#define LED3_GPIO_Port GPIOB
#define LED4_Pin GPIO_PIN_4
#define LED4_GPIO_Port GPIOB
#define LED5_Pin GPIO_PIN_5
#define LED5_GPIO_Port GPIOB
#define LED6_Pin GPIO_PIN_6
#define LED6_GPIO_Port GPIOB
#define LED7_Pin GPIO_PIN_7
#define LED7_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

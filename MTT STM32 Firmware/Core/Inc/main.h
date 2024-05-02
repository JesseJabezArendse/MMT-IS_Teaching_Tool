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
#define SW_0_Pin GPIO_PIN_2
#define SW_0_GPIO_Port GPIOE
#define SW_1_Pin GPIO_PIN_3
#define SW_1_GPIO_Port GPIOE
#define SW_2_Pin GPIO_PIN_4
#define SW_2_GPIO_Port GPIOE
#define SW_3_Pin GPIO_PIN_5
#define SW_3_GPIO_Port GPIOE
#define Pot0_Pin GPIO_PIN_0
#define Pot0_GPIO_Port GPIOA
#define Pot1_Pin GPIO_PIN_1
#define Pot1_GPIO_Port GPIOA
#define Pot2_Pin GPIO_PIN_2
#define Pot2_GPIO_Port GPIOA
#define Pot3_Pin GPIO_PIN_3
#define Pot3_GPIO_Port GPIOA
#define LED_0_Pin GPIO_PIN_0
#define LED_0_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_1
#define LED_1_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_2
#define LED_2_GPIO_Port GPIOB
#define TOG_0_Pin GPIO_PIN_7
#define TOG_0_GPIO_Port GPIOE
#define TOG_1_Pin GPIO_PIN_8
#define TOG_1_GPIO_Port GPIOE
#define TOG_2_Pin GPIO_PIN_9
#define TOG_2_GPIO_Port GPIOE
#define TOG_3_Pin GPIO_PIN_10
#define TOG_3_GPIO_Port GPIOE
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
#define SEG_G0_Pin GPIO_PIN_2
#define SEG_G0_GPIO_Port GPIOG
#define SEG_G1_Pin GPIO_PIN_3
#define SEG_G1_GPIO_Port GPIOG
#define SEG_A_Pin GPIO_PIN_4
#define SEG_A_GPIO_Port GPIOG
#define SEG_F_Pin GPIO_PIN_5
#define SEG_F_GPIO_Port GPIOG
#define SEG_B_Pin GPIO_PIN_6
#define SEG_B_GPIO_Port GPIOG
#define SEG_G2_Pin GPIO_PIN_7
#define SEG_G2_GPIO_Port GPIOG
#define SEG_G_Pin GPIO_PIN_8
#define SEG_G_GPIO_Port GPIOG
#define Relay_1_Pin GPIO_PIN_2
#define Relay_1_GPIO_Port GPIOD
#define Relay_2_Pin GPIO_PIN_3
#define Relay_2_GPIO_Port GPIOD
#define SEG_C_Pin GPIO_PIN_9
#define SEG_C_GPIO_Port GPIOG
#define SEG_DP_Pin GPIO_PIN_10
#define SEG_DP_GPIO_Port GPIOG
#define SEG_D_Pin GPIO_PIN_11
#define SEG_D_GPIO_Port GPIOG
#define SEG_E_Pin GPIO_PIN_12
#define SEG_E_GPIO_Port GPIOG
#define IMU_INT_Pin GPIO_PIN_15
#define IMU_INT_GPIO_Port GPIOG
#define IMU_INT_EXTI_IRQn EXTI15_10_IRQn
#define LED_3_Pin GPIO_PIN_3
#define LED_3_GPIO_Port GPIOB
#define LED_4_Pin GPIO_PIN_4
#define LED_4_GPIO_Port GPIOB
#define LED_5_Pin GPIO_PIN_5
#define LED_5_GPIO_Port GPIOB
#define LED_6_Pin GPIO_PIN_6
#define LED_6_GPIO_Port GPIOB
#define LED_7_Pin GPIO_PIN_7
#define LED_7_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define SG90_ANGLE_Pin GPIO_PIN_0
#define SG90_ANGLE_GPIO_Port GPIOA
#define X_28BYJ_CTL1_Pin GPIO_PIN_1
#define X_28BYJ_CTL1_GPIO_Port GPIOA
#define X_28BYJ_CTL2_Pin GPIO_PIN_2
#define X_28BYJ_CTL2_GPIO_Port GPIOA
#define X_28BYJ_CTL3_Pin GPIO_PIN_3
#define X_28BYJ_CTL3_GPIO_Port GPIOA
#define X_28BYJ_CTL4_Pin GPIO_PIN_4
#define X_28BYJ_CTL4_GPIO_Port GPIOA
#define JOYTICK_X_Pin GPIO_PIN_6
#define JOYTICK_X_GPIO_Port GPIOA
#define JOYTICK_Y_Pin GPIO_PIN_7
#define JOYTICK_Y_GPIO_Port GPIOA
#define N20_CTL1_Pin GPIO_PIN_0
#define N20_CTL1_GPIO_Port GPIOB
#define N20_CTL2_Pin GPIO_PIN_1
#define N20_CTL2_GPIO_Port GPIOB
#define Y_28BYJ_CTL1_Pin GPIO_PIN_8
#define Y_28BYJ_CTL1_GPIO_Port GPIOA
#define Y_28BYJ_CTL2_Pin GPIO_PIN_9
#define Y_28BYJ_CTL2_GPIO_Port GPIOA
#define Y_28BYJ_CTL3_Pin GPIO_PIN_10
#define Y_28BYJ_CTL3_GPIO_Port GPIOA
#define Y_28BYJ_CTL4_Pin GPIO_PIN_11
#define Y_28BYJ_CTL4_GPIO_Port GPIOA
#define SG90_CTL1_Pin GPIO_PIN_4
#define SG90_CTL1_GPIO_Port GPIOB
#define SG90_CTL2_Pin GPIO_PIN_5
#define SG90_CTL2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

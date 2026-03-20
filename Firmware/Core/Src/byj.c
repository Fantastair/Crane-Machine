/*
28BYJ-48 步进电机控制模块
采用4拍驱动，每拍连通2相
*/

#include "main.h"
#include "tim.h"

#include "byj.h"

/**
 * @brief 步进电机模块初始化
 * @param step_delay_us 每步延时，单位微秒，决定转速
 */
void BYJ_Init(uint16_t step_delay_us)
{
    /* TIM4 定时器用于产生定时中断来自动控制步进电机运动，
       定时器已经设置了预分频为 (72 - 1)，所以自动重装值就是 (step_delay_us - 1) */
    __HAL_TIM_SET_AUTORELOAD(&htim4, step_delay_us - 1);
    HAL_TIM_Base_Start_IT(&htim4);
}

/**
 * @brief 步进
 * @param motor 步进电机实例
 */
void BYJ_Step(BYJ_Motor *motor)
{
    if (motor->state == BYJ_MOVE_STOP)
    {
        return;
    }

    uint8_t step;
    switch (motor->state)
    {
    case BYJ_MOVE_FORWARD:
        step = (motor->step + 1) % 4;
        break;

    case BYJ_MOVE_BACKWARD:
        step = (motor->step + 3) % 4;
        break;

    default:
        break;
    }

    HAL_GPIO_WritePin(
        motor->port,
        motor->pins[(step + 2) % 4] | motor->pins[(step + 3) % 4],
        GPIO_PIN_RESET);
    HAL_GPIO_WritePin(
        motor->port,
        motor->pins[step] | motor->pins[(step + 1) % 4],
        GPIO_PIN_SET);

    motor->step = step;
}

/**
 * @brief 停止（省电）
 * @param motor 步进电机实例
 */
void BYJ_Stop(BYJ_Motor *motor)
{
    motor->state = BYJ_MOVE_STOP;
    HAL_GPIO_WritePin(
        motor->port,
        motor->pins[0] | motor->pins[1] | motor->pins[2] | motor->pins[3],
        GPIO_PIN_RESET);
}

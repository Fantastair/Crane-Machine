/*
MAX1616H 双路电机驱动模块
*/
#include "main.h"
#include "tim.h"

#include "max1616h.h"

/**
 * @brief MAX1616H 通道初始化
 * @param channel MAX1616H通道配置结构体指针
 */
void MAX1616H_Init(MAX1616H_Channel *channel)
{
    HAL_TIM_PWM_Start(channel->pwm_timer, channel->pwm_channel1);
    HAL_TIM_PWM_Start(channel->pwm_timer, channel->pwm_channel2);

    MAX1616H_SetState(channel, MAX1616H_STOP);
}

/**
 * @brief 设置MAX1616H模块状态
 * @param channel MAX1616H通道配置结构体指针
 * @param state 目标状态
 */
void MAX1616H_SetState(MAX1616H_Channel *channel, MAX1616H_State state)
{
    channel->state = state;

    switch (state)
    {
    case MAX1616H_STOP:
        __HAL_TIM_SetCompare(channel->pwm_timer, channel->pwm_channel1, 0);
        __HAL_TIM_SetCompare(channel->pwm_timer, channel->pwm_channel2, 0);
        break;

    case MAX1616H_FORWARD:
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel1, MAX1616H_MAX_SPEED
        );
        __HAL_TIM_SetCompare(
            channel->pwm_timer,
            channel->pwm_channel2,
            MAX1616H_MAX_SPEED - channel->speed
        );
        break;

    case MAX1616H_BACKWARD:
        __HAL_TIM_SetCompare(
            channel->pwm_timer,
            channel->pwm_channel1,
            MAX1616H_MAX_SPEED - channel->speed
        );
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel2, MAX1616H_MAX_SPEED
        );
        break;

    case MAX1616H_BRAKE:
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel1, MAX1616H_MAX_SPEED
        );
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel2, MAX1616H_MAX_SPEED
        );
        break;

    default:
        break;
    }
}

/**
 * @brief 设置MAX1616H模块速度
 * @param channel MAX1616H通道配置结构体指针
 * @param speed 速度值，范围0-1000，对应0%-100%占空比
 * @note 只有在前进或后退状态下设置速度才有效，停止或刹车状态下速度无效
 */
void MAX1616H_SetSpeed(MAX1616H_Channel *channel, uint16_t speed)
{
    if (speed > MAX1616H_MAX_SPEED) { speed = MAX1616H_MAX_SPEED; }
    channel->speed = speed;

    switch (channel->state)
    {
    case MAX1616H_FORWARD:
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel2, MAX1616H_MAX_SPEED - speed
        );
        break;

    case MAX1616H_BACKWARD:
        __HAL_TIM_SetCompare(
            channel->pwm_timer, channel->pwm_channel1, MAX1616H_MAX_SPEED - speed
        );
        break;

    default:
        break;
    }
}

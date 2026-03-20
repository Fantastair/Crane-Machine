/*
SG90 舵机（180°）控制模块
由 MAX1616H 控制电源通道
*/

#include "main.h"
#include "tim.h"

#include "max1616h.h"
#include "sg90.h"

/**
 * @brief SG90 舵机控制模块初始化
 */
void SG90_Init(SG90_Servo *servo)
{
    uint16_t SG90_TIM_PERIOD = __HAL_TIM_GetAutoreload(servo->timer);
    servo->tim_min_pulse = (uint16_t)(SG90_TIM_PERIOD * 0.025);
    servo->tim_max_pulse = (uint16_t)(SG90_TIM_PERIOD * 0.125);
}

/**
 * @brief 打开 SG90 舵机电源
 * @param servo SG90舵机实例指针
 */
void SG90_PowerOn(SG90_Servo *servo)
{
    MAX1616H_SetState(servo->power_channel, MAX1616H_STOP); // 舵机不能反向供电
    HAL_TIM_PWM_Start(servo->timer, servo->tim_channel);
}

/**
 * @brief 关闭 SG90 舵机电源
 * @param servo SG90舵机实例指针
 */
void SG90_PowerOff(SG90_Servo *servo)
{
    HAL_TIM_PWM_Stop(servo->timer, servo->tim_channel);
    MAX1616H_SetState(servo->power_channel, MAX1616H_STOP);
}

/**
 * @brief 设置 SG90 舵机角度
 * @param servo SG90舵机实例指针
 * @param angle 目标角度
 */
void SG90_SetAngle(SG90_Servo *servo, double angle)
{
    if (angle < 0) { angle = 0; }
    if (angle > 180) { angle = 180; }

    uint16_t pulse_length = (uint16_t)(
        servo->tim_min_pulse + \
        (servo->tim_max_pulse - servo->tim_min_pulse) * (angle / 180.0)
    );
    __HAL_TIM_SetCompare(servo->timer, servo->tim_channel, pulse_length);
}

/*
钩爪舵机控制模块
*/

#include "main.h"
#include "tim.h"

#include "max1616h.h"
#include "sg90.h"
#include "claw.h"

MAX1616H_Channel claw_power_channel = {
    &htim3,
    TIM_CHANNEL_1,
    TIM_CHANNEL_2,
    MAX1616H_STOP,
    MAX1616H_MAX_SPEED
};

/* 钩爪舵机实例 */
SG90_Servo claw_servo = {
    &claw_power_channel,
    &htim2,
    TIM_CHANNEL_1
};

const double claw_open_angle = 60.0;  // 钩爪打开时的角度
const double claw_close_angle = 70.0; // 钩爪关闭时的角度

const uint16_t claw_action_total_ms = 1000; // 钩爪动作总持续时间（毫秒）
uint16_t claw_action_elapsed_ms = 1000;     // 钩爪动作已持续时间（毫秒）

/**
 * @brief 初始化钩爪模块
 */
void Claw_Init(void)
{
    SG90_Init(&claw_servo);
}

/**
 * @brief 钩爪释放
 */
void Claw_Release(void)
{
    SG90_PowerOn(&claw_servo);
    SG90_SetAngle(&claw_servo, claw_open_angle);
    claw_action_elapsed_ms = 0;
}

/**
 * @brief 钩爪抓取
 */
void Claw_Scrape(void)
{
    SG90_PowerOn(&claw_servo);
    SG90_SetAngle(&claw_servo, claw_close_angle);
    claw_action_elapsed_ms = 0;
}

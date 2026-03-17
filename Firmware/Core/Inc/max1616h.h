#ifndef __MAX1616H_H__
#define __MAX1616H_H__

#include "main.h"

#define MAX1616H_MAX_SPEED 1000

/* MAX1616H状态枚举 */
typedef enum
{
    MAX1616H_STOP,     // 停止
    MAX1616H_FORWARD,  // 前进
    MAX1616H_BACKWARD, // 后退
    MAX1616H_BRAKE     // 刹车
} MAX1616H_State;

/* 直流电机驱动通道结构体 */
typedef struct
{
    uint16_t in1_pin;             // IN1引脚
    uint16_t in2_pin;             // IN2引脚
    GPIO_TypeDef *in1_port;       // IN1引脚所在GPIO端口
    GPIO_TypeDef *in2_port;       // IN2引脚所在GPIO端口
    TIM_HandleTypeDef *pwm_timer; // PWM定时器句柄
    uint32_t pwm_channel1;        // PWM通道1
    uint32_t pwm_channel2;        // PWM通道2
    MAX1616H_State state;         // 状态
    uint16_t speed;               // 速度
} MAX1616H_Channel;

void MAX1616H_Init(MAX1616H_Channel *channel);
void MAX1616H_SetState(MAX1616H_Channel *channel, MAX1616H_State state);
void MAX1616H_SetSpeed(MAX1616H_Channel *channel, uint16_t speed);

#endif

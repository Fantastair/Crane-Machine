#ifndef __SG90_H__
#define __SG90_H__

#include "main.h"
#include "max1616h.h"

typedef struct
{
    MAX1616H_Channel *power_channel; // 电源控制通道
    TIM_HandleTypeDef *timer; // 定时器句柄
    uint32_t tim_channel; // 定时器通道
    uint16_t tim_min_pulse; // 最小脉宽（对应0°）
    uint16_t tim_max_pulse; // 最大脉宽（对应180°）
} SG90_Servo;

void SG90_Init(SG90_Servo *servo);
void SG90_PowerOn(SG90_Servo *servo);
void SG90_PowerOff(SG90_Servo *servo);
void SG90_SetAngle(SG90_Servo *servo, double angle);

#endif

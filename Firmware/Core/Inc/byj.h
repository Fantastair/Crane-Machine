#ifndef __BYJ_H__
#define __BYJ_H__

#include "main.h"

/* 步进电机状态枚举 */
typedef enum
{
    BYJ_MOVE_FORWARD,  // 前进
    BYJ_MOVE_BACKWARD, // 后退
    BYJ_MOVE_STOP      // 停止
} BYJ_State;

/* 步进电机结构体 */
typedef struct
{
    BYJ_State state;    // 当前状态
    uint8_t step;       // 当前步数
    uint16_t pins[4];   // 电机引脚
    GPIO_TypeDef *port; // GPIO端口，所有引脚在同一个端口
} BYJ_Motor;

void BYJ_Init(uint16_t step_delay_us);
void BYJ_Step(BYJ_Motor *motor);
void BYJ_Stop(BYJ_Motor *motor);

#endif

#ifndef __CROSS_H__
#define __CROSS_H__

#include "byj.h"

extern BYJ_Motor x_motor; // X轴步进电机实例
extern BYJ_Motor y_motor; // Y轴步进电机实例

void Cross_Init(void);
void Cross_MoveLeft(void);
void Cross_MoveRight(void);
void Cross_MoveForward(void);
void Cross_MoveBackward(void);
void Cross_Stop(void);

#endif

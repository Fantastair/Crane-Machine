#ifndef __CLAW_H__
#define __CLAW_H__

#include "sg90.h"

extern SG90_Servo claw_servo; // 钩爪舵机实例

extern const uint16_t claw_action_total_ms; // 钩爪动作总持续时间（毫秒）
extern uint16_t claw_action_elapsed_ms;     // 钩爪动作已持续时间（毫秒）

void Claw_Init(void);
void Claw_Release(void);
void Claw_Scrape(void);

#endif

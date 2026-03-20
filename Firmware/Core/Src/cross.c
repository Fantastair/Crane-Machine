/*
XY轴十字驱动模块
*/

#include "main.h"

#include "byj.h"
#include "cross.h"

/* X轴步进电机 */
BYJ_Motor x_motor = {
    BYJ_MOVE_STOP,
    0,
    {
        X_28BYJ_CTL1_Pin,
        X_28BYJ_CTL2_Pin,
        X_28BYJ_CTL3_Pin,
        X_28BYJ_CTL4_Pin
    },
    X_28BYJ_CTL1_GPIO_Port
};

/* Y轴步进电机 */
BYJ_Motor y_motor = {
    BYJ_MOVE_STOP,
    0,
    {
        Y_28BYJ_CTL1_Pin,
        Y_28BYJ_CTL2_Pin,
        Y_28BYJ_CTL3_Pin,
        Y_28BYJ_CTL4_Pin
    },
    Y_28BYJ_CTL1_GPIO_Port
};

/**
 * @brief 十字驱动模块初始化
 */
void Cross_Init(void)
{
    BYJ_Init(2000); // 初始化步进电机控制模块
    // 复位
    Cross_MoveLeft();
    Cross_MoveForward();
}

/**
 * @brief 向左移动
 */
void Cross_MoveLeft(void)
{
    x_motor.state = BYJ_MOVE_BACKWARD;
}

/**
 * @brief 向右移动
 */
void Cross_MoveRight(void)
{
    x_motor.state = BYJ_MOVE_FORWARD;
}

/**
 * @brief 向前移动
 */
void Cross_MoveForward(void)
{
    y_motor.state = BYJ_MOVE_FORWARD;
}

/**
 * @brief 向后移动
 */
void Cross_MoveBackward(void)
{
    y_motor.state = BYJ_MOVE_BACKWARD;
}

/**
 * @brief 停止移动
 */
void Cross_Stop(void)
{
    BYJ_Stop(&x_motor);
    BYJ_Stop(&y_motor);
}

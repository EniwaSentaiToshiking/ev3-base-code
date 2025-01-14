/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */

#include "SpinTurnBehaviorModel.h"

void SpinTurnBehaviorModel::init()
{
    wheelDeviceDriver.init();
    
}

void SpinTurnBehaviorModel::run(int pwm, SpinTurnLeftOrRight spinTurnLeftOrRight)
{
    switch (spinTurnLeftOrRight)
    {
    case NONE_L_R:
        break;

    case LEFTWARD:
        wheelDeviceDriver.setLeftPWM(-pwm);
        wheelDeviceDriver.setRightPWM(pwm);
        break;

    case RIGHTWARD:
        wheelDeviceDriver.setLeftPWM(pwm);
        wheelDeviceDriver.setRightPWM(-pwm);
        break;
        
    default:
        break;
    }
}

void SpinTurnBehaviorModel::terminate()
{
    wheelDeviceDriver.terminate();
}
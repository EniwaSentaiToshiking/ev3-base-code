/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#include "SpinTurnAngleDeterminationModel.h"

void SpinTurnAngleDeterminationModel::init()
{
    wheelDeviceDriver.init();
}

bool SpinTurnAngleDeterminationModel::determine(SpinTurnAngleList spinTurnAngle)
{
    if(wheelDeviceDriver.getDistance() >= spinTurnAngle)
    {
        return true;
    }
    return false;
}

void SpinTurnAngleDeterminationModel::terminate()
{
    wheelDeviceDriver.resetDistance();
}

// int SpinTurnAngleDeterminationModel::calSpinTurnDistance()
// {
//     return 2 * M_PI * treadWidthRadius *
// }
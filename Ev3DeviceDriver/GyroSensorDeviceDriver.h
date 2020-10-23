#pragma once

#include "GyroSensor.h"

#include "DebugUtil.h"
#include <stdlib.h>

using namespace ev3api;

class GyroSensorDeviceDriver
{
    GyroSensor gyroSensor;

public:
    GyroSensorDeviceDriver();
    void init();
    void resetAngle();
    int getAngle();
    void terminate();
    ~GyroSensorDeviceDriver();

    /* debug */
    DebugUtil d;
    FILE *file;
};
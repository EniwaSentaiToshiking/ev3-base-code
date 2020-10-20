#pragma once

#include "TemplateGameState.h"
#include "Motor.h"
// #include "ColorSensorDeviceDriver.h"
#include "InterfaceDeterminationModel.h"
#include "DebugUtil.h"
#include "PIDCalculator.h"

class RunningGameState : public TemplateGameState
{
  // Motor leftWheel;
  // Motor rightWheel;
  WheelDeviceDriver wheelDeviceDriver;
  InterfaceDeterminationModel interfaceDeterminationModel;
  ColorSensorDeviceDriver colorSensorDeviceDriver;
  PIDCalculator pidCalculator;
  DebugUtil debugUtil;

public:
  RunningGameState();
  void init();
  void run();
  bool isFinished();
  void terminate();
  ~RunningGameState();

private:
  // const int8_t pwm = (Motor::PWM_MAX) / 2;
  int8_t pwm = 70;
};

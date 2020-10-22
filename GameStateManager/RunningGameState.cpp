#include "RunningGameState.h"

// RunningGameState::RunningGameState() : leftWheel(PORT_C), rightWheel(PORT_B)
// {
//   this->init();
// }

RunningGameState::RunningGameState()
{
  this->init();
}

void RunningGameState::init()
{
  debugUtil.init("RunningGameState");
  colorSensorDeviceDriver.init();
  wheelDeviceDriver.init();
}

void RunningGameState::run()
{
  debugUtil.lcd_msg_debug("running...", 1);
  const int m_target_color_value = 18;
  float m_control_value = pidCalculator.calcPID(2.0, 0.03, 0.2, colorSensorDeviceDriver.getBrightness(), m_target_color_value);
  int m_left_pwm = pwm - m_control_value;                                                                                             
  int m_right_pwm = pwm + m_control_value;                                                                                            
  // leftWheel.setPWM(m_left_pwm);
  // rightWheel.setPWM(m_right_pwm);
  wheelDeviceDriver.setLeftPWM(m_left_pwm);
  wheelDeviceDriver.setRightPWM(m_right_pwm);
}

bool RunningGameState::isFinished()
{
  // return interfaceDeterminationModel.selectColor(COLOR_BLUE);
  // return interfaceDeterminationModel.selectDistance(800.0);
  return false;
}

void RunningGameState::terminate()
{
  debugUtil.lcd_msg_debug("Stopped.", 1);
  // leftWheel.stop();
  // rightWheel.stop();
  colorSensorDeviceDriver.terminate();
  wheelDeviceDriver.terminate();
  debugUtil.led_debug(LED_RED);
}

RunningGameState::~RunningGameState()
{
  this->terminate();
}

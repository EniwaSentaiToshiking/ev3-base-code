#include "PlaygroundGameState.h"

PlaygroundGameState::PlaygroundGameState()
{
}

void PlaygroundGameState::init()
{
  d.init("PlaygroundGameState");
  // /*distance, pwm, kp, ki, kd, targetVal*/
  // runSectionParamVector.push_back({800.0, 90, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({1200.0, 80, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({400.0, 90, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({1200.0, 70, 2.0, 0.03, 0.2, 18});
  // /* Gate 1*/
  // runSectionParamVector.push_back({600.0, 90, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({500.0, 70, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({600.0, 80, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({1700.0, 70, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({500.0, 80, 2.0, 0.03, 0.2, 18});
  // /* Gate 2*/
  // runSectionParamVector.push_back({800.0, 80, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({1550.0, 100, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({550.0, 70, 2.0, 0.03, 0.2, 18});
  // runSectionParamVector.push_back({1100.0, 90, 2.0, 0.03, 0.2, 18});
}

extern char syslogBuf[50];
void PlaygroundGameState::run()
{
  iBehaviorModel.selectSpinTrun(40, LEFTWARD);
  // RunSectionParam currentRunSectionParam = runSectionParamVector.front();
  // iBehaviorModel.selectLineTrace(currentRunSectionParam.pwm, currentRunSectionParam.kP,
  //                                currentRunSectionParam.kI, currentRunSectionParam.kD, currentRunSectionParam.targetVal);

  // if (iDeterminationModel.selectDistance(currentRunSectionParam.distance))
  // {
  //   iDeterminationModel.terminate();
  //   runSectionParamVector.erase(runSectionParamVector.begin());
  // }
}

bool PlaygroundGameState::isFinished()
{
  return iDeterminationModel.selectAngle(DEGREE135);
  // float dis = wheelDeviceDriver.getDistance();
  // snprintf(syslogBuf, sizeof(syslogBuf), "Distance %f", dis);
  // syslog(LOG_NOTICE, syslogBuf);
  // if (dis >= 204)
  // {
  //   return true;
  // }
  //   return false;
}


void PlaygroundGameState::terminate()
{
  d.lcd_msg_debug("Stopped.", 1);
  d.led_debug(LED_RED);
  iBehaviorModel.selectLineTrace(0,0,0,0,0);
}

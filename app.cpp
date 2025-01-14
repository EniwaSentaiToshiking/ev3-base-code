#include "app.h" 
#include "SetupGame.h"
#include "Edge.h"
#include "GameStateManager.h"
// #include "Ev3StateManager.h"
// #include "Ev3State.h"
#include "DebugUtil.h"

/**
 * 左コース/右コース向けの設定を定義します
 * デフォルトは左コース(ラインの右エッジをトレース)です
 */

#if defined(MAKE_RIGHT)
  int edge = LEFT_EDGE;
#else
  int edge = RIGHT_EDGE;
#endif

using namespace ev3api;

SetupGame setupGame;
GameStateManager gameStateManager;
DebugUtil d;
// syslog
char syslogBuf[50] = "syslog";
/*
  snprintf(syslogBuf, sizeof(syslogBuf), "section, %d, Distance %f", runSection, wheelDeviceDriver.getDistance());
  syslog(LOG_NOTICE, syslogBuf);
*/

int nowGameState = RUNNING_GAME_STATE;
// int nowEv3State = PRE_GAME_STATE;

void setup_game_task(intptr_t exinf)
{
  d.init("Ready");
  if (setupGame.isStarted())
  {
    gameStateManager.init();
    sta_cyc(GAME_STATE_MANAGER_CYC);
  }

  if (ev3_button_is_pressed(LEFT_BUTTON))
  {
    snprintf(syslogBuf, sizeof(syslogBuf), "push left button:stop ev3");
    syslog(LOG_NOTICE, syslogBuf);
    stp_cyc(SETUP_GAME_CYC);
    stp_cyc(GAME_STATE_MANAGER_CYC);
    gameStateManager.terminate();
  }
  ext_tsk();
}

void game_state_manager_task(intptr_t exinf)
{
  gameStateManager.manageGameState();
  ext_tsk();
}
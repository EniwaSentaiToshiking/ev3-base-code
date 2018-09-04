#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"
#include "LineTrace.h"
#include "PointDetecter.h"

#ifndef RUNSTATUS_H
#define RUNSTATUS_H

class RunStatus
{
  protected:
    RunCommander *runCommander;
    ArmCommander *armCommander;
    TailCommander *tailCommander;
    LineTrace *lineTrace;
    PointDetecter *pointDetecter;

  public:
    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    virtual void init() = 0;

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {void}
     */
    virtual void run() = 0;

    /**
     * isFinish - 終了判定
     *
     * @param  {void}
     * @return {bool}
     */
    virtual bool isFinish() = 0;
    virtual ~RunStatus(){};
};

#endif
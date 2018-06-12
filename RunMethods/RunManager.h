#include "RunCommander.h"
#include "ArmCommander.h"
#include "TailCommander.h"
#include "LineTrace.h"

class RunManager {

private:
    RunCommander *runCommander;
    ArmCommander *armCommander;
    TailCommander *tailCommander;
    LineTrace *lineTrace;

public:
    RunManager();

    /**
     * init - 走行前の初期設定
     *
     * @param  {void}
     * @return {void}
     */
    void init();

    /**
     * run - 走行する
     *
     * @param  {void}
     * @return {void}
     */
    void run();
    virtual ~RunManager();

};
#pragma once

#include "TemplateGameState.h"
#include "InterfaceDeterminationModel.h"
#include "InterfaceBehaviorModel.h"
#include "RunSectionParam.h"
#include <vector>

#include "DebugUtil.h"

using namespace ev3api;
using namespace std;

class BlockBingoGameState : public TemplateGameState
{
  InterfaceDeterminationModel interfaceDeterminationModel;
  InterfaceBehaviorModel interfaceBehaviorModel;
  vector<RunSectionParam> runSectionParamVector;

  DebugUtil d;

public:
  BlockBingoGameState();
  void init();
  void createRunSectionL();
  void createRunSectionR();
  void run();
  bool isFinished();
  void terminate();
};
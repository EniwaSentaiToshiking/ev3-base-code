/*
 * Created on Wed Feb 03 2021
 *
 * Copyright (c) 2021 Kazuki Hamaguchi
 */
#pragma once

#include "GameState.h"
#include "RunningGameState.h"
#include "BlockBingoGameState.h"
#include "GarageGameState.h"
#include "PlaygroundGameState.h"
#include "DebugUtil.h"

extern int nowGameState;

class GameStateManager
{
    RunningGameState runningGameState;
    BlockBingoGameState blockBingoGameState;
    GarageGameState garageGameState;

    /* debug */
    PlaygroundGameState playgroundGameState;
    DebugUtil d;

public:
    GameStateManager();
    void init();
    void manageGameState();
    void terminate();
};
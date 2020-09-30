#include "GameStateManager.h"

GameStateManager::GameStateManager()
{
}

void GameStateManager::init()
{
    debugUtil.init("GameStateManager");
    runningGameState.init();
    playgroundGameState.init();
}

void GameStateManager::manageGameState() 
{
    switch (nowState)
    {
    case RUNNING_GAME_STATE:
        runningGameState.run();
        if (runningGameState.isChanged())
        {
            runningGameState.terminate();
            nowState = BLOCK_BINGO_GAME_STATE;
        }
        break;
    case BLOCK_BINGO_GAME_STATE:
        break;
    case GARAGE_GAME_STATE:
        break;
    case PLAYGROUND_GAME_STATE:
        playgroundGameState.run();
        if (playgroundGameState.isChanged())
        {
            debugUtil.led_debug(LED_RED);
        }
        break;
    default:
        break;
    }
}

void GameStateManager::terminate()
{
    runningGameState.terminate();
    playgroundGameState.terminate();
}
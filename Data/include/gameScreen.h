#ifndef GAME_STATE
#define GAME_STATE


#include "stateManager.h"
#include <gsKit.h>
#include <dmaKit.h>
#include <gsToolkit.h>


void GameStart(GSGLOBAL* gsGlobal);
void GameUpdate(GSGLOBAL* gsGlobal);
void GameDraw(GSGLOBAL* gsGlobal, u64 colour);
void GameEnd(GSGLOBAL* gsGlobal);

extern StateManager GameState;

#endif

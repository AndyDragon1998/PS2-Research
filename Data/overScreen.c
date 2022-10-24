#include "include/gameScreen.h"
#include "include/menuScreen.h"
#include "include/overScreen.h"
#include "include/musicManager.h"
#include "include/pad.h"

extern StateMachine GameMachineState;


void OverStart(GSGLOBAL* gsGlobal)
{

}

void OverUpdate(GSGLOBAL* gsGlobal)
{

}

void OverDraw(GSGLOBAL* gsGlobal, u64 colour)
{

}

void OverEnd(GSGLOBAL* gsGlobal)
{

}

StateManager OverState =
{
	OverStart,
	OverUpdate,
	OverDraw,
	OverEnd
};

#include "include/gameScreen.h"
#include "include/menuScreen.h"
#include "include/overScreen.h"
#include "include/soundEffects.h"
#include "include/musicManager.h"
#include "include/pad.h"

extern StateMachine GameMachineState;
extern Controller PlaystationGamePad;

GSTEXTURE image;

SE StartGameSE;
BGM MenuMusic;

void MenuStart(GSGLOBAL* gsGlobal)
{

	printf("Loading Image in Memory...\n");
	gsKit_texture_png(gsGlobal, &image, "host:Graphics/Images/Image2.png");

}

void MenuUpdate(GSGLOBAL* gsGlobal)
{

}

void MenuDraw(GSGLOBAL* gsGlobal, u64 colour)
{
	int i = (4096 - gsGlobal->CurrentPointer/1024);
	printf("VRAM: %d\n", i);

	gsKit_prim_sprite_texture(gsGlobal, &image,0,  // X1
						0,  // Y2
						0.0f,  // U1
						0.0f,  // V1
						image.Width, // X2
						image.Height, // Y2
						image.Width, // U2
						image.Height, // V2
						2,
						colour);

}

void MenuEnd(GSGLOBAL* gsGlobal)
{

}

StateManager MenuState =
{
	MenuStart,
	MenuUpdate,
	MenuDraw,
	MenuEnd
};

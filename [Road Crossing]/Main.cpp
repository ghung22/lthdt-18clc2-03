#pragma comment (lib, "winmm.lib")
#include "CGAME.h"

static CGAME* game;

int main()
{
	game = new CGAME;
	game->start();

	return 0;
}
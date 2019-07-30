#pragma comment (lib, "winmm.lib")
#include "CGAME.h"

CGAME* game;

int main()
{
	game = new CGAME;
	game->start();

	return 0;
}
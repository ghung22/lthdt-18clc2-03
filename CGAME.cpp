#include "CGAME.h"



CGAME::CGAME()
{
}

void CGAME::Input()
{
	if (_kbhit())
	{
		char key = _getch();
		if (key = 'a')
			player->x--;
		if (key = 'd')
			player->x++;
		if (key = 'w')
			player->y++;
		if (key = 's')
			player->y--;
		if (key = 'q')
			quit = true;
	}
}


CGAME::~CGAME()
{
}

#include "CGAME.h"

/* RETURN VALUE LIST:
	0	-	Ko vấn đề.
*/

CGAME* game;

int main()
{
	game = new CGAME;
	game->start();

	return 0;
}
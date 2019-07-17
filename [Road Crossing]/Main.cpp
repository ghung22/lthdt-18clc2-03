#include "CGAME.h"

/* RETURN VALUE LIST:
	0	-	Ko vấn đề.
	1	-	Code chạy đến cuối hàm main, điều vốn ko nên xảy ra.
*/

CGAME* game;

int main()
{
	game = new CGAME;
	game->start();

	return 1;
}
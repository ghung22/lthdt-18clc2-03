#include "Window.h"
#include "Threads.h"
#include "CGAME.h"

/* RETURN VALUE LIST:
	0	-	Ko vấn đề.
	1	-	Code chạy đến cuối hàm main, điều vốn ko nên xảy ra.
*/

char MOVING;
CGAME* game;

int main()
{
	game = new CGAME();
	char pressed;
	LockWinSize();
	game->start();
	thread gThread(UpdateGameFrame);		//Chạy hàm song song với main()
	while (true)
	{
		pressed = toupper(getchar());
		if (!game->getPeople().isDead())	//Nếu người chơi chưa die, nhận nút di chuyển và các nút menu
			switch (pressed)
			{
			case 27:	//Phím ESC
				game->exit(gThread.native_handle());
				return 0;
			case 'P':
				game->pause(gThread.native_handle());
				break;
			default:
				game->resume(gThread.native_handle());
				MOVING = pressed;	//Cập nhật bước di chuyển
				break;
			}
		else	//Khi đã die hoặc mới bắt đầu game, ấn Y thì bắt đầu chơi
		{
			if (pressed == 'Y')
				game->start();
			else
			{
				game->exit(gThread.native_handle());
				return 0;
			}
		}
	}

	return 1;
}
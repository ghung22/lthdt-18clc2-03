#include "Threads.h"
#include "CGAME.h"

#include <iostream>
using namespace std;

bool IS_RUNNING = true;
extern bool IS_PAUSED;

void exitGame(thread& t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t.join();			//Join main thread
}

void UpdateGameFrame(CGAME* g)
{
	long temp = 0;

	while (IS_RUNNING)
	{
		if (!IS_PAUSED)
		{
			//g->truck[0].moveXY(1, 0);

			if (temp >= 50000) //Hết time, thua
				break;

			if (g->p.getPos().Y >= 9) //Người chơi đến đích, tăng level
			{
				g->reset(false);
				temp = 0;
			}

			if (temp % 20 == 0)
			{
				long s = temp / 20;
				//Di chuyển object
			}
			temp++;
			Sleep(1);
		}
	}
}
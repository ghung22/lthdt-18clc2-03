#include "Threads.h"
#include "Constants.h"
#include "CGAME.h"

#include <iostream>
using namespace std;

bool IS_RUNNING = true;

void exitGame(thread& t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t.join();			//Join main thread
}

void UpdateGameFrame(CGAME* g)
{
	int temp = 0;
	Point _t = { 2,4 }, _c = { 16,2 },
		_b = { 32,6 }, _d = { 4,8 };

	g->p.moveXY(0, 0);
	while (!IS_RUNNING)
	{
		if (temp >= 50000)
			break;

		if (temp % 20 == 0)
		{
			short s = temp / 20;
			g->truck[0].erase({ _t.X + s, _t.Y });
			g->truck[0].draw({ _t.X + s, _t.Y });
			
			g->car[0].erase({ _c.X + s, _c.Y });
			g->car[0].draw({ _c.X + s, _c.Y });
			
			g->bird[0].erase({ _b.X + s, _b.Y });
			g->bird[0].draw({ _b.X + s, _b.Y });
			
			g->dino[0].erase({ _d.X + s, _d.Y });
			g->dino[0].draw({ _d.X + s, _d.Y });
		}
		temp++;
		Sleep(1);
	}
}
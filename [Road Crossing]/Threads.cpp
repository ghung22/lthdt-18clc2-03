#include "Threads.h"
#include "CGAME.h"
#include "Constants.h"

bool IS_RUNNING = true;

void exitGame(thread* t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t->join();			//Join main thread
}

void UpdateGameFrame()
{
	int temp = 0;
	CTruck t;
	CCar c;
	COORD _t = { 2,4 }, _c = { 16,2 };
	while (IS_RUNNING)
	{
		if (temp >= 5000)
			break;

		if (temp % 20 == 0)
		{
			short s = temp / 20;
			t.draw(' ', { _t.X + s - 1, _t.Y });
			c.draw(' ', { _c.X + s - 1, _c.Y });
			t.draw(OBJECT_SYMBOL, { _t.X + s, _t.Y });
			c.draw(OBJECT_SYMBOL, { _c.X + s, _c.Y });
		}
		temp++;
		Sleep(1);
	}
}
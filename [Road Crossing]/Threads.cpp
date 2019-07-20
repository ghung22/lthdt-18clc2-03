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
	CBird b;
	CDino d;
	CPEOPLE p;
	Point _t = { 2,4 }, _c = { 16,2 },
		_b = { 32,6 }, _d = { 4,8 },
		_p = { 64, 16 };

	p.draw(_p);
	while (IS_RUNNING)
	{
		if (temp >= 50000)
			break;

		if (temp % 20 == 0)
		{
			short s = temp / 20;
			t.draw({ _t.X + s, _t.Y }, true);
			t.draw({ _t.X + s, _t.Y });
			
			c.draw({ _c.X + s, _c.Y }, true);
			c.draw({ _c.X + s, _c.Y });
			
			b.draw({ _b.X + s, _b.Y }, true);
			b.draw({ _b.X + s, _b.Y });
			
			d.draw({ _d.X + s, _d.Y }, true);
			d.draw({ _d.X + s, _d.Y });
		}
		temp++;
		Sleep(1);
	}
}
#include "Threads.h"
#include "CGAME.h"
#include "Constants.h"

#include <iostream>
using namespace std;

bool IS_RUNNING = true;

void exitGame(thread* t)
{
	system("CLS");
	IS_RUNNING = false;	//Stop update frames
	t->join();			//Join main thread
}
//GetKeyState()
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
			t.erase({ _t.X + s, _t.Y });
			t.draw({ _t.X + s, _t.Y });
			
			c.erase({ _c.X + s, _c.Y });
			c.draw({ _c.X + s, _c.Y });
			
			b.erase({ _b.X + s, _b.Y });
			b.draw({ _b.X + s, _b.Y });
			
			d.erase({ _d.X + s, _d.Y });
			d.draw({ _d.X + s, _d.Y });
		}
		temp++;
		Sleep(1);
	}
}
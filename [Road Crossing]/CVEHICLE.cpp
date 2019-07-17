#include "CVEHICLE.h"
#include "Windows.h"

#include <iostream>
#include <string>
using namespace std;

bool CVEHICLE::inContact(Point ppos)
{
	return pos.x <= ppos.x && ppos.x <= pos.x + 2
		&& pos.y == ppos.y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của vehicle
}

void CTruck::draw(char s, COORD pos)
{
	GotoXY(pos.X, pos.Y);
	cout << s << s << s;
	GotoXY(pos.X, pos.Y + 1);
	cout << s << s << s << s;
}
void CCar::draw(char s, COORD pos)
{
	GotoXY(pos.X, pos.Y);
	cout << ' ' << s << s;
	GotoXY(pos.X, pos.Y + 1);
	cout << s << s << s << s;
}
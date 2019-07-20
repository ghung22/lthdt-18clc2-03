#include "CVEHICLE.h"

#include <iostream>
using namespace std;

bool CVEHICLE::inContact(Point ppos)
{
	return pos.x <= ppos.x && ppos.x <= pos.x + 2
		&& pos.y == ppos.y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của vehicle
}

CVEHICLE::CVEHICLE()
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
}

CVEHICLE::CVEHICLE(int y, int s_speed)
{
	pos.x = 0;
	pos.y = y;
	speed = s_speed;
}

CTruck::CTruck() : CVEHICLE(2, 25){}

CCar::CCar(): CVEHICLE(4, 20){}

void CVEHICLE::draw() { }
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
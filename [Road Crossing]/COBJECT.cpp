#include "COBJECT.h"
#include "CGAME.h"

Window wd;

COBJECT::COBJECT()
{
	pos = { 0,0 };
	speed = 0;
	for (int i = 0; i < 3; i++)
		avatar.push_back("");
}

void COBJECT::draw(Point p)
{
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X, p.Y + i);
		cout << avatar[i];
	}
}
void COBJECT::erase(Point p)
{
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X - 4, p.Y + i);
		cout << "          ";
	}
}

void COBJECT::moveXY(short x, short y)
{
	Point temp = pos;
	temp.Y = (10 - pos.Y) * 5 + 2;

	erase(temp);
	pos.X += x;
	pos.Y += y;

	temp.Y = (10 - pos.Y) * 5 + 2;
	draw(temp);
}
#include "COBJECT.h"
#include "CGAME.h"

Window w;

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
		w.GotoXY(p.X, p.Y + i);
		cout << avatar[i];
	}
}
void COBJECT::erase(Point p)
{
	for (int i = 0; i < 3; i++)
	{
		w.GotoXY(p.X - 4, p.Y + i);
		cout << "          ";
	}
}
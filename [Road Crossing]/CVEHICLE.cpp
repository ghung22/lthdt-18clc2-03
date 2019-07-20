#include "CVEHICLE.h"

#include <iostream>
using namespace std;

bool CVEHICLE::inContact(Point ppos)
{
	return pos.X <= ppos.X && ppos.X <= pos.X + 2
		&& pos.Y == ppos.Y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của vehicle
}

//void CVEHICLE::draw() { }
void CTruck::draw(Point pos, bool erase)
{
	if (erase)
	{
		GotoXY(pos.X - 1, pos.Y);
		cout << "    ";
		GotoXY(pos.X - 1, pos.Y + 1);
		cout << "     ";
		GotoXY(pos.X - 1, pos.Y + 2);
		cout << "    ";
	}
	else
	{
		GotoXY(pos.X, pos.Y);
		cout << char(218) << char(196) << char(196) << char(191);			//┌──┐
		GotoXY(pos.X, pos.Y + 1);											//│ ███
		cout << char(179) << ' ' << char(219) << char(219) << char(219);	//O──O
		GotoXY(pos.X, pos.Y + 2);
		cout << 'O' << char(196) << char(196) << 'O';
	}
}
void CCar::draw(Point pos, bool erase)
{
	if (erase)
	{
		GotoXY(pos.X - 1, pos.Y + 1);
		cout << "   ";
		GotoXY(pos.X - 1, pos.Y + 2);
		cout << "    ";
	}
	else
	{
		GotoXY(pos.X, pos.Y + 1);
		cout << char(218) << char(196) << char(191);	//┌─┐
		GotoXY(pos.X, pos.Y + 2);						//O▀▀o
		cout << 'O' << char(223) << char(223) << 'o';
	}
}
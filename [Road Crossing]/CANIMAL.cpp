#include "CANIMAL.h"

#include <iostream>
using namespace std;

bool CANIMAL::inContact(Point ppos)
{
	return pos.X <= ppos.X && ppos.X <= pos.X + 2
		&& pos.Y == ppos.Y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của animal
}

//void CANIMAL::draw() { }
void CBird::draw(Point pos, bool erase)
{
	if (erase)
	{
		GotoXY(pos.X - 1, pos.Y);
		cout << "   ";
	}
	else
	{
		GotoXY(pos.X, pos.Y);
		cout << char(169) << char(250) << char(170); //⌐·¬	-·-
	}
}
void CDino::draw(Point pos, bool erase)
{
	if (erase)
	{
		GotoXY(pos.X - 1, pos.Y);
		cout << "  ";
		GotoXY(pos.X - 1, pos.Y + 1);
		cout << "   ";
		GotoXY(pos.X - 1, pos.Y + 2);
		cout << "   ";
	}
	else
	{
		GotoXY(pos.X, pos.Y);
		cout << ' ' << char(244);			// ⌠
		GotoXY(pos.X, pos.Y + 1);			//(0)
		cout << "(0)";						//┘LL
		GotoXY(pos.X, pos.Y + 2);
		cout << char(217) << "LL";
	}
}

void CANIMAL::speak() { }
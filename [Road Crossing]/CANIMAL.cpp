#include "CANIMAL.h"

#include <iostream>
using namespace std;

bool CANIMAL::inContact(Point ppos)
{
	return pos.x <= ppos.x && ppos.x <= pos.x + 2
		&& pos.y == ppos.y;
	//Việc xét điểm y còn tuỳ vào kích cỡ của animal
}

CANIMAL::CANIMAL()
{
	pos.x = 0;
	pos.y = 0;
	speed = 0;
}

CANIMAL::CANIMAL(int y, int s_speed)
{
	pos.x = 0;
	pos.y = y;
	speed = s_speed;
}

CBird::CBird() : CANIMAL(1, 20){}

CDino::CDino(): CANIMAL(3, 30){}

void CANIMAL::draw() { }
void CBird::draw(char s, COORD pos)
{
	GotoXY(pos.X, pos.Y);
	cout << ' ' << ' ' << ' ' << s;
	GotoXY(pos.X, pos.Y + 1);
	cout << s;
	GotoXY(pos.X, pos.Y + 2);
	cout << ' ' << ' ' << s;
}
void CDino::draw(char s, COORD pos)
{
	GotoXY(pos.X, pos.Y);
	cout << s;
	GotoXY(pos.X, pos.Y + 1);
	cout << s << s;
	GotoXY(pos.X, pos.Y + 2);
	cout << s << s << s;
}

void CANIMAL::speak() { }
#include "CPEOPLE.h"
#include "Constants.h"

#include <iostream>
using namespace std;

CPEOPLE::CPEOPLE()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(console, &cbsi);
	
	icon = 0;
	pos = { cbsi.srWindow.Right / 2, cbsi.srWindow.Bottom };
	alive = true;
}

//bool CPEOPLE::inContact(CVEHICLE v)
//{
//	return v.inContact(pos);
//}
//bool CPEOPLE::inContact(CANIMAL a)
//{
//	return a.inContact(pos);
//}
//CVEHICLE CPEOPLE::nowContact(const CVEHICLE*& v)
//{
//	for (int i = 0; i < MAX_TRUCK + MAX_CAR; i++)
//	{
//		if (inContact(v[i]))
//			return v[i];
//	}
//}
//CANIMAL CPEOPLE::nowContact(const CANIMAL*& a)
//{
//	for (int i = 0; i < MAX_DINO + MAX_BIRD; i++)
//	{
//		if (inContact(a[i]))
//			return a[i];
//	}
//}

bool CPEOPLE::isDead()
{
	return true;
}

void CPEOPLE::draw(Point pos, bool erase)
{
	if (erase)
	{
		GotoXY(pos.X, pos.Y);
		cout << "  ";
		GotoXY(pos.X, pos.Y + 1);
		cout << "   ";
		GotoXY(pos.X, pos.Y + 2);
		cout << "  ";
	}
	else
	{
		char i;
		switch (icon)
		{
		case 1: i = char(235); break; //δ
		case 2: i = char(229); break; //σ
		default: i = 'o'; break;
		}
		GotoXY(pos.X, pos.Y);
		cout << ' ' << i;
		GotoXY(pos.X, pos.Y + 1);						// o				 o
		cout << char(218) << char(197) << char(217);	//┌┼┘ //192 197 191 └┼┐
		GotoXY(pos.X, pos.Y + 2);						// π				 π
		cout << ' ' << char(227);
	}
}
int CPEOPLE::getIcon() { return icon; }
int CPEOPLE::setIcon(int i)
{
	icon = i;
	if (icon > 2 || icon < 0)
		icon = 0;
	return icon;
}
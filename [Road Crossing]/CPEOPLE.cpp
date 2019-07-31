#include "CPEOPLE.h"
#include "Constants.h"

Window wp;

CPEOPLE::CPEOPLE()
{
	SMALL_RECT sizeRect = wp.GetConsoleSize();
	icon = 0;
	//CPEOPLE ko cần dùng speed nên ko cần đặt giá trị
	pos = { sizeRect.Right / 2, PEOPLE_Y };
	alive = true;
	setAvatar(0);
	lv = 0;
}
void CPEOPLE::setAvatar(int i)
{
	char c;
	switch (icon)
	{
	case 1: c = P_HEAD1; break; //δ
	case 2: c = P_HEAD2; break; //σ
	default: c = P_HEAD0; break;
	}
	avatar[0] = { ' ', c };								// o				 o
	avatar[1] = { char(218), char(197), char(217) };	//┌┼┘ //192 197 191 └┼┐
	avatar[2] = { ' ', char(227) };						// π				 π
}
void CPEOPLE::reset()
{
	SMALL_RECT sizeRect = wp.GetConsoleSize();
	icon = 0;
	pos = { sizeRect.Right / 2, PEOPLE_Y };
	alive = true;
	setAvatar(0);
	lv = 0;
}

void CPEOPLE::Move(char button)
{
	switch (button)
	{
	case 'W': case 'I': case VK_UP:
		up(); break;
	case 'A': case 'J': case VK_LEFT:
		left(); break;
	case 'S': case 'K': case VK_DOWN:
		down(); break;
	case 'D': case 'L': case VK_RIGHT:
		right(); break;
	}
}
void CPEOPLE::arms()
{
	if (avatar[1][0] == char(218))
	{
		avatar[1][0] = char(192);
		avatar[1][2] = char(191);
	}
	else
	{
		avatar[1][0] = char(218);
		avatar[1][2] = char(217);
	}
}
void CPEOPLE::up()
{
	if (1 <= pos.Y && pos.Y < 9)
	{
		arms();
		moveXY(0, 1);
	}
}
void CPEOPLE::left()
{
	if (4 < pos.X && pos.X <= wp.GetConsoleSize().Right - 5)
	{
		arms();
		moveXY(-1, 0);
	}
}
void CPEOPLE::down()
{
	if (1 < pos.Y && pos.Y <= 9)
	{
		arms();
		moveXY(0, -1);
	}
}
void CPEOPLE::right()
{
	if (4 <= pos.X && pos.X < wp.GetConsoleSize().Right - 5)
	{
		arms();
		moveXY(1, 0);
	}
}

bool CPEOPLE::isDead() { return !alive; }

char CPEOPLE::getIcon(int mode)
{
	if (mode == 0)
		switch (icon)
		{
		case 1: return P_HEAD1;
		case 2: return P_HEAD2;
		default: return P_HEAD0;
		}
	else
		return icon;
}
int CPEOPLE::setIcon(int i)
{
	icon = i;
	if (icon > 2 || icon < 0)
		icon = 0;
	setAvatar(i);
	return icon;
}

unsigned CPEOPLE::getLevel() { return lv; }
unsigned CPEOPLE::setLevel(unsigned l) { return lv = l; }
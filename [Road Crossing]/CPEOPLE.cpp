#include "CPEOPLE.h"
#include "Constants.h"

CPEOPLE::CPEOPLE()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	GetConsoleScreenBufferInfo(console, &cbsi);

	SMALL_RECT sizeRect = cbsi.srWindow;
	icon = 0;
	pos = { sizeRect.Right / 2, sizeRect.Bottom };
	alive = true;
	setAvatar(0);
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
	return !alive;
}

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
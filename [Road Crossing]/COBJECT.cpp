//Cần thêm winmm.lib vào Linker trong Project Properties để hàm speak hoạt động
#include <Windows.h>
#include <mmsystem.h>

#include "COBJECT.h"
#include "CGAME.h"

Window wd;

COBJECT::COBJECT()
{
	type = "object";
	pos = { 0, 0 };
	speed = 1;
	for (int i = 0; i < 3; i++)
		avatar.push_back("");
	voice = "Data\\Sounds\\";
}

void COBJECT::draw(Point p)
{
	flip();
	if (p.X == -1 && p.Y == -1)
		p = pos;

	p.Y = (10 - p.Y) * 5 + 2;
	wd.GotoXY(p.X, p.Y - 1);
	cout << "           "; //Xoá ký tự dư trên đầu khi wrap sang phía bên kia
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X, p.Y + i);
		cout << avatar[i];
	}
}
void COBJECT::erase(Point p)
{
	if (p.X == -1 && p.Y == -1)
		p = pos;

	p.Y = (10 - p.Y) * 5 + 2;
	for (int i = 0; i < 3; i++)
	{
		wd.GotoXY(p.X - 4, p.Y + i);
		cout << "          ";
	}
}

void COBJECT::moveXY(short x, short y, long timer)
{
	if (timer % abs(speed) != 0)
		return;

	//Di chuyển y theo làn, ko phải theo dòng kí tự trên console
	if (x != 0 || y != 0)
	{
		erase();
		pos.X += speed > 0 ? x : -x;
		pos.Y += y;
	}
	draw(pos);
}
void COBJECT::speak()
{
	static CGAME* g;
	if (g->getSound())
		PlaySound(voice.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}

Point COBJECT::getPos() { return pos; }
void COBJECT::speedDirChange(int i)
{
	if (speed < 0)
		speed *= -1;
	speed *= i / abs(i);
}

void COBJECT::flip()
{
	//Nếu đang đi chiều nghịch mà avatar đang hướng chiều thuận
	if (speed < 0 && avatar == defaultAva::avatar(type))
		avatar = defaultAva::avatar(type + "_flipped");
	//Nếu đang đi chiều thuận mà avatar đang hướng chiều nghịch
	else if (speed > 0 && avatar != defaultAva::avatar(type))
		avatar = defaultAva::avatar(type);
}
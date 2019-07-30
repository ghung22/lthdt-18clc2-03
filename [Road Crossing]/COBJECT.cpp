//Cần thêm winmm.lib vào Linker trong Project Properties để hàm speak hoạt động
#include <Windows.h>
#include <mmsystem.h>

#include "COBJECT.h"
#include "CGAME.h"

Window wd;

COBJECT::COBJECT()
{
	pos = { rand() % 20, 0 };
	speed = 0;
	for (int i = 0; i < 3; i++)
		avatar.push_back("");
	voice = "Data\\Sounds\\";
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
	wd.GotoXY(p.X - 4, p.Y + 3); //Phòng việc xoá mất làn đường
	cout << '_';
}

void COBJECT::moveXY(short x, short y)
{
	//Di chuyển y theo làn, ko phải theo dòng kí tự trên console
	Point temp = pos;

	if (x != 0 || y != 0)
	{
		temp.Y = (10 - pos.Y) * 5 + 2;
		erase(temp);

		pos.X += x;
		pos.Y += y;
	}

	temp.Y = (10 - pos.Y) * 5 + 2;
	draw(temp);
}
void COBJECT::speak()
{
	static CGAME* g;
	if (g->getSound())
		PlaySound(voice.c_str(), NULL, SND_ASYNC | SND_FILENAME);
}